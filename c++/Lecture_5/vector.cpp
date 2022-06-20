#include <vector>
#include <iostream>
#include <memory>
#include <algorithm>
template<typename T>
class Vector{
  
  // we want a resizable array so we need to remember a pointer to the array,
  // how big it is and to avoid to allocate a new array every time we do a pushback,
  // we will allocate more elements than it is strictly required, so we need an
  // additional variable/pointer that remembers how big the memory we have allocated is
  
  std::unique_ptr<T[]> elem;
  std::size_t _size{};
  std::size_t _capacity{};

  void check_and_increase_capacity(){
    if(_capacity == 0){
      reserve(8);	// reserve 8 elements
    }else if (_size == _capacity){
      reserve(2*_capacity);
    }
    
    
  }


  template <typename O>
  void _push_back(O&& x){
    check_and_increase_capacity();
    elem[_size] = std::forward<O>(x); 		//copy or move assignment depending on the type of x
    ++_size;
  }

 public:

  auto size() const { return _size;}
  auto capacity() const { return _capacity;}

  Vector() = default; 	// default ctor
  ~Vector() = default;	// default destructor is fine we don' have raw pointers
  
  // Copy and move semantics are the same implemented in the lectures
  
  Vector(std::initializer_list<T> list): //passed by value	// std::initializer_list ctor
    elem{new T[list.size()]},
    _size{list.size()},
    _capacity{list.size()}{
    
    std::copy(list.begin(), list.end(), elem.get());
  
    //for(std::size_t i=0; i<list.size(); ++i){		// this syntax needs the subscripting operator
    //  elem[i] = std::move(list[i]);			// to be defined
    //}
  }

  void reserve(const std::size_t n){
    if(_capacity<n){
      T* _tmp{new T[n]};
      for(std::size_t i=0; i<_size; ++i){
        _tmp[i]=std::move(elem[i]);
      }
      elem.reset(_tmp);
      _capacity = n;
    }
  }

  void push_back(const T& x){ 		//l-value reference
    _push_back(x);
  }

  void push_back(const T&& x){		//r-value reference
    _push_back(std::move(x));
  }

  auto& operator[](const std::size_t i){
    //pre-conditions i<_size and elem != nullptr
    return elem[i];
  }

  const auto& operator[](const std::size_t i) const {
   //pre-conditions i<_size and elem != nullptr
    return elem[i];
  }

  template <typename... Types>		//variadic template; packing
  void emplace_back(Types&&... args){   // unpacking;  with && each argument is declared as a forwarding reference 
  check_and_increase_capacity();
  elem[_size]= T{std::forward<Types>(args)...}
  ++_size
  }
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& x){
  os << "capacity: " << x.capacity() << ", size: " << x.size() << "\n";
  for(auto i=0u; i< x.size(); ++i){
    os << x[i] << " ";
  }
  os << std::endl;
  return os;
}

struct Foo{
  Foo(){std::cout<< "foo ctor" << std::endl;}
  
}

int main(){

  Vector<Foo> vf{{},{}};

  vf.emplace_back();

  return 0;
  
  Vector<int> x{1,2,3,4};
    
  std::cout << x;

  x.push_back(5);

  std::cout << x;

}

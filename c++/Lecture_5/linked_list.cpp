#include <iostream>
#include <memory> //needed for std::unique_ptr
#include <utility>

enum class Method{push_back, push_front};

template <typename T>
class List{

  // we implement the concept of node inside the list
  // it is private since we don't want the user to be
  // aware of it
   
  struct node{
    std::unique_ptr<node> next; //unique pointer that points to the next node
    T value;                    //value stored

    explicit node(const T& x): value{x} {std::cout<<"l-value\n";} // custom ctor that takes a value
    node(const T& x, node* p): next{p}, value{x} {std::cout<<"l-value\n";}
    
    // constructors for the second version of insert
    explicit node(T&& x): value{std::move(x)} {std::cout<<"r-value"<< std::endl;}
    node(T&& x, node* p): next{p}, value{std::move(x)} {std::cout<<"r-value"<< std::endl;}

    explicit node(const std::unique_ptr<node>& x): value{x->value}{
      if(x->next)
        next.reset(new node{x->next});
    }
  };

  std::unique_ptr<node> head;   //the head pointer will point to the first block
  std::size_t _size;
  
  // private functions push_back and push_front
  
  // forwarding reference 
  template <typename O>		// it must be templated
  void push_front(O&& x){	// forwarding ref. not r-value, it can accept both l and r values
 
    // auto tmp = new node{x, head.release()};
    // head.reset(tmp);
    // collapsed version of the two lines:

    head.reset(new node{std::forward<O>(x), head.release()}); // this works even if our list is empty
  }


  // forwarding reference 
  template <typename O>
  void push_back(O&& x){
    
    auto _node = new node{std::forward<O>(x)};
    // auxiliary pointer to get to the last block
    auto tmp = head.get();

    if(!tmp){ // if tmp == nullptr the list is empty
      head.reset(_node);
      return;
    }
    
    while(tmp->next) // while ymp->next.get() != nullptr
      tmp = tmp->next.get();
    
    tmp->next.reset(_node);  
  }

  public:
  
  List() = default;		// default constructor
  ~List() = default;		// we don't have raw pointers so the default generated destructor is fine
  
  // move semantics: since we don't have raw pointers the move
  // 		     semantics generated by the compiler is fine
  
  List(List&&) = default; // move constructor
  
  List& operator=(List&&) = default;  // move assignment

  // manual implementation of move semantics: we call a move on each member
  
  // List(List&& x): head{std::move(x.head)}, _size{std::move(x._size)}{
  //   x._size=0;
  //   x.head.reset(nullptr);
  // }

  // List& operator=(List&& x){
  //   head = std::move(x.head);
  //   _size = std::move(x._size);
       
  //   x._size=0;
  //   x.head.reset(nullptr);
  //   return *this;  //to support a = b = c = std::move(x)
  // }
 
  // copy semantics:
  List(const List& x): _size{x._size} { // copy ctor
    
     if(x.head)
       head.reset(new node{x.head});
  }

  List& operator=(const List& x){  // copy assignment
    
    head.reset();
    
    auto tmp = x; 		// copy ctor
    *this = std::move(tmp); 	// move assignment
    return *this;
  }

  void insert(const T& x, const Method m); // we define it outside, we don't want it to be inlined
  void insert(T&& x, const Method m);	   // we can define insert in a different way to use 
					   // move instead of copy

  friend
  std::ostream& operator<<(std::ostream& os, const List& x){
    auto tmp = x.head.get();
    os << "[" << x._size << "] ";

    while(tmp){
      os << tmp->value << " ";
      tmp = tmp->next.get();
    }
    os << std::endl;
    return os;  
  }
  
};

template <typename T>
void List<T>::insert(const T& x, const Method m){
  std::cout << "l-value insert" << std::endl;
  switch(m){
    case Method::push_back:
      push_back(x);
      break;
    
    case Method::push_front:
      push_front(x);
      break;
    
    default:
      std::cout << "Unknown method" << std::endl;
      break;
  };
  
  ++_size;
}

template <typename T>
void List<T>::insert(T&& x, const Method m){
 
  std::cout << "r-value insert" << std::endl;
  switch(m){
    case Method::push_back:
    push_back(std::move(x));	// if we have an r-value reference it is passed as an l-value
    break;
       
    case Method::push_front:
    push_front(std::move(x));
    break;
       
    default:
    std::cout << "Unknown method" << std::endl;
    break;
  };  
 
  ++_size;
}


template <typename T>			
  //void my_swap(T& a, T& b){   	// in this way we are "cloning"
  //auto tmp = a; // copy ctor		// here we have 2 a, 1 b
  //a=b;	// copy assignment	// here 1 a, 2 b
  //b=tmp;	// copy assignment	// here 2 a and 1 b 
					// we don't need all these objects!

  // better way to implement is by using move
  void my_swap(T& a, T& b){
    auto tmp = std::move(a);
    a = std::move(b);
    b = std::move(tmp);
}

int main(){

  List<int> l{};
  
  int a = 7;

  l.insert(a, Method::push_back);
  l.insert(1, Method::push_back);
  l.insert(5, Method::push_front);
  
  std::cout << l << std::endl;

  // test move semantics:

  List<int> l2{std::move(l)};
  
  std::cout << l2 << std::endl;
  
  // wiritng std::cout << l;  is a bug of undefined behaviour after the move
  
  l = List<int>{}; // move assignment, l will get an empty list

  // test copy semantics:

  List<int> l3{l2};

  l3.insert(99, Method::push_front);
  l2.insert(877, Method::push_back);

  std::cout << l2 << "\n" << l3 << std::endl;

}

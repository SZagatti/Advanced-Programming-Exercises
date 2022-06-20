#include <array>
#include <iostream>
#include <vector>
#include <map>
enum class Month{January=1, February, March, April, May, June, July, August, September, October, November,     December};

class Date{
  
  private:

  // private member variables
  unsigned int c_Day;
  Month c_Month;
  unsigned int c_Year;
  
  //private member functions
  void add_one_day();
  void add_one_month();
  void add_one_year();
  
  public:

  // custom consytuctor:
  Date(unsigned int dd, Month mm, unsigned int yyyy)
   : c_Day{dd}, c_Month{mm}, c_Year{yyyy} {};

  // inlined public functions
  const unsigned int day() const {return c_Day;}
  const Month month() const {return c_Month;}
  const unsigned int year() const{return c_Year;}
  
  // non-inlined functions 
  void add_days(const unsigned int);
};

// Definition of the non inlined functions

bool is_leap(const unsigned int y){

  if((y % 4u == 0u && y % 100u != 0u)||(y % 400u == 0u)){
  
    return true;
  
  }else{
    
    return false;
  }
}

Month next_month(const Month m){

  switch(m){

  case(Month::January): 
    return Month::February;
    break;

  case(Month::February):
    return Month::March;
    break;

  case(Month::March): 
    return Month::April;
    break;

  case(Month::April): 
    return Month::May;
    break;
  
  case(Month::May): 
    return Month::June;
    break;

  case(Month::June): 
    return Month::July;
    break;

  case(Month::July): 
    return Month::August;
    break;

  case(Month::August): 
    return Month::September;
    break;

  case(Month::September): 
    return Month::October;
    break;

  case(Month::October):
    return Month::November;
    break;

  case(Month::November):
    return Month::December;
    break;

  case(Month::December):
    return Month::January;
    break;
 
  default: 
    std::cout << "Error" << std::endl;
    break;
  }
}

void Date::add_one_year(){
  
   c_Year ++;
}

void Date::add_one_month(){

  if(c_Month==Month::December){
    add_one_year();
  }
  c_Month = next_month(c_Month);
}

void Date::add_one_day(){

  switch(c_Month){
  
  case(Month::November):case(Month::April):
  case(Month::June):case(Month::September):{

    if(c_Day==30){
      add_one_month();
      c_Day=1;

    }else{
      c_Day++;
    }
  break;
  }
  case(Month::February):{

    if(is_leap(c_Year)==true){
      if(c_Day==29){
        add_one_month();
        c_Day=1;
      }else{
        c_Day++;
      }  
    }else{
      if(c_Day==28){
        add_one_month();
        c_Day=1;
      }else{
        c_Day++;
      }
    }
  break;
  }
  default:{
    if(c_Day==31){
      add_one_month();
      c_Day=1;
    }else{
      c_Day++;
    }
  break;
  }
  }
}

void Date::add_days(const unsigned int n){

  for(unsigned int i=0; i<n; i++){
    add_one_day();
  }
}

// External Helper Functions

bool operator==(const Date& lhs, const Date& rhs){
  
  if((lhs.day()==rhs.day()) && (lhs.month()==rhs.month()) && (lhs.year()==rhs.year())){
    return true;
  }else{
    return false;
  }
}

bool operator !=(const Date& lhs, const Date& rhs){
  return(!(lhs==rhs));
}

std::ostream& operator<<(std::ostream& os, const Date& d){

std::map<unsigned int, std::string> mm{{1,"January"}, {2,"February"}, {3,"March"}, {4,"April"}, {5,"May"}, {6,"June"}, {7,"July"}, {8,"August"}, {9,"September"}, {10,"October"}, {11,"November"}, {12,"December"}};

std::string month;

for(unsigned int i=1; i<=12; i++){
  
  if((static_cast<unsigned int>(d.month()))==i){
  
    month=mm[i];
  }
} 
  os << d.day() << " " << month << " " << d.year() << std::endl;
  return os;
}

//========================================================================================================

int main(){

  Date my_birthday(11, Month::January, 1995);

  std::cout << "My Birthday is the: " << my_birthday << std::endl;

  my_birthday.add_days(365*26 + 7);

  std::cout << "I turned 26 on the " << my_birthday << "\n"
            << "I've checked this by adding a total of 365*26 + 7 days to my birthday, where 7 is the number of leap years I've been through!"<< std::endl;


  return 0;
}






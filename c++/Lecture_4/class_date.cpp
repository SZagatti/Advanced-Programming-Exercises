#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <array>
#include <iomanip>

// Scoped Enum for the month

enum class month_enum{
  Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec
};

// IS_LEAP: checks if the year is leap

bool is_leap(const unsigned int y){

  if((y % 4u == 0u && y % 100u != 0u)||( y % 400u == 0u)){
 
    return true;

  }else{
 
    return false;
  }
}


month_enum next_month( const month_enum m){
  
  switch(m){

    case (month_enum::Jan): return month_enum::Feb;

    case (month_enum::Feb): return month_enum::Mar;
    
    case (month_enum::Mar): return month_enum::Apr;
    
    case (month_enum::Apr): return month_enum::May;
    
    case (month_enum::May): return month_enum::Jun;
    
    case (month_enum::Jun): return month_enum::Jul;
    
    case (month_enum::Jul): return month_enum::Aug;

    case (month_enum::Aug): return month_enum::Sep;

    case (month_enum::Sep): return month_enum::Oct;

    case (month_enum::Oct): return month_enum::Nov;

    case (month_enum::Nov): return month_enum::Dec;

    case (month_enum::Dec): return month_enum::Jan;

    default: std::cout << "Error" << std::endl;
  }
}

// Class Date

class Date{

  private:

  unsigned int cday;
  month_enum cmonth;
  unsigned int cyear;

  void add_one_day();
  void add_one_month();
  void add_one_year();

  public:

  // custom constructor

  Date(unsigned int input_day, month_enum input_month, unsigned int input_year):
    cday{input_day}, cmonth{input_month}, cyear{input_year} {};

  unsigned int day() const {return cday;}
  month_enum month() const {return cmonth;}
  unsigned int year() const {return cyear;}
  
  void add_days(const unsigned int);
};

// ==================== NON INLINED FUNCTIONS ====================

unsigned int n_days( const month_enum m, unsigned int y){
 
  switch(m)

    {
      case(month_enum::Feb):

        {

        if(is_leap(y) == false){

          return 28;
        }
        else{

          return 29;
        }}

     case(month_enum::Nov): case(month_enum::Apr):
     case(month_enum::Jun): case(month_enum::Sep):

        return 30;

      default:

        return 31;
   }
}

// ADD_DAYS: adds a given number of days to the date
void Date::add_days(const unsigned int n){
 
  for(int i=0; i<n; i++){
 
    Date::add_one_day();

  }
}


// ADD_ONE_DAY: adds one day to the date

void Date::add_one_day(){

  if(Date::cday == n_days(Date::cmonth, Date::cyear)){

    Date::cday = 1;
    Date::add_one_month();
  }
  else{
  
    Date::cday++;

  }
}


// ADD_ONE_MONTH: adds one month to the date

void Date::add_one_month(){
           
  if(Date::cmonth == month_enum::Dec){
  
    Date::cmonth = next_month(Date::cmonth);
    Date::add_one_year();
  }
  else {

    Date::cmonth = next_month(Date::cmonth);
  }

}


// ADD_ONE_YEAR: adds one year to the date

void Date::add_one_year(){

  Date::cyear++;

}


// ===============================================================

// ==================== HELPER FUNCTIONS ====================

bool operator==(const Date& lhs, const Date& rhs);
bool operator!=(const Date& lhs, const Date& rhs);
std::ostream& operator<<(std::ostream& os, const Date& d);


bool operator==(const Date& lhs, const Date& rhs){

  if(lhs.day() == rhs.day() && lhs.month() == rhs.month() && lhs.year() == rhs.year()){
  
    return true;
  
  }else{

    return false;
  }
}






bool operator!=(const Date& lhs, const Date& rhs){

  return(!(lhs==rhs));
}

std::ostream& operator<<(std::ostream& os, const Date& d){

  os << d.day() <<"/"<< static_cast<unsigned int>(d.month())<<"/"<<d.year();
  return os;

}

// ===============================================================

int main(){

  Date my_birthday(11, month_enum::Jan, 1995);

  std::cout << "My Birthday is the: " << my_birthday << std::endl;

  my_birthday.add_days(26*365+7);

  std::cout << "I turned 26 on the " << my_birthday << "\n"
            << "I've checked this by adding a total of 365*26 + 7 days to my birthday, where 7 is the number of leap years I've been through!"<< std::endl;


  return 0;
}


#include <iostream>
#include "date.hpp"
#include <string>

void event::setDescription (std::string Desc){
  Description = Desc ;
}

std::string event::getDescription (){
  return Description;
}

 /* void date::askDay(int dd) {
  day = dd;
}

int date::inDay() {
  return day;
}*/
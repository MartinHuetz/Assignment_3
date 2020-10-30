#include <iostream>

#include "date.hpp"

#include <string>

date::date() {
  day = 0;
  month = 0;
  year = 0;
}

//Definition of variables 

date::date(int yy, int mm, int dd) {
  day = dd;
  month = mm;
  year = yy;
}

date::~date() {}

void date::askDay(int dd) {
  day = dd;
}

void date::askMonth(int mm) {
  month = mm;
}

void date::askYear(int yy) {
  year = yy;
}

void date::outDate() {
  std::cout << year << " " << month << " " << day << " ";
}

int date::inDay() {
  return day;
}

int date::inMonth() {
  return month;
}

int date::inYear() {
  return year;
}

//The possibility of a leapyear is taken into account 
//A leapyear occurs usually every 4 years. Except centenary years that are not divisible by 400

bool leapyear(int x) {
  bool ly = false;
  if (x % 4 == 0) {
    ly = true;
  }
  if (x % 100 == 0) {
    ly = false;
  }
  if (x % 400 == 0) {
    ly = true;
  }
  return ly;
}

//Equation to calculate the number of days starting from 2000
//In a leapyear February has 29 days instead of 28 days 

int date::inTotalDays() {

  int daysfromstart = (year - 2000) * 365;

  for (int y = 2000; y < year; y++) {
    if (leapyear(y))
      daysfromstart++;
  }

  int monthlength[] = {31,28,31,30,31,30,31,31,30,31,30,31};
  
  for (int m = 0; m < month - 1; m++) {
    daysfromstart += monthlength[m];
  }

  if (leapyear(year) && (month > 2))
    daysfromstart++;

  daysfromstart += day - 1;

  return daysfromstart;

}

void date::inWeekday() {
  int totalDays = date::inTotalDays();
  int dayNumber = totalDays % 7 + 1;

  switch (dayNumber) {
  case 1:
    std::cout << "monday\n";
    break;
  case 2:
    std::cout << "tuesday\n";
    break;
  case 3:
    std::cout << "wednesday\n";
    break;
  case 4:
    std::cout << "thursday\n";
    break;
  case 5:
    std::cout << "friday\n";
    break;
  case 6:
    std::cout << "saturday\n";
    break;
  case 7:
    std::cout << "sunday\n";
    break;
  default:
    std::cout << "An error occurred.\n";
  }

}
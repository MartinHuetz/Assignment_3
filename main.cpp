#include <iostream>
#include "date.hpp"
#include <string>


int main() {

  std::cout << "Enter the dates in year month day format, one per line. To finish, enter the date 0 0 0.";

//Definition of variables

  int yy, mm, dd;
  char colon; 
  std::string Desc;
  int i = 0;
  //date dates[20];
  //date storeDates[20];
 //we are using subclass event instead of claas date, so we have a Description
  event dates[20];
  event storeDates[20];


//Retrieve information from the user

  std::cin >> yy >> mm >> dd >> colon >> Desc;
  while (yy != 0 && mm != 0 && dd != 0) {
    dates[i].askYear(yy);
    dates[i].askMonth(mm);
    dates[i].askDay(dd);
    dates[i].setDescription(Desc);
    storeDates[i].askYear(yy);
    storeDates[i].askMonth(mm);
    storeDates[i].askDay(dd);
    storeDates[i].setDescription(Desc);

    i++;
    std::cin >> yy >> mm >> dd >> colon >> Desc;

  }

  std::cout << "\n";
  int DayNumber [i];
  std::string eachDesc [i];
  for (int j = 0; j < i; j++) {
    DayNumber[j] = dates[j].inTotalDays();
    eachDesc[j]=dates[j].getDescription();
  }


//Sorting of days

  for (int s = 0; s < i; s++) {
    int x = s;
    int fromstart = DayNumber[x];
    for (int s2 = s + 1; s2 < i; s2++) {
      if (DayNumber[s2] < fromstart) {
        fromstart = DayNumber[s2];
        x = s2;
      }
    }
    DayNumber[x] = DayNumber[s];
    DayNumber[s] = fromstart;
  }

//Go through sorted days, print the day number and date if the conditions are fulfilled

  for (int n = 0; n < i; n++) {
    for (int v = 0; v < i; v++) {
      if (DayNumber[n] == storeDates[v].inTotalDays()) {
        storeDates[v].outDate();
        //.old std::cout << DayNumber[n] << "\n"; //.OLD 
        std::cout << eachDesc[n] << "\n";

      }
    }
  }

  return 0;
}
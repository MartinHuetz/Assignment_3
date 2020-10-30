#pragma once

class date {
  private:
    int day;
    int month;
    int year;
    
  public:
    date();
    date(int dd, int mm, int yy);
    ~date();
  //protected:
    void askDay(int dd);
    void askMonth(int mm);
    void askYear(int yy);
    void outDate();
    int inTotalDays();
    void outTotalDays();
    void inWeekday();
    int inDay();
    int inMonth();
    int inYear();

};

class event : public date {
  private:
    std::string Description;
  public:
    /*event();
    event(std::string Desc);
    ~event();
*/
  void setDescription (std::string Desc);
  std::string getDescription ();
};
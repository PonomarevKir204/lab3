#pragma once
#include <time.h>
#include <fstream>
#include <sstream>
#include <istream>
#include <ostream>

using namespace std;

class Datetime
{
private:
    int hour;
    int minute;
    int second;

    int day;
    int month;
    int year;
public:
    Datetime(int hour, int minute, int second, int day, int month, int year);
    Datetime() {}
    ~Datetime() {}
    
    void System_time(Datetime& obj);
    void Get_next_date(Datetime& next);
    void Get_prev_date(Datetime& prev);

    int& Get_hour();
    int& Get_minute();
    int& Get_second();
    int& Get_day();
    int& Get_month();
    int& Get_year();

    void Set_hour(int hour);
    void Set_minute(int minute);
    void Set_second(int second);
    void Set_day(int day);
    void Set_month(int month);
    void Set_year(int year);

    friend std::ostream& operator << (std::ostream& stream, const Datetime& dt);
    friend std::istream& operator >> (std::istream& stream, Datetime& dt);
};

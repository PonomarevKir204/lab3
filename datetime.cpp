#include "datetime.h"

Datetime::Datetime(int hour, int minute, int second, int day, int month, int year) 
{
    this->day = day;
    this->month = month;
    this->year = year;
    this->hour = hour;
    this->minute = minute;
    this->second = second;
}

int& Datetime::Get_hour() {return hour;}
int& Datetime::Get_minute() {return minute;}
int& Datetime::Get_second() {return second;}
int& Datetime::Get_day() {return day;}
int& Datetime::Get_month() {return month;}
int& Datetime::Get_year() {return year;}

void Datetime::Set_hour(int hour) 
{ 
    if(hour >= 0 && hour < 24) 
        this->hour = hour;
}
void Datetime::Set_minute(int minute) 
{
    if(minute >= 0 && minute < 60) 
        this->minute = minute;
}
void Datetime::Set_second(int second)
{ 
    if(second >= 0 && second < 60) 
        this->second = second;
}
void Datetime::Set_day(int day)
{ 
    if(day >= 0 && day <= 31) 
        this->day = day;
}
void Datetime::Set_month(int month)
{ 
    if(month >= 0 && month <= 12) 
        this->month = month;
}
void Datetime::Set_year(int year)
{ 
    if(year >= 0) 
        this->year = year;
}

ostream& operator << (ostream& stream, const Datetime& dt)
{
    stream << dt.day << ' ' << dt.month << ' ' << dt.year << ' ' << dt.hour << ' ' << dt.minute << ' ' << dt.second << std::endl;
    return stream;
}

istream& operator >> (istream& stream, Datetime& dt)
{
    stream >> dt.day >> dt.month >> dt.year >> dt.hour >> dt.minute >> dt.second;
    return stream;
}

void Datetime::System_time(Datetime& obj)
{
    time_t rawtime;
    tm timeinfo;
    time(&rawtime);
    localtime_s(&timeinfo, &rawtime);
    obj.day = timeinfo.tm_mday;
    obj.month = timeinfo.tm_mon + 1;
    obj.year = timeinfo.tm_year + 1900;
    obj.hour = timeinfo.tm_hour;
    obj.minute = timeinfo.tm_min;
    obj.second = timeinfo.tm_sec;
}

time_t Get_unix_time(Datetime obj)
{
    tm timeinfo;
    timeinfo.tm_year = obj.Get_year() - 1900;
    timeinfo.tm_mon = obj.Get_month() - 1;
    timeinfo.tm_mday = obj.Get_day();
    timeinfo.tm_hour = obj.Get_hour();
    timeinfo.tm_min = obj.Get_minute();
    timeinfo.tm_sec = obj.Get_second();
    time_t unix_time = mktime(&timeinfo);
    return unix_time;
}

void Get_normal_time(time_t unix_time, Datetime& obj)
{
    tm timeinfo;
    localtime_s(&timeinfo, &unix_time);
    obj.Set_hour(timeinfo.tm_hour);
    obj.Set_minute(timeinfo.tm_min);
    obj.Set_second(timeinfo.tm_sec);
    obj.Set_day(timeinfo.tm_mday);
    obj.Set_month(timeinfo.tm_mon + 1);
    obj.Set_year(timeinfo.tm_year + 1900);
}

void Datetime::Get_next_date(Datetime& next)
{
    int min = 2419200 * 2;
    int max = 31536000;
    Get_normal_time(Get_unix_time(*this) + (min + rand() % (max - min + 1)), next);
}

void Datetime::Get_prev_date(Datetime& prev)
{
    int min = 2419200 * 2;
    int max = 31536000;
    Get_normal_time(Get_unix_time(*this) - (min + rand() % (max - min + 1)), prev);
}


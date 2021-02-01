/*
* File Name: lab3Clock.cpp
* Lab # and Assignment #: Lab 3 Exercise C
* Lab section: B01
* Completed by: Davis Allan, 10016543
* Submission Date: Oct 9 2020
*/
#include "lab3Clock.h"

Clock::Clock(): hour(0), minute(0), second(0) 
{

}

Clock::Clock(int second)
{
    if (second < 0) {
        set_hour(0);
        set_minute(0);
        set_second(0);
    } 
    else {
        sec_to_hms(second);
    }
    
}

Clock::Clock(int hour, int minute, int second)
{
    if (is_valid_hour(hour) && is_valid_min_or_sec(minute) && is_valid_min_or_sec(second)) {
        set_hour(hour);
        set_minute(minute);
        set_second(second);
    } 
    else {
        set_hour(0);
        set_minute(0);
        set_second(0);
    }
}

int Clock::get_hour() const
{
    return hour;
}

void Clock::set_hour(int hour)
{
    if (is_valid_hour(hour)) {
        this->hour = hour;
    }
}

int Clock::get_minute() const
{
    return minute;
}

void Clock::set_minute(int minute)
{
    if (is_valid_min_or_sec(minute)) {
        this->minute = minute;
    }
}

int Clock::get_second() const
{
    return second;
}

void Clock::set_second(int second)
{
    if (is_valid_min_or_sec(second)) {
        this->second = second;
    }
}

void Clock::increment()
{
    second++;
    if (second == 60){ 
        second = 0;
        minute++;
    }
    if (minute == 60) {
        minute = 0;
        hour++;
    }
    if (hour == 24) {
        hour = 0;
        minute = 0;
        second = 0;
    }
}

void Clock::decrement()
{
    second--;
    if (second == -1){ 
        second = 59;
        minute--;
    }
    if (minute == -1) {
        minute = 59;
        hour--;
    }
    if (hour == -1) {
        hour = 23;
        minute = 59;
        second = 59;
    }
}

void Clock::add_seconds(int second)
{
    int time = hms_to_sec() + second;
    sec_to_hms(time);
}

int Clock::hms_to_sec()
{
    int total, hour, minute, second;

    hour = get_hour();
    minute = get_minute();
    second = get_second();

    total = (hour * 3600) + (minute * 60) + second;
    return total;
}

void Clock::sec_to_hms(int n)
{
    int hour, remain, minute, second;
    
    hour = n / 3600;
    //if the hour is greater than 24, then multiple day(s) have passed
    if (!is_valid_hour(hour)) {  
        hour %= 24;
    }
    remain = n % 3600;
    minute = remain / 60;
    second = remain % 60;

    set_hour(hour);
    set_minute(minute);
    set_second(second);
}

bool Clock::is_valid_hour(int hour)
{
    if (hour >= 0 && hour <= 23){
        return true;
    }
    else {
        return false;
    }
}

bool Clock::is_valid_min_or_sec(int time) 
{
    if (time >= 0 && time <= 59) {
        return true;
    }
    else {
        return false;
    }
}
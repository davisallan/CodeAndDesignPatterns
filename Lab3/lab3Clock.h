/*
* File Name: lab3Clock.h
* Lab # and Assignment #: Lab 3 Exercise C
* Lab section: B01
* Completed by: Davis Allan, 10016543
* Submission Date: Oct 9 2020
*/
#ifndef CLOCK
#define CLOCK

class Clock {

public:
    Clock();
    //PROMISES: Clock object created with all data members initialized to zeros

    Clock(int second);
    //PROMISES: 
    //  Clock object created with data members hour, minute and second initialized
    //  from the arg second
    //REQUIRES:
    //  second >= 0

    Clock(int hour, int minute, int second);
    //PROMISES:
    //  Clock object created with data members intialized to the values of hour, minute
    //  and second respectively
    //REQUIRES:
    //  hour >= 0 && hour <=23
    //  minute >= 0 && minute <= 59
    //  second >= 0 && ssecond <= 59

    int get_hour() const;
    //PROMISES: returns the current value for the hour

    void set_hour(int hour);
    //PROMISES: sets a new value for the clock's hour
    //REQUIRES: hour >= 0 && hour <= 23

    int get_minute() const;
    //PROMISES: returns the current value for the clock's minute

    void set_minute(int minute);
    //PROMISES: sets a new value for the clock's minute
    //REQUIRES: minute >= 0 && minute <= 59

    int get_second() const;
    //PROMISES: returns the current value for the clock's second

    void set_second(int second);
    //PROMISES: sets a new value for the clock's second
    //REQUIRES: second >= 0 && second <= 59

    void increment();
    //PROMISES: increments the value of the clock's time by one

    void decrement();
    //PROMISES: decrements the value of the clock's time by one

    void add_seconds(int second);
    //PROMISES: adds the value of the arg seconds to the clock's seconds
    //REQUIRES: second >= 0

private:
    int hour;
    int minute;
    int second;

    int hms_to_sec();
    //PROMISES: returns the total value of data members in a Clock object in seconds

    void sec_to_hms(int n);
    //PROMISES: sets the values for the Clock data members, second, minute, 
    //          and hour based on the arg n given in seconds
    //REQUIRES: n >= 0

    bool is_valid_hour(int hour);
    //PROMISES: return true if hour >= 0 && hour <=23, false otherwise

    bool is_valid_min_or_sec(int time);
    //PROMISES: return true if time >= 0 && time <= 59, false otherwise
};

#endif
// Raymond An
// CECS 282-07
// Prog 2 - myDate
// Due 3/4/2020


#ifndef myDate_hpp
#define myDate_hpp

#include <stdio.h>
#include <string>
using namespace std;

class myDate {
    
private:
    int month;
    int day;
    int year;
    string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    
public:
    myDate();
    myDate(int month, int day, int year);
    void display();
    void increaseDate(int numDays);
    void decreaseDate(int numDays);
    int daysBetween(myDate date);
    int getMonth();
    int getDay();
    int getYear();
    int dayOfYear();
    string dayName();
    static int Greg2Julian(int month, int day, int year);
    static void Julian2Greg(int JD, int &month, int&day, int &year);
    
};

#endif /* myDate_hpp */

// Raymond An
// CECS 282-07
// Prog 2 - myDate
// Due 3/4/2020


#include "myDate.hpp"
#include <iostream>

int myDate:: Greg2Julian(int month, int day, int year) {
    int I = year;
    int J = month;
    int K = day;
    
    int julianDate = K - 32075 + 1461 * (I + 4800 + (J - 14) / 12) / 4 + 367 * (J - 2 - (J - 14) / 12 * 12) / 12 - 3 * ((I + 4900 + (J - 14) / 12) / 100) / 4;
    
    return julianDate;
}

void myDate:: Julian2Greg(int JD, int &month, int &day, int &year) {
    int I;
    int J;
    int K;
    int L;
    int N;
    
    L = JD + 68569;
    N = 4 * L / 146097;
    L = L - (146097 * N + 3) / 4;
    I = 4000 * (L + 1) / 1461001;
    L = L - 1461 * I / 4 + 31;
    J = 80 * L / 2447;
    K = L - 2447 * J / 80;
    L = J / 11;
    J = J + 2 - 12 * L;
    I = 100 * (N-49) + I + L;
    
    month = J;
    day = K;
    year = I;
}

myDate:: myDate() {
    month = 5;
    day = 11;
    year = 1959;
}

myDate:: myDate(int month, int day, int year) {
    this->month = month;
    this->day = day;
    this->year = year;
    
    // changes month, day, year to Julian
    int julianDate = Greg2Julian(month, day, year);
    // pass that Julian date and change that to month, day, year
    Julian2Greg(julianDate, month, day, year);
    // and if everything is equal, then it's a valid date
        
    if (this->month != month || this->day != day || this->year != year) {
        this->month = 5;
        this->day = 11;
        this->year = 1959;
    }
}

void myDate:: display() {
    string stringMonth;
    stringMonth = months[month - 1];
        
    cout << "(" << stringMonth << " " << day << ", " << year << ")";
}

void myDate:: increaseDate(int numDays) {
    int julianDate = Greg2Julian(month, day, year);
    julianDate = julianDate + numDays;
    Julian2Greg(julianDate, month, day, year);
}

void myDate:: decreaseDate(int numDays) {
    int julianDate = Greg2Julian(month, day, year);
    julianDate = julianDate - numDays;
    Julian2Greg(julianDate, month, day, year);
}

int myDate:: daysBetween(myDate date) {
    int julianDate1 = Greg2Julian(month, day, year);
    int julianDate2 = Greg2Julian(date.month, date.day, date.year);
    return julianDate2 - julianDate1;
}

int myDate:: getMonth() {
    return month;
}

int myDate:: getDay() {
    return day;
}

int myDate:: getYear() {
    return year;
}

int myDate:: dayOfYear() {
    int julianDate1 = Greg2Julian(month, day, year);
    int julianDate2 = Greg2Julian(1, 1, year);
    return julianDate1 - julianDate2 + 1;
}

string myDate:: dayName() {
    int julianDate = Greg2Julian(month, day, year);
    int dayOfWeek = julianDate % 7;
    
    string names[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    
    return names[dayOfWeek];
}

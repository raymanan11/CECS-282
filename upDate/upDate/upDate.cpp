//
//  upDate.cpp
//  upDate
//
//  Created by Raymond An on 4/3/20.
//  Copyright © 2020 Raymond An. All rights reserved.
//

#include "upDate.hpp"
#include <iostream>
#include <string>

int upDate:: count = 0;

int upDate:: Greg2Julian(int month, int day, int year) {
    int I = year;
    int J = month;
    int K = day;
    
    int julianDate = K - 32075 + 1461 * (I + 4800 + (J - 14) / 12) / 4 + 367 * (J - 2 - (J - 14) / 12 * 12) / 12 - 3 * ((I + 4900 + (J - 14) / 12) / 100) / 4;
    
    return julianDate;
}

void upDate:: Julian2Greg(int JD, int &month, int &day, int &year) {
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

upDate:: upDate() {
    ptr = new int[3];
    ptr[0] = 5;
    ptr[1] = 11;
    ptr[2] = 1959;
    
    count++;
}

upDate:: upDate(int month, int day, int year) {
    ptr = new int[3];
    ptr[0] = month;
    ptr[1] = day;
    ptr[2] = year;
    
    int julianDate = Greg2Julian(month, day, year);
    Julian2Greg(julianDate, month, day, year);
    
    if(ptr[0] != month || ptr[1] != day || ptr[2] != year) {
        ptr[0] = 5;
        ptr[1] = 11;
        ptr[2] = 1959;
    }
    
    count++;
}

upDate:: upDate(int jd) {
    ptr = new int[3];
    
    int month;
    int day;
    int year;
    
    Julian2Greg(jd, month, day, year);
    
    ptr[0] = month;
    ptr[1] = day;
    ptr[2] = year;
    
    count++;
}

upDate:: upDate(const upDate &d) {
    ptr = new int[3];
    ptr[0] = d.ptr[0];
    ptr[1] = d.ptr[1];
    ptr[2] = d.ptr[2];
    
    count++;
}

void upDate:: setDate(int month, int day, int year) {
    ptr[0] = month;
    ptr[1] = day;
    ptr[2] = year;
    
    int julianDate = Greg2Julian(month, day, year);
    Julian2Greg(julianDate, month, day, year);
    
    if(ptr[0] != month || ptr[1] != day || ptr[2] != year) {
        ptr[0] = 5;
        ptr[1] = 11;
        ptr[2] = 1959;
    }
}

upDate:: ~upDate() {
    delete [] ptr;
    count--;
}

int upDate:: getMonth() {
    return ptr[0];
}

int upDate:: getDay() {
    return ptr[1];
}

int upDate:: getYear() {
    return ptr[2];
}

string upDate:: getMonthName() {
    return months[ptr[0] - 1];
}

void upDate:: display() {
    cout << getMonthName() << " " << ptr[1] << ", " << ptr[2];
}

upDate upDate:: operator=(upDate d) {
    ptr[0] = d.ptr[0];
    ptr[1] = d.ptr[1];
    ptr[2] = d.ptr[2];
    return *this;
}

upDate upDate:: operator+(int n) {
    int julianDate = Greg2Julian(ptr[0], ptr[1], ptr[2]);
    int resultJD = julianDate + n;
    
    int m1;
    int d1;
    int y1;
    
    Julian2Greg(resultJD, m1, d1, y1);
    
    upDate result(m1, d1, y1);
    return result;
}

upDate operator+(int n, upDate d) {
    int julianDate = d.Greg2Julian(d.ptr[0], d.ptr[1], d.ptr[2]);
    int resultJD = julianDate + n;
    upDate result;
    result.Julian2Greg(resultJD, result.ptr[0], result.ptr[1], result.ptr[2]);
    return result;
}

upDate upDate:: operator-(int n) {
    int julianDate = Greg2Julian(ptr[0], ptr[1], ptr[2]);
    int resultJD = julianDate - n;
    
    int m1 = 0;
    int d1 = 0;
    int y1 = 0;
    
    Julian2Greg(resultJD, m1, d1, y1);
    
    upDate result(m1, d1, y1);
    return result;
}

upDate upDate:: operator+=(int n) {
    int jd = Greg2Julian(ptr[0], ptr[1], ptr[2]);
    int resultJD = jd + n;
    Julian2Greg(resultJD, ptr[0], ptr[1], ptr[2]);
    return *this;
}

upDate upDate::operator-=(int n) {
    int jd = Greg2Julian(ptr[0], ptr[1], ptr[2]);
    int resultJD = jd - n;
    Julian2Greg(resultJD, ptr[0], ptr[1], ptr[2]);
    return *this;
}

// ++date;
upDate upDate:: operator++() {
    int jd = Greg2Julian(ptr[0], ptr[1], ptr[2]);
    jd++;
    Julian2Greg(jd, ptr[0], ptr[1], ptr[2]);
    return *this;
}

// date++;
upDate upDate:: operator++(int n) {
    upDate temp(*this);
    int jd = Greg2Julian(ptr[0], ptr[1], ptr[2]);
    jd++;
    Julian2Greg(jd, ptr[0], ptr[1], ptr[2]);
    return temp;
}

// --date;
upDate upDate:: operator--() {
    int jd = Greg2Julian(ptr[0], ptr[1], ptr[2]);
    jd--;
    Julian2Greg(jd, ptr[0], ptr[1], ptr[2]);
    return *this;
}

// date--;
upDate upDate:: operator--(int n) {
    upDate temp(*this);
    int jd = Greg2Julian(ptr[0], ptr[1], ptr[2]);
    jd--;
    Julian2Greg(jd, ptr[0], ptr[1], ptr[2]);
    return temp;
}

int upDate:: operator-(upDate d) {
    int jd1 = Greg2Julian(ptr[0], ptr[1], ptr[2]);
    int jd2 = Greg2Julian(d.ptr[0], d.ptr[1], d.ptr[2]);
    
    int result = jd1 - jd2;
    return result;
}

int upDate:: julian() {
    int jd = Greg2Julian(ptr[0], ptr[1], ptr[2]);
    return jd;
}

bool upDate:: operator==(upDate d) {
    bool equal;
    int jd1 = Greg2Julian(ptr[0], ptr[1], ptr[2]);
    int jd2 = d.Greg2Julian(d.ptr[0], d.ptr[1], d.ptr[2]);
    if(jd1 == jd2) {
        equal = true;
    }
    else {
        equal = false;
    }
    return equal;
}

bool upDate:: operator<(upDate d) {
    bool lessThan;
    int jd1 = Greg2Julian(ptr[0], ptr[1], ptr[2]);
    int jd2 = d.Greg2Julian(d.ptr[0], d.ptr[1], d.ptr[2]);
    if(jd1 < jd2) {
        lessThan = true;
    }
    else {
        lessThan = false;
    }
    return lessThan;
}

bool upDate:: operator>(upDate d) {
    bool greaterThan;
    int jd1 = Greg2Julian(ptr[0], ptr[1], ptr[2]);
    int jd2 = d.Greg2Julian(d.ptr[0], d.ptr[1], d.ptr[2]);
    if(jd1 > jd2) {
        greaterThan = true;
    }
    else {
        greaterThan = false;
    }
    return greaterThan;
}

string upDate:: toString() const {
    string result = to_string(ptr[0]) + "/" + to_string(ptr[1]) + "/" + to_string(ptr[2]);
    return result;
}

ostream& operator<<(ostream &str, const upDate &date) {
    return str << date.toString();
}

int upDate:: GetDateCount() {
    return count;
}





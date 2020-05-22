//
//  upDate.hpp
//  upDate
//
//  Created by Raymond An on 4/3/20.
//  Copyright © 2020 Raymond An. All rights reserved.
//

#ifndef upDate_hpp
#define upDate_hpp
#include <string>
#include <stdio.h>
using namespace std;

class upDate {
private:
    int *ptr;
    string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    static int count;
public:
    upDate();
    upDate(int m, int d, int y);
    upDate(int jd);
    upDate(const upDate &d);
    void setDate(int m, int d, int y);
    ~upDate();
    int getMonth();
    int getDay();
    int getYear();
    void display();
    string getMonthName();
    static int Greg2Julian(int month, int day, int year);
    static void Julian2Greg(int JD, int &month, int&day, int &year);
    string toString() const;
    
    // D3 = D2 + 5;
    upDate operator+(int n);
    // D3 = 5 + D2;
    friend upDate operator+(int n, upDate d);
    // D3 = D2 - 11;
    upDate operator-(int n);
    // D1 = D2;
    upDate operator=(upDate d);
    // D1 += 5;
    upDate operator+=(int n);
    // D1 -= 7;
    upDate operator-=(int n);
    // ++D1;
    upDate operator++();
    // D1++;
    upDate operator++(int n);
    // --D1;
    upDate operator--();
    // ++D1;
    upDate operator--(int n);
    // int x = D5 - D4;
    int operator-(upDate d);
    int julian();
    // if(D1 == D2)
    bool operator==(upDate d);
    // if(D1 < D2)
    bool operator<(upDate d);
    // if(D1 > D2)
    bool operator>(upDate d);
    friend ostream& operator<<(ostream &str, const upDate &date);
    static int GetDateCount();
};

#endif /* upDate_hpp */

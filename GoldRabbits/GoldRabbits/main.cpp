//
//  main.cpp
//  GoldRabbits
//
//  Created by Raymond An on 4/26/20.
//  Copyright © 2020 Raymond An. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <map>
#include <iterator>
using namespace std;

class BigInt {
    
private:
    vector<char> v;

public:

    BigInt(int x);
    BigInt(string s);
    BigInt();
    void addZeros(BigInt &bigInt);
    BigInt operator+(BigInt bigInt);
    BigInt operator+(int n);
    friend BigInt operator+(int n, BigInt bigInt);
    BigInt operator-(BigInt bigInt);
    BigInt operator-(int n);
    friend BigInt operator-(int n, BigInt bigInt);
    friend bool operator<(const BigInt& l, const BigInt& r);
    bool operator<=(int n);
    bool operator==(int n);
    bool operator==(BigInt bigInt);
    BigInt operator=(BigInt bigInt);
    BigInt operator++(int n);
    friend ostream& operator<<(ostream &str, const BigInt &bigInt);
    void print();
};

BigInt goldRabbits(BigInt bigInt);
void pause();

int main() {
    BigInt B1("123456789123456789123456789123456789");
    BigInt B2(B1);
    BigInt MAX(INT_MAX);
    cout << "B1: " << B1 << "\nB2: " << B2 << "\nMAX: " << MAX << endl;
    pause();
    cout << "\nB1:";
    B1.print();
    cout << endl;
    pause();

    for(BigInt i=0; i<=3000; i++) {
        cout << "\ngoldRabbits("<< i <<") = " << goldRabbits(i);
    }
    cout << endl;
    pause();
    cout<< "\nThis is the value of goldRabbits(3000)\n\n";
    BigInt gR3000 = goldRabbits(BigInt(3000));
    gR3000.print();
    cout << endl;
    pause();
}

void pause() {
    cout << "Press Enter to continue...";
    getchar();
}

BigInt goldRabbits(BigInt bigInt) {
    static map<BigInt,BigInt> fiboMap;
    map<BigInt,BigInt>:: iterator it;
    map<BigInt,BigInt>:: iterator it2;
    BigInt nMinus1;
    BigInt nMinus2;

    if(bigInt == 0 || bigInt == 1) {
        if(fiboMap.find(bigInt) == fiboMap.end()) {
            fiboMap[bigInt] = BigInt(1);
        }
        
        return fiboMap[bigInt];
    }
    else {
        it = fiboMap.find(bigInt - 1);
        if(it == fiboMap.end()) {
            nMinus1 = goldRabbits(bigInt - 1);
            fiboMap.insert({bigInt - 1, nMinus1});
        }
        else {
            nMinus1 = it->second;
        }
        
        it2 = fiboMap.find(bigInt - 2);
        if(it2 == fiboMap.end()) {
            nMinus2 = goldRabbits(bigInt - 2);
            fiboMap.insert({bigInt - 2, nMinus2});
        }
        else {
            nMinus2 = it2->second;
        }

        return nMinus1 + nMinus2;
    }
}

BigInt:: BigInt() {
    v.push_back(0);
}

BigInt:: BigInt(int x) {
    while(x > 9) {
        int digit = x % 10;
        v.push_back(digit);
        x /= 10;
    }
    v.push_back(x);
}

BigInt:: BigInt(string s) {
    for(int i = s.size() - 1; i >= 0; i--) {
        int singleNum = s[i] - '0';
        v.push_back(singleNum);
    }
}

bool operator<(const BigInt& l, const BigInt& r) {
    
    if(l.v.size() < r.v.size()) {
        return true;
    }
    if(l.v.size() > r.v.size()) {
        return false;
    }

    for(int i = 0; i < l.v.size(); i++) {
        if(l.v[l.v.size() - 1 - i] != r.v[l.v.size() - 1 - i]) {
            return l.v[l.v.size() - 1 - i] < r.v[l.v.size() - 1 - i];
        }
    }

    return false;
}

bool BigInt:: operator<=(int n) {
    BigInt num(n);
    BigInt temp(*this);
    
    if(temp.v.size() < num.v.size()) {
        return true;
    }
    if(temp.v.size() > num.v.size()) {
        return false;
    }
    
    for(int i = 0; i < temp.v.size(); i++) {
        if(temp.v[temp.v.size() - 1 - i] != num.v[temp.v.size() - 1 - i]) {
            return temp.v[temp.v.size() - 1 - i] < num.v[temp.v.size() - 1 - i];
        }
    }
    return true;
}

void BigInt:: addZeros(BigInt &bigInt) {
    if(v.size() - bigInt.v.size() != 0) {
        long numZeros = v.size() - bigInt.v.size();
        vector<char>:: iterator it;
        
        // if number of zeros is negative then that means the BigInt being
        // added has more numbers
        if(numZeros < 0) {
            for(int i = 0; i < abs(numZeros); i++) {
                it = v.end();
                it = v.insert(it, 0);
            }
        }
        else {
            for(int i = 0; i < numZeros; i++) {
                it = bigInt.v.end();
                it = bigInt.v.insert(it, 0);
            }
        }
    }
}

BigInt BigInt:: operator+(BigInt bigInt) {
    
    addZeros(bigInt);
    int carry = 0;
    for(int i = 0; i < v.size(); i++) {
        
        int total = (int)v[i] + (int)bigInt.v[i];
        //cout << total << endl;
        
        if(total > 9) {
            v[i] = total % 10;
            carry = total / 10;
            if(carry > 0 && i == v.size() - 1) {
                v.push_back(carry);
                break;
            }
            else {
                v[i+1] += carry;
            }
        }
        else {
            v[i] = total;
        }
    }
    return *this;
}

BigInt BigInt:: operator+(int n) {
    BigInt num(n);
    num = *this + num;
    return num;
}

BigInt operator+(int n, BigInt bigInt) {
    BigInt num(n);
    num = num + bigInt;
    return num;
}

BigInt BigInt:: operator-(BigInt bigInt) {
    BigInt temp = *this;
    
    addZeros(bigInt);

    for(int i = 0; i < temp.v.size(); i++) {
        // if above number is less than bottom number
        if((int)temp.v[i] < (int)bigInt.v[i]) {
            temp.v[i] = (int)temp.v[i] + 10;
            temp.v[i+1] = (int)temp.v[i+1] - 1;
            temp.v[i] = (int)temp.v[i] - (int)bigInt.v[i];
        }
        // goes here if above number is greater than below number and subtract
        else {
            temp.v[i] = (int)temp.v[i] - (int)bigInt.v[i];
        }

        // erases the leftover zero if both top and bottom are zero and the first position
        if(temp.v[i] == 0 && bigInt.v[i] == 0 && i == temp.v.size() - 1) {
            temp.v.erase(temp.v.end() - 1);
        }
    }
    return temp;
}

BigInt BigInt:: operator-(int n) {
    BigInt num(n);
    return *this - num;
}

BigInt operator-(int n, BigInt bigInt) {
    BigInt num(n);
    return num - bigInt;
}

bool BigInt:: operator==(int n) {
    BigInt temp(*this);
    BigInt num(n);
    if(temp.v.size() == num.v.size()) {
        for(int i = 0; i < temp.v.size(); i++) {
            if(temp.v[i] != num.v[i]) {
                return false;
                break;
            }
        }
    }
    else {
        return false;
    }
    return true;
}

bool BigInt:: operator==(BigInt bigInt) {
    BigInt temp(*this);
    if((temp - bigInt) == 0) {
        return true;
    }
    else {
        return false;
    }
}

BigInt BigInt:: operator=(BigInt bigInt) {
    v = bigInt.v;
    return *this;
}

BigInt BigInt:: operator++(int n) {
    *this + 1;
    return *this;
}

ostream& operator<<(ostream &str, const BigInt &bigInt) {
    string s = "";
    for(int i = 0; i < bigInt.v.size(); i++) {
        s += to_string(bigInt.v[bigInt.v.size() - 1 - i]);
    }
    if(s.size() <= 12) {
        return str << s;
    }
    else {
        string scientificNot = "";
        scientificNot += to_string(s[0] - '0') + ".";
        for(int i = 0; i < 10; i++) {
            scientificNot += to_string(s[i+1] - '0');
        }
        scientificNot += "e" + to_string(s.size() - 1);
        return str << scientificNot;
    }
    return str << s;

}

void BigInt:: print() {
    vector<char>:: reverse_iterator rit;
    for(rit = v.rbegin(); rit != v.rend(); rit++) {
        cout << (int)*rit;
    }
}

//vector<char> BigInt:: getV() {
//    return v;
//}

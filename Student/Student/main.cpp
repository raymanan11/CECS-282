// CECS 282
// Raymond An
// Prog 3: Structs and Pointers
// Due Date: 3/25/2020

#include <iostream>
#include "myDate.hpp"
#include <string.h>
#include <iomanip>
using namespace std;

struct Student {
    int SID;
    char grade;
    myDate bday;
    string homeTown;
    char name[20];
};

void displayMenu();
myDate randomBDay();
void populate(Student *s[]);
void populateID(Student *s[]);
void display(Student *s[]);
void sortByName(Student *s[]);
void sortByID(Student *s[]);
void sortByGrade(Student *s[]);
void sortByBday(Student *s[]);
void sortByHometown(Student *s[]);

int main() {
    Student *s1[10];
    // fill up the array with names, ID, bdays, grades, hometowns
    populate(s1);
    populateID(s1);
    // then display it
    display(s1);
    
    cout << endl << "************** WELCOME! **************" << endl;
    //displayMenu();
    int choice = 0;
    while(choice != 6) {
        cout << endl;
        displayMenu();
        cout << endl << "Please enter your choice: ";
        cin >> choice;
        
        if(choice == 1) {
            sortByName(s1);
            display(s1);
        }
        else if (choice == 2) {
            sortByID(s1);
            display(s1);
        }
        else if(choice == 3) {
            sortByBday(s1);
            display(s1);
        }
        else if(choice == 4) {
            sortByGrade(s1);
            display(s1);
        }
        else if(choice == 5) {
            sortByHometown(s1);
            display(s1);
            }
        else {
            break;
        }
    }
    return 0;
}

void displayMenu() {
    cout << "1.) Display list sorted by Name" << endl;
    cout << "2.) Display list sorted by Student ID" << endl;
    cout << "3.) Display list sorted by Birthday" << endl;
    cout << "4.) Display list sorted by Grade" << endl;
    cout << "5.) Display list sorted by Hometown" << endl;
    cout << "6.) Exit" << endl;
}

myDate randomBDay() {
    int month = 1;
    int day = 1;
    int year = 1999;
    int month2 = 12;
    int day2 = 31;
    int year2 = 2004;

    myDate date(month, day, year);
    int leastDate = date.Greg2Julian(date.getMonth(), date.getDay(), date.getYear());
    myDate date2(month2, day2, year2);
    int greatestDate = date2.Greg2Julian(date2.getMonth(), date2.getDay(), date2.getYear());
    
    int numDays = greatestDate - leastDate;
    int randomDays = rand() % numDays;
    date.increaseDate(randomDays);
    return date;
}

void populate(Student *s[]) {
    char grades[10] = {'A', 'B', 'C', 'D', 'F', 'A', 'B', 'C', 'D', 'F'};
    string ht[10] = {"Small", "Oatmeal", "Xianmen", "Booger Hole", "Mosquitoville",
        "Ding Dong", "Paw Paw", "Normal", "Coupon", "Zagazig"};
    srand(time(0));
    
    for(int i = 0; i < 10; i++) {
        s[i] = new Student;
        s[i]->grade = grades[i];
        s[i]->homeTown = ht[i];
        s[i]->bday = randomBDay();
    }
    // copies string into null terminated character arrays
    strcpy(s[0]->name, "Raymond");
    strcpy(s[1]->name, "Kesha");
    strcpy(s[2]->name, "Madonna");
    strcpy(s[3]->name, "Eminem");
    strcpy(s[4]->name, "Pink");
    strcpy(s[5]->name, "Teller");
    strcpy(s[6]->name, "Prince");
    strcpy(s[7]->name, "Nelly");
    strcpy(s[8]->name, "Shakira");
    strcpy(s[9]->name, "Rihanna");
}

void populateID(Student *s[]) {
    srand(time(0));
    
    for(int i = 0; i < 10; i++) {
        int studentID = 1000;
        // random student ID from 1000 to 9999
        studentID = studentID + (rand() % 9000);
        s[i]->SID = studentID;
    }
}

void display(Student *s[]) {
    cout << setw(10) << left << "Name"
         << setw(15) << left << "Student ID"
         << setw(20) << left << "Birthday"
         << setw(15) << left << "Grade"
         << setw(5) << left << "Hometown"
         << endl << endl;

    for(int i = 0; i < 10; i++) {
        cout << setw(10) << left << s[i]->name
             << setw(15) << left << s[i]->SID
             << setw(20) << left << s[i]->bday.toString()
             << setw(15) << left << s[i]->grade
             << setw(5) << left << s[i]->homeTown
             << endl;
    }
}

void sortByName(Student *s[]) {
    cout << endl;
    for(int sorted = 0; sorted < 9; sorted++) {
        for (int i = 0; i < 10 - sorted - 1; i++) {
            // if num is > 0 then s[i]->name is bigger than s[i+1]->name
            // if num is < 0 then s[i]->name is smaller than s[i+1]->name
            // if num = 0 then strings are equal
            int num = strcmp(s[i]->name, s[i+1]->name);
            if(num > 0) {
                swap(s[i], s[i+1]);
            }
        }
    }
}

void sortByID(Student *s[]) {
    cout << endl;
    for(int sorted = 0; sorted < 9; sorted++) {
        for (int i = 0; i < 10 - sorted - 1; i++) {
            if(s[i]->SID > s[i+1]->SID) {
                swap(s[i], s[i+1]);
            }
        }
    }
}

void sortByGrade(Student *s[]) {
    cout << endl;
    for(int sorted = 0; sorted < 9; sorted++) {
        for (int i = 0; i < 10 - sorted - 1; i++) {
            if(s[i]->grade > s[i+1]->grade) {
                //swap(s[i]->grade, s[i+1]->grade);
                swap(s[i], s[i+1]);
            }
        }
    }
}

void sortByBday(Student *s[]) {
    cout << endl;
    for(int sorted = 0; sorted < 9; sorted++) {
        for (int i = 0; i < 10 - sorted - 1; i++) {
            // convert to julian dates to see which date is bigger
            int jd1 = s[i]->bday.Greg2Julian(s[i]->bday.getMonth(), s[i]->bday.getDay(), s[i]->bday.getYear());
            int jd2 = s[i+1]->bday.Greg2Julian(s[i+1]->bday.getMonth(), s[i+1]->bday.getDay(), s[i+1]->bday.getYear());
            // if s[i] > s[i+1] then swap bdays
            if(jd1 > jd2) {
                swap(s[i], s[i+1]);
            }
        }
    }
}

void sortByHometown(Student *s[]) {
    cout << endl;
    for(int sorted = 0; sorted < 9; sorted++) {
        for (int i = 0; i < 10 - sorted - 1; i++) {
            if(s[i]->homeTown > s[i+1]->homeTown) {
                swap(s[i], s[i+1]);
            }
        }
    }
}

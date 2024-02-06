#include "Roster.h"
#include <iostream>
using namespace std;

void Roster::parse(string studentData)
{
    int rhs = studentData.find(",");
    string sID = studentData.substr(0, rhs);

    int lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string fName = studentData.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string lName = studentData.substr(lhs, rhs - lhs);


    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string mail = studentData.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int years = stoi(studentData.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int day1 = stoi(studentData.substr(lhs, rhs - lhs));
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int day2 = stoi(studentData.substr(lhs, rhs - lhs));
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int day3 = stoi(studentData.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string strProgram = (studentData.substr(lhs, rhs - lhs));

    DegreeProgram degreeProgram;

    if (strProgram == "SECURITY") {
        degreeProgram = SECURITY;
    }
    else if (strProgram == "NETWORK") {
        degreeProgram = NETWORK;
    }
    else if (strProgram == "SOFTWARE") {
        degreeProgram = SOFTWARE;
    }
    else {
        cout << "Error: Invalid degree program." << endl;
    }

    add(sID, fName, lName, mail, years, day1, day2, day3, degreeProgram);
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1,
    int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)
{
    int days[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };

    classRosterArray[++lastStudent] = new Student(studentID, firstName, lastName, emailAddress, age, days, degreeprogram);

}

void Roster::remove(string studentID) {
    bool found = false;
    for (int i = 0; i <= lastStudent; i++) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            found = true;
            delete classRosterArray[i];
            for (int j = i; j < lastStudent; j++) {
                classRosterArray[j] = classRosterArray[j + 1];
            }
            classRosterArray[lastStudent] = NULL;
            lastStudent--;
            cout << "Student with ID " << studentID << " was removed." << endl;
            break;
        }
    }
    if (!found) {
        cout << "Student with ID " << studentID << " not found." << endl;
    }
}

void Roster::printAll() {
    for (int i = 0; i <= Roster::lastStudent; i++) {
        classRosterArray[i]->print();
    }
}

void Roster::printAverageDaysInCourse(string studentID) {
    for (int i = 0; i <= Roster::lastStudent; i++) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            int* days = classRosterArray[i]->getDaysToCompleteCourse();
            cout << studentID << ":";
            cout << ((days[0] + days[1] + days[2]) / 3.0) << endl;
            return;
        }
    }
    cout << "Student ID not found." << endl;
}

void Roster::printInvalidEmails() {
    bool invalidEmail = false;

    for (int i = 0; i <= Roster::lastStudent; i++) {
        string email = classRosterArray[i]->getEmail();
        if (email.find('@') == string::npos || email.find('.') == string::npos || email.find(' ') != string::npos) {
            invalidEmail = true;
            cout << email << " is an invalid email address belonging to student: " << classRosterArray[i]->getStudentID() << endl;
        }
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    for (int i = 0; i <= Roster::lastStudent; i++) {
        if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
    cout << endl;
}

Roster::~Roster() {
    for (int i = 0; i <= lastStudent; i++) {
        if (classRosterArray[i] != NULL) {
            delete classRosterArray[i];
            classRosterArray[i] = NULL;
        }
    }
}
#include "Degree.h"
#include "Student.h"
#include <iostream>
#include <string>
using namespace std;


Student::Student(string studentID, string firstName, string lastName, string Email, int age, int daystoCompleteCourse[], DegreeProgram degreeProgram)
{
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->Email = Email;
    this->age = age;
    for (int i = 0; i < sizeofdaystoCompleteCourse; i++)
    {
        this->daystoCompleteCourse[i] = daystoCompleteCourse[i];
    }
    this->degreeProgram = degreeProgram;
}

string Student::getStudentID() {
    return studentID;
}
string Student::getFirstName() {
    return firstName;
}
string Student::getLastName() {
    return lastName;
}
string Student::getEmail() {
    return Email;
}
int Student::getAge() {
    return age;
}
int* Student::getDaysToCompleteCourse() {
    return daystoCompleteCourse;
}
DegreeProgram Student::getDegreeProgram() {
    return this->degreeProgram;
}

void Student::setStudentID(string studentID) {
    this->studentID = studentID;
}

void Student::setFirstName(string firstName) {
    this->firstName = firstName;
}

void Student::setLastName(string lastName) {
    this->lastName = lastName;
}

void Student::setEmail(string Email) {
    this->Email = Email;
}

void Student::setAge(int age) {
    this->age = age;
}

void Student::setDaysToCompleteCourse(int daystoCompleteCourse[]) {
    for (int i = 0; i < sizeofdaystoCompleteCourse; i++) {
        this->daystoCompleteCourse[i] = daystoCompleteCourse[i];
    }
}

void Student::setDegree(DegreeProgram degreeProgram) {
    this->degreeProgram = degreeProgram;
}

void Student::print() {
    cout << studentID << "\t";
    cout << "First Name: " << firstName << "\t";
    cout << "Last Name: " << lastName << "\t";
    cout << "Age: " << age << "\t";
    cout << "daysInCourse: {";
    for (int i = 0; i < sizeofdaystoCompleteCourse; i++) {
        cout << daystoCompleteCourse[i];
        if (i < sizeofdaystoCompleteCourse - 1) {
            cout << ", ";
        }
    }
    cout << "}" << "\t";
    cout << "\t Degree Program: " << DegreePrograms[degreeProgram] << endl;
}


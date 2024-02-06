#ifndef ROSTER_H
#define ROSTER_H

#include "Student.h"

class Roster {
public:
    void parse(string studentData);
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1,
        int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
    ~Roster();

private:
    int lastStudent = -1;
    const static int numStudents = 5;
    Student* classRosterArray[numStudents];
};

#endif

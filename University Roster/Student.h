#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include "Degree.h"
#include <string>
using namespace std;

class Student
{
public:
	Student(string studentID, string firstName, string lastName, string Email,
		int age, int daystoCompleteCourse[], DegreeProgram degreeprogram);
	const static int sizeofdaystoCompleteCourse = 3;

	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int* getDaysToCompleteCourse();
	DegreeProgram getDegreeProgram();

	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string Email);
	void setAge(int age);
	void setDaysToCompleteCourse(int daystoCompleteCourse[]);
	void setDegree(DegreeProgram degreeProgram);

	void print();

private:
	string studentID;
	string firstName;
	string lastName;
	string Email;
	int age;
	int daystoCompleteCourse[sizeofdaystoCompleteCourse];
	DegreeProgram degreeProgram;
};

#endif

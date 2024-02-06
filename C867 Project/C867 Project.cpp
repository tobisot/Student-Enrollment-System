#include "Roster.h"
#include <iostream>
#include <string>
using namespace std; 

int main(){
    cout << "Course Title: C867 - Scripting and Programming Applications" << endl;
    cout << "Programming Language Used: C++" << endl;
    cout << "WGU Student ID: 011316222" << endl;
    cout << "Name: Tobi Sotannde" << endl;
    cout << endl;
    Roster classRoster;
    
     const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Tobi,Sotannde,tobi.sotannde@gmail.com,28,7,30,14,SOFTWARE"
    };
    const int numStudents = 5;
    

    
    for (int i = 0; i < numStudents; i++) {
        classRoster.parse(studentData[i]);
    }
    cout << "All students:" << endl;
    classRoster.printAll();
    
    cout << "Invalid email addresses:" << endl;
    classRoster.printInvalidEmails();
    
    cout << "Average days in course for each student:" << endl;
    for (int i = 0; i < numStudents; i++) {
    classRoster.printAverageDaysInCourse("A" + to_string(i + 1)); // Assuming IDs are A1, A2, ...
}
    
    cout << "Printing by SOFTWARE degree program:" << endl;
    classRoster.printByDegreeProgram(SOFTWARE);
    
    classRoster.remove("A3");
    
    classRoster.printAll();
    
    classRoster.remove("A3");
    
}
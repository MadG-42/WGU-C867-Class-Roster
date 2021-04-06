/* 
Madison Gish   000745675
C867 - Scripting and Programming Applications
03/31/2021
*/ 
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "Roster.h"

using namespace std;

int main() {
	const int ROSTER_SIZE = 5;
// adding the students information as well as adding my own information into A5
	const string studentData[5] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Madison,Gish,mgish2@wgu.edu,23,57,43,38,SOFTWARE"}; 

	DegreeProgram degreeProgram;
	
//Printing my WGU infortmation 
	cout << "C867- Scripting and Programming" << endl;
	cout << "Language Used: C++" << endl;
	cout << "Student ID#  000745675 " << endl;
	cout << "Name: Madison Gish" << endl << endl;


	Roster classRoster;

	string studentID;

//Adding Students onto the Roster
	for (int i = 0; i < sizeof(studentData) / sizeof(studentData[i]); i++){
		string input = studentData[i];
		istringstream ss(input);
		string token;
		string rAddDat[9];
	
		int j = 0;
		while (getline(ss, token, ',')) {
			rAddDat[j] = token;
			j += 1;
		}
	
		if (rAddDat[8] == "SECURITY") {
			degreeProgram = SECURITY;
		}
		else if (rAddDat[8] == "NETWORK") {
			degreeProgram = NETWORK;
		}
		else if (rAddDat[8] == "SOFTWARE") {
			degreeProgram = SOFTWARE;
		}
		classRoster.add(rAddDat[0],
			rAddDat[1],
			rAddDat[2],
			rAddDat[3],
			std::stoi(rAddDat[4]),
			std::stoi(rAddDat[5]),
			std::stoi(rAddDat[6]),
			std::stoi(rAddDat[7]),
			degreeProgram);
	}
	cout << endl << endl;

// Printing the Roster
	cout << endl << "Here is the complete Roster:" << endl;
	classRoster.printAll();

//Printing the invalid email addresses
	cout << endl << "Here are the invalid email addresses:" << endl;
	classRoster.printInvalidEmails();

//Printing the average days in a course for each student
	cout << endl << "Here is the average amount of days in a course for each student:" << endl;
	for (int i = 0; i < ROSTER_SIZE; i++) {
		classRoster.printAverageDaysInCourse(classRoster.getSID(i));
	}
	
//Printing the List of Students off the Roster who are in the SOFTWARE degree Program
	cout << endl << "Here are the students in SOFTWARE" << endl;
	classRoster.printByDegreeProgram(SOFTWARE);

//Removing A3 for the Roster
	cout << endl << "Let's remove A3 from the Roster" << endl;
	classRoster.remove("A3");
	
//Printing the Roster
	cout << endl << "Re-printing the Roster" << endl;
	classRoster.printAll();
	
//Attempting the remove A3 from the Roster, there should be an error as we cannot remove them again
	cout << endl << "Let's remove A3 from the Roster" << endl;
	classRoster.remove("A3");
}
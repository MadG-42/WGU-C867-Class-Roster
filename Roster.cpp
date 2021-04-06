#include <iostream>
#include <string>

#include "Roster.h"

using namespace std;

Roster::Roster()
{
}

Roster::~Roster()
{
// delete the students in the Roster
	int i = 0;
	for (i = 0; i < ROSTER_SIZE; i++) {
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}

void Roster::add(string studentID,
	string firstName,
	string lastName,
	string emailAddress,
	int age,
	int daysInCourse1,
	int daysInCourse2,
	int daysInCourse3,
	DegreeProgram degreeprogram)
{

	int courseDays[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };

	for (int i = 0; i < ROSTER_SIZE; i++) {
		if (classRosterArray[i] == nullptr) {
			classRosterArray[i] = new Student(studentID,
				firstName,
				lastName,
				emailAddress,
				age,
				courseDays,
				degreeprogram);
			break;
		}
	}

}
// Removing students from the Roster by Student ID, unless the student is not found, then sends a message
void Roster::remove(string studentID)
{
	bool j = false;
	for ( int i = 0; i < ROSTER_SIZE; i++) {
		if (classRosterArray[i] == nullptr) {
		}
		else {
			if (classRosterArray[i]->getStudentID() == studentID) {
				delete classRosterArray[i];
				classRosterArray[i] = nullptr;
				j = true;
			}
		}
	}
	if (j == false) {
		cout << "Student with ID: " << studentID << " was not found." << endl;
	}
}
//Printing the entire current Roster of students 
void Roster::printAll()
{
	for (int i = 0; i < ROSTER_SIZE; i++) {
		if (classRosterArray[i] == nullptr) {
		}
		else{
			classRosterArray[i]->print();
		}
	}
}
//Printing the average number of days in a course for each student ID
void Roster::printAverageDaysInCourse(string studentID)
{

	int studentIDNum;

	for (int i = 0; i < ROSTER_SIZE; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			studentIDNum = i;
		}
	}
	cout << "Student " << classRosterArray[studentIDNum]->getStudentID() << " "
		<< "  averaged "
		<< classRosterArray[studentIDNum]->getAverageDaysInCourses()
		<< " day(s) to complete a course." << endl;
}
//Printing Invalid Emails Addresses
void Roster::printInvalidEmails()
{
	int i = 0;
	for (i = 0; i < ROSTER_SIZE; i++) {
		if (classRosterArray[i]->validateEmailAddress() == 1) {
			cout << classRosterArray[i]->getEmailAddress() << endl;
		}
	}
}
//Printing the Students information by degree progrom
void Roster::printByDegreeProgram(DegreeProgram byDegreeProgram)
{
	int i = 0;
	for (i = 0; i < ROSTER_SIZE; i++) {
		if (classRosterArray[i]->getDegreeProgram() == byDegreeProgram) {
			classRosterArray[i]->print();
		}
	}
}
void Roster::printByDegreeProgram()
{
	for (int i = 0; i < ROSTER_SIZE; i++) {
		for (int j = 0; j < ROSTER_SIZE; j++) {
			if (classRosterArray[i]->getDegreeProgram() == NETWORK) {
				classRosterArray[i]->print();
			}
		}
		for (int j = 0; j < ROSTER_SIZE; j++) {
			if (classRosterArray[i]->getDegreeProgram() == SECURITY) {
				classRosterArray[i]->print();
			}
		}
		for (int j = 0; j < ROSTER_SIZE; j++) {
			if (classRosterArray[i]->getDegreeProgram() == SOFTWARE) {
				classRosterArray[i]->print();
			}
		}
		for (int j = 0; j < ROSTER_SIZE; j++) {
			if (classRosterArray[i]->getDegreeProgram() == UNDECLARED) {
				classRosterArray[i]->print();
			}
		}
	}
}
//Getting the student ID number 
string Roster::getSID(int studentNo)
{
	return classRosterArray[studentNo]->getStudentID(); 
}
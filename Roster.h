#pragma once
#include "Student.h"

using namespace std;

class Roster
{
public: 
	Roster();
	~Roster();
	void add(string studentID,
		string firstName,
		string lastName,
		string emailAddress,
		int age,
		int daysInCourse1,
		int daysInCourse2,
		int daysInCourse3,
		DegreeProgram degreeprogram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram);
	void printByDegreeProgram();
	string getSID(int studentNo);

private:
	const int MAX_COURSES = 3;
	const int ROSTER_SIZE = 5;
	Student* classRosterArray[5] = { nullptr,
	                                nullptr,
	                                nullptr,
	                                nullptr,
	                                nullptr };
};
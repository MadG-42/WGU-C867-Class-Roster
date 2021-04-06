#include <iostream>
#include <string>

#include "Student.h"

using namespace std;


Student::Student(string XstudentID, 
                string XfirstName,
                string XlastName,
                string XemailAddress,
                int Newage,
	            int XdaysInCourse[3], 
	            DegreeProgram XdegreeProgram)
{
	studentID = XstudentID;
	firstName = XfirstName;
	lastName = XlastName;
	emailAddress = XemailAddress;
	age = Newage;
	for (int i = 0; i < 3; i++) {
		daysInCourse[i] = XdaysInCourse[i];
	}
	degreeProgram = XdegreeProgram;
}

Student::~Student()
{
}
// Student ID 
string Student::getStudentID()
{
	return studentID;
}

void Student::setStudentID(string newStudentID)
{
	studentID = newStudentID;
}


//First Name 
string Student::getFirstName()
{
	return firstName;
}

void Student::setFirstName(string newFirstName)
{
	firstName = newFirstName;
}

//Last Name 
string Student::getLastName()
{
	return lastName;
}

void Student::setLastName(string newLastName)
{
	lastName = newLastName;
}

//Email Addresses 
string Student::getEmailAddress()
{
	return emailAddress;
}

void Student::setEmailAddress(string newEmailAddress)
{
	emailAddress = newEmailAddress;
}

//Making sure email address if valid 
int Student::validateEmailAddress()
{

	if (emailAddress.find("@") == string::npos) { 
		return 1;
	}
	if (emailAddress.find(".") == string::npos) { 
		return 1;
	}
	if (emailAddress.find(" ") != string::npos) {
		return 1;
	}
	return 0;
}

//Age 
int Student::getAge()
{
	return age;
}

void Student::setAge(int newAge)
{
	age = newAge;
}

//Days in Couse 
int* Student::getDaysInCourse()
{
	return daysInCourse;
}

void Student::setDaysInCourse(int* XdaysInCourse)
{
	//daysInCourse = daysInCourse;
	for (int i = 0; i < 3; i++) {
		daysInCourse[i] = XdaysInCourse[i];
	}

}

void Student::setDaysInCourse(int index, int days)
{
	daysInCourse[index] = days;
}

//Degree Program
DegreeProgram Student::getDegreeProgram()
{
	return degreeProgram;
}

string Student::getDegreeProgram(string str)
{
	if (degreeProgram == SECURITY) {
		return "SECURITY";
	}
	else if (degreeProgram == NETWORK) {
		return "NETWORK";
	}
	else if (degreeProgram == SOFTWARE) {
		return "SOFTWARE";
	}
}

void Student::setDegreeProgram(DegreeProgram newDegreeProgram)
{
	degreeProgram = newDegreeProgram;
}

//Printing the Roster Information with tabs
void Student::print() 
{
	int i = 0;
	string dg = "UNDECIDED";

	cout << studentID << "\t" <<
		"First Name: " << firstName << "\t" <<
		"Last Name: " << lastName << "\t" <<
		"Age: " << age << "\t" <<
		"daysInCourse: {" << "\t";
	cout << daysInCourse[i];
	for (int i = 1; i < MAX_COURSES; i++) {
		cout << ", " << daysInCourse[i];
	}
	cout << "}\t Degree Program: " << getDegreeProgram(dg) << "." << endl;
}
//Calculating the average days in courses by student ID 
float Student::getAverageDaysInCourses()
{
	int i = 0;
	int sum = 0;
	for (i = 0; i < MAX_COURSES; i++) {
		sum = sum + daysInCourse[i];
	}
	return static_cast<float>(sum) / static_cast<float>(MAX_COURSES);
}
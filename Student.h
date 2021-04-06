#pragma once
#include "Degree.h"

using namespace std;

class Student
{
public:
	Student(string studentID,
	        string firstName,
	        string lastName, 
	        string emailAddress, 
	        int age, 
	        int* courseDays,
	        DegreeProgram degreeProgram);
	        
	~Student();
//Student ID 
	string getStudentID();
	void setStudentID(string newStudentID);
// First Name 
	string getFirstName();
	void setFirstName(string newFirstName);
//Last Name 
	string getLastName();
	void setLastName(string newLastName);
//Email Address
	string getEmailAddress();
	void setEmailAddress(string newEmailAddress);

	int validateEmailAddress();
//Age
	int getAge();
	void setAge(int newAge);
//Days in Course 
	int* getDaysInCourse();
	void setDaysInCourse(int* daysInCourseVal);
	void setDaysInCourse(int index, int days);
//Degree Program`
	DegreeProgram getDegreeProgram();
	string getDegreeProgram(string str);
	void setDegreeProgram(DegreeProgram newDegProg);


	void print();
	float getAverageDaysInCourses();


private:
	const int MAX_COURSES = 3;
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysInCourse[3] = { 210, 210, 210 };
	DegreeProgram degreeProgram;
};
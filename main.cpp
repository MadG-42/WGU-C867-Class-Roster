//Madison Gish
//ID: 000745675
//C897 Scripting and Programming II 
//Date: 03/29/2021
#include<iostream>
#include<stdio.h>
#include<string>
//reading in from seperate files 
#include "student.h"
#include "roster.h"
using namespace std;

// Inputting the student information from the table provided
// 		and adding my personal details 
const string studentData[] =
{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
"A5,Madison,Gish,mgish2@wgu.edu,23,53,34,48,SOFTWARE"};

int main()
{
	cout << "Course Title: C867 - Scripting and Programming Applications " << endl;
	cout << "Programming Language Used: C++ " << endl;
	cout << "Student ID: 000745675 " << endl;
	cout << "Name: Madison Gish " << endl << endl;
	roster classRoster;
	string data[9];
	string s = "";
	int in = 0;
	cout << "Adding Students" << endl;

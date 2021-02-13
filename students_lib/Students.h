#pragma once
#include <iostream>
using namespace std;

struct Date
{
	int day;
	int month;
	int year;

	friend  ostream& operator << (ostream& ostr, const Date& D);
};

class Student
{
private:
	string first_name;
	string last_name;
	Date date_of_birth;
	int course;

public:
	Student(string _first_name, string _last_name, 
		Date date, int _course = 1);
	~Student();

	void NextCourse();
	void ChangeLastName(const string new_last_name);

	int GetCourse();
	string GetName();

	friend ostream& operator << (ostream& ostr, const Student& S);
};

inline ostream& operator<<(ostream& ostr, const Date& D)
{
	ostr << (D.day < 10 ? "0" : "") << D.day << "." <<
		(D.month < 10 ? "0" : "") << D.month << "." << D.year;
	return ostr;
}

inline ostream& operator<<(ostream& ostr, const Student& S)
{
	ostr << "Student: " << S.first_name << " " << S.last_name <<
		"\n" << S.date_of_birth << "\n" << "Course " << S.course;
	return ostr;
}

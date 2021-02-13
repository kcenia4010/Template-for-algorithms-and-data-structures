#include "Students.h"

Student::Student(string _first_name, string _last_name, 
	Date date, int _course) : first_name(_first_name), last_name(_last_name), course(_course)
{
	date_of_birth.day = date.day;
	date_of_birth.month = date.month;
	date_of_birth.year = date.year;
}

Student::~Student()
{
}

void Student::NextCourse()
{
	++course;
}

void Student::ChangeLastName(const string new_last_name)
{
	last_name = new_last_name;
}

int Student::GetCourse()
{
	return course;
}

string Student::GetName()
{
	return first_name + " " + last_name;
}

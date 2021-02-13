#include <iostream>
#include <Students.h>

int main()
{
	Date date1;
	date1.day = 18;
	date1.month = 6;
	date1.year = 2001;

	Student S("Ksenia", "Zaytseva", date1);

	cout << S << endl << endl;
	S.NextCourse();
	cout << "Next year\n" << S;
	return 0;
}

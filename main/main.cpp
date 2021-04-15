#include <iostream>
#include <text.h>
#include <conio.h>

int main()
{
	Text T;	
	while (1)
	{
		char ch = getch();
		int code = static_cast<int>(ch);
		if (ch == 27) // клавиша esc
			exit(0);
		if (ch == 's') // стрелка S
			T.next();
		if (ch == 'w') // стрелка W
			T.top();
		if (ch == 'd') // стрелка D
			T.down();
		if (ch == 32) // пробел
		{
			system("cls");
			string str;
			cout << "Name of new header: ";
			cin >> str;
			T.addDown(str);
		}
		if (ch == 'n') // буква N
		{
			system("cls");
			string str;
			cout << "Name of new header: ";
			cin >> str;
			T.addNext(str);
		}
		if (ch == 'q') // буква Q
			T.deleteCurr();
		if (ch == 'c') // буква C
		{
			system("cls");
			string str;
			cout << "Name of new header: ";
			cin >> str;
			T.SetCurr(str);
		}

		system("cls");
		T.print();
		//print(T.GetHeadNode(), T.GetCurrNode());
	}
	return 0;
}

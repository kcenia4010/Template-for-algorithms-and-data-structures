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
		if (ch == 27) // ������� esc
			exit(0);
		if (ch == 's') // ������� S
			T.next();
		if (ch == 'w') // ������� W
			T.top();
		if (ch == 'd') // ������� D
			T.down();
		if (ch == 32) // ������
		{
			system("cls");
			string str;
			cout << "Name of new header: ";
			cin >> str;
			T.addDown(str);
		}
		if (ch == 'n') // ����� N
		{
			system("cls");
			string str;
			cout << "Name of new header: ";
			cin >> str;
			T.addNext(str);
		}
		if (ch == 'q') // ����� Q
			T.deleteCurr();
		if (ch == 'c') // ����� C
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

#include <iostream>
#include <Convertor.h>
#include <string>
using namespace std;
int main()
{
	Convertor C;
	string str("MMXXI Hello III world IV CCXLII");
	int pos;
	roman num;
	arabic new_num;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == 'I' || str[i] == 'V' || str[i] == 'X' ||
			str[i] == 'L' || str[i] == 'C' || str[i] == 'D' ||
			str[i] == 'M')
		{
			pos = str.find(" ", i);
			num.value = "";
			num.value.insert(0, str, i, pos - i);
			if (C.check(num))
			{
				new_num = C.toArabic(num);
				str.erase(i, pos - i);
				str.insert(i, to_string(new_num.value));
				i += to_string(new_num.value).size();
			}
		}
	}
	cout << str;
	return 0;
}

#include "Convertor.h"
#include "vector"
#include <string>
#include <map>
using namespace std;


arabic Convertor::toArabic(roman t)
{
	arabic result;
	result.value = 0;
	map<char, int> M;
	M['I'] = 1; M['V'] = 5; M['X'] = 10;
	M['L'] = 50; M['C'] = 100; M['D'] = 500;
	M['M'] = 1000;

	for (int i = 0; i < t.value.size() - 1; i++)
	{
		if ((t.value[i] == 'I' || t.value[i] == 'X' || t.value[i] == 'C') &&
			(M[t.value[i + 1]] > M[t.value[i]]))
			result.value -= M[t.value[i]];
		else
			result.value += M[t.value[i]];
	}
	result.value += M[t.value.back()];
	return result;
}

roman Convertor::toRoman(arabic t)
{
	vector<string> v;
	string s = to_string(t.value);
	for (int i = 0; i < s.length(); i++)
	{
		string one, half, next;
		int num = t.value % 10;
		t.value = floor(t.value / 10);
		if (i == 0)
		{
			one = 'I'; half = 'V'; next = 'X';
		}
		else if (i == 1)
		{
			one = 'X'; half = 'L'; next = 'C';
		}
		else if (i == 2)
		{
			one = 'C'; half = 'D'; next = 'M';
		}
		else if (i == 3)
		{
			one = 'M';
		}
		switch(num)
		{	
		case 9:
			v.push_back(next);
			v.push_back(one);
			break;
		case 8:
			v.push_back(one);
		case 7:
			v.push_back(one);
		case 6:
			v.push_back(one);
		case 5:
			v.push_back(half);
			break;
		case 4:
			v.push_back(half);
			v.push_back(one);
			break;
		case 3:
			v.push_back(one);
		case 2:
			v.push_back(one);
		case 1:
			v.push_back(one);
		default:
			break;
		}
	}
	roman result;
	result.value = "";
	while (v.size())
	{
		result.value += v.back();
		v.pop_back();
	}
	return result;
}

bool Convertor::check(roman& t)
{
	bool f = true;
	while (t.value.find("VV") != string::npos || t.value.find("LL") != string::npos || 
		t.value.find("DD") != string::npos || t.value.find("IIII") != string::npos || 
		t.value.find("XXXX") != string::npos  || t.value.find("CCCC") != string::npos)
	{
		f = false;
		if (t.value.find("VV") != string::npos)
		{
			int pos = t.value.find("VV");
			t.value.erase(pos, 2);
			t.value.insert(pos, "X");
		}
		if (t.value.find("LL") != string::npos)
		{
			int pos = t.value.find("LL");
			t.value.erase(pos, 2);
			t.value.insert(pos, "C");
		}
		if (t.value.find("DD") != string::npos)
		{
			int pos = t.value.find("DD");
			t.value.erase(pos, 2);
			t.value.insert(pos, "M");
		}
		if (t.value.find("IIII") != string::npos)
		{
			int pos = t.value.find("IIII");
			t.value.erase(pos, 4);
			t.value.insert(pos, "IV");
		}
		if (t.value.find("XXXX") != string::npos)
		{
			int pos = t.value.find("XXXX");
			t.value.erase(pos, 4);
			t.value.insert(pos, "XL");
		}
		if (t.value.find("CCCC") != string::npos)
		{
			int pos = t.value.find("CCCC");
			t.value.erase(pos, 4);
			t.value.insert(pos, "CD");
		}
	}
	return f;
}

void Convertor::print(arabic A)
{
	cout << A.value;
}

void Convertor::print(roman R)
{
	cout << R.value;
}

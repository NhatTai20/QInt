#include"function.h"
#include"QInt.h"

void ScanQInt(QInt& x)
{
	string temp = "";
	cout << "Nhap so nguyen: ";
	cin >> temp;
	x = NumberToQInt(temp);
}

void PrintQInt(QInt x)
{
	string s = "";
	s = QIntToNumber(x);
	cout << s;
}

string exp2String(int exp)
{
	string result = "1";
	if (exp < 0)
	{
		return "0";
	}
	for (int i = 0; i < exp; i++)
	{
		result = MultiString2(result);
	}
	return result;
}
string MultiString2(string data)
{
	string temp = "";
	int n = data.length();
	int d = 0, k = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		d = (int)(data[i] - '0') * 2 + k;
		k = d / 10;
		d %= 10;

		temp += to_string(d);
	}

	if (k != 0)
		temp += to_string(k);

	string result = "";
	n = temp.length();
	for (int i = n - 1; i >= 0; i--)
	{
		result += temp[i];
	}
	return result;
}
string StringPlus(string str1, string str2)
{
	string value = "";
	if (str2.length() > str1.length())
	{
		string temp = str1;
		str1 = str2;
		str2 = temp;
	}

	// cộng
	string result = "";
	int n = str1.length(), k = 0, d = 0;
	int m = str1.length() - str2.length();
	for (int i = n - 1; i >= 0; i--)
	{
		if (i - m >= 0)
		{
			d = (int)(str1[i] - '0') + (int)(str2[i - m] - '0') + k;
		}
		else if (k != 0)
		{
			d = (int)(str1[i] - '0') + k;
		}
		else if (k == 0)
		{
			d = (int)(str1[i] - '0');
		}

		k = d / 10;
		d %= 10;
		result += to_string(d);
	}
	// có thể tràn
	if (k != 0)
		result += to_string(k);

	// đọc ngược dãy lại lấy kết quả cộng
	n = result.length();
	for (int i = n - 1; i >= 0; i--)
	{
		value += result[i];
	}

	return value;
}
string deleteZero(string s)
{
	int pos = 0;
	for (int pos = 0; pos < s.length(); pos++)
	{
		if (s[pos] != '0')
			break;
	}
	return s.substr(pos);
}
string Divide2String(string value, bool& bit)
{
	// 0 is 48
	if ((int)value[value.length() - 1] % 2 == 0)
		bit = 0;
	else
		bit = 1;
	// chia 2
	string temp = "";
	int d = 0, n = value.length(), mod = 0;

	for (int i = 0; i < n; i++)
	{
		// lấy từng phần tử chia cho 2 lấy dư
		d = (int)(value[i] - '0') + mod * 10;
		mod = d % 2;
		d /= 2;
		if (d == 0 && i == 0)
			continue;

		temp += to_string(d);
	}
	return temp;
}


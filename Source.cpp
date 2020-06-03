#include"QInt.h"
#include"function.h"
QInt::QInt() {
	for (int i = 0; i < 4; i++)
	{
		data[i] = 0;
	}
}
QInt::~QInt() {

}
bool QInt::GetBit(int pos) {
	int index = pos / 32;
	int indexbit = 32 - 1 - pos % 32;
	return (data[index] >> indexbit) & 1;
}
void QInt::SetBit(int pos, bool  bit) {

	int index = pos / 32;

	int indexbit = 32 - 1 - pos % 32;

	if (bit == 1) {
		data[index] = (1 << indexbit) | data[index];
	}
	else {
		data[index] = ~(1 << indexbit) & data[index];
	}
}
QInt QInt::operator+(QInt x)
{
	QInt result;
	for (int i = 0; i < 4; i++) {
		result.data[i] = 0;
	}
	int temp = 0;
	for (int i = 127; i >= 0; i++)
	{
		int tong = this->GetBit(i) + x.GetBit(i) + temp;
		result.SetBit(i, tong % 2);
		temp = tong / 2;
	}
	return result;

}
QInt QInt::ChuyenSangBu2()
{
	QInt res;
	for (int i = 0; i < 4; i++)
	{
		res.data[i] = 0;
	}
	for (int i = 127; i >= 0; i++)
	{
		bool temp = this->GetBit(i);
		if (temp == 0)
			res.SetBit(i, 1);
		else res.SetBit(i, 0);
	}
	QInt one;
	for (int i = 0; i < 4; i++)
	{
		one.data[i] = 0;
	}
	one.SetBit(127, 1);
	res = res + one;
	return res;
}
QInt QInt::operator-(QInt x)
{
	QInt bu2 = x.ChuyenSangBu2();
	return  (*this) + x;
	
}
QInt QInt::operator=(const QInt& x)
{
	for (int i = 0; i < 4; i++)
	{
		this->data[i] = x.data[i];
	}
	return *this;
}
QInt QInt::operator<<(int times)
{
	QInt res1 = *this;
	QInt res2 = *this;
	for (int i = 0; i < times; i++)
	{
		for (int j = 0; j < 127; j++)
		{
			res1.SetBit(j, res2.GetBit(j + 1));
		}
	}
	res1.SetBit(127, 0);
	return res1;
}
QInt QInt::operator>>(int times)
{
	QInt res1 = *this;
	QInt res2 = *this;
	bool sign = GetBit(0);//lấy dấu
	for (int i = 0; i < times; i++)
	{
		for (int j = 127; j >= 1; j--)
		{
			res1.SetBit(j, res2.GetBit(j - 1));
		}
	}
	res1.SetBit(0, sign);//gán lại dấu
	return res1;
}
QInt QInt::operator*(QInt Q)
{
	QInt A;
	QInt M = *this;
	char Q1 = 0;
	for (int i = 128; i > 0; i--)
	{
		if ((Q.GetBit(127) & 1) & (Q1 ^ 1)) A = A - M;
		else if ((Q.GetBit(127) ^ 1) & (Q1 & 1)) A = A + M;

		Q1 = Q.GetBit(127);
		for (int j = 127; j0; j--)
		{
			Q.SetBit(j, Q.GetBit(j - 1));
		}
		Q.SetBit(0, A.GetBit(127));
		for (int j = 127; j0; j--)
		{
			A.SetBit(i, A.GetBit(j - 1));
		}
	}
	return Q;
}
QInt QInt::operator/(QInt Q)
{
	QInt A;

	bool KtraTraiDau = Q.GetBit(0) ^ this->GetBit(0);
	if (Q.GetBit(0))
		Q = Q.ChuyenSangBu2();
	if (this->GetBit(0))
		this->ChuyenSangBu2();
	for (int i = 128; i > 0; i--)
	{
		for (int j = 0; i < 127; j++)
		{
			A.SetBit(j, A.GetBit(j + 1));
		}
		A.SetBit(127, this->GetBit(0));
		for (int j = 0; j < 127; j++)
		{
			this->SetBit(j, this->GetBit(j + 1));
		}
		this->SetBit(127, 0);
		A = A - Q;
		if (A.GetBit(0)) {
			A = A + Q;
		}
		else {
			this->SetBit(127, 1);
		}
	}
	if (KtraTraiDau) return this->ChuyenSangBu2();
	return (*this);
}
string BinToHex(string bin)
{
	string res="";
	for (int i = 0; i < bin.length(); i+=4)
	{
		string o = bin.substr(i, 4);
		if (o == "0000") res += '0';
		else if (o == "0001") res += '1';
		else if (o == "0010") res += '2';
		else if (o == "0011") res += '3';
		else if (o == "0100") res += '4';
		else if (o == "0101") res += '5';
		else if (o == "0110") res += '6';
		else if (o == "0111") res += '7';
		else if (o == "1000") res += '8';
		else if (o == "1001") res += '9';
		else if (o == "1010") res += 'A';
		else if (o == "1011") res += 'B';
		else if (o == "1100") res += 'C';
		else if (o == "1101") res += 'D';
		else if (o == "1110") res += 'E';
		else if (o == "1111") res += 'F';
	}
	return res;
}
string HexToBin(string hex)
{
	string res="";
	for (int i = 0; i < hex.length(); i++)
	{
		if (hex[i] == 0) res += "0000";
		else if (hex[i] == '1') res += "0001";
		else if (hex[i] == '2') res += "0010";
		else if (hex[i] == '3') res += "0011";
		else if (hex[i] == '4') res += "0100";
		else if (hex[i] == '5') res += "0101";
		else if (hex[i] == '6') res += "0110";
		else if (hex[i] == '7') res += "0111";
		else if (hex[i] == '8') res += "1000";
		else if (hex[i] == '9') res += "1001";
		else if (hex[i] == 'A') res += "1010";
		else if (hex[i] == 'B') res += "1011";
		else if (hex[i] == 'C') res += "1100";
		else if (hex[i] == 'D') res += "1101";
		else if (hex[i] == 'E') res += "1110";
		else if (hex[i] == 'F') res += "1111";
	}
	return res;
}

QInt QInt::QInt::rol()
{
	QInt res;
	res = *this << 1;
	res.SetBit(0, 1);
	int i = 127;
	while (res.GetBit(i) == 0) i--;
	res.SetBit(i, 0);
	return res;
}

QInt QInt::ror()
{
	QInt res;
	bool index;
	index = this->GetBit(0);
	res = *this >> 1;
	if (index == 1)
	{
		int i = 127;
		while (res.GetBit(i)==0)
			i--;
		res.SetBit(i + 1, index);
	}
	return res;
}

string QIntToNumber(QInt x)
{
	string value = "0";
	string res = "";
	bool FullZero = false;

	if (x.GetBit(0) == 1)//so am
	{
		x.ChuyenSangBu2();
		res += '-';
	}
	for (int i = 127; i >= 1; i--)
	{
		if (x.GetBit(i) == 1)
		{
			//result += exp2String(128 - i - 1)
			res = StringPlus(res, exp2String(128 - 1 - i));
		}
	}

	value += res;
	return value;
}

QInt NumberToQInt(string value)
{
	QInt x;
	x;
	bool negative = false;

	if (value[0] == '-')
	{
		negative = true;
		value[0] = '0';
	}
	else if (value[0] == '+')
	{
		value[0] = '0';
	}
	bool bit = 0;
	int vt = 127;
	while (value != "0" && value != "")
	{
		value = Divide2String(value, bit);
		x.SetBit(vt, bit);
		vt--;
	}

	if (negative == true) // số âm thì lưu bù 2
	{
		x.ChuyenSangBu2();
	}
	return x;
}
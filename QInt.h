#pragma once
#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;

class QInt {
private:
	int data[4];
public:
	QInt();
	~QInt();
	QInt ChuyenSangBu2();
	QInt(string, int = 0);
	bool GetBit(int pos);
	void SetBit(int pos, bool bit);
	/*operator*/
	QInt operator=(const QInt&);
	QInt operator+(QInt);
	QInt operator - (QInt);
	QInt operator*(QInt);
	QInt operator / (QInt);
	/*dich trai, phai so hoc*/
	QInt operator << (int);
	QInt operator >> (int);

	QInt rol();
	QInt ror();
};
string BinToHex(string);
string HexToBin(string);
string QIntToNumber(QInt);
QInt NumberToQInt(string value);
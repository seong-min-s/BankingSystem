#ifndef _MYSTRING_H_
#define _MYSTRING_H_
#include "BankingSystem.h"
class mystring {
private:
	char* str;
	int len;
public:
	mystring() :len(0) { str = NULL; }
	mystring(const mystring& s);
	mystring(const char* s);
	~mystring();
	int getLength();
	mystring& operator=(const mystring& s);
	mystring& operator+=(const mystring& s);
	mystring operator+(const mystring& s);
	bool operator==(const mystring& );

	friend ostream& operator<<(ostream& os, const mystring& s);
	friend istream& operator>>(istream& is, mystring&);
};
#endif

#ifndef _MYSTRING_H_
#define _MYSTRING_H_

#include "BankingSystem.h"
class mystring {
private:
	char* str;
	int len;
public:
	mystring() :len(0) { str = NULL; }
	mystring(const mystring&);
	mystring(const char*);

	int getLength();

	mystring& operator=(const mystring&);
	mystring operator+=(const mystring&);

	bool operator==(const mystring&);

	friend ostream& operator<<(ostream& os, const mystring&);
	friend istream& operator>>(istream& os, mystring&);
};
#endif

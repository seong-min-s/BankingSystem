#ifndef _MYSTRING_H_
#define _MYSTRING_H_
#include <iostream>
using namespace std;
class mystring {
private:
	char* str;
	int len;
public:
	mystring() :len(0) { str = NULL; }
	mystring(const mystring& copy);
	mystring(const char* getstr);

	int getLength();

	mystring& operator=(const mystring& copy);
	mystring operator+=(const mystring& ref);

	bool operator==(const mystring& ref);
	~mystring();
	friend ostream& operator<<(ostream& os, const mystring& tmp);
	friend istream& operator>>(istream& is, mystring& ref);
};
#endif

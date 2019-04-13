#include "mystring.h"
mystring::mystring(const mystring& copy) :len(copy.len)
{
	str = new char[strlen(copy.str) + 1];
	strcpy(str, copy.str);
}
mystring::mystring(const char* getstr)
{
	len = strlen(getstr) + 1;
	str = new char[len];
	strcpy(str, getstr);
}

int mystring::getLength()
{
	return len;
}
mystring& mystring::operator=(const mystring& copy)
{
	if (str != NULL)
	{
		delete[]str;
	}
	len = copy.len;
	str = new char[len];
	strcpy(str, copy.str);
	return *this;
}
mystring mystring::operator+(const mystring& s)
{
	char *newstr = new char[len + s.len - 1];
	strcpy(newstr, str);
	strcat(newstr, s.str);

	mystring temp = newstr;
	delete[]newstr;
	return temp;
}
mystring& mystring::operator+=(const mystring& tmp)
{
	len = len + tmp.len - 1;
	char *newStr = new char[len];
	strcpy(newStr, str);
	strcat(newStr, tmp.str);

	if (str != NULL) {
		delete[]str;
	}
	str = newStr;
	return *this;
}

bool mystring::operator== (const mystring& ref)
{
	return strcmp(str, ref.str)? false :true;
}

ostream& operator<<(ostream& os, const mystring& ref)
{
	os << ref.str;
	return os;
}
istream& operator>>(istream& is, mystring& getstr)
{
	char *tmp;
	is >> tmp;
	getstr = tmp;
	return is;
}
mystring::~mystring()
{
	if (str != NULL)
		delete[]str;
}
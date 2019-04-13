#include "mystring.h"
#include "cstring"
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
	len = strlen(copy.str) + 1;
	str = new char[len];
	strcpy(str, copy.str);
	return *this;
}
mystring mystring::operator+=(const mystring& tmp)
{
	
	len = len + tmp.len - 1;
	char *newStr;
	newStr = new char[len];
	if (str != NULL) {
		strcpy(newStr, str);
		delete[]str;
	}
	strcat(newStr, tmp.str);

	str = new char[len];
	strcpy(str, newStr);

	delete[]newStr;

	return *this;
}

bool mystring::operator== (const mystring& ref)
{
	if (strcmp(str, ref.str) == 0) {
		return true;
	}
	else {
		return false;
	}
}

ostream& operator<<(ostream& os, const mystring& ref)
{
	os << ref.str << endl;
	return os;
}
istream& operator>>(istream& is, mystring& getstr)
{
	char *tmp;
	is >> tmp;
	getstr = tmp;
	return is;
}
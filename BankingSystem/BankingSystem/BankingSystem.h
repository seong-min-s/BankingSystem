#ifndef _BANKINGSYSTEM_H
#define _BANKINGSYSTEM_H
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

const int LEN_NAME = 20;
enum { CREATE = 1, DEPOSIT, WITHDRAW, DISPLAY, EXIT };
namespace CREDIT_GRADE{
	enum {
		A = 7,
		B = 4,
		C = 2
	};
}
namespace ACCOUNT_TYPE {
	enum {
		ONLY_DEPOSIT = 0,
		NORMAL = 1,
		HIGHCREDIT = 2
	};
}
#endif
#pragma once
#include <iostream>
#include <cstring>
#include "Account.h"
#include "NormalAccount.h"
#include "HightCreditAccount.h"
#include "AccountHandler.h"
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
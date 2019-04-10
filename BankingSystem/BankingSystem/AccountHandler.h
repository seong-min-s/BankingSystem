/*
	클래스 이름 : AccountHandler
	클래스 유형 : Control Class
*/
#ifndef _ACCOUNTHANDLER_H
#define _ACCOUNTHANDLER_H
#include "Account.h"
#include "AccountArray.h"
class AccountHandler {
public:
	int numberOfguest;
	//Account *account[100];
	AccountArray acc_arr;
	AccountHandler();
	~AccountHandler();
public:
	void ShowMenu() const;      //메뉴 출력
	void CreateAccount(); //계좌 개설
	void DepositAccount();//입     금
	void WithdrawMoney(); //출     금
	void Display() const;		  //잔액 조회
};
#endif


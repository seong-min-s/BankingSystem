#pragma once
/*
	클래스 이름 : AccountHandler
	클래스 유형 : Control Class
*/
#include "BankingSystem.h"
class AccountHandler {
public:
	const static int LEN_NAME = 20;
	static int numberOfguest;
	Account *account[100];
	~AccountHandler();
public:
	void ShowMenu() const;      //메뉴 출력
	void CreateAccount(); //계좌 개설
	void DepositAccount();//입     금
	void WithdrawMoney(); //출     금
	void Display() const;		  //잔액 조회
};


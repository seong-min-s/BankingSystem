#pragma once
#include <iostream>
#include <cstring>
enum { CREATE = 1, DEPOSIT, WITHDRAW, DISPLAY, EXIT };
/*
	클래스 이름 : Account
	클래스 유형 : Entity Class
*/
class Account {
private:
	int accID;
	char *cusName;
	double balance;
public :
	Account(int number, char *name, double money);
	Account(const Account &copy);
	~Account();
	bool SetBalance(int COMMAND, double amount);
	int GetNumber()const;
	char* GetName()const;
	double GetBalance()const;
	void ShowAllInfo()const;
};
/*
	클래스 이름 : AccountHandler
	클래스 유형 : Control Class
*/
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


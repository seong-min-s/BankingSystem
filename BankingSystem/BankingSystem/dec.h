#pragma once
#include <iostream>
#include <cstring>
enum { CREATE = 1, DEPOSIT, WITHDRAW, DISPLAY, EXIT };
const int LEN_NAME = 20;
class Account {
private:
	int accID;
	char *cusName;
	double balance;
public :
	Account(int number, char *name, double money) : accID(number), balance(money){
		this->cusName = new char[strlen(name)+1];//문제요구사항 : 멤버변수로 문자열 포인터를 지니고, 동적 할당의 형태로 구현해야 한다.
		strcpy(this->cusName, name);
	}
	Account(const Account &copy) :accID(copy.accID),balance(copy.balance){
		this->cusName = new char[strlen(copy.cusName)+1];
		strcpy(cusName, copy.cusName);
	}
	~Account() {
		delete[]cusName;
	}
	bool SetBalance(int COMMAND, double amount);
	int GetNumber()const;
	char* GetName()const;
	double GetBalance()const;
	void ShowAllInfo()const;
};
void ShowMenu();      //메뉴 출력
void CreateAccount(); //계좌 개설
void DepositAccount();//입     금
void WithdrawMoney(); //출     금
void Display();		  //잔액 조회


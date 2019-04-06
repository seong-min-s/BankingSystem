#pragma once
#include <iostream>
#include <cstring>
#include "Account.h"
enum { CREATE = 1, DEPOSIT, WITHDRAW, DISPLAY, EXIT };

/*
	Ŭ���� �̸� : AccountHandler
	Ŭ���� ���� : Control Class
*/
class AccountHandler {
public:
	const static int LEN_NAME = 20;
	static int numberOfguest;
	Account *account[100];
	~AccountHandler();
public:
	void ShowMenu() const;      //�޴� ���
	void CreateAccount(); //���� ����
	void DepositAccount();//��     ��
	void WithdrawMoney(); //��     ��
	void Display() const;		  //�ܾ� ��ȸ
};


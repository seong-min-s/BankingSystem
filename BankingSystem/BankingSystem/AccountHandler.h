/*
	Ŭ���� �̸� : AccountHandler
	Ŭ���� ���� : Control Class
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
	void ShowMenu() const;      //�޴� ���
	void CreateAccount(); //���� ����
	void DepositAccount();//��     ��
	void WithdrawMoney(); //��     ��
	void Display() const;		  //�ܾ� ��ȸ
};
#endif


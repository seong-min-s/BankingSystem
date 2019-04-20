/*
	Ŭ���� �̸� : AccountHandler
	Ŭ���� ���� : Control Class
*/
#ifndef _ACCOUNTHANDLER_H
#define _ACCOUNTHANDLER_H
#include "Account.h"
#include "BoundCheckArray.h"
#include"AccountException.h"
typedef Account* Account_ptr;
class AccountHandler {
public:
	int numberOfguest;
	//Account *account[100];
	//AccountArray acc_arr;
	BoundCheckArray<Account_ptr> acc_arr;
	AccountHandler();
	~AccountHandler();
public:
	void ShowMenu() const;      //�޴� ���
	void CreateAccount(); //���� ����
	void DepositAccount()throw (MinusException);//��     ��
	void WithdrawMoney(); //��     ��
	void Display() const;		  //�ܾ� ��ȸ
};
#endif


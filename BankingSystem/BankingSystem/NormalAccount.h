#ifndef _NORMAL_H
#define _NORMAL_H
#include "Account.h"
class NormalAccount : public Account {
private:
	float interest;
public:
	NormalAccount(int number, char *name, double money, float ratio) : Account(number, name, money), interest(ratio) {};
	bool Deposit(double amount)
	{
		return Account::Deposit(amount)*Account::Deposit(GetDepositInterest(this->interest));
	}
	int GetDepositInterest(float interest)
	{
		return Account::GetBalance()*interest;
	}
	void ShowAllInfo()const {
		std::cout << "보통계좌 입니다." << std::endl;
		Account::ShowAllInfo();
	}
};
#endif
#ifndef _HIGHCREDIT_H
#define _HIGHCREDIT_H
#include "NormalAccount.h"
#include "mystring.h"
class HightCreditAccount : public NormalAccount {
private:
	int specialRate;
public:
	HightCreditAccount(int number, mystring name, double money, float ratio, int special) : NormalAccount(number, name, money, ratio), specialRate(special) {}
	bool Deposit(double money)
	{
		return NormalAccount::Deposit(money)*Account::Deposit(GetExtraInterest(specialRate / 100.0));
	}
	int GetExtraInterest(float interest)
	{
		return Account::GetBalance()*interest;
	}
	void ShowAllInfo()const
	{
		std::cout << "신용계좌" << "_등급 :" << specialRate << std::endl;
		Account::ShowAllInfo();
	}
};
#endif
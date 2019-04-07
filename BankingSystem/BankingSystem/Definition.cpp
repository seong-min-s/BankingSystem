#include "dec.h"//함수 또는 변수정의
int AccountHandler::numberOfguest = -1;


NormalAccount::NormalAccount(int number, char *name, double money, float ratio) : Account(number, name, money), interest(ratio)
{ }
bool NormalAccount::Deposit(double money)
{
	return Account::Deposit(money)*Account::Deposit(GetDepositInterest(this->interest));
}
int  NormalAccount::GetDepositInterest(float interest)
{
	return Account::GetBalance()*interest;
}
void NormalAccount::ShowAllInfo()const {
	std::cout << "보통계좌 입니다." << std::endl;
	Account::ShowAllInfo();
}


HightCreditAccount::HightCreditAccount(int number, char *name, double money, float ratio, int special) : NormalAccount(number, name, money, ratio), specialRate(special) {}
bool HightCreditAccount::Deposit(double money)
{
	return NormalAccount::Deposit(money)*Account::Deposit(GetExtraInterest(grade / 100.0));
}
int HightCreditAccount::GetExtraInterest(float interest)
{
	return Account::GetBalance()*interest;
}
void HightCreditAccount::ShowAllInfo()const
{
	std::cout << "신용계좌" << "_등급 :" << grade <<std::endl;
	Account::ShowAllInfo();
}

void AccountHandler::DepositAccount()
{
	int temp_number;
	double temp_money;
	std::cout << "입     금" << std::endl;
	std::cout << "계좌 번호 :(이름 아님)" << std::endl;
	std::cin >> temp_number;
	std::cout << "입금 금액 :" << std::endl;
	std::cin >> temp_money;
	//계좌를 찾고 넣자
	for (int i = 0; i <= numberOfguest; i++)
	{
		if (account[i]->GetNumber()== temp_number)
		{
			account[i]->Deposit(temp_money);
			std::cout << "입금 완료" << std::endl;
			break;
		}
	}
}
void AccountHandler::WithdrawMoney()
{
	int temp_number;
	double temp_money;
	std::cout << "입     금" << std::endl;
	std::cout << "계좌 ID :" << std::endl;
	std::cin >> temp_number;
	std::cout << "출금 액 :" << std::endl;
	std::cin >> temp_money;
	for (int i = 0; i <= numberOfguest; i++)
	{
		if (account[i]->GetNumber() == temp_number)
		{
			account[i]->Withdraw(temp_money);
			std::cout << "출금 완료" << std::endl;
			break;
		}
	}
}
void AccountHandler::Display() const
{
	for (int i = 0; i <= numberOfguest; i++)
	{
		account[i]->ShowAllInfo();
		std::cout << std::endl;
	}
}
void AccountHandler::CreateAccount() {
	int number, balance, type, grade;
	char name[LEN_NAME];
	float interest;
	numberOfguest++;
	std::cout << "Enter your account number." << std::endl;
	std::cin >> number;

	std::cout << "Enter your account name." << std::endl;
	std::cin >> name;

	std::cout << "Enter your account BALANCE." << std::endl;
	std::cin >> balance;

	std::cout << "What kind of account do you want?" << std::endl;
	std::cout << "0-무이자계좌, 1->보통에금계좌, 2->신용신뢰게좌" << std::endl;
	std::cin >> type;
	
	switch (type) {
	case ACCOUNT_TYPE::ONLY_DEPOSIT:
		account[numberOfguest] = new Account(number, name, balance);
		break;
	case ACCOUNT_TYPE::NORMAL :
		std::cout << "이자율";
		std::cin >> interest;
		account[numberOfguest] = new NormalAccount(number, name, balance, interest);
		break;
	case ACCOUNT_TYPE::HIGHCREDIT :
		std::cout << "이자율 : ";
		std::cin >> interest;
		std::cout << "신용등급 : ";
		std::cin >> grade;
		account[numberOfguest] = new HightCreditAccount(number, name, balance, interest,grade);
		break;
	default :
			break;
	}
}
void AccountHandler::ShowMenu() const
{
	std::cout << "-----MENU-----" << std::endl;
	std::cout << "1. 계좌개설" << std::endl;
	std::cout << "2. 입    금" << std::endl;
	std::cout << "3. 출    금" << std::endl;
	std::cout << "4. 계좌정보 전체 출력" << std::endl;
	std::cout << "5. 프로그램 종료" << std::endl;
}
AccountHandler::~AccountHandler() {
	for (int i = 0; i < AccountHandler::numberOfguest; i++) {
		delete[i]account;
	}
}
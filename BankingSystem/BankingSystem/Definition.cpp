#include "dec.h"//함수 또는 변수정의

int numberOfguest = -1;
Account account[100];
bool Account::InitAccount(int number, char *name, double balance) {
	if (number < 0) {
		return false;
	}else {
		this->number = number;
	}
	if (balance < 0) {
		return false;
	}else {
		this->balance = balance;
	}
	return true;
}
void CreateAccount() {
	numberOfguest++;
	int number, balance;
	char name[LEN_NAME];//문제발생
	std::cout << "Enter your account number." << std::endl;
	std::cin >>number;

	std::cout << "Enter your account name." << std::endl;
	std::cin >>name;

	std::cout << "Enter your account BALANCE." << std::endl;
	std::cin >> balance;
	account[numberOfguest].InitAccount(number, name, balance);
}
bool Account::SetBalance(int COMMAND, double amount)
{
	if (amount < 0) {
		return false;
	}
	if (COMMAND == DEPOSIT)
	{
		this->balance += amount;
	}
	else if (COMMAND == WITHDRAW) {
		this->balance -= amount;
	}
	return true;
}
int Account::GetNumber()
{
	return this->number;
}
char* Account::GetName()
{
	return this->name;
}
double Account::GetBalance()
{
	return this->balance;
}
void DepositAccount()
{
	int temp_number;
	double temp_money;
	std::cout << "입     금" << std::endl;
	std::cout << "계좌 ID :" << std::endl;
	std::cin >> temp_number;
	std::cout << "입금 액 :" << std::endl;
	std::cin >> temp_money;
	//계좌를 찾고 넣자
	for (int i = 0; i <= numberOfguest; i++)
	{
		if (account[i].GetNumber()== temp_number)
		{
			account[i].SetBalance(DEPOSIT, temp_money);
			std::cout << "입금 완료" << std::endl;
			break;
		}
	}
}
void WithdrawMoney()
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
		if (account[i].GetNumber() == temp_number)
		{
			account[i].SetBalance(WITHDRAW, temp_money);
			std::cout << "출금 완료" << std::endl;
			break;
		}
	}
}
void Display()
{
	for (int i = 0; i <= numberOfguest; i++)
	{
		std::cout << "이름 :" << account[i].GetName() << std::endl;
		std::cout << "계좌 번호 :" << account[i].GetNumber() << std::endl;
		std::cout << "잔액 :" << account[i].GetBalance() << std::endl;
		std::cout << std::endl;
	}
}
void ShowMenu()
{
	std::cout << "-----MENU-----" << std::endl;
	std::cout << "1. 계좌개설" << std::endl;
	std::cout << "2. 입    금" << std::endl;
	std::cout << "3. 출    금" << std::endl;
	std::cout << "4. 계좌정보 전체 출력" << std::endl;
	std::cout << "5. 프로그램 종료" << std::endl;
}
/*
고객 계좌정보 구조체 정보
typedef struct guest_info{
	int number;
	char name[20];
	int left;
}guest_info;
*/
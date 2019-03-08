#include "dec.h"//함수 또는 변수정의

int numberOfguest = -1;
Account *account[100];

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
	return this->accID;
}
char* Account::GetName()//이름을 얻는 과정에서 오류발생
{
	return this->cusName;
}
double Account::GetBalance()
{
	return this->balance;
}
void Account::ShowAllInfo()
{
	std::cout << "이    름 : " << this->cusName << std::endl;
	std::cout << "계좌번호 : " << this->accID << std::endl;
	std::cout << "잔    액 : " << this->balance << std::endl;
}
void DepositAccount()
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
			account[i]->SetBalance(DEPOSIT, temp_money);
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
		if (account[i]->GetNumber() == temp_number)
		{
			account[i]->SetBalance(WITHDRAW, temp_money);
			std::cout << "출금 완료" << std::endl;
			break;
		}
	}
}
void Display()
{
	for (int i = 0; i <= numberOfguest; i++)
	{
		account[i]->ShowAllInfo();
		std::cout << std::endl;
	}
}
void CreateAccount() {
	int number, balance;
	char name[LEN_NAME];//문제발생
	numberOfguest++;
	std::cout << "Enter your account number." << std::endl;
	std::cin >> number;

	std::cout << "Enter your account name." << std::endl;
	std::cin >> name;

	std::cout << "Enter your account BALANCE." << std::endl;
	std::cin >> balance;
	account[numberOfguest] = new Account(number, name, balance);
	//account[numberOfguest].InitAccount(number, name, balance);
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
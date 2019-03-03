#include "dec.h"//함수 또는 변수정의

int numberOfguest = -1;
guest_info guest[100];
void CreateAccount() {
	numberOfguest++;
	std::cout << "Enter your account number." << std::endl;
	std::cin >> guest[numberOfguest].number;

	std::cout << "Enter your account name." << std::endl;
	std::cin >> guest[numberOfguest].name;

	guest[numberOfguest].left = 0;
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
		if (guest[i].number == temp_number)
		{
			guest[i].left += temp_money;
			break;
		}
	}
	guest[temp_number].left += temp_money;
	std::cout << "입금 완료" << std::endl;
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
		if (guest[i].number == temp_number)
		{
			guest[i].left -= temp_money;
			break;
		}
	}
	std::cout << "출금 완료" << std::endl;
}
void Display()
{
	for (int i = 0; i <= numberOfguest; i++)
	{
		std::cout << "이름 :" << guest[i].name << std::endl;
		std::cout << "계좌 번호 :" << guest[i].number << std::endl;
		std::cout << "잔액 :" << guest[i].left << std::endl;
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
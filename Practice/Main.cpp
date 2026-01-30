#include <iostream>

class Account
{
public:
    Account(const Account& account)
        : id(account.id), balance(account.balance)
    {
        int length = strlen(account.name) + 1;
        name = new char[length];
        strcpy_s(name, sizeof(char), account.name);
    }
    Account(int id, char* name, int balance)
        : id(id), balance(balance)
    {
        int length = strlen(name) + 1;
        this->name = new char[length];
        strcpy_s(this->name, length, name);
    }
    ~Account()
    {
        delete[] name;
        name = nullptr;
    }
    void PrintInfo()
    {
        std::cout << "id: " << id << "\n";
        std::cout << "name: " << name << "\n";
        std::cout << "balance: " << balance << "\n";
        std::cout << "\n";
    }
    int GetId()
    {
        return id;
    }
    void Deposit(int balance)
    {
        this->balance += balance;
    }
    void Withdraw(int balance)
    {
        this->balance -= balance;
    }

private:
    int id = 0;
    char* name = nullptr;
    int balance = 0;
};


class Bank
{
public:
    Bank() {

    }
    ~Bank() {
       
    }
    void Run()
    {

        char input = ' ';

        while (input != 'q')
        {
            ShowMenu();
            std::cout << "문자를 입력하세요 (q로 종료): ";
            std::cin >> input;

            if (input == '1')
            {
                CreateAccount();
            }

            if (input == '2')
            {
                Deposit();
            }

            if (input == '3')
            {
                Withdraw();
            }

            if (input == '4')
            {
                Inquire();
            }
        }
    }

private:
    void ShowMenu()
    {
        std::cout << "1. 계좌 개설\n";
        std::cout << "2. 입금\n";
        std::cout << "3. 출금\n";
        std::cout << "4. 전체 고객 잔액 조회\n\n\n";

    }
    void CreateAccount() {
        int id = 0;
        char name[100];
        int balance = 0;
        std::cout << "1번 메뉴 선택하셨습니다.\n";
        std::cout << "id를 입력해주세요: \n";
        std::cin >> id;
        std::cout << "이름을 입력해주세요: \n";
        std::cin >> name;
        std::cout << "잔액을 입력해주세요: \n";
        std::cin >> balance;

        std::cout << "계좌 개설이 완료되었습니다.\n\n\n";

        Account* account = new Account(id, name, balance);
        accounts[accountsIndex++] = account;
    }
    void Deposit() {
        int id = 0;
        int balance = 0;
        std::cout << "2번 메뉴 선택하셨습니다.\n";
        std::cout << "id를 입력해주세요: \n";
        std::cin >> id;
        std::cout << "금액을 입력해주세요: \n";
        std::cin >> balance;

        for (Account* account : accounts)
        {
            if (account->GetId() == id)
            {
                account->Deposit(balance);
                break;
            }
        }
    }
    void Withdraw() {
        int id = 0;
        int balance = 0;
        std::cout << "3번 메뉴 선택하셨습니다.\n";
        std::cout << "id를 입력해주세요: \n";
        std::cin >> id;
        std::cout << "금액을 입력해주세요: \n";
        std::cin >> balance;

        for (Account* account : accounts)
        {
            if (account->GetId() == id)
            {
                account->Withdraw(balance);
                break;
            }
        }
    }
    void Inquire() {
        for (int i = 0; i < accountsIndex; ++i)
        {
            accounts[i]->PrintInfo();
        }

    }
    int accountsIndex = 0;
    Account* accounts[100] = {};
};


int main()
{
    Bank bank;
    bank.Run();

    std::cin.get();
}
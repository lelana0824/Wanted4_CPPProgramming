#include <iostream>

class Account
{
public:
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
        std::cout << "name: " << *name << "\n";
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

        while (bInitView)
        {
            ShowMenu();
        }

        while (!bInitView)
        {
            std::string input;
            std::cout << "문자를 입력하세요 (q로 종료): ";

            // 1. 공백을 포함한 한 줄을 입력받거나, 
            //    문자 하나만 필요하다면 cin >> input 사용
            if (!(std::cin >> input)) break;

            // 2. std::string은 널 종료 문자(\0)를 알아서 관리함
            if (input == "q") {
                break; // 3. delete[] 필요 없음
            }
            if (input == "1")
            {
                int id = 0; 
                char* name = new char(100);
                int balance = 0;
                std::cout << "1번 메뉴 선택하셨습니다.\n";
                std::cout << "id를 입력해주세요: \n";
                std::cin >> id;
                std::cout << "이름을 입력해주세요: \n";
                std::cin >> *name;
                std::cout << "잔액을 입력해주세요: \n";
                std::cin >> balance;

                std::cout << "계좌 개설이 완료되었습니다.\n";

                CreateAccount(id, name, balance);
                bInitView = true;
                break;
                
            }

            if (input == "4")
            {
                Inquire();
                bInitView = true;
                break;
            }
        }
    }

private:
    void ShowMenu()
    {
        std::cout << "1. 계좌 개설\n";
        std::cout << "2. 입금\n";
        std::cout << "3. 출금\n";
        std::cout << "4. 전체 고객 잔액 조회\n";

        std::string input;
        std::cout << "문자를 입력하세요 (q로 종료): ";
    }
    void CreateAccount(int id, char* name, int balance) {
        Account* account = new Account(id, name, balance);
        accounts[0] = account;
        
    }
    void Deposit(int id, int balance) {
        for (Account* account : accounts)
        {
            if (account->GetId() == id)
            {
                account->Deposit(balance);
            }
        }
    }
    void Withdraw(int id, int balance) {
        for (Account* account : accounts)
        {
            if (account->GetId() == id)
            {
                account->Withdraw(balance);
            }
        }
    }
    void Inquire() {
        for (Account* account : accounts)
        {
            account->PrintInfo();
        }

    }
    Account* accounts[100] = {};
    bool bInitView = true;
};


int main()
{
    Bank bank;
    bank.Run();

    std::cin.get();
}
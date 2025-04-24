#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

std::string setName()
{
    std::string name;
    std::cout << "Enter your name -> ";
    std::getline(std::cin, name);

    while (name.length() < 3 || name.length() > 10)
    {
        std::cerr << "Name must be longer than 3 and shorter than 10.\n";
        std::cout << "Enter your name -> ";
        std::getline(std::cin, name);
    }

    char first_symbol{ name.at(0) };
    if (std::islower(first_symbol))
    {
        std::transform(name.begin(), name.begin() + 1, name.begin(), ::toupper);
    }

    return name;
}

class Bank
{
public:
    Bank(std::string name, double balance) : name(name), balance(balance)
    {
        std::cout << "Login from account completed\n";
    }

    ~Bank()
    {
        std::cout << "Account logged out\n";
    }

    void main_screen()
    {
        int sum;
        std::string choice;
        std::cout << "Welcome " << name << std::endl;

        while (true)
        {
            std::cout << "Select operation: <Deposit> <Withdraw> -> ";
            std::cin >> choice;
            std::transform(choice.begin(), choice.end(), choice.begin(), ::tolower);

            if (choice == "deposit" || choice == "withdraw")
            {
                break;
            }
            std::cerr << "Wrong choice. Please enter 'deposit' or 'withdraw'.\n";
        }

        if (choice == "deposit")
        {
            std::cout << "Enter the amount you wish to deposit -> ";
            std::cin >> sum;
            balance += sum;
        }
        else if (choice == "withdraw")
        {
            std::cout << "Enter the amount you want to withdraw -> ";
            std::cin >> sum;
            if (sum > balance)
            {
                std::cerr << "Insufficient funds!\n";
            }
            else
            {
                balance -= sum;
            }
        }

        std::cout << "Current balance: " << balance << std::endl;
    }

private:
    std::string name;
    double balance;
};

int main()
{
    std::string name = setName();
    double initial_balance = 0.0;

    std::cout << "Enter initial balance -> ";
    std::cin >> initial_balance;

    Bank account{ name, initial_balance };
    account.main_screen();

    return 0;
}
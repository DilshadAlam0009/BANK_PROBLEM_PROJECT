#include <iostream>
#include <string>
#include<limits.h>
using namespace std;

class Bank
{

protected:
    string name, address;
    int age;
    char y;
    static int total_amount;

public:
    static int acc_no;
};
int Bank ::total_amount = 0;
int Bank::acc_no = 800001;

class user : public Bank
{
    int amount;

public:
    void openaccount()
    {
        cout << "enter  your name " << endl;
        cin.ignore();
        getline(cin , name);
        cout << "enter your address" << endl;
        getline(cin,address) ;
        cout << "enter your age" << endl;
        cin >> age;
        cout << "enter your account type s for saving and  c for currrent" << endl;
        cin >> y;

        if (age > 18)
        {
            cout << "** congratulation your account has been  created **:" << endl;
            acc_no++;
            cout << "your name is :" << name << endl;
            cout << "your adddress is :" << address << endl;
            cout << "your age is :" << age << endl;
            if (y == 's')
            {
                cout << "your account type is saving :" << endl;
            }
            else if (y == 'c')
            {
                cout << "your account type is currrent :" << endl;
            }
            cout << "your acount number is: " << acc_no<< endl;
        }

        else
        {
            cout << "sorry you are not able create account !" << endl;
            return;
        }
    }

    void deposit()
    {

        cout << "enter amount to be deposit: " << endl;
        cin >> amount;
        if (amount > 0)
        {
            total_amount += amount;
            cout << "amount debited successfully" << endl;
        }
        else
        {
            cout << "enter amount positive";
        }
    }
    void credit()
    {

        cout << "enter amount to credit: " << endl;
        cin >> amount;

        if (amount > 0 && amount <= total_amount)
        {
            total_amount -= amount;
            cout << "amount credited successfully ||" << endl;
            cout << "your account balance is :" << total_amount;
        }
        else
        {
            cout << "plz enter valid amount" << endl;
        }
    }
    void balance()
    {
        cout << "your balance is :";
        cout << total_amount << endl;
    }
};

int main()
{
    int ch;
    int accountnumber;
    char x;
    user A1;

    do
    {
        cout << "1) press 1 to open new account" << endl;
        cout << "2) press 2 to deposit ammount" << endl;
        cout << "3) press 3 to withdrawl amount" << endl;
        cout << "4) press 4 to see you balance" << endl;
        cout << "chose any option from above" << endl;
        // user = cin >> "Enter User " << endl;
        cin >> ch;
        if (ch == 1)
        {
            A1.openaccount();

            // return 0;
        }

        else if (ch == 2)
        {
            cout << "enter you account no" << endl;
            cin >> accountnumber;
            if (accountnumber == A1.acc_no)
            {
                A1.deposit();
            }
            else
            {
                cout << "your account number is wrong:";
            }
        }

        else if (ch == 3)

        {
            cout << "enter you account no" << endl;
            cin >> accountnumber;
            if (accountnumber == A1.acc_no)
            {
                A1.credit();
            }
            else
            {
                cout << "enter correct account number: " << endl;
            }
        }
        else if (ch == 4)
        {
            A1.balance();
        }
        else
        {
            cout << "plzz choose from above";
        }

        cout << "do want to exit type yes(Y) or no(N):" << endl;
        cin >> x;
        if (x == 'y' || x == 'y')
        {
            return 0;
        }

    } while (x == 'n');

    return 0;
}
//BANK MANAGEMENT SYSTEM

#include<iostream>
#include<fstream> //-> for file operations
#include<cctype> //-> for char operations
#include<iomanip> //-> input/ouput manipulators
using namespace std;

class Account{
   protected:
      long accountNo;
      string firstName;
      string lastName;
      long double balance;

   public:
      Account(string firstName, string lastName, long accountNo, long double balance)
      {
         this->firstName = firstName;
         this->lastName = lastName;
         this->accountNo = accountNo;
         this->balance = balance;

      }

      string getfirstName()
      {
         return firstName;
      }
      string getlastName()
      {
         return lastName;
      }
      void setfirstName(string firstName)
      {
          firstName = firstName;
      }
      void setlastName(string lastName)
      {
          lastName = lastName;
      }
      
      int getaccountNo()
      {
         return accountNo;
      }

      void setaccountNo(long accountNo)
      {
         accountNo = accountNo;
      }
      
      int getbalance()
      {
         return balance;
      }

      void setbalance(long double balance)
      {
         balance = balance;
      }

      void create_account(); //-> func to create acc
      void display_account() ;
      void deposit(long amount);
      void withdraw(long amount);
      void listAllaccounts();
      void delete_account();

};

void Account :: create_account()
{
   cout<<"Enter the Account Number: ";
   cin>>accountNo;
   cout<<"Enter your First Name: ";
   cin.ignore();
   getline(cin,firstName);
   cout<<"Enter your Last Name: ";
   cin.ignore();
   getline(cin,lastName);
   cout<<"YOUR ACCOUNT HAS BEEN CREATED..."<<endl;
}

void Account :: display_account() 
{
   cout<<"Enter the Account Number: ";
   cin>>accountNo;
   cout<<"First Name: "<< firstName <<endl;
   cout<<"Last Name: "<< lastName <<endl;
   cout<<"Balance Amount : "<<balance <<endl;
   
}

void Account :: deposit(long amount)
{
   balance+=amount;
}

void Account :: withdraw(long amount)
{
   balance-=amount;
}



















int main(){

   return 0;
}


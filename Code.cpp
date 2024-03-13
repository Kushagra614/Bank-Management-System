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
   Account(){}
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

//FUNCTION DECLERATION

void writeAccount();
void depositAmmount();
void listAllaccounts();
void deleteAccount();


int main()
{
   char ch;
   int num;
   do
   {
      cout<<"MAIN MENU"<<endl;
      cout<<"1.CREATE ACCOUNT"<<endl;
      cout<<"2. DEPOSIT AMOUNT"<<endl;
      cout<<"3. WITHDRAW AMOUNT"<<endl;
      cout<<"4. DISPLAY BALANCE"<<endl;
      cout<<"5. DISPLAY ALL ACCOUNTS"<<endl;
      cout<<"6. DELETE AN ACCOUNT"<<endl;
      cout<<"7. EXIT"<<endl;
      
      cin>>ch;
      switch(ch)
      {
         case '1':
         write_account();
         break;
         case '2':
         depositAmount();
         break;
         case '3':
         withdrawAmount();
         break;
         case '4':
         displayBalance();
         break;
         case '5':
         listAllaccounts();
         break;
         case '6':
         deleteAccount();
         break;
         case '7':
         cout<<"THANK YOU FOR USING THE BANK MANAGEMENT SYSTEM"<<endl;
         break;
      }
         
   }
   while(ch!='8');
   return 0;
   
}
void write_account()
{
   Account ac;
   ofstream outfile("account.data");
   ac.create_account();
   outfile<< ac.getaccountNo()<<endl;
   outfile<< ac.getfirstName()<<endl;
   outfile<< ac.getlastName()<<endl;
   

}

void depositAmount()
{
   int amt;
   Account ac;
   ifstream infile("account.data");

}

void withdrawAmount()
{

}

void displayBalance()
{
   
}





















int main(){

   return 0;
}


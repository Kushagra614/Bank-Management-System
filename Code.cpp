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
         depositAmount(num);
         break;
         case '3':
         withdrawAmount(num);
         break;
         case '4':
         displayBalance(num);
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
   ofstream outFile;
   outFile.open("account.data", ios::binary|ios::app);
   ac.create_account();
   outFile.write(reinterpret_cast<char *> (&ac), sizeof(Account));
   outFile.close();
   

}

void depositAmount(int n)
{
  int n;
  int amt;
  bool found = false;
  Account ac;
  fstream File;
  File.open("account.data", ios::binary|ios::in);
  if(!File)
  {
   cout<<"File could not be Found!!! \n Press Any Key...";
   return;
  }
  while(!File.eof() && found == false)
  {
    File.read(reinterpret_cast<char *> (&ac), sizeof(Account));
    if(ac.getaccountNo()==n)
    {
      ac.display_account();
      cout<<"\nTO DEPOSIT AMOUNT"<<endl;
      cout<<"ENTER THE AMOUNT TO BE DEPSOTIED: ";
      cin>>amt;
      ac.deposit(amt);

      streampos currentPosition = File.tellg(); // Get the current position of the file pointer
      File.seekp(currentPosition - static_cast<streampos>(sizeof(ac))); // Move the file pointer back to the beginning of the record
      File.write(reinterpret_cast<char *>(&ac), sizeof(Account)); // Write the modified account object to the file
      cout << "Record Updated"<<endl;
      found = true;


    }
  }
  File.close();
  if(found == false )
  {
   cout<<"Record not Found"<<endl; 
  }

}

void withdrawAmount(int n)
{   
    int amt;
    bool found = false;
    Account ac;
    fstream File;
    File.open("account.dat", ios::binary | ios::in | ios::out);
    if (!File)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }
    while (!File.eof() && found == false)
    {
        File.read(reinterpret_cast<char *>(&ac), sizeof(Account));
        if (ac.getaccountNo() == n)
        {
            ac.display_account();
            cout << "\nTO WITHDRAW AMOUNT "<<endl;
            cout << "Enter The amount to be withdrawn: "<<endl;
            cin >> amt;
            int bal = ac.getbalance() - amt;
            if ((bal < 500 ))
                cout << "Insufficient balance";
            else
            {
               ac.withdraw(amt);

               streampos currentPosition = File.tellg(); // Get the current position of the file pointer
               File.seekp(currentPosition - static_cast<streampos>(sizeof(ac))); // Move the file pointer back to the beginning of the record
               File.write(reinterpret_cast<char *>(&ac), sizeof(Account)); // Write the modified account object to the file
               cout << " Record Updated";
               found = true;

            }
        }
    }
    File.close();
    if (found == false)
        cout << " Record Not Found "<<endl;
}

void displayBalance(int n)
{
   Account ac;
   bool flag = false;
   ifstream inFile;
   inFile.open("account.data", ios::binary);
   if(!inFile)
   {
      cout<<"File could not be found !! \nPress any Key...";
		return;
   }
   cout<<"\n BALANCE DETAILS"<<endl;

   while(inFile.read(reinterpret_cast<char*> (&ac), sizeof(Account)))
   {
      if(ac.getaccountNo()==n)
      {
         ac.display_account();
         flag = true;
      }
   } 
   inFile.close();
   if(flag ==false)
   {
      cout<<"\n Account Number does not exist!!!"<<endl;
   }
}

void deleteAccount(int n)
{
   Account ac;
   ifstream inFile;
   ofstream outFile;
   inFile.open("account.data", ios::binary);
   if(!inFile)
   {
      cout<<"\n File cound not be found!!! \n Press any key..."<<endl;
      return ;
   }
   outFile.open("Temp.data", ios::binary);
}





















int main(){

   return 0;
}


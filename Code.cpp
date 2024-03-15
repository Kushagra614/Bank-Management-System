// // BANK MANAGEMENT SYSTEM

// #include <iostream>
// #include <fstream>
// #include <string>
// #include <iomanip>
// using namespace std;

// class Account
// {
// protected:
//    long accountNo;
//    string firstName;
//    string lastName;
//    long double balance;


// public:

//    Account() {}
//    Account(string firstName, string lastName, long accountNo, long double balance)
//    {
//       this->firstName = firstName;
//       this->lastName = lastName;
//       this->accountNo = accountNo;
//       this->balance = balance;
//    }

//    string getfirstName()
//    {
//       return firstName;
//    }
//    string getlastName()
//    {
//       return lastName;
//    }
//    void setfirstName(string firstName)
//    {
//       this->firstName = firstName;
//    }
//    void setlastName(string lastName)
//    {
//       this->lastName = lastName;
//    }

//    long getaccountNo()
//    {
//       return accountNo;
//    }

//    void setaccountNo(long accountNo)
//    {
//       this->accountNo = accountNo;
//    }

//    long double getbalance()
//    {
//       return balance;
//    }

//    void setbalance(long double balance)
//    {
//       this->balance = balance;
//    }

//    void report() const;
//    void create_account();
//    void display_account() const ;
//    void deposit(long amount);
//    void withdraw(long amount);
// };

// void Account::create_account()
// {
//    cout << "Enter the Account Number: ";
//    cin >> accountNo;
//    cout << "Enter your First Name: ";
//    cin >> firstName;
//    cout << "Enter your Last Name: ";
//    cin >> lastName;
//    cout<<"Your initial Balance: ";
//    cin>>balance;
//    cout << "YOUR ACCOUNT HAS BEEN CREATED..." << endl;

// }

// void Account::display_account() const
// {
//    cout << "Account Number: " << accountNo << endl;
//    cout << "First Name: " << firstName << endl;
//    cout << "Last Name: " << lastName << endl;
//    cout << "Balance Amount : " << balance << endl;
// }

// void Account::deposit(long amount)
// {
//    balance += amount;
// }

// void Account::withdraw(long amount)
// {
//    balance -= amount;
// }

// void Account::report() const
// {
//    cout << accountNo << setw(10) << " " << firstName<<" "<< lastName << setw(10) << " " << setw(6) << balance << endl;
// }

// void write_account();
// void depositAmount(long accountNumber);
// void listAllaccounts();
// void deleteAccount();
// void displayAccount(long accountNumber);

// void write_account()
// {
//    Account ac;
//    ofstream outFile;
//    outFile.open("account.data", ios::binary | ios::app);
//    ac.create_account();
//    outFile.write(reinterpret_cast<char *>(&ac), sizeof(Account));
//    outFile.close();
// }

// void depositAmount(long accountNumber)
// {
//     int amt;
//     bool found = false;
//     Account ac;
//     fstream File;
//     File.open("account.data", ios::binary | ios::in | ios::out);
//     if (!File)
//     {
//         cout << "File could not be open !! Press any Key...";
//         return;
//     }
//     while (File.read(reinterpret_cast<char *>(&ac), sizeof(Account)))
//     {
//         if (ac.getaccountNo() == accountNumber)
//         {
//             ac.display_account();
//             cout << "\nTO DEPOSIT AMOUNT " << endl;
//             cout << "Enter the amount to be deposited: ";
//             cin >> amt;

//             ac.deposit(amt);

//             // Update the account object in the file
//             int currentPosition = File.tellg(); // Get the current position of the file pointer
//             File.seekp(currentPosition - static_cast<int>(sizeof(Account))); // Move the file pointer back to the beginning of the record
//             File.write(reinterpret_cast<char *>(&ac), sizeof(Account)); // Write the modified account object to the file
//             cout << "Record Updated" << endl;
//             found = true;
//             break; // Exit the loop once the account is found and updated
//         }
//     }
//     File.close();
//     if (!found)

//     {
//         cout << "Record not Found" << endl;
//     }
// }

// void withdrawAmount(long accountNumber)
// {
//     int amt;
//     bool found = false;
//     Account ac;
//     fstream File;
//     File.open("account.data", ios::binary | ios::in | ios::out);
//     if (!File)
//     {
//         cout << "File could not be open !! Press any Key...";
//         return;
//     }
//     while (File.read(reinterpret_cast<char *>(&ac), sizeof(Account)))
//     {
//         if (ac.getaccountNo() == accountNumber)
//         {
//             ac.display_account();
//             cout << "\nTO WITHDRAW AMOUNT " << endl;
//             cout << "Enter the amount to be withdrawn: ";
//             cin >> amt;
//             if (amt > ac.getbalance())
//             {
//                 cout << "Insufficient balance" << endl;
//                 break;
//             }
//             ac.withdraw(amt);

//             // Update the account object in the file
//             int currentPosition = File.tellg(); // Get the current position of the file pointer
//             File.seekp(currentPosition - static_cast<int>(sizeof(Account))); // Move the file pointer back to the beginning of the record
//             File.write(reinterpret_cast<char *>(&ac), sizeof(Account)); // Write the modified account object to the file
//             cout << "Record Updated" << endl;
//             found = true;
//             break; // Exit the loop once the account is found and updated
//         }
//     }
//     File.close();
//     if (!found)
//     {
//         cout << "Record not Found" << endl;
//     }
// }


// void displayBalance(long accountNumber)
// {
//     bool found = false;
//     Account ac;
//     ifstream inFile;
//     inFile.open("account.data", ios::binary);
//     if (!inFile)
//     {
//         cout << "File could not be found!! \nPress any Key...";
//         return;
//     }
//     cout << "\nBALANCE DETAILS" << endl;
//     while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(Account)))
//     {
//         if (ac.getaccountNo() == accountNumber)
//         {
//             cout << "Account Number: " << ac.getaccountNo() << endl;
//             cout << "First Name: " << ac.getfirstName() << endl;
//             cout << "Last Name: " << ac.getlastName() << endl;
//             cout << "Balance: " << ac.getbalance() << endl;
//             found = true;
//             break; // Exit the loop once the account is found and displayed
//         }
//     }
//     inFile.close();
//     if (!found)
//     {
//         cout << "\nAccount number does not exist" << endl;
//     }
// }





// void deleteAccount()
// {
//    Account ac;
//    long accountNumber;
//    cout << "Enter Account Number to delete: ";
//    cin >> accountNumber;

//    ifstream inFile;
//    ofstream outFile;
//    inFile.open("account.data", ios::binary);
//    if (!inFile)
//    {
//       cout << "\n File could not be found!!! \n Press any key..." << endl;
//       return;
//    }
//    outFile.open("Temp.data", ios::binary);
//    while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(Account)))
//    {
//       if (ac.getaccountNo() != accountNumber)
//       {
//          outFile.write(reinterpret_cast<char *>(&ac), sizeof(Account));
//       }
//    }
//    inFile.close();
//    outFile.close();
//    remove("account.data");
//    rename("Temp.data", "account.data");
//    cout << "\n ACCOUNT DELETED" << endl;
// }

// void listAllaccounts()
// {
//    Account ac;
//    ifstream inFile;
//    inFile.open("account.data", ios::binary);
//    if (!inFile)
//    {
//       cout << "The file could not be found!!! \n Press any key" << endl;
//       return;
//    }
//    cout << "\n\n\t\tACCOUNT HOLDER LIST\n\n";
//    cout << "====================================================\n";
//    cout << "A/c no.      NAME             Balance\n";
//    cout << "====================================================\n";
//    while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(Account)))
//    {
//       ac.report();
//    }
//    inFile.close();
// }

// void displayAccount(long accountNumber)
// {
//    Account ac;
//    bool found = false;
//    ifstream inFile;
//    inFile.open("account.data", ios::binary);
//    if (!inFile)
//    {
//       cout << "File could not be open !!\n Press any Key...";
//       return;
//    }
//    cout << "\nBALANCE DETAILS\n";
//    while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(Account)))
//    {
//       if (ac.getaccountNo() == accountNumber)
//       {
//          ac.display_account();
//          found = true;
//          break;
//       }
//    }
//    inFile.close();
//    if (!found)
//       cout << "\nAccount number does not exist" << endl;
// }

// int main()
// {
//    char ch;
//    long accountNumber;
//    do
//    {
//       cout << "MAIN MENU" << endl;
//       cout << "1. CREATE ACCOUNT" << endl;
//       cout << "2. DEPOSIT AMOUNT" << endl;
//       cout << "3. WITHDRAW AMOUNT" << endl;
//       cout << "4. DISPLAY BALANCE" << endl;
//       cout << "5. DISPLAY ALL ACCOUNTS" << endl;
//       cout << "6. DELETE AN ACCOUNT" << endl;
//       cout << "7. EXIT" << endl;

//       cout << "Enter your choice: ";
//       cin >> ch;

//       switch (ch)
//       {
//       case '1':
//          write_account();
//          break;
//       case '2':
//          cout << "Enter Account Number: ";
//          cin >> accountNumber;
//          depositAmount(accountNumber);
//          break;
//       case '3':
//          cout << "Enter Account Number: ";
//          cin >> accountNumber;
//          withdrawAmount(accountNumber);
//          break;
//       case '4':
//          cout << "Enter Account Number: ";
//          cin >> accountNumber;
//          displayBalance(accountNumber);
//          break;
//       case '5':
//          listAllaccounts();
//          break;
//       case '6':
//          deleteAccount();
//          break;
//       case '7':
//          cout << "THANK YOU FOR USING THE BANK MANAGEMENT SYSTEM" << endl;
//          break;
//       default:
//          cout << "Invalid choice! Please enter a valid option." << endl;
//          break;
//       }
//    } while (ch != '7');
//    return 0;
// }


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

class Account
{
private:
    long accountNo;
    string firstName;
    string lastName;
    long double balance;

public:
    Account() {}
    Account(string firstName, string lastName, long accountNo, long double balance)
    {
        this->firstName = firstName;
        this->lastName = lastName;
        this->accountNo = accountNo;
        this->balance = balance;
    }

    string getfirstName() const
    {
        return firstName;
    }
    string getlastName() const
    {
        return lastName;
    }
    void setfirstName(string firstName)
    {
        this->firstName = firstName;
    }
    void setlastName(string lastName)
    {
        this->lastName = lastName;
    }

    long getaccountNo() const
    {
        return accountNo;
    }

    void setaccountNo(long accountNo)
    {
        this->accountNo = accountNo;
    }

    long double getbalance() const
    {
        return balance;
    }

    void setbalance(long double balance)
    {
        this->balance = balance;
    }

    void report() const
    {
        cout << accountNo << setw(10) << " " << firstName << " " << lastName << setw(10) << " " << setw(6) << balance << endl;
    }
    void create_account();
    void display_account() const;
    void deposit(long amount);
    void withdraw(long amount);
    friend void write_account();
    friend void depositAmount(long accountNumber);
    friend void withdrawAmount(long accountNumber);
    friend void listAllaccounts();
    friend void deleteAccount();
    friend void displayBalance(long accountNumber);
};

void Account::create_account()
{
    cout << "Enter the Account Number: ";
    cin >> accountNo;
    cout << "Enter your First Name: ";
    cin >> firstName;
    cout << "Enter your Last Name: ";
    cin >> lastName;
    cout << "Enter your initial Balance: ";
    cin >> balance;
    cout << "YOUR ACCOUNT HAS BEEN CREATED..." << endl;
}

void Account::display_account() const
{
    cout << "Account Number: " << accountNo << endl;
    cout << "First Name: " << firstName << endl;
    cout << "Last Name: " << lastName << endl;
    cout << "Balance Amount : " << balance << endl;
}

void Account::deposit(long amount)
{
    balance += amount;
}

void Account::withdraw(long amount)
{
    balance -= amount;
}

void write_account()
{
    Account ac;
    ofstream outFile;
    outFile.open("account.txt", ios::app);
    if (!outFile)
    {
        cout << "Error opening file for writing!" << endl;
        return;
    }
    ac.create_account();
    outFile << ac.getaccountNo() << " " << ac.getfirstName() << " " << ac.getlastName() << " " << ac.getbalance() << endl;
    outFile.close();
}

void depositAmount(long accountNumber)
{
    int amt;
    bool found = false;
    Account ac;
    fstream File;
    File.open("account.txt", ios::in | ios::out);
    if (!File)
    {
        cout << "Error opening file for deposit!" << endl;
        return;
    }
    while (File >> ac.accountNo >> ac.firstName >> ac.lastName >> ac.balance)
    {
        if (ac.getaccountNo() == accountNumber)
        {
            ac.display_account();
            cout << "\nTO DEPOSIT AMOUNT " << endl;
            cout << "Enter the amount to be deposited: ";
            cin >> amt;

            ac.deposit(amt);

            int currentPosition = File.tellg(); 
            File.seekp(currentPosition - static_cast<int>(sizeof(Account))); 
            File << ac.getaccountNo() << " " << ac.getfirstName() << " " << ac.getlastName() << " " << ac.getbalance() << endl; 
            cout << "Record Updated" << endl;
            found = true;
            break; 
        }
    }
    File.close();
    if (!found)
    {
        cout << "Record not Found" << endl;
    }
}

void withdrawAmount(long accountNumber)
{
    int amt;
    bool found = false;
    Account ac;
    fstream File;
    File.open("account.txt", ios::in | ios::out);
    if (!File)
    {
        cout << "Error opening file for withdrawal!" << endl;
        return;
    }
    while (File >> ac.accountNo >> ac.firstName >> ac.lastName >> ac.balance )
    {
        if (ac.getaccountNo() == accountNumber)
        {
            ac.display_account();
            cout << "\nTO WITHDRAW AMOUNT " << endl;
            cout << "Enter the amount to be withdrawn: ";
            cin >> amt;
            if (amt > ac.getbalance())
            {
                cout << "Insufficient balance" << endl;
                break;
            }
            ac.withdraw(amt);

            int currentPosition = File.tellg(); 
            File.seekp(currentPosition - static_cast<int>(sizeof(Account))); 
            File << ac.getaccountNo() << " " << ac.getfirstName() << " " << ac.getlastName() << " " << ac.getbalance() << endl; 
            cout << "Record Updated" << endl;
            found = true;
            break; 
        }
    }
    File.close();
    if (!found)
    {
        cout << "Record not Found" << endl;
    }
}

void displayBalance(long accountNumber)
{
    bool found = false;
    Account ac;
    ifstream inFile;
    inFile.open("account.txt");
    if (!inFile)
    {
        cout << "Error opening file for balance check!" << endl;
        return;
    }
    while (inFile >> ac.accountNo>> ac.firstName >> ac.lastName >> ac.balance)
    {
        if (ac.getaccountNo() == accountNumber)
        {
            cout << "\nBALANCE DETAILS" << endl;
            ac.display_account();
            found = true;
            break;
        }
    }
    inFile.close();
    if (!found)
    {
        cout << "\nAccount number does not exist" << endl;
    }
}

void deleteAccount()
{
    long accountNumber;
    cout << "Enter Account Number to delete: ";
    cin >> accountNumber;

    ifstream inFile;
    ofstream outFile;
    inFile.open("account.txt");
    outFile.open("temp.txt");
    Account ac;
    bool found = false;
    while (inFile >> ac.accountNo >> ac.firstName >> ac.lastName >> ac.balance)
    {
        if (ac.getaccountNo() != accountNumber)
        {
            outFile << ac.accountNo << " " << ac.firstName << " " << ac.lastName << " " << ac.balance << endl;
        }
        else
        {
            found = true;
        }
    }
    inFile.close();
    outFile.close();

    if (found)
    {
        remove("account.txt");
        rename("temp.txt", "account.txt");
        cout << "\n ACCOUNT DELETED" << endl;
    }
    else
    {
        cout << "\n Account number not found. Deletion failed." << endl;
    }
}

void listAllaccounts()
{
    Account ac;
    ifstream inFile;
    inFile.open("account.txt");
    if (!inFile)
    {
        cout << "Error opening file for listing accounts!" << endl;
        return;
    }
    cout << "\n\n\t\tACCOUNT HOLDER LIST\n\n";
    cout << "====================================================\n";
    cout << "A/c no.      NAME             Balance\n";
    cout << "====================================================\n";
    while (inFile >> ac.accountNo >> ac.firstName >> ac.lastName >> ac.balance)
    {
        ac.report();
    }
    inFile.close();
}

int main()
{
    char ch;
    long accountNumber;
    do
    {
        cout << "MAIN MENU" << endl;
        cout << "1. CREATE ACCOUNT" << endl;
        cout << "2. DEPOSIT AMOUNT" << endl;
        cout << "3. WITHDRAW AMOUNT" << endl;
        cout << "4. DISPLAY BALANCE" << endl;
        cout << "5. DISPLAY ALL ACCOUNTS" << endl;
        cout << "6. DELETE AN ACCOUNT" << endl;
        cout << "7. EXIT" << endl;

        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case '1':
            write_account();
            break;
        case '2':
            cout << "Enter Account Number: ";
            cin >> accountNumber;
            depositAmount(accountNumber);
            break;
        case '3':
            cout << "Enter Account Number: ";
            cin >> accountNumber;
            withdrawAmount(accountNumber);
            break;
        case '4':
            cout << "Enter Account Number: ";
            cin >> accountNumber;
            displayBalance(accountNumber);
            break;
        case '5':
            listAllaccounts();
            break;
        case '6':
            deleteAccount();
            break;
        case '7':
            cout << "THANK YOU FOR USING THE BANK MANAGEMENT SYSTEM" << endl;
            break;
        default:
            cout << "Invalid choice! Please enter a valid option." << endl;
            break;
        }
    } while (ch != '7');
    return 0;
}

# BANK MANAGEMENT SYSTEM

## Bank Management System in C++: 

This project provides a user-friendly bank management system implemented in C++. It empowers users to manage their accounts efficiently and conveniently, offering a range of essential functionalities.

**Key Features:**

* **Account Creation:** Establish new accounts effortlessly by providing your first and last name, along with your initial deposit. The system will assign a unique account number for easy identification.
* **Deposit Funds:** Enhance your account balance by making deposits. Simply enter your account number and the amount you wish to deposit. The system seamlessly updates your account information for accurate record-keeping.
* **Withdrawal Flexibility:** Need to access your funds? The system facilitates withdrawals. Enter your account number and the withdrawal amount. However, the system prioritizes responsible banking by verifying sufficient balance before allowing withdrawals, preventing overdrafts.
* **Balance Inquiry:** Stay informed about your account status. Enter your account number, and the system promptly displays your current balance, providing transparency and control over your finances.
* **Comprehensive Account Listing:** Gain an overview of all accounts within the system. This feature generates a report listing account numbers, names, and corresponding balances, offering a valuable tool for administrative purposes or personal record-keeping.
* **Account Deletion:**  Closing an account is straightforward. Enter the account number you wish to delete, and the system removes it from the database, streamlining account management.

**Implementation Details:**

* The system leverages a text file named "account.txt" to store account information persistently.
* Each line within the text file represents an individual account, containing the account number, first name, last name, and current balance, separated by spaces for clear organization.
* The program utilizes well-defined functions to handle specific tasks. These functions include `create_account`, `depositAmount`, `withdrawAmount`, `displayBalance`, `listAllaccounts`, and `deleteAccount`, promoting modularity and code reusability.

**Getting Started:**

1. Compile the C++ code using a suitable C++ compiler.
2. Execute the generated program file.
3. The program presents a user-friendly menu outlining various options for managing bank accounts.
4. Select the desired functionality by entering the corresponding number and follow the on-screen instructions for a smooth user experience.

**Additional Considerations:**

* This implementation serves as a foundation for a bank management system. It can be further enhanced to incorporate features like:
    * User authentication and login mechanisms for enhanced security.
    * Transaction history for comprehensive record-keeping.
    * Interest calculations for savings accounts to promote financial growth.
* Remember, this program prioritizes basic functionalities for educational purposes. Real-world banking systems typically involve more complex security measures and regulations.

**Embrace Efficient Banking Management:**

This C++ bank management system empowers you to manage your finances effectively. With its intuitive interface and core functionalities, it streamlines account creation, deposits, withdrawals, balance inquiries, and account management – all within a user-friendly environment.


# ATM Simple System

A simple ATM simulation system written in C++. This project demonstrates basic banking operations such as account management, deposits, withdrawals, transfers, and password changes, with a minimal Windows GUI for user interaction.

## Features
- Admin and Customer modes
- Add, delete, and view accounts (Admin)
- Deposit, withdraw, transfer funds (Customer)
- Change account password
- View account balance
- Transaction logging
- Minimal GUI using Windows message boxes and dialogs

## Requirements
- Windows OS
- C++ compiler (e.g., MinGW, MSVC)

## Building
1. Open a terminal in the project directory.
2. Compile all source files:
   ```sh
    g++ main.cpp ATM/ATM.cpp Interface/UserInterface.cpp Account/Account.cpp Account/AdminMode.cpp Account/Customer.cpp Account/CustomerMode.cpp Trans/Transaction.cpp -o atm.exe
   ```
   The `-mwindows` flag is required to build a Windows GUI application.

## Running
- Double-click `atm.exe` or run from terminal:
  ```sh
  .\atm.exe
  ```

## Usage
- On launch, a main menu appears with Admin and Customer modes.
- Use dropdowns and message boxes for all interactions.
- Admin password is set to `admin` by default.
- Follow on-screen instructions for all operations.

## File Structure
- `main.cpp` - Entry point
- `ATM.cpp/h` - Core ATM logic
- `Account.cpp/h` - Account base class
- `Customer.cpp/h` - Customer account logic
- `AdminMode.cpp/h` - Admin operations
- `CustomerMode.cpp/h` - Customer operations
- `Transaction.cpp/h` - Transaction logging
- `UserInterface.cpp/h` - User interaction (GUI)

## License
See [LICENSE](LICENSE) for details.

# Banking-management-system

this is my first git Repository
Features of the Banking Management System
1. Account Creation

Allows the user to create a new bank account.

Stores account number, name, and initial balance in bank.txt.

2. Deposit Money

User can deposit money into an existing account.

Reads all data from the file, updates the balance, and rewrites the file.

 
Uniqueness of Your Banking Management System
1. Persistent Data Storage

The system uses actual file handling to store accounts permanently.

Data remains intact even after the program closes.

2. Real-Time File Update Mechanism

Uses the read–modify–write approach:

Reads old data from bank.txt

Makes updates

Writes new data to temp.txt

Replaces old file using rename()

This resembles how real banking software updates records safely.

output
![output](https://github.com/user-attachments/assets/3bcfda19-f00a-455d-8702-243f254356d5)

<img width="673" height="447" alt="Screenshot 2025-11-26 111318" src="https://github.com/user-attachments/assets/c1784e2d-6d4d-49d0-a322-5804b7a3083e" />






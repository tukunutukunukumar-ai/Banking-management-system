#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Account {
    int acc_no;
    char name[50];
    float balance;
};

void createAccount();
void deposit();
void withdraw();
void checkBalance();
void displayAll();

int main() {
    int choice;

    while (1) {
        printf("\n=========== BANKING MANAGEMENT SYSTEM ===========\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Display All Accounts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createAccount(); break;
            case 2: deposit(); break;
            case 3: withdraw(); break;
            case 4: checkBalance(); break;
            case 5: displayAll(); break;
            case 6: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}

void createAccount() {
    struct Account acc;
    FILE *fp = fopen("bank.txt", "a");

    if (!fp) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Account Number: ");
    scanf("%d", &acc.acc_no);
    printf("Enter Name: ");
    scanf("%s", acc.name);
    printf("Enter Initial Deposit: ");
    scanf("%f", &acc.balance);

    fprintf(fp, "%d %s %.2f\n", acc.acc_no, acc.name, acc.balance);
    fclose(fp);

    printf("Account created successfully!\n");
}

void deposit() {
    struct Account acc;
    int acc_no;
    float amount;
    int found = 0;

    printf("Enter Account Number: ");
    scanf("%d", &acc_no);

    FILE *fp = fopen("bank.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    while (fscanf(fp, "%d %s %f", &acc.acc_no, acc.name, &acc.balance) != EOF) {
        if (acc.acc_no == acc_no) {
            printf("Enter Amount to Deposit: ");
            scanf("%f", &amount);
            acc.balance += amount;
            found = 1;
        }
        fprintf(temp, "%d %s %.2f\n", acc.acc_no, acc.name, acc.balance);
    }

    fclose(fp);
    fclose(temp);
    remove("bank.txt");
    rename("temp.txt", "bank.txt");

    if (found)
        printf("Amount deposited successfully!\n");
    else
        printf("Account not found!\n");
}

void withdraw() {
    struct Account acc;
    int acc_no;
    float amount;
    int found = 0;

    printf("Enter Account Number: ");
    scanf("%d", &acc_no);

    FILE *fp = fopen("bank.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    while (fscanf(fp, "%d %s %f", &acc.acc_no, acc.name, &acc.balance) != EOF) {
        if (acc.acc_no == acc_no) {
            printf("Enter Amount to Withdraw: ");
            scanf("%f", &amount);

            if (acc.balance >= amount) {
                acc.balance -= amount;
                printf("Withdrawal successful!\n");
            } else {
                printf("Insufficient balance!\n");
            }
            found = 1;
        }
        fprintf(temp, "%d %s %.2f\n", acc.acc_no, acc.name, acc.balance);
    }

    fclose(fp);
    fclose(temp);
    remove("bank.txt");
    rename("temp.txt", "bank.txt");

    if (!found)
        printf("Account not found!\n");
}

void checkBalance() {
    struct Account acc;
    int acc_no;
    int found = 0;

    printf("Enter Account Number: ");
    scanf("%d", &acc_no);

    FILE *fp = fopen("bank.txt", "r");

    while (fscanf(fp, "%d %s %f", &acc.acc_no, acc.name, &acc.balance) != EOF) {
        if (acc.acc_no == acc_no) {
            printf("\nAccount Number: %d\nName: %s\nBalance: %.2f\n",
                   acc.acc_no, acc.name, acc.balance);
            found = 1;
            break;
        }
    }
    fclose(fp);

    if (!found)
        printf("Account not found!\n");
}

void displayAll() {
    struct Account acc;
    FILE *fp = fopen("bank.txt", "r");

    printf("\n---- All Accounts ----\n");

    while (fscanf(fp, "%d %s %f", &acc.acc_no, acc.name, &acc.balance) != EOF) {
        printf("Acc No: %d, Name: %s, Balance: %.2f\n",
               acc.acc_no, acc.name, acc.balance);
    }

    fclose(fp);
}
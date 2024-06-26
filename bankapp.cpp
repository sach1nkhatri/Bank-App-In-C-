//A bank in Kathmandu wants an application that can store customers and view all 
//customer information. The bank has two types of accounts.
//1. Saving account
//2. Salary account
//ite a Menu-driven program in C where users will have options to
//1. Add customer.
//2. View customers.
//3. Deposit amount.
//4. Withdraw amount.
//5. Check balance.
//6. Search customers using the Account number.
//7. Exit program.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ACCOUNTS 100

struct account {
    char firstName[50];
    char lastName[50];
    int accno;
    float balance;
    char acctype[20];
};

struct account accounts[MAX_ACCOUNTS];
int num_accounts = 0;

int generate_random_accno() {
    srand(time(NULL)); 
    int accno = rand() % 9000 + 1000; 
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].accno == accno) { 
            accno = generate_random_accno();
            break;
        }
    }
    return accno;
}

void create_account() {
    struct account new_account;
    printf("Enter your first name: ");
    scanf("%s", new_account.firstName);
    printf("Enter your last name: ");
    scanf("%s", new_account.lastName);
    new_account.accno = generate_random_accno();
    printf("Your account number is: %d\n", new_account.accno);
    printf("Enter your account type: ");
    scanf("%s", new_account.acctype);
    printf("Enter opening balance: $ ");
    scanf("%f", &new_account.balance);
    accounts[num_accounts] = new_account;
    num_accounts++;
    printf("Account created successfully!\n");
}

void deposit() {
    int accno;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accno);
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].accno == accno) {
            printf("Enter deposit amount: $");
            scanf("%f", &amount);
            accounts[i].balance += amount;
            printf("Deposit of %.2f successful!\n", amount);
            return;
        }
    }
    printf("Account not found!\n");
}

void withdraw() {
    int accno;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accno);
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].accno == accno) {
            printf("Enter withdrawal amount: ");
            scanf("%f", &amount);
            if (amount > accounts[i].balance) {
                printf("Insufficient balance! Enter valid amount!\n");
                return;
            }
            accounts[i].balance -= amount;
            printf("Withdrawal of %.2f successful!\n", amount);
            return;
        }
    }
    printf("Account not found!\n");
}

void display() {
    int accno;
    printf("Enter account number: ");
    scanf("%d", &accno);
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].accno == accno) {
            printf("Account name: %s %s\n", accounts[i].firstName, accounts[i].lastName);
            printf("Account number: %d\n", accounts[i].accno);
            printf("Account type: %s\n", accounts[i].acctype);
            printf("Account balance: $%.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}

int main() {
    int choice;
    while (1) {
        printf("\nEnter your choice:\n");
        printf("1. Create account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. View account details\n");
        printf("5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                create_account();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
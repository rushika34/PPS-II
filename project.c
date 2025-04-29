#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_ACCOUNTS 100
#define MAX_NAME_LEN 50
#define MAX_TYPE_LEN 20
#define MAX_USERNAME_LEN 30
#define MAX_ACCNO_LEN 20

typedef struct {
    char acno[MAX_ACCNO_LEN];
    char name[MAX_NAME_LEN];
    float money;
    char type[MAX_TYPE_LEN];
    int pin;
    char username[MAX_USERNAME_LEN];
    float total_trans;
    float total_dep;
    float total_with;
} BankAccount;

const char m_id[] = "MANAGER100";
const char m_user_name[] = "manager_100";
long long number = 100000000001;
int acc_count = 0;

// Function prototypes
int pin_digit(int pin_no);
void new_acc(BankAccount *account);
void modify_acc(BankAccount *account);
void acc_detail(BankAccount *account);
void delete_acc(BankAccount *account);
void check_balance(BankAccount *account);
void deposit(BankAccount *account);
void withdraw(BankAccount *account);
void total_tra_of_day(BankAccount *account);
void transfer_money(BankAccount *receiver, BankAccount *sender);
int find_acc(BankAccount accounts[], char *acc_no);
int find_username1(BankAccount accounts[], char *username);
void clear_input_buffer();
void clear_screen();
void pause_screen();

int main() {
    int num;
    BankAccount accounts[MAX_ACCOUNTS];
    
    do {
        clear_screen();
        printf("\n\n\t\t\t*****************************************");
        printf("\n\t\t\t          BANK MANAGEMENT SYSTEM");
        printf("\n\t\t\t*****************************************\n");
        printf("\n\n\tWHO ARE YOU?\n");
        printf("\n\t1. CUSTOMER \n");
        printf("\n\t2. MANAGER \n");
        printf("\n\t3. EXIT \n");
        printf("\n\tSELECT YOUR OPTION (1-3) : ");
        scanf("%d", &num);
        clear_input_buffer();

        switch(num) {
            case 1: {
                int c_num;
                do {
                    clear_screen();
                    printf("\n\n\t\t\t##################################");
                    printf("\n\t\t\t         CUSTOMER PORTAL");
                    printf("\n\t\t\t##################################\n");
                    printf("\n\t1. CREATE NEW ACCOUNT \n");
                    printf("\n\t2. LOG-IN AN ACCOUNT \n");
                    printf("\n\t3. CLOSE AN ACCOUNT \n");
                    printf("\n\t4. EXIT \n");
                    printf("\n\tSELECT YOUR OPTION (1-4) : ");
                    scanf("%d", &c_num);
                    clear_input_buffer();

                    switch(c_num) {
                        case 1: {
                            if (acc_count >= MAX_ACCOUNTS) {
                                printf("\n\tMaximum number of accounts reached!\n");
                                pause_screen();
                                break;
                            }
                            
                            new_acc(&accounts[acc_count]);
                            printf("\n\tENTER USERNAME : ");
                            char username[MAX_USERNAME_LEN];
                            fgets(username, MAX_USERNAME_LEN, stdin);
                            username[strcspn(username, "\n")] = '\0';
                            
                            int x = find_username1(accounts, username);
                            while(x != -1) {
                                printf("\n\tUSERNAME ALREADY EXISTS.. \n");
                                printf("\n\tENTER USERNAME : ");
                                fgets(username, MAX_USERNAME_LEN, stdin);
                                username[strcspn(username, "\n")] = '\0';
                                x = find_username1(accounts, username);
                            }
                            
                            strcpy(accounts[acc_count].username, username);
                            printf("\n\tENTER PIN NUMBER (MUST BE 4 DIGITS ONLY): ");
                            int pin_no;
                            scanf("%d", &pin_no);
                            clear_input_buffer();
                            int pin_count = pin_digit(pin_no);
                            
                            while(pin_count != 4) {
                                printf("\n\tENTER ONLY 4 DIGIT PIN!!\n");
                                printf("\n\tENTER PIN NUMBER AGAIN : ");
                                scanf("%d", &pin_no);
                                clear_input_buffer();
                                pin_count = pin_digit(pin_no);
                            }
                            
                            accounts[acc_count].pin = pin_no;
                            printf("\n\tACCOUNT CREATED SUCCESSFULLY.\n");
                            printf("\n\tYOUR ACCOUNT NUMBER IS : %s", accounts[acc_count].acno);
                            acc_count++;
                            pause_screen();
                            break;
                        }
                        
                        case 2: {
                            printf("\n\tENTER YOUR USERNAME :  ");
                            char username[MAX_USERNAME_LEN];
                            fgets(username, MAX_USERNAME_LEN, stdin);
                            username[strcspn(username, "\n")] = '\0';
                            
                            int x = find_username1(accounts, username);
                            if(x == -1) {
                                printf("\n\tCREATE YOUR ACCOUNT FIRST!!\n");
                                pause_screen();
                                break;
                            }
                            
                            printf("\n\tENTER YOUR PIN (MUST BE 4 DIGITS ONLY): ");
                            int pin_no;
                            scanf("%d", &pin_no);
                            clear_input_buffer();
                            int pin_count = pin_digit(pin_no);
                            
                            if(pin_count != 4) {
                                printf("\n\tENTER ONLY 4 DIGIT PIN!!\n");
                                while(pin_count != 4) {
                                    printf("\n\tENTER YOUR PIN (MUST BE 4 DIGITS ONLY): ");
                                    scanf("%d", &pin_no);
                                    clear_input_buffer();
                                    pin_count = pin_digit(pin_no);
                                }
                            }
                            
                            if(pin_no != accounts[x].pin) {
                                printf("\n\t PIN IS INVALID!!\n");
                                pause_screen();
                                break;
                            }
                            
                            int n;
                            do {
                                clear_screen();
                                printf("\n\t\t\t=========================================");
                                printf("\n\t\t\t          CUSTOMER PORTAL");
                                printf("\n\t\t\t=========================================\n");
                                printf("\n\t1. MODIFY AN ACCOUNT \n");
                                printf("\n\t2. DEPOSIT AMOUNT \n");
                                printf("\n\t3. WITHDRAW AMOUNT \n");
                                printf("\n\t4. CHECK BALANCE OF ACCOUNT \n");
                                printf("\n\t5. ACCOUNT DETAILS \n");
                                printf("\n\t6. CHECK YOUR WHOLE DAY TRANSACTION \n");
                                printf("\n\t7. DO YOU WANT TO TRANSFER MONEY ?\n");
                                printf("\n\t8. EXIT \n");
                                printf("\n\tSELECT YOUR OPTION (1-8) : ");
                                scanf("%d", &n);
                                clear_input_buffer();
                                
                                switch(n) {
                                    case 1:
                                        modify_acc(&accounts[x]);
                                        pause_screen();
                                        break;
                                        
                                    case 2:
                                        deposit(&accounts[x]);
                                        pause_screen();
                                        break;
                                        
                                    case 3:
                                        withdraw(&accounts[x]);
                                        pause_screen();
                                        break;
                                        
                                    case 4:
                                        check_balance(&accounts[x]);
                                        pause_screen();
                                        break;
                                        
                                    case 5:
                                        acc_detail(&accounts[x]);
                                        pause_screen();
                                        break;
                                        
                                    case 6:
                                        total_tra_of_day(&accounts[x]);
                                        pause_screen();
                                        break;
                                        
                                    case 7: {
                                        printf("\n\tENTER RECEIVER ACCOUNT NUMBER : ");
                                        char rec_acc[MAX_ACCNO_LEN];
                                        fgets(rec_acc, MAX_ACCNO_LEN, stdin);
                                        rec_acc[strcspn(rec_acc, "\n")] = '\0';
                                        int rec_index = find_acc(accounts, rec_acc);
                                        
                                        if(rec_index == -1) {
                                            printf("\n\tACCOUNT NOT FOUND!!\n");
                                        } else if(rec_index == x) {
                                            printf("\n\tENTER ANOTHER ACCOUNT!!\n");
                                        } else {
                                            transfer_money(&accounts[rec_index], &accounts[x]);
                                        }
                                        pause_screen();
                                        break;
                                    }
                                    
                                    default:
                                        if(n != 8) {
                                            printf("\n\tOPTION IS INVALID PLEASE TRY AGAIN!!\n");
                                            pause_screen();
                                        }
                                        break;
                                }
                            } while(n != 8);
                            break;
                        }
                        
                        case 3: {
                            printf("\n\tENTER YOUR USERNAME :  ");
                            char username[MAX_USERNAME_LEN];
                            fgets(username, MAX_USERNAME_LEN, stdin);
                            username[strcspn(username, "\n")] = '\0';
                            int x = find_username1(accounts, username);
                            
                            if(x == -1) {
                                printf("\n\tPLEASE ENTER VALID USERNAME!!\n");
                                pause_screen();
                                break;
                            }
                            
                            printf("\n\tENTER YOUR PIN (MUST BE 4 DIGITS ONLY): ");
                            int pin_no;
                            scanf("%d", &pin_no);
                            clear_input_buffer();
                            int pin_count = pin_digit(pin_no);
                            
                            if(pin_count != 4) {
                                printf("\n\tENTER ONLY 4 DIGIT PIN!!\n");
                                while(pin_count != 4) {
                                    printf("\n\tENTER YOUR PIN (MUST BE 4 DIGITS ONLY): ");
                                    scanf("%d", &pin_no);
                                    clear_input_buffer();
                                    pin_count = pin_digit(pin_no);
                                }
                            }
                            
                            if(pin_no != accounts[x].pin) {
                                printf("\n\t PIN IS INVALID!!\n");
                                pause_screen();
                                break;
                            }
                            
                            delete_acc(&accounts[x]);
                            pause_screen();
                            break;
                        }
                        
                        default:
                            if(c_num != 4) {
                                printf("\n\tOPTION IS INVALID PLEASE TRY AGAIN!!\n");
                                pause_screen();
                            }
                            break;
                    }
                } while(c_num != 4);
                break;
            }
            
            case 2: {
                printf("\n\tENTER YOUR USERNAME : ");
                char manager_name[MAX_USERNAME_LEN];
                fgets(manager_name, MAX_USERNAME_LEN, stdin);
                manager_name[strcspn(manager_name, "\n")] = '\0';
                
                if(strcmp(manager_name, m_user_name) != 0) {
                    printf("\n\tINVALID USERNAME! \n");
                    pause_screen();
                    break;
                }
                
                printf("\n\tENTER MANAGER ID : ");
                char manager_id[20];
                fgets(manager_id, 20, stdin);
                manager_id[strcspn(manager_id, "\n")] = '\0';
                
                if(strcmp(manager_id, m_id) != 0) {
                    printf("\n\tYOUR ID IS INVALID \n");
                    pause_screen();
                    break;
                }
                
                printf("\n\tYOU ARE ENTERED SUCCESSFULLY!\n");
                pause_screen();
                int m_num;
                
                do {
                    clear_screen();
                    printf("\n\n\t\t\t##################################");
                    printf("\n\t\t\t         MANAGER PORTAL");
                    printf("\n\t\t\t##################################\n");
                    printf("\n\t1. CHECK TOTAL TRANSACTION OF TODAY\n");
                    printf("\n\t2. SEE USERS DETAILS\n");
                    printf("\n\t3. EXIT \n");
                    printf("\n\tSELECT YOUR OPTION (1-3) : ");
                    scanf("%d", &m_num);
                    clear_input_buffer();
                    
                    switch(m_num) {
                        case 1:
                            printf("\n\tBANK TOTAL TRANSACTION OF DAY \n\n");
                            printf("%30s%20s%20s\n", "NAME OF ACCOUNT HOLDER", "METHOD", "AMOUNT");
                            printf("----------------------------------------------------------------------\n");
                            for(int i = 0; i < acc_count; i++) {
                                printf("%30s%20s%20.2f\n", accounts[i].name, "TRANSACTION", accounts[i].total_trans);
                            }
                            printf("----------------------------------------------------------------------\n\n");
                            printf("%30s%20s%20s\n", "NAME OF ACCOUNT HOLDER", "METHOD", "AMOUNT");
                            printf("----------------------------------------------------------------------\n");
                            for(int i = 0; i < acc_count; i++) {
                                printf("%30s%20s%20.2f\n", accounts[i].name, "WITHDRAW", accounts[i].total_with);
                            }
                            printf("----------------------------------------------------------------------\n\n");
                            printf("%30s%20s%20s\n", "NAME OF ACCOUNT HOLDER", "METHOD", "AMOUNT");
                            printf("----------------------------------------------------------------------\n");
                            for(int i = 0; i < acc_count; i++) {
                                printf("%30s%20s%20.2f\n", accounts[i].name, "DEPOSIT", accounts[i].total_dep);
                            }
                            printf("----------------------------------------------------------------------\n\n");
                            pause_screen();
                            break;
                            
                        case 2:
                            printf("\n\t%20s%30s%30s%20s\n", "ACCOUNT NO.", "NAME OF ACCOUNT HOLDER", "ACCOUNT BALANCE", "ACCOUNT TYPE");
                            printf("\n\t----------------------------------------------------------------------------------------------------\n");
                            for(int i = 0; i < acc_count; i++) {
                                printf("\n\t%20s%30s%30.2f%20s\n", accounts[i].acno, accounts[i].name, accounts[i].money, accounts[i].type);
                            }
                            pause_screen();
                            break;
                            
                        default:
                            if(m_num != 3) {
                                printf("\n\tOPTION IS INVALID PLEASE TRY AGAIN!!\n");
                                pause_screen();
                            }
                            break;
                    }
                } while(m_num != 3);
                break;
            }
            
            default:
                if(num != 3) {
                    printf("\n\tOPTION IS INVALID PLEASE TRY AGAIN!!\n");
                    pause_screen();
                }
                break;
        }
    } while(num != 3);
    
    return 0;
}

// Utility functions
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void clear_screen() {
    system("cls");
}

void pause_screen() {
    printf("\nPress Enter to continue...");
    clear_input_buffer();
}

// Bank account functions
int pin_digit(int pin_no) {
    int digit = 0;
    while(pin_no != 0) {
        pin_no /= 10;
        digit++;
    }
    return digit;
}

void new_acc(BankAccount *account) {
    sprintf(account->acno, "%lld", number);
    number++;
    printf("\n\tENTER NAME OF ACCOUNT HOLDER : ");
    fgets(account->name, MAX_NAME_LEN, stdin);
    account->name[strcspn(account->name, "\n")] = '\0';
    printf("\n\tENTER INITIAL BALANCE : ");
    scanf("%f", &account->money);
    clear_input_buffer();
    
    while(account->money < 500) {
        printf("\n\tMINIMUM 500 Rs. REQUIRED. ");
        printf("\n\tENTER INITIAL BALANCE : ");
        scanf("%f", &account->money);
        clear_input_buffer();
    }
    
    printf("\n\tENTER TYPE OF ACCOUNT : ");
    fgets(account->type, MAX_TYPE_LEN, stdin);
    account->type[strcspn(account->type, "\n")] = '\0';
    account->total_trans = 0;
    account->total_dep = 0;
    account->total_with = 0;
}

void modify_acc(BankAccount *account) {
    int n;
    do {
        clear_screen();
        printf("\n\t****WHAT DO YOU WANT TO MODIFY?****\n");
        printf("\n\t1. ACCOUNT HOLDER NAME \n");
        printf("\n\t2. ACCOUNT TYPE \n");
        printf("\n\t3. PIN NO. \n");
        printf("\n\t4. USERNAME \n");
        printf("\n\t5. EXIT \n");
        printf("\n\tSELECT YOUR OPTION (1-5) : ");
        scanf("%d", &n);
        clear_input_buffer();
        
        switch(n) {
            case 1:
                printf("\n\tENTER NEW NAME OF ACCOUNT HOLDER : ");
                fgets(account->name, MAX_NAME_LEN, stdin);
                account->name[strcspn(account->name, "\n")] = '\0';
                printf("\n\tNAME CHANGED SUCCESSFULLY!\n");
                break;
                
            case 2:
                printf("\n\tENTER NEW TYPE OF ACCOUNT : ");
                fgets(account->type, MAX_TYPE_LEN, stdin);
                account->type[strcspn(account->type, "\n")] = '\0';
                printf("\n\tTYPE CHANGED SUCCESSFULLY!\n");
                break;
                
            case 3:
                printf("\n\tENTER NEW PIN : ");
                scanf("%d", &account->pin);
                clear_input_buffer();
                int pin_count = pin_digit(account->pin);
                
                while(pin_count != 4) {
                    printf("\n\tENTER ONLY 4 DIGIT PIN!!\n");
                    printf("\n\tENTER PIN NUMBER AGAIN : ");
                    scanf("%d", &account->pin);
                    clear_input_buffer();
                    pin_count = pin_digit(account->pin);
                }
                
                printf("\n\tPIN CHANGED SUCCESSFULLY!\n");
                break;
                
            case 4:
                printf("\n\tENTER NEW USERNAME : ");
                fgets(account->username, MAX_USERNAME_LEN, stdin);
                account->username[strcspn(account->username, "\n")] = '\0';
                printf("\n\tUSERNAME CHANGED SUCCESSFULLY!\n");
                break;
                
            default:
                if(n != 5) {
                    printf("\n\tOPTION IS INVALID PLEASE TRY AGAIN!!\n");
                }
                break;
        }
    } while(n != 5);
}

void acc_detail(BankAccount *account) {
    printf("\n\tACCOUNT NUMBER : %s\n", account->acno);
    printf("\n\tACCOUNT HOLDER NAME: %s\n", account->name);
    printf("\n\tCURRENT BALANCE : %.2f\n", account->money);
    printf("\n\tTYPE OF ACCOUNT : %s\n", account->type);
}

void delete_acc(BankAccount *account) {
    strcpy(account->acno, "-");
    strcpy(account->name, "-");
    account->money = 0;
    strcpy(account->type, "-");
    strcpy(account->username, "-");
    printf("\n\tYOUR ACCOUNT HAS BEEN DELETED SUCCESSFULLY!!\n");
}

void check_balance(BankAccount *account) {
    printf("\n\tYOUR CURRENT BALANCE : %.2f\n", account->money);
}

void deposit(BankAccount *account) {
    float deposit_amount;
    printf("\n\tENTER AMOUNT OF DEPOSIT : ");
    scanf("%f", &deposit_amount);
    clear_input_buffer();
    
    while(deposit_amount <= 0) {
        printf("\n\tENTER AMOUNT GREATER THAN ZERO!\n");
        printf("\n\tENTER AMOUNT OF DEPOSIT : ");
        scanf("%f", &deposit_amount);
        clear_input_buffer();
    }
    
    account->money += deposit_amount;
    printf("\n\tYOUR DEPOSIT IS SUCCESSFUL !!\n");
    account->total_trans += deposit_amount;
    account->total_dep += deposit_amount;
}

void withdraw(BankAccount *account) {
    float withdraw_amount;
    printf("\n\tENTER AMOUNT OF WITHDRAW : ");
    scanf("%f", &withdraw_amount);
    clear_input_buffer();
    
    if(account->money < withdraw_amount) {
        printf("\n\tAMOUNT YOU WANT TO WITHDRAW IS GREATER THAN YOUR CURRENT BALANCE :)\n");
        return;
    }
    
    while(withdraw_amount <= 0) {
        printf("\n\tENTER AMOUNT GREATER THAN ZERO!\n");
        printf("\n\tENTER AMOUNT YOU WANT TO WITHDRAW : ");
        scanf("%f", &withdraw_amount);
        clear_input_buffer();
    }
    
    account->money -= withdraw_amount;
    printf("\n\tYOUR WITHDRAW IS SUCCESSFUL !!\n");
    account->total_trans += withdraw_amount;
    account->total_with += withdraw_amount;
}

void total_tra_of_day(BankAccount *account) {
    printf("\n\tTOTAL TRANSACTIONS OF DAY : %.2f\n", account->total_trans);
    printf("\n\tTOTAL DEPOSITS OF THE DAY : %.2f\n", account->total_dep);
    printf("\n\tTOTAL WITHDRAWS OF DAY : %.2f\n", account->total_with);
}

void transfer_money(BankAccount *receiver, BankAccount *sender) {
    float tra_money;
    printf("\n\tENTER MONEY YOU WANT TO TRANSFER : ");
    scanf("%f", &tra_money);
    clear_input_buffer();
    
    if(tra_money > sender->money) {
        printf("\n\tTRANSACTION AMOUNT IS BIGGER THAN CURRENT AMOUNT:)\n");
        return;
    }
    
    if(tra_money <= 0) {
        printf("\n\tENTER AMOUNT GREATER THAN ZERO!\n");
        return;
    }
    
    printf("\n\tARE YOU SURE ? ENTER YES OR NO : ");
    char a[10];
    fgets(a, 10, stdin);
    a[strcspn(a, "\n")] = '\0';
    
    if(strcmp(a, "YES") == 0 || strcmp(a, "yes") == 0 || strcmp(a, "Yes") == 0) {
        receiver->money += tra_money;
        sender->money -= tra_money;
        receiver->total_trans += tra_money;
        sender->total_trans += tra_money;
        printf("\n\tTRANSACTION SUCCESSFUL!!\n");
    } else {
        printf("\n\tTRANSACTION CANCELLED!!\n");
    }
}

int find_acc(BankAccount accounts[], char *acc_no) {
    for(int i = 0; i < acc_count; i++) {
        if(strcmp(accounts[i].acno, acc_no) == 0) {
            return i;
        }
    }
    return -1;
}

int find_username1(BankAccount accounts[], char *username) {
    for(int i = 0; i < acc_count; i++) {
        if(strcmp(accounts[i].username, username) == 0) {
            return i;
        }
    }
    return -1;
}

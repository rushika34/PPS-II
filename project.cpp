#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>

using namespace std;
int pin_digit(int);

class Bank
{
    string acno;
    string name;
    float money;
    string type;
    int pin;
    float total_trans;
    float total_dep;
    float total_with;

    public:

    void new_acc()
    {
        cin.ignore();
        cout<<"\n\tENTER ACCOUNT NUMBER : ";
        getline(cin,acno);
        if(acno=="" || acno<="0")
        {
            cout<<"\n\tPLEASE ENTER VALID ACCOUNT NUMBER!!"<<endl;
        }
        cout<<"\n\tENTER NAME OF ACCOUNT HOLDER : ";
        getline(cin,name);
        cout<<"\n\tENTER CURRENT BALANCE : ";
        cin>>money;
        cin.ignore();
        cout<<"\n\tENTER TYPE OF ACCOUNT : ";
        getline(cin,type);
        cout<<"\n\tENTER PIN NUMBER (MUST BE 4 DIGITS ONLY): ";
        cin>>pin;                
        int pin_count=pin_digit(pin);
        while(pin_count!=4)
        {
            cout<<"\n\tENTER ONLY 4 DIGIT PIN!!"<<endl;
            cout<<"\n\tENTER PIN NUMBER AGAIN : ";
            cin>>pin;
            pin_count=pin_digit(pin);
        }
    }

    void modify_acc()
    {
        cin.ignore();
        cout<<"\n\tENTER NEW NAME OF ACCOUNT HOLDER : ";
        getline(cin,name);
        if(acno=="" || acno<="0")
        {
            cout<<"\n\tPLEASE ENTER VALID ACCOUNT NUMBER!!"<<endl;
        }
        cout<<"\n\tENTER NEW TYPE OF ACCOUNT : ";
        getline(cin,type);
    }

    void deposit()
    {
        float deposit_amount;
        cout<<"\n\tENTER AMOUNT OF DEPOSIT : ";
        cin>>deposit_amount;
        money+=deposit_amount;
        cout<<"\n\tYOUR DEPOSIT IS SUCCESSFULL !!"<<endl;
        total_trans+=deposit_amount;
        total_dep+=deposit_amount;
    }

    void withdraw()
    {
        float withdraw_amount;
        cout<<"\n\tENTER AMOUNT OF WITHDRAW : ";
        cin>>withdraw_amount;
        if(money<withdraw_amount)
        {
            cout<<"\n\tYOU CAN NOT WITHDRAW AMOUNT :)";
        }
        else
        {
            money-=withdraw_amount;
            cout<<"\n\tYOUR WITHDRAW IS SUCCESSFULL !!"<<endl;
        }
        total_trans+=withdraw_amount;
        total_with+=withdraw_amount;
    }

    void check_balance()
    {
        cout<<"\n\tHERE YOUR BALANCE IS : "<<money<<endl;
    }

    void acc_detail()
    {
        cout<<"\n\tACCOUNT NUMBER IS : "<<acno<<endl;
        cout<<"\n\tNAME IS : "<<name<<endl;
        cout<<"\n\tCURRENT BALANCE : "<<money<<endl;
        cout<<"\n\tTYPE OF ACCOUNT : "<<type<<endl;
    }

    void delete_acc()
    {
        acno="";
        name="";
        money=0;
        type="";
        cout<<"\n\tYOUR ACCOUNT HAS BEEN DELETED !!"<<endl;
    }

    void total_tra_of_day()
    {
        cout<<"\n\tTOTAL TRANSACTION OF DAY IS : "<<total_trans<<endl;
        cout<<"\n\tTOTAL DEPOSIT OF DAY IS : "<<total_dep<<endl;
        cout<<"\n\tTOTAL WITHDRAW OF DAY IS : "<<total_with<<endl;
    }

    string ret_acc_no()
    {
        return acno;
    }

    int ret_pin()
    {
        return pin;
    }  

    void transfer_money(Bank &b)
    {
        int tra_money;
        string a;
        cout<<"\n\tENTER MONEY YOU WANT TO TRANSFER : ";
        cin>>tra_money;
        if(tra_money>b.money)
        {
            cout<<"\n\tTRANSACTION AMOUNT IS BIGGER THAN CURRENT AMOUNT:)"<<endl;
        }
        else
        {
            cin.ignore();
            cout<<"\n\tARE YOU SURE ? ENTER YES OR NO : ";
            getline(cin,a);
            if(a=="YES" || a=="yes" || a=="Yes")
            {
                money+=tra_money;
                b.money-=tra_money;
                total_trans+=tra_money;
                b.total_trans+=tra_money;
                cout<<"\n\tTRANSACTION SUCCESSFULL!!"<<endl;
            }
            else
            {
                cout<<"\n\tTRANSACTION CANCELLED!!"<<endl;
            }
        }
    }
};


int find_acc(Bank b[],string acc_no,int acc_count)
{
    for(int i=0;i<acc_count;i++)
    {
        if(b[i].ret_acc_no()==acc_no)
        {
            return i;
        }
    }
    return -1;

}
int pin_digit(int pin_no)
{
    int digit=0;
    int rem;
    while(pin_no!=0)
    {
        rem=pin_no%10;
        pin_no/=10;
        digit++;
    }
    return digit;
}

int main()
{
    string acc_no;
    int n,index,pin_no;
    Bank b[100];
    int acc_count=0;
    do
    {      
    cout<<"\n\t\t\t=========================================";
    cout<<"\n\t\t\t          BANK MANAGMENT SYSTEM";
    cout<<"\n\t\t\t=========================================";
    cout<<"\n\t1. CREATE NEW ACCOUNT "<<endl;
    cout<<"\n\t2. MODIFY AN ACCOUNT "<<endl;
    cout<<"\n\t3. DEPOSIT AMOUNT "<<endl;
    cout<<"\n\t4. WITHDRAW AMOUNT "<<endl;
    cout<<"\n\t5. CHECK BALANCE OF ACCOUNT "<<endl;
    cout<<"\n\t6. ACCOUNT DETAILS "<<endl;
    cout<<"\n\t7. CLOSE AN ACCOUNT "<<endl;
    cout<<"\n\t8. CHECK YOUR WHOLE DAY TRANSACTION "<<endl;
    cout<<"\n\t9. DO YOU WANT TO TRANSFER MONEY ?"<<endl;
    cout<<"\n\t10. EXIT "<<endl;
    cout<<"\n\tSELECT YOUR OPTION (1-10) : ";
    cin>>n;
    
    switch(n)
    {
        case 1:
                b[acc_count].new_acc();
                acc_count++;
            break;

        case 2:
                cout<<"\n\tENTER ACCOUNT NUMBER :  ";
                cin>>acc_no;
                if(acc_no=="" || acc_no<="0")
                {
                    cout<<"\n\tPLEASE ENTER VALID ACCOUNT NUMBER!!"<<endl;
                }
                else
                {
                    index=find_acc(b,acc_no,acc_count);
                    cout<<"\n\tENTER YOUR PIN (MUST BE 4 DIGITS ONLY): ";
                    cin>>pin_no;
                    int pin_count=pin_digit(pin_no);
                    if(pin_count!=4)
                    {
                        cout<<"\n\tENTER ONLY 4 DIGIT PIN!!"<<endl;
                    
                    }
                    else
                    {
                        if(pin_no!=b[index].ret_pin())
                        {
                            cout<<"\n\t PIN IS INVALID!!";
                        }
                        else
                        {
                            if(index==-1)
                            {
                                cout<<"\n\tACCOUNT NOT FOUND!!"<<endl;
                            }
                            else if(b[index].ret_acc_no()=="")
                            {
                                cout<<"\n\tACCOUNT DELETED.";
                            }
                            else
                            {
                                b[index].modify_acc();
                            }        
                        }
                    }
                }
            break;

        case 3:
                cout<<"\n\tENTER ACCOUNT NUMBER :  ";
                cin>>acc_no;
                if(acc_no=="" || acc_no<="0")
                {
                    cout<<"\n\tPLEASE ENTER VALID ACCOUNT NUMBER!!"<<endl;
                }
                else
                {
                    index=find_acc(b,acc_no,acc_count);
                    cout<<"\n\tENTER YOUR PIN (MUST BE 4 DIGITS ONLY): ";
                    cin>>pin_no;
                    int pin_count=pin_digit(pin_no);
                    if(pin_count!=4)
                    {
                        cout<<"\n\tENTER ONLY 4 DIGIT PIN!!"<<endl;
                    }
                    else
                    {
                        if(pin_no!=b[index].ret_pin())
                        {
                            cout<<"\n\tPIN IS INVALID!!";
                        }
                        else
                        {
                            if(index==-1)
                            {
                                cout<<"\n\tACCOUNT NOT FOUND!!"<<endl;
                            }
                            else if(b[index].ret_acc_no()=="")
                            {
                                cout<<"\n\tACCOUNT DELETED.";
                            }
                            else
                            {
                                b[index].deposit();
                            }             
                        }
                    }
                }  
            break;

        case 4:
                cout<<"\n\tENTER ACCOUNT NUMBER :  ";
                cin>>acc_no;
                if(acc_no=="" || acc_no<="0")
                {
                    cout<<"\n\tPLEASE ENTER VALID ACCOUNT NUMBER!!"<<endl;
                }
                else
                {
                    index=find_acc(b,acc_no,acc_count);
                    cout<<"\n\tENTER YOUR PIN (MUST BE 4 DIGITS ONLY): ";
                    cin>>pin_no;
                    int pin_count=pin_digit(pin_no);
                    if(pin_count!=4)
                    {
                        cout<<"\n\tENTER ONLY 4 DIGIT PIN!!"<<endl;
                    }
                    else
                    {
                        if(pin_no!=b[index].ret_pin())
                        {
                            cout<<"\n\tPIN IS INVALID!!";
                        }
                        else
                        {
                            if(index==-1)
                            {
                                cout<<"\n\tACCOUNT NOT FOUND!!"<<endl;
                            }
                            else if(b[index].ret_acc_no()=="")
                            {
                                cout<<"\n\tACCOUNT DELETED.";
                            }
                            else
                            {
                                b[index].withdraw();
                            }            
                        }
                    } 
                }    
            break;

        case 5:
                cout<<"\n\tENTER ACCOUNT NUMBER :  ";
                cin>>acc_no;
                if(acc_no=="" || acc_no<="0")
                {
                    cout<<"\n\tPLEASE ENTER VALID ACCOUNT NUMBER!!"<<endl;
                }
                else
                {
                    index=find_acc(b,acc_no,acc_count);
                    cout<<"\n\tENTER YOUR PIN (MUST BE 4 DIGITS ONLY): ";
                    cin>>pin_no;
                    int pin_count=pin_digit(pin_no);
                    if(pin_count!=4)
                    {
                        cout<<"\n\tENTER ONLY 4 DIGIT PIN!!"<<endl;
                    }
                    else
                    {
                        if(pin_no!=b[index].ret_pin())
                        {
                            cout<<"\n\tPIN IS INVALID!!";
                        }
                        else
                        {
                            if(index==-1)
                            {
                            cout<<"\n\tACCOUNT NOT FOUND!!"<<endl;
                            }
                            else if(b[index].ret_acc_no()=="")
                            {
                                cout<<"\n\tACCOUNT DELETED.";
                            }
                            else
                            {
                                b[index].check_balance();
                            }
                        }
                    }
                }
            break;
                
        case 6:
                cout<<"\n\tENTER ACCOUNT NUMBER :  ";
                cin>>acc_no;
                if(acc_no=="" || acc_no<="0")
                {
                    cout<<"\n\tPLEASE ENTER VALID ACCOUNT NUMBER!!"<<endl;
                }
                else
                {
                    index=find_acc(b,acc_no,acc_count);
                    cout<<"\n\tENTER YOUR PIN (MUST BE 4 DIGITS ONLY): ";
                    cin>>pin_no;
                    int pin_count=pin_digit(pin_no);
                    if(pin_count!=4)
                    {
                        cout<<"\n\tENTER ONLY 4 DIGIT PIN!!"<<endl;
                    }
                    else
                    {
                        if(pin_no!=b[index].ret_pin())
                        {
                            cout<<"\n\tPIN IS INVALID!!";
                        }
                        else
                        {
                            if(index==-1)
                            {
                                cout<<"\n\tACCOUNT NOT FOUND!!"<<endl;
                            }  
                            else if(b[index].ret_acc_no()=="")
                            {
                                cout<<"\n\tACCOUNT DELETED.";
                            }
                            else
                            {
                                b[index].acc_detail();
                            } 
                        } 
                    }
                }       
            break;

        case 7:
                cout<<"\n\tENTER ACCOUNT NUMBER :  ";
                cin>>acc_no;
                if(acc_no=="" || acc_no<="0")
                {
                    cout<<"\n\tPLEASE ENTER VALID ACCOUNT NUMBER!!"<<endl;
                }
                else
                {
                    index=find_acc(b,acc_no,acc_count);
                    cout<<"\n\tENTER YOUR PIN (MUST BE 4 DIGITS ONLY): ";
                    cin>>pin_no;
                    int pin_count=pin_digit(pin_no);
                    if(pin_count!=4)
                    {
                        cout<<"\n\tENTER ONLY 4 DIGIT PIN!!"<<endl;
                    }
                    else
                    {
                        if(pin_no!=b[index].ret_pin())
                        {
                            cout<<"\n\tPIN IS INVALID!!";
                        }
                        else
                        {
                            if(index==-1)
                            {
                                cout<<"\n\tACCOUNT NOT FOUND!!"<<endl;
                            }
                            else
                            {
                                b[index].delete_acc();
                            }
                        }
                    } 
                }  
            break; 

        case 8:
                cout<<"\n\tENTER ACCOUNT NUMBER :  ";
                cin>>acc_no;
                if(acc_no=="" || acc_no<="0")
                {
                    cout<<"\n\tPLEASE ENTER VALID ACCOUNT NUMBER!!"<<endl;
                }
                else
                {
                    index=find_acc(b,acc_no,acc_count);
                    cout<<"\n\tENTER YOUR PIN (MUST BE 4 DIGITS ONLY): ";
                    cin>>pin_no;
                    int pin_count=pin_digit(pin_no);
                    if(pin_count!=4)
                    {
                        cout<<"\n\tENTER ONLY 4 DIGIT PIN!!"<<endl;
                    }
                    else
                    {
                        if(pin_no!=b[index].ret_pin())
                        {
                            cout<<"\n\tPIN IS INVALID!!";
                        }
                        else
                        {
                            if(index==-1)
                            {
                                cout<<"\n\tACCOUNT NOT FOUND!!"<<endl;
                            }
                            else
                            {
                                b[index].total_tra_of_day();
                            }
                        }
                    }
                }    
            break;
                
        case 9:
                cout<<"\n\tENTER YOUR ACCOUNT NUMBER :  ";
                cin>>acc_no;
                if(acc_no=="" || acc_no<="0")
                {
                    cout<<"\n\tPLEASE ENTER VALID ACCOUNT NUMBER!!"<<endl;
                }
                else
                {
                    index=find_acc(b,acc_no,acc_count);
                    cout<<"\n\tENTER YOUR PIN (MUST BE 4 DIGITS ONLY): ";
                    cin>>pin_no;
                    int pin_count=pin_digit(pin_no);
                    if(pin_count!=4)
                    {
                        cout<<"\n\tENTER ONLY 4 DIGIT PIN!!"<<endl;
                    }
                    else
                    {
                        if(pin_no!=b[index].ret_pin())
                        {
                            cout<<"\n\tPIN IS INVALID!!";
                        }
                        else
                        {
                            if(index==-1)
                            {
                                cout<<"\n\tACCOUNT NOT FOUND!!"<<endl;
                            }
                            else
                            {
                                string rec_acc;
                                int rec_index;
                                cin.ignore();
                                cout<<"\n\tENTER RECEIVER ACCOUNT NUMBER : ";
                                getline(cin,rec_acc);
                                rec_index=find_acc(b,rec_acc,acc_count);
                                if(rec_index==-1)
                                {
                                    cout<<"\n\tACCOUNT NOT FOUND!!"<<endl;
                                }
                                else
                                {
                                    b[rec_index].transfer_money(b[index]);
                                }
                            }
                        }
                    }
                }   
            break;  
                  
        default:
                if(n!=10)
                {
                    cout<<"\n\tOPTION IS INVALID PLEASE TRY AGAIN!!"<<endl;
                }   
                else
                {
                    break;
                }                                
    }
    }while(n<10 && n>0);

    return 0;
}

#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>

using namespace std;

int pin_digit(int);

 long long number=100000000001;
class Person
{
    protected:

    string acno;
    string name;
    float money;
    string type;
    int pin;
    
    string username;
    public:

    // void new_acc();

    void modify_acc();

    void acc_detail()
    {
        cout<<"\n\tACCOUNT NUMBER : "<<acno<<endl;
        cout<<"\n\tACCOUNT HOLDER NAME: "<<name<<endl;
        cout<<"\n\tCURRENT BALANCE : "<<money<<endl;
        cout<<"\n\tTYPE OF ACCOUNT : "<<type<<endl;
    }

    void delete_acc()
    {
        acno="";
        name="";
        money=0;
        type="";
        username="";
        cout<<"\n\tYOUR ACCOUNT HAS BEEN DELETED SUCCESSFULLY!!"<<endl;
    }

    void check_balance()
    {
        cout<<"\n\tYOUR CURRENT BALANCE : "<<money<<endl;
    }

    string ret_acc_no()
    {
        return acno;
    }

    string ret_name()
    {
        return name;
    }

    float ret_money()
    {
        return money;
    }

    string ret_type()
    {
        return type;
    }
    string ret_username(){
        return username;
    }
    void set_username(string u_name){
          username=u_name;
    }
    int ret_pin()
    {
        return pin;
    }  

    void set_acno(string n_acno)
    {
        acno=n_acno;
    }

    void set_name(string n_name)
    {
        name=n_name;
    }

    void set_money(float n_money)
    {
        money=n_money;
    }

    void set_type(string n_type)
    {
        type=n_type;
    }

    void set_pin(int n_pin)
    {
        pin=n_pin;
    }

};
class Bank;

class Bank : public Person
{
    float total_trans;
    float total_dep;
    float total_with;
    static int  acc_count;
    public:
    void new_acc();
    void deposit();

    void withdraw();

    void total_tra_of_day()
    {
        cout<<"\n\tTOTAL TRANSACTIONS OF DAY : "<<total_trans<<endl;
        cout<<"\n\tTOTAL DEPOSITS OF THE DAY : "<<total_dep<<endl;
        cout<<"\n\tTOTAL WITHDRAWS OF DAY : "<<total_with<<endl;
    }

    void transfer_money(Bank &b);
   
};
   int Bank::acc_count=0;
    void Bank::new_acc()
    {
        cin.ignore();
        
         acno = std::to_string(number);
         number++;
        cout<<"\n\tENTER NAME OF ACCOUNT HOLDER : ";
        getline(cin,name);
        // cout<<"\n\tENTER USERNAME : ";
        // getline(cin,username);
        
        cout<<"\n\tENTER INITIAL BALANCE : ";
        cin>>money;
        cin.ignore();
        while(money<500)
        {
            cout<<"\n\tMINIMUM 500 Rs. REQUIRED. "; 
            cout<<"\n\tENTER INITIAL BALANCE : ";
            cin>>money;
            cin.ignore();
        }

       
        cout<<"\n\tENTER TYPE OF ACCOUNT : ";
    
        getline(cin,type);
        
        // cout<<"\n\tENTER PIN NUMBER (MUST BE 4 DIGITS ONLY): ";
        // cin>>pin;                
        // int pin_count=pin_digit(pin);
        
        // while(pin_count!=4)
        // {
        //     cout<<"\n\tENTER ONLY 4 DIGIT PIN!!"<<endl;
        //     cout<<"\n\tENTER PIN NUMBER AGAIN : ";
        //     cin>>pin;
        //     pin_count=pin_digit(pin);
        // }
        acc_count++;
    }

    void Person::modify_acc()
    {
        int n,pin_count;
        do
        {      
            cout<<"\n\tWHAT DO YOU WANT TO MODIFY? "<<endl;
            cout<<"\n\t1. ACCOUNT HOLDER NAME "<<endl;
            cout<<"\n\t2. ACCOUNT TYPE "<<endl;
            cout<<"\n\t3. PIN N0. "<<endl;
            cout<<"\n\t4. EXIT "<<endl;
            cout<<"\n\tSELECT YOUR OPTION (1-4) : ";
            cin>>n;
        
            switch(n)
            {
                case 1:
                    cin.ignore();
                    cout<<"\n\tENTER NEW NAME OF ACCOUNT HOLDER : ";
                    getline(cin,name);
                    break;
                case 2:
                    cin.ignore();
                    cout<<"\n\tENTER NEW TYPE OF ACCOUNT : ";
                    getline(cin,type);
                    break;
                case 3:
                    cin.ignore();
                    cout<<"\n\tENTER NEW PIN : ";
                    cin>>pin;
                    pin_count=pin_digit(pin);
                    while(pin_count!=4)
                    {
                        cout<<"\n\tENTER ONLY 4 DIGIT PIN!!"<<endl;
                        cout<<"\n\tENTER PIN NUMBER AGAIN : ";
                        cin>>pin;
                        pin_count=pin_digit(pin);
                    }
                    break;
                default:
                    if(n!=4)
                    {
                        cout<<"\n\tOPTION IS INVALID PLEASE TRY AGAIN!!"<<endl;
                    }   
                    else
                    {
                        break;
                    }  
            }
        }while(n!=4);
    }

    void Bank::deposit()
    {
        float deposit_amount;
        cout<<"\n\tENTER AMOUNT OF DEPOSIT : ";
        cin>>deposit_amount;
        while(deposit_amount<=0){
            cout<<"\n\tENTER AMOUNT GREATER THAN ZERO ";
            cout<<"\n\tENTER AMOUNT OF DEPOSIT : ";
        cin>>deposit_amount;
        }
        money+=deposit_amount;
        cout<<"\n\tYOUR DEPOSIT IS SUCCESSFULL !!"<<endl;
        total_trans+=deposit_amount;
        total_dep+=deposit_amount;
    }

    void Bank::withdraw()
    {
        float withdraw_amount;
        cout<<"\n\tENTER AMOUNT OF WITHDRAW : ";
        cin>>withdraw_amount;
        if(ret_money()<withdraw_amount)
        {
            cout<<"\n\tAMOUNT YOU WANT TO WITHDRAW IS GREATER THAN YOUR CURRENT BALANCE :)";
        }
        else
        {
            while(withdraw_amount<=0){
                cout<<"\n\tENTER AMOUNT GREATER THAN ZERO ";
                cout<<"\n\tENTER AMOUNT YOU WANT TO WITHDRAW : ";
            cin>>withdraw_amount;
            }

            money-=withdraw_amount;
            cout<<"\n\tYOUR WITHDRAW IS SUCCESSFULL !!"<<endl;
        }
        total_trans+=withdraw_amount;
        total_with+=withdraw_amount;
    }

    void Bank::transfer_money(Bank &b)
    {
        float tra_money;
        string a;
        cout<<"\n\tENTER MONEY YOU WANT TO TRANSFER : ";
        cin>>tra_money;
        if(tra_money>b.money )
        {
            cout<<"\n\tTRANSACTION AMOUNT IS BIGGER THAN CURRENT AMOUNT:)"<<endl;
        }
        else
        {
            if(money<=0){
                cout<<"\n\tENTER AMOUNT GREATER THAN ZERO"<<endl;
            }
            else{
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
    }

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
int find_username1(Bank b[],string username,int acc_count)
{
    for(int i=0;i<acc_count;i++)
    {
        if(b[i].ret_username()==username)
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
    string acc_no,username;
    int n,index,pin_no,x;
    Bank b[100];
    int acc_count=0,pin_count;
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
                    cout<<"\n\tENTER USERNAME : ";
                    getline(cin,username);
                   x=find_username1(b,username,acc_count);
                   while(x!=-1){
                    cout<<"\n\tUSERNAME ALREADY EXIST.. ";
                    cout<<"\n\tENTER USERNAME : ";
                    getline(cin,username);
                    x=find_username1(b,username,acc_count);
                   }
                   b[acc_count].set_username(username);
                    cout<<"\n\tENTER PIN NUMBER (MUST BE 4 DIGITS ONLY): ";
                    cin>>pin_no;                
                     pin_count=pin_digit(pin_no);
        
        while(pin_count!=4)
        {
            cout<<"\n\tENTER ONLY 4 DIGIT PIN!!"<<endl;
            cout<<"\n\tENTER PIN NUMBER AGAIN : ";
            cin>>pin_no;
            pin_count=pin_digit(pin_no);
        }
        b[acc_count].set_pin(pin_no);
                    cout<<"\n\tACCOUNT CREATED SUCCESSFULLY.";
                    cout<<"\n\tYOUR ACCOUNT NUMBER IS :  "<<b[acc_count].ret_acc_no();
                    acc_count++;
                break;
    
            case 2:
                    cin.ignore();
                    cout<<"\n\tENTER YOUR USERNAME :  ";
                    getline(cin,username);
                    x=find_username1(b,username,acc_count);
                    if(x==-1)
                    {
                        cout<<"\n\tPLEASE ENTER VALID USERNAME!!"<<endl;
                    }
                    else
                    {
                        
                        
                            // index=find_username1(b,username,acc_count);
                            cout<<"\n\tENTER YOUR PIN (MUST BE 4 DIGITS ONLY): ";
                            
                            cin>>pin_no;
                            cin.ignore();
                             pin_count=pin_digit(pin_no);
                            if(pin_count!=4)
                            {    
                                cout<<"\n\tENTER ONLY 4 DIGIT PIN!!"<<endl;
                                while(pin_count!=4){
                                    cout<<"\n\tENTER YOUR PIN (MUST BE 4 DIGITS ONLY): ";
                                    cin>>pin_no;
                                   cin.ignore();
                                    pin_count=pin_digit(pin_no);
                                }
                               
                            
                            }
                            
                            
                                if(pin_no!=b[x].ret_pin())
                                {
                                    cout<<"\n\t PIN IS INVALID!!";
                                }
                                else
                                {
                                     b[x].modify_acc();
                                }        
                                
                            
                        
                    }
                break;
    
            case 3:
            cin.ignore();
                    cout<<"\n\tENTER YOUR USERNAME :  ";
                    getline(cin,username);
                    x=find_username1(b,username,acc_count);
                    if(x==-1)
                    {
                        cout<<"\n\tPLEASE ENTER VALID USERNAME!!"<<endl;
                    }
                    else
                    {
                        
                        
                            // index=find_username1(b,username,acc_count);
                            cout<<"\n\tENTER YOUR PIN (MUST BE 4 DIGITS ONLY): ";
                            
                            cin>>pin_no;
                            cin.ignore();
                             pin_count=pin_digit(pin_no);
                            if(pin_count!=4)
                            {    
                                cout<<"\n\tENTER ONLY 4 DIGIT PIN!!"<<endl;
                                while(pin_count!=4){
                                    cout<<"\n\tENTER YOUR PIN (MUST BE 4 DIGITS ONLY): ";
                                    cin>>pin_no;
                                   cin.ignore();
                                    pin_count=pin_digit(pin_no);
                                }
                               
                            
                            }
                            
                            
                                if(pin_no!=b[x].ret_pin())
                                {
                                    cout<<"\n\t PIN IS INVALID!!";
                                }
                                else
                                {
                                     b[x].deposit();
                                }        
                                
                            
                        
                    }
                break;
    
            case 4:
            cin.ignore();
            cout<<"\n\tENTER YOUR USERNAME :  ";
            getline(cin,username);
            x=find_username1(b,username,acc_count);
            if(x==-1)
            {
                cout<<"\n\tPLEASE ENTER VALID USERNAME!!"<<endl;
            }
            else
            {
                
                
                    // index=find_username1(b,username,acc_count);
                    cout<<"\n\tENTER YOUR PIN (MUST BE 4 DIGITS ONLY): ";
                    
                    cin>>pin_no;
                    cin.ignore();
                     pin_count=pin_digit(pin_no);
                    if(pin_count!=4)
                    {    
                        cout<<"\n\tENTER ONLY 4 DIGIT PIN!!"<<endl;
                        while(pin_count!=4){
                            cout<<"\n\tENTER YOUR PIN (MUST BE 4 DIGITS ONLY): ";
                            cin>>pin_no;
                           cin.ignore();
                            pin_count=pin_digit(pin_no);
                        }
                       
                    
                    }
                    
                    
                        if(pin_no!=b[x].ret_pin())
                        {
                            cout<<"\n\t PIN IS INVALID!!";
                        }
                        else
                        {
                             b[x].withdraw();
                        }        
                        
                    
                
            }
        break;
        
    
            case 5:
            cin.ignore();
            cout<<"\n\tENTER YOUR USERNAME :  ";
            getline(cin,username);
            x=find_username1(b,username,acc_count);
            if(x==-1)
            {
                cout<<"\n\tPLEASE ENTER VALID USERNAME!!"<<endl;
            }
            else
            {
                
                
                    // index=find_username1(b,username,acc_count);
                    cout<<"\n\tENTER YOUR PIN (MUST BE 4 DIGITS ONLY): ";
                    
                    cin>>pin_no;
                    cin.ignore();
                     pin_count=pin_digit(pin_no);
                    if(pin_count!=4)
                    {    
                        cout<<"\n\tENTER ONLY 4 DIGIT PIN!!"<<endl;
                        while(pin_count!=4){
                            cout<<"\n\tENTER YOUR PIN (MUST BE 4 DIGITS ONLY): ";
                            cin>>pin_no;
                           cin.ignore();
                            pin_count=pin_digit(pin_no);
                        }
                       
                    
                    }
                    
                    
                        if(pin_no!=b[x].ret_pin())
                        {
                            cout<<"\n\t PIN IS INVALID!!";
                        }
                        else
                        {
                             b[x].check_balance();
                        }        
                        
                    
                
            }
        break;
                    
            case 6:
            cin.ignore();
            cout<<"\n\tENTER YOUR USERNAME :  ";
            getline(cin,username);
            x=find_username1(b,username,acc_count);
            if(x==-1)
            {
                cout<<"\n\tPLEASE ENTER VALID USERNAME!!"<<endl;
            }
            else
            {
                
                
                    // index=find_username1(b,username,acc_count);
                    cout<<"\n\tENTER YOUR PIN (MUST BE 4 DIGITS ONLY): ";
                    
                    cin>>pin_no;
                    cin.ignore();
                     pin_count=pin_digit(pin_no);
                    if(pin_count!=4)
                    {    
                        cout<<"\n\tENTER ONLY 4 DIGIT PIN!!"<<endl;
                        while(pin_count!=4){
                            cout<<"\n\tENTER YOUR PIN (MUST BE 4 DIGITS ONLY): ";
                            cin>>pin_no;
                           cin.ignore();
                            pin_count=pin_digit(pin_no);
                        }
                       
                    
                    }
                    
                    
                        if(pin_no!=b[x].ret_pin())
                        {
                            cout<<"\n\t PIN IS INVALID!!";
                        }
                        else
                        {
                             b[x].acc_detail();
                        }        
                        
                    
                
            }
        break;
    
            case 7:
            cin.ignore();
            cout<<"\n\tENTER YOUR USERNAME :  ";
            getline(cin,username);
            x=find_username1(b,username,acc_count);
            if(x==-1)
            {
                cout<<"\n\tPLEASE ENTER VALID USERNAME!!"<<endl;
            }
            else
            {
                
                
                    // index=find_username1(b,username,acc_count);
                    cout<<"\n\tENTER YOUR PIN (MUST BE 4 DIGITS ONLY): ";
                    
                    cin>>pin_no;
                    cin.ignore();
                     pin_count=pin_digit(pin_no);
                    if(pin_count!=4)
                    {    
                        cout<<"\n\tENTER ONLY 4 DIGIT PIN!!"<<endl;
                        while(pin_count!=4){
                            cout<<"\n\tENTER YOUR PIN (MUST BE 4 DIGITS ONLY): ";
                            cin>>pin_no;
                           cin.ignore();
                            pin_count=pin_digit(pin_no);
                        }
                       
                    
                    }
                    
                    
                        if(pin_no!=b[x].ret_pin())
                        {
                            cout<<"\n\t PIN IS INVALID!!";
                        }
                        else
                        {
                             b[x].delete_acc();
                        }        
                        
                    
                
            }
        break; 
        
                case 8:
                       cin.ignore();
                    cout<<"\n\tENTER YOUR USERNAME :  ";
                    getline(cin,username);
                    x=find_username1(b,username,acc_count);
                    if(x==-1)
                    {
                        cout<<"\n\tPLEASE ENTER VALID USERNAME!!"<<endl;
                    }
                    else
                    {
                        
                        
                            // index=find_username1(b,username,acc_count);
                            cout<<"\n\tENTER YOUR PIN (MUST BE 4 DIGITS ONLY): ";
                            
                            cin>>pin_no;
                            cin.ignore();
                             pin_count=pin_digit(pin_no);
                            if(pin_count!=4)
                            {    
                                cout<<"\n\tENTER ONLY 4 DIGIT PIN!!"<<endl;
                                while(pin_count!=4){
                                    cout<<"\n\tENTER YOUR PIN (MUST BE 4 DIGITS ONLY): ";
                                    cin>>pin_no;
                                   cin.ignore();
                                    pin_count=pin_digit(pin_no);
                                }
                               
                            
                            }
                            
                            
                                if(pin_no!=b[x].ret_pin())
                                {
                                    cout<<"\n\t PIN IS INVALID!!";
                                }
                                else
                                {
                                     b[x].total_tra_of_day();
                                }        
                                
                            
                        
                    }
                break;
                    
            case 9:
            cin.ignore();
                    cout<<"\n\tENTER YOUR USERNAME :  ";
                    getline(cin,username);
                    x=find_username1(b,username,acc_count);
                    if(x==-1)
                    {
                        cout<<"\n\tPLEASE ENTER VALID USERNAME!!"<<endl;
                    }
                    else
                    {
                       
                        
                        
                            // index=find_acc(b,acc_no,acc_count);
                            cout<<"\n\tENTER YOUR PIN (MUST BE 4 DIGITS ONLY): ";
                            cin>>pin_no;
                            cin.ignore();
                             pin_count=pin_digit(pin_no);
                             if(pin_count!=4)
                            {    
                                cout<<"\n\tENTER ONLY 4 DIGIT PIN!!"<<endl;
                                while(pin_count!=4){
                                    cout<<"\n\tENTER YOUR PIN (MUST BE 4 DIGITS ONLY): ";
                                    cin>>pin_no;
                                   cin.ignore();
                                    pin_count=pin_digit(pin_no);
                                }
                               
                            
                            }
                            
                            
                                if(pin_no!=b[x].ret_pin())
                                {
                                    cout<<"\n\tPIN IS INVALID!!";
                                }
                                else
                                {
                                    
                                    
                                    
                                        string rec_acc;
                                        int rec_index;
                                        
                                        cout<<"\n\tENTER RECEIVER ACCOUNT NUMBER : ";
                                        getline(cin,rec_acc);
                                        rec_index=find_acc(b,rec_acc,acc_count);
                                        if(rec_index==-1)
                                        {
                                            cout<<"\n\tACCOUNT NOT FOUND!!"<<endl;
                                        }
                                        else
                                        {
                                            if(rec_index==x){
                                                cout<<"\n\tENTER ANOTHER ACCOUNT!!"<<endl;
                                            }
                                            else{
                                            b[rec_index].transfer_money(b[x]);
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

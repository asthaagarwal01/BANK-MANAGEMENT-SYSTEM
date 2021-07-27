#include<iostream>
#include<string>
#include<conio.h>
#include<cstdio>

using namespace std;

class Bank
{

    int acno;
    int age,mn,ac;
    long long mob;
    string name,type;
    double balance;


    public:

 // CONSTRUCTOR TO INITIALISE DATA MEMBERS

    Bank()
    {

      age=0;
      mob=0;
      name="";
      balance=0;
      type="";

    }

    //FUNCTION TO CREATE NEW ACCOUNT

    void create_account()
    {

        cout<<endl<<endl;
        cout<<"Enter your details correctly"<<endl<<endl;
        cout<<"NAME : ";
        fflush(stdin);
        getline(cin,name);
        cout<<"MOBILE NUMBER : ";
        cin>>mob;
        cout<<"TYPE OF ACCOUNT ( SAVINGS / CURRENT ) : ";
        fflush(stdout);
        cin>>type;
        cout<<"AGE : ";
        cin>>age;
        if(age<18)                                                               // CHECKING FOR ELIGIBILITY OF ACCOUNT HOLDER
        {
        cout<<endl;
        cout<<"NOT VALID , YOU ARE A MINOR , SORRY !! ";
        menu();
        }
        ac=acno++;

    }                                                                             // END OF create_account()

    // FUNCTION TO EDIT ACCOUNT DETAILS

    void edit_details()
    {

        cout<<endl<<endl;
        if(age=0)                                                               // CHECKING WHETHER ACCOUNT EXISTS OR NOT
            {
                 cout<<"Create an account first"<<endl<<endl;
                 menu();
            }
        else
           {
                 cout<<"Following fields can be edited : ";
                 cout<<endl<<"1 . NAME "<<endl;
                 cout<<"2 . MOBILE NUMBER "<<endl;
                 cout<<"Enter your choice ( 1 / 2 )"<<endl;
                 int c;
                 cin>>c;
                 switch(c)
                {
                  case 1:
                  cout<<endl;
                  cout<<endl;
                  cout<<"Enter new name : ";
                  fflush(stdout);
                  cin>>name;
                  break;
                  case 2:
                  cout<<endl;
                  cout<<endl;
                  cout<<"Enter new mobile number : ";
                  cin>>mob;
                  break;
                  default :
                  cout<<"Wrong option selected , Enter again"<<endl;
                  edit_details();
                }
           }

    }

    // FUNCTION FOR CHECKING ACCOUNT BALANCE

    void check_balance()
    {

        cout<<"Current Available balance : ";
        cout<<balance;

    }                                                                                    // END OF edit_details()

   // FUNCTION FOR DEPOSITING CASH

    void deposit()
    {

        double d;
        cout<<"Enter the amount to be deposited : ";
        cin>>d;
        balance=balance+d;
        cout<<"Transaction successful !!!"<<endl;
        check_balance();
        mn=1;

    }                                                                                          // END OF deposit()

    // FUNCTION FOR WITHDRAWING CASH

    void withdraw()
    {

        double w;
        cout<<"Enter the amount to be withdrawn : ";
        cin>>w;
        if(balance<1500 || w>=balance)                                                        // CHECKING WHETHER ACCOUNT HAS ENOUGH BALANCE OR NOT
        {
            check_balance();
            cout<<endl;
            cout<<endl;
            cout<<"Transaction Failed , Not enough balance , Please maintain minimum balance !!"<<endl;
        }
        else
        {
            balance=balance-w;
            cout<<"Transaction Successful !!"<<endl;
            check_balance();
            mn=0;
        }

    }                                                                                            // END OF withdraw()

    // FUNCTION FOR PRINTING MINI STATEMENTS

    void mini_statement()
    {

        cout<<endl;
        cout<<endl;
        cout<<"*************************"<<endl;
        cout<<"*                       *"<<endl;
        cout<<"*     MINI STATEMENT    *"<<endl;
        cout<<"*                       *"<<endl;
        cout<<"*************************"<<endl<<endl<<endl;
        cout<<endl;
        display_account_holder_details();
        if(mn==0)
        {
            cout<<endl;
            cout<<"Last Transcation : Withdrawal"<<endl;
            cout<<endl;
        }
        else if(mn=1)
        {
            cout<<endl;
            cout<<"Last Transaction : Deposition"<<endl;
            cout<<endl;
        }

    }                                                                                       // END OF mini_statement()

   // FUNCTION FOR DISPLAYING ACCOUNT HOLDER DETAILS

    void display_account_holder_details()
    {

        cout<<endl;
        cout<<endl;
        cout<<"NAME : "<<name<<endl;
        cout<<"MOBILE NUMBER : "<<mob<<endl;
        cout<<"TYPE OF ACCOUNT : "<<type<<endl;
        cout<<"ACCOUNT NUMBER : "<<ac<<endl;
        cout<<"AGE : "<<age<<endl;
        check_balance();

    }                                                                                              // END OF display_account_holder_details()

    // FUNCTION FOR DISPLAYING MAIN MENU OF BANK

    void menu()
    {

        int ch;
        h:                                                                                        // LABEL OF GOTO STATEMENT
        cout<<endl;
        cout<<endl;
        cout<<"FOLLOWING OPTIONS ARE AVAILABLE : "<<endl<<endl;
        cout<<endl;
        cout<<"1 . Create new account "<<endl;
        cout<<"2 . Edit details of currently available account "<<endl;
        cout<<"3 . Check balance of your account "<<endl;
        cout<<"4 . To deposit cash in account "<<endl;
        cout<<"5 . To withdraw cash from account "<<endl;
        cout<<"6 . To print mini statement "<<endl;
        cout<<"7 . To display account holder details "<<endl<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"ENTER YOUR CHOICE : ";
        cin>>ch;

        switch(ch)
        {

            case 1:
            create_account();
            break;

            case 2:
            edit_details();
            break;

            case 3:
            check_balance();
            break;

            case 4:
            deposit();
            break;

            case 5:
            withdraw();
            break;

            case 6:
            mini_statement();
            break;

            case 7:
            display_account_holder_details();
            break;

            default:
            cout<<"You have entered wrong option , please choose again"<<endl;
            goto h;                                                                                        // JUMP STATEMENT TO EXECUTE MENU() AGAIN

        }                                                                                                // END OF SWITCH
        char chh;
        cout<<endl;
        cout<<endl;
        cout<<"Do you want to continue ?"<<endl;
        cout<<"Enter Y or y to continue and N or n to exit"<<endl;
        cin>>chh;
        if(chh=='Y' || chh=='y')
        goto h;
        else
        {
            cout<<endl;
            cout<<endl;
            cout<<"THANKYOU FOR USING OUR SERVICES !!!"<<endl;
            cout<<endl;
            cout<<endl;
            exit(0);
        }
    }                                                                                             // END OF menu()

    // FUNCTION FOR DISPLAYING WELCOME MESSAGE

    void welcome()
    {

        cout<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"*************************"<<endl;
        cout<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"*                       *"<<endl;
        cout<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"*  WELCOME TO BBA BANK  *"<<endl;
        cout<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"*                       *"<<endl;
        cout<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"*************************"<<endl<<endl<<endl;
        cout<<endl;
        //cout<<"Enter any key to contiue"<<endl;
        //getch();
       // system("cls");
        menu();

    }                                                                                                  // END OF welcome()


};                                                                                                     //END OF CLASS


int main()
{
    Bank ob;
    ob.welcome();
    return 0;
}                                                                                                     // END OF main()

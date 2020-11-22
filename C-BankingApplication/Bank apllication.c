//Program for BANKING APPLICATION PORTAL..

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 999
//structure of account holder
struct account
{
    char name[50];
    int account_no;
    float balance;
    int pin;
}customers[999];
int n=0;

//Initialize Admin pin to zero
int admin_pin=0;

//validate function to get number of digits
int validate(int number)
{
    int count=0;
    while(number!=0)
    {
        number/=10;
        count++;


    }
    return count;
}

//admin registration
int admin_registration()
{
    int i=1,number,acc_number,pin,chance=0,flag=1;
    printf("\n Enter the number of customers:");
    scanf("%d",&number);
    while(i<=number)
    {
        if(n>max)
        {
            printf("\n please increase size..");
            return;
        }
        printf("\n Enter account number(must have 5-digit):");
        scanf("%d",&acc_number);
        if(search(acc_number)==-1 && validate(acc_number)==5)
            customers[n].account_no=acc_number;
        else
        {
            printf("\n Not valid account number.. or account alredy exist..");
            continue;
        }
        printf("\n Enter account name:");
        scanf("%s",&customers[n].name);
        while(chance<=3)
        {
        printf("\n Enter 4-digit pin:");
        scanf("%d",&pin);
        if(validate(pin)==4)
        {
            customers[n].pin=pin;
            break;
        }

        else
        {
            printf("\n pin is not valid");
            flag=0;
        }
        chance++;

        }
        if (flag==1)
            n++;
        else
            printf("\n This particular registration failed");
        i++;
    }
    printf("\n registration sucessful..");
    return;


}

//displaying customers
int display()
{

    int i=0;
    if(n==0)
    {
        printf("\n no customers...");
        return;
    }

    while(i<n)
    {

        printf("\n------Details of customer %d-----",i+1);
        printf("\n Account number:%d",customers[i].account_no);
        printf("\n name          :%s",customers[i].name);
        printf("\n Balance       :%f",customers[i].balance);
        i++;

    }
}

//Admin operrations
int admin_operation()
{
    int option;
    do
    {
    printf("\n 1.register customers \n 2.display customers \n 3.exit");
    printf("\n enter your option:");
    scanf("%d",&option);
    switch(option)
    {

    case 1:
        admin_registration();
        break;
    case 2:
        display();
        break;
    case 3:
        return;
        break;
    default:
        printf("\n enter correct option");

    }
    }while(option!=3);
}


//Admin main function
int admin()
{
    printf("\n -----Welcome to Admin pannel-----");
    if(admin_pin==0)
    {
        int new_pin,confirm_pin;
        int count=0;
        printf("\n Please set pin..(pin must have  six digits)");
        while(count<=3)
        {
        printf("\n Enter new pin:");
        scanf("%d",&new_pin);
        printf("\n confirm pin:");
        scanf("%d",&confirm_pin);
        if(new_pin==confirm_pin && validate(new_pin)==6 && validate(confirm_pin)==6)
        {
            admin_pin=new_pin;
            printf("\n thank you!");
            admin_operation();
            return;
        }
        else
        {
            printf("\n pin does not satisfies condtion..");
        }
        count++;
        }
        printf("\n pin setting terminated ...please try after some time");
        return;

    }
    else
    {
        int temp;
        int count=1;
        while(count<=3)
        {
        printf("\n Enter admin pin:");
        scanf("%d",&temp);
        if(temp==admin_pin)
        {
            admin_operation();
            return;
        }
        else
        {
            printf("\n Wrong pin try again:");
        }
        count++;
        }
        printf("\n admin login terminated ... try after some time..");
        return;

    }



}
//Search for the customers
int search(int key)
{

    for(int i=0;i<n;i++)
    {
        if(customers[i].account_no==key)
        {
            printf("\n %d",customers[i].account_no);
            return i;
        }
    }
    return -1;
}

// Function for deposit
int deposit(int pos)
{
    float amount;
    printf("\n Enter the amount to be deposited:");
    scanf("%f",&amount);
    customers[pos].balance+=amount;
    printf("\n Deposited sucessfully..");
    printf("\n new balance:%f",customers[pos].balance);
    return 0;



}

//Function for withdraw
int withdraw(int pos)
{
    float amount;
    printf("\n Enter the amount to be withdrawn:");
    scanf("%f",&amount);
    if(amount>customers[pos].balance)
    {
        printf("\n insufficient funds..");
        printf("\n  Balance:%f",customers[pos].balance);
        return;
    }
    else{
       customers[pos].balance-=amount;
       printf("\n  Balance:%f",customers[pos].balance);
       printf("\n Withdrawn sucessfully..");


    }
    return 0;

}

//Function for money transfer
int money_transfer(int pos)
{
    int acc_number,result;
    float amount;
    int count=1;
    while(count<=3)
    {
    printf("\n Enter destination account number:");
    scanf("%d",&acc_number);
    result=search(acc_number);
    if(result==-1 || pos==acc_number)
    {
        printf("\n invalid account number");

    }
    else{
        printf("\n Enter amount:");
        scanf("%f",&amount);
        if(balance>=amount)
        {
        customers[pos].balance-=amount;
        customers[result].balance+=amount;
        printf("\n Transaction sucessful..");
        return;
        }
        else
        {
            printf("\n Insufficient funds..");
            return;
        }

    }
    count++;
    }
    printf("\n Transaction failed...");

}

//customer operations
int customer_operation(int pos)
{
    int option;
    do
    {
    printf("\n ---------welcome %s-------",customers[pos].name);
    printf("\n 1.Deposit\n 2.Withdraw \n 3.Balance Enqiury \n 4.Money transfer \n 5.exit");
    printf("\n Enter your option:");
    scanf("%d",&option);

        switch(option)
        {
        case 1:
            deposit(pos);
            break;
        case 2:
            withdraw(pos);
            break;
        case 3:
            printf("\n account balance:%f",customers[pos].balance);
            break;
        case 4:
            money_transfer(pos);
            break;
        case 5:
            return;
            break;
        default:
            printf("\n invalid option");

        }
    }while(option!=5);

}


//customer login
int login()
{
    int account_number,result,count=1,chance=1;
    int pin;
    while(count<=3)
    {
    printf("Enter account number:");
    scanf("%d",&account_number);
    result=search(account_number);
    if(result==-1)
    {
        printf("\n invalid account number");
        return;
    }
    else
    {
        while(chance<=3)
        {
        printf("\n Enter pin:");
        scanf("%d",&pin);
        if(pin==customers[result].pin)
        {
            customer_operation(result);
            return;
        }
        else
        {
           printf("\n wrong pin..");
        }
        chance++;
        }
        printf("\n login terminated");
        return;
    }
    count++;
    }
    printf("\n login terminated...");



}

//customer Registration
int registration()
{
    int new_pin,confirm_pin,acc_number;
    int count=1,chance=1;
    printf("\n ----------- Registration portal-----------");
    if(n<max)
    {
    printf("\n Enter your account number:");
    scanf("%d",&acc_number);
    if(search(acc_number)!=-1)
    {
        printf("\n This account already registered..");
        return;
    }
    while(chance<=3)
    {
    if(validate(acc_number)==5)
    {
    while(count<=3)
    {
    printf("\n Enter new pin(must be 4 digit)");
    scanf("%d",&new_pin);
    printf("\n confirm  pin:");
    scanf("%d",&confirm_pin);
    if(new_pin==confirm_pin && validate(new_pin)==4 && validate(confirm_pin)==4)
    {
        customers[n].account_no=acc_number;
        customers[n].pin=new_pin;
        printf("\n Registration sucessful..");
        customer_operation(n);
        n++;
        return;

    }
    else
        printf("\n pin does not match");
    count++;
    }
    }
    else{
        printf("\n Account number not valid..");
    }
    chance++;
    }
    printf("portal locked try after some time..");
    }
    else
        printf("\n please increase size..");
    return;
}


// Customer main function
int customer()
{

    int option;
    do{
        printf("\n ------------ customer portal------------");
        printf("\n 1.login \n 2.register \n 3.exit");
        printf(" Enter your option:");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
            login();
            break;
        case 2:
            registration();
            break;
        case 3:
            return;
            break;
        default:
            printf("\n invalid option");

        }
    }while(option!=3);


}

//main function
int main()
{
    int choice;
    do
    {
    printf("-----------Bank Application portal-----------");
    printf("\n 1.Customer \n 2.Admin\n 3.exit");
    printf("\n Enter your option:");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        customer();
        break;
    case 2:
        admin();
        break;
    case 3:
        exit(0);
        break;
    default:
        printf("\n Enter correct option:");
    }

    }while(choice!=3);
}

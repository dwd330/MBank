#include <iostream>
#include <iomanip> //output formating
#include <windows.h> //for sleep time ,beep function
using namespace std;

 // client data using linked list

    struct node
    {
        string name;
        int id;
        int balance;
        float loan;
        int paytime ;
        float fees;
        int irate;
        node *next;
    };
    node *start_ptr =NULL; //head


//function deceleration
void add_to_end(node *&start, string name,int id,int balance,float loan,
                int irate,int paytime,float fees);
void display();
void delete_id(int id);
void transaction(int id);
bool idcheck(int id);
void conform();
void transfer(int id1,int id2) ;

//variables
    string name;
    int id ;
    int balance;
    int paytime;  //for the loan
    int irate;  //interest rate
    float fees; //bank fees
    float amount ; //amount $
    int c;  //choice number


int main()
{
    cout << "                 --> mini bank <--         " << endl; //bank name

    //security
    int password;
    cout << "  enter you password :"; //admin password
    cin>>password;
    while (password !=1234)
    {
        cout << "  enter you password :"; //admin password
        cin>>password;
        if (password!=1234)
        {
           for (int i=1000;i<1500;i+=100)
                Beep(4000,i);


        }

    }


cout << endl<< endl<< "            welcome    " << endl; //bank name

do
{
cout<<endl<<endl;
cout<<"------- Main system (press (0) for exit) -------"<<endl<<endl;
cout<<"     1- add user"<<endl<<endl;
cout<<"     2- delete user"<<endl<<endl;
cout<<"     3- show all users"<<endl<<endl;
cout<<"     4- transactions"<<endl<<endl;
cout<<"     5- transfer"<<endl<<endl;
cout<<"     6- about"<<endl<<endl;
cout <<" >>>make your choice: ";
cin>> c; //for choice
Sleep(1000); //wait 1 sec

switch (c)
{
case 0:break;

case 1:
    cout <<" enter user name :";
    cin>> name;
    cout <<" enter user id :";
    cin>> id;
    while(idcheck(id)==0) //check if id repeated
    {
        cout <<" this user id is occupied"<<endl;
        cout <<" enter different user id :";
        cin>> id;
    }
    cout <<" enter user balance :";
    cin>> balance;
    add_to_end(start_ptr, name,id,balance,0,0,0,0);
    Sleep(1000); //wait 1 sec

 break;


case 2: //delete by id
    cout <<" enter user id :";
    cin>> id;
    if(idcheck(id)==0) //check if id exist
    {
        delete_id(id);
    }
    else
        cout<<" user id does not exist.try again"<<endl;


 break;


case 3:
display(); break; //show all users


case 4: //transaction
    cout <<" enter user id :";
    cin>> id;

    if(idcheck(id)==0) //check if id exist
    {
        transaction(id);
    }
    else
        cout<<" user id does not exist.try again"<<endl;

break;


case 5: //transfer
    int id1,id2;
    cout <<" enter donor id :";
    cin>> id1;
    cout <<" enter acceptor id :";
    cin>> id2;

     if (idcheck(id1 ) ==0 && idcheck(id2) == 0 )
        {
            transfer(id1,id2) ;

        }
    else
            cout<<" user id does not exist.try again"<<endl;


break;

case 6://about
    cout<<endl<<endl;
    Sleep(1000);
    cout<<"this is a progam about bank account written in c++ late 2017"<<endl<<endl;
    cout<<"issued for DSA course by prof/ h.turkey"<<endl<<endl;
    cout<<"credit:"<<endl<<endl;
    cout<<"mohamed ali dawoud "<<endl<<endl;
    cout<<"mohamed saad "<<endl<<endl;
    cout<<"mohamed mostafa mohamed abdALgany"<<endl;


break;

default:
cout<<"ERROR: You Entered Wrong Choice Number. Try Again" <<endl;
break;
}

}
while(c!=0);



    return 0;
}


bool idcheck(int id)  //check for repeated id
{

if(start_ptr!=NULL)
{
        node *user1=new node;
        user1=start_ptr;

        while(user1->id !=id && user1->next !=NULL)
            {
                user1=user1->next;
            }
    if(user1->id == id)
        {
           return false;  //input  id exist
        }
    else { return true;}
}
else
    {return true;}

}

void conform() //conformation massage
    {
        cout <<endl<<"processing";
        for (int l=0;l<20;l++)
        {
            cout <<". ";
            Sleep(50);
        }
        cout <<endl<<"operation complete."<<endl;
    }
void transfer(int id1,int id2)  //transfer to account
{


if(start_ptr!=NULL)

{

       //--id-- find user1
    node *user1=new node;
    user1=start_ptr;
        while(user1->id !=id1)
            {
                user1=user1->next;
            }
        //--id-- find user2
    node *user2=new node;
    user2=start_ptr;
        while(user2->id !=id2)
            {
                user2=user2->next;
            }

       //transfer
    cout<<"enter amount in $:";
    cin>>amount;
    user1->balance=user1->balance -amount;
    user2->balance=user2->balance +amount;
    conform(); //conformation
}
else
    cout<<"error"<<endl;

}


//Add a node to the end of the list
void add_to_end(node *&start, string name,int id,int balance,float loan,
                int irate,int paytime,float fees)
{
    node * new_node = new node;
        new_node->name= name; //filling data
        new_node->id= id;
        new_node->balance= balance;
        new_node->loan= loan;
        new_node->irate= irate;
        new_node->paytime= paytime;
        new_node->fees= fees;

    new_node->next = NULL;
    if (start == NULL) //if list is empty
        start = new_node;
    else
    {
        // go to the last node
        node *current_node = start;
        while (current_node->next != NULL)
            current_node = current_node->next ;
        current_node->next = new_node;
    }
    conform(); //conformation

}

//display all user
 void display()
  {
    cout<<endl;
    cout<<endl;
    cout <<
    setw(10) << left << "name" <<
    setw(10) << left << "id" <<
    setw(10) << left << "balance" <<
    setw(10) << left << "loan$"<<
    setw(10) << left << "irate"<<
    setw(10) << left << "paytime"<<
    setw(10) << left << "fees" << endl;

    node *temp=new node;
    temp=start_ptr;

    while(temp!=NULL)
    {
        cout<<"-------------------------------------------------------------------"<<endl;
        cout <<
        setw(10) << left << temp->name <<
        setw(10) << left <<temp->id <<
        setw(10) << left <<temp->balance <<
        setw(10) << left <<temp->loan <<
        setw(10) << left <<temp->irate <<
        setw(10) << left <<temp->paytime <<
        setw(10) << left << temp->fees << endl;
        Sleep(500); //wait 2 sec


       temp=temp->next;
    }
    cout<<endl<<endl;;
  }

//delete by id

 void delete_id(int id)
  {

        node *current=new node;
        node *previous=new node;
        current=start_ptr;
        //if it the first node
        if(start_ptr->id ==id)
        {
            node *temp=new node;
            temp=start_ptr;
            start_ptr=start_ptr->next;
            delete temp;
        }

        else
        {
            while(current->id !=id)
            {
                previous=current;
                current=current->next;
            }
            previous->next=current->next;
        }

        conform(); //conformation

  }



void transaction(int id)
{

//--id-- find user

    node *user=new node;
    user=start_ptr;
        while(user->id !=id)
            {
                user=user->next;
            }



// ---transaction---


    //inputs
    cout<<endl;
    cout <<"      1-deposit"<<endl<<endl;
    cout <<"      2-withdraw"<<endl<<endl;
    cout <<"      3- loan"<<endl<<endl;
    cout <<" >>>make your choice : ";
    c=0;
    cin >>c;

Sleep(1000); //wait 1 sec

switch (c)
{

case 1://deposit
    cout <<" enter amount in $ :";
    cin>> amount;
    user->balance=user->balance +amount;
    conform(); //conformation
    cout << amount <<" added to " <<user->name <<endl;


 break;



case 2://withdraw
    cout <<" enter amount in $ :";
    cin>> amount;
    if (user->balance -amount >=0)
    {
        user->balance=user->balance -amount;
        conform(); //conformation
        cout << amount <<" withdraw from " <<user->name <<endl;

    }

    else
        cout <<" error"<<endl;

 break;



case 3://loan

    cout <<" enter amount of loan $:";
    cin>> amount; //loan value $
    cout <<" enter interest rate (%):";
    cin>> irate;  //interest rate
    cout <<" enter user loan-time(years) :";
    cin>> paytime;   //how long is the loan

    fees=(irate*amount)/100;

    //add to user
    user->balance=user->balance +amount;   //add loan to balance
    user->loan=amount;
    user->paytime=paytime;
    user->fees=fees;
    user->irate=irate;
    conform(); //conformation

 break;


default:
cout<<"error . Try Again" <<endl;
break;
}


}

//end




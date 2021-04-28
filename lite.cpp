#include <iostream>
#include <iomanip> //output formating
using namespace std;

// client data using linked list
    struct node
    {
        string name;
        int id;
        int balance;
        node *next;
    };
    node *start_ptr =NULL; //head

//function deceleration
    void add_to_end(node *&start, string name,int id,int balance);
    void transaction(int id);
    void display();

//variables
    string name;
    int id ;
    float balance;
    int c;  //choice number
int main()
{
        cout << "                 --> mini bank <--         " << endl; //bank name
do
    {
    cout<<endl<<endl<<"------- Main system (press (0) for exit) -------"<<endl<<endl;
    cout<<"     1- add user"<<endl<<endl;
    cout<<"     2- show all users"<<endl<<endl;
    cout<<"     3- transactions"<<endl<<endl;
    cout <<" >>>make your choice: ";
    cin>> c; //for choice
    switch (c)
        {
        case 0:break;
        case 1:
            cout <<" enter user name :";
            cin>> name;
            cout <<" enter user id :";
            cin>> id;
            cout <<" enter user balance :";
            cin>> balance;
            add_to_end(start_ptr, name,id,balance);break;

        case 2:
            display(); break; //show all users

        case 3: //transaction
            cout <<" enter user id :";
            cin>> id;
            transaction(id);break;
        }
    }
while(c!=0);

    return 0;
}

//  ---function implementations---

//Add a node to the end of the list
void add_to_end(node *&start, string name,int id,int balance)
{
    node * new_node = new node;
        new_node->name= name; //filling data
        new_node->id= id;
        new_node->balance= balance;

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
}

//display all user
 void display()
  {
    node *temp=new node;
    temp=start_ptr;

    while(temp!=NULL)
    {
        cout <<
        setw(10) << left << temp->name <<
        setw(10) << left <<temp->id <<
        setw(10) << left <<temp->balance << endl;
        temp=temp->next;
    }
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

    cout <<"      1-deposit"<<endl<<endl;
    cout <<"      2-withdraw"<<endl<<endl;
    cout <<" >>>make your choice : ";
    c=0; //reuse variable c
    cin >>c;
    cout <<" enter amount in $ :";
    float amount ; //amount $
    cin>> amount;
    switch (c)
    {
        case 1://deposit
            user->balance=user->balance +amount;break;

        case 2://withdraw
            user->balance=user->balance -amount;break;
    }
}











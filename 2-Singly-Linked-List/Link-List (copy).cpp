#include<iostream>
using namespace std;

    struct node{
        int info;
        node *next;
    };

class Array{

    private:
        node *head;
        node *temp, *temp1;

    public:
        Array();
        void add();
        void print();
        void options();
        void funs();
};

    Array::Array()
    {
        head = temp = temp1 = NULL;
    }

    void Array::add()
    {
        int Key;        
        if(head == NULL)
        {
            head = new node;
            cout<<"Enter Data: ";
            cin>>head->info;
            head->next= NULL;
            return;
        }
        temp = head;
        cout<<"Enter Number to insert After that: ";
        cin>>Key;
        while(temp != NULL)
        {
            if(temp->info == Key)
            {
                temp1 = new node;
                cout<<"Enter Number to Insert: ";
                cin>>temp1->info;
                cout << temp1->info << endl;
                temp1->next = temp->next;
                cout << temp1->next << endl;
                temp->next= temp1;
                
            }
            temp = temp->next;
            cout << temp << "Hello" << endl;
        }
        // if(temp->info != Key)
        // {
        //     cout<<"Number Not Found"<<endl;
        // }
    }

    void Array::print()
    {
        //temp = head;
        // if(head == NULL)
        // {
        //     cout<<"There is No Number../n First Add Some Numbers"<<endl;
        // }

        if (head == NULL)
            cout << "Nothing Found!\n";

        while(head != NULL)
        {
            cout<<temp->info<<endl;
            temp = temp->next;
        }
    } 

    void Array::options()
    {
        cout<<"Enter Number to Run that Function"<<endl;
        cout<<"Enter 1 to Print"<<endl;
        cout<<"Enter 2 to Add"<<endl;
        cout<<"Enter 3 to Exit"<<endl;
    }

    void Array::funs()
    {
        cout<<"Enter 1 to Continue...\nEnter 2 to Exit..."<<endl;
        int vl;
        cin>>vl;
        if(vl == 1)
        {
            Array::options();
            int opt;
            cout<<"Select: ";
            cin>>opt;
            switch (opt)
            {
            case 1:
                Array::print();
                Array::funs();
                break;
            case 2:
                Array::add();
                Array::funs();
                break;
            case 3:
                cout<<"Function is Exit.."<<endl;
                break;
            default:
                cout<<"Invalid Input / Number..."<<endl;
                break;
            }
        }
        if(vl == 2)
        {
            cout<<"Progarm Exit"<<endl;
        }
    }

int main()
{
    Array n;
    for(int i = 0; i < 3; i++)
        n.add();
    n.print();
    // n.funs();
    return 0;
}
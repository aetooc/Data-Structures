#include<iostream>

using namespace std;

struct node{
    int info;
    node* previous;
    node* next;
};

class List{

    private:
        node* head;
        node* temp, *temp1;
        int key;
        bool found = false;

    public:
        List();
        void Insert();
        void InsertAtEnd();
        void Delete();
        void Print();
        // ~List();
};

List::List(){
    head = temp = temp1 = NULL;
}

void List::Insert(){
    if (head == NULL){
        head = new node;
        cout << "Enter Your Data You Want To Enter: ";
        cin >> head->info;
        head->next = head;
        head->previous = head;
    }
    else{
        temp = head;
        cout << "Enter element after which you want to enter: ";
        cin >> key;

        do{
            if(temp->info == key){
                found = true;
                temp1 = new node;
                cout << "Enter New Data: ";
                cin >> temp1->info;
                temp1->next = temp->next;
                temp1->previous = temp;
                temp->next = temp1;
                temp1->next->previous = temp1;
            }
            temp = temp->next;

        }while(temp != head);

        if (found == false){
            cout << key << " not found!\n";
        }
    }
}

void List::Delete(){
    if (head == NULL){
        cout << "No Data Found!\n";
        return;
    }
    else{
        cout << "Enter the Key You Want to Delete: ";
        cin >> key;
        temp = head;

        do{
            if(temp->info == key){
                if(temp == head){
                    head->previous->next = head->next;
                    head->next->previous = head->previous;
                    temp = temp->next;
                    delete head;
                    head=temp=NULL;
                    return;
                }
                else{
                    temp->previous->next = temp->next;
                    temp->next->previous = temp->previous;
                    temp1 = temp;
                    delete temp1; temp1 = NULL;
                    temp = head;
                }
                
            }temp = temp->next;
        }while(temp != head);
    }
}

void List::InsertAtEnd(){

    if (head == NULL){
        head = new node;
        cout << "Enter Your Data You Want To Enter: ";
        cin >> head->info;
        head->next = head;
        head->previous = head;
    }

    else{
        temp = head;
        temp1 = new node;
        cout << "Enter Data: ";
        cin >>temp1->info;
        temp1->previous = temp->previous;
        temp1->next = temp;
        temp->previous->next = temp1;
        temp->previous = temp1;
        return; 
    }
}

void List::Print(){
    if (head != NULL){
        temp = head;
        cout << "\nLink List Data: \n";
        do{
            cout << temp->info << " ";
            temp = temp->next;
        }while(temp != head);
        cout << endl;
    }

    else
        cout << "Link List is empty.\n";
}

// List::~List(){

// }

int main(){
    List obj;

    obj.Insert();
    obj.Print();
    obj.Delete();
    obj.Print();
    obj.Insert();
    obj.Print();
}
//Hello World
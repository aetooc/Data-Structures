#include <iostream>

using namespace std;

struct node{
    int info;
    node* next;
};

class List{
    private:
        node* head;
        node *temp, *temp1;
        int key;
    
    public:
        List();
        void Print();
        void Insert();
        void Search();
        void Delete();
        ~List();

};

List::List(){
    head = temp = temp1 = NULL;
}

void List::Print(){
    if (head != NULL){
        temp = head;
        
        while(temp != NULL){
            cout << temp->info << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    else
        cout << "Link List is empty.\n";
}

void List::Search(){
    bool check = false;

    if(head != NULL){
        temp = head;
        cout << "Enter the item you want to search: ";
        cin >> key;

        while (temp != NULL){
            if (temp->info == key){
                cout << key << " Found!\n";
                check = true;
            }
            temp = temp->next;
        }

        if (check == false){
            cout << "Key not found!\n";
        }
        
    }

    else
        cout << "Link List is empty.\n";

}

void List::Insert(){
    if (head == NULL){
        head = new node;
        cout << "Please Enter Data: ";
        cin >> head->info;
        head->next = NULL;
        return;
    }

    else{
        temp = head;
        cout << "Enter item after which You want to insert new data: ";
        cin >> key;

        while(temp != NULL){
            if (temp->info == key){
                temp1 = new node;
                cout << "Enter new data: ";
                cin >> temp1->info;
                temp1->next = temp->next;
                temp->next = temp1;
            }
            temp = temp->next;
        }
    }
}

void List::Delete(){
    if (head == NULL){
        cout << "No Element Found!\n";
        return;
    }

    else{
        temp = head;
        bool check = false;
        cout << "Enter the element you want to delete: ";
        cin >> key;

        while(temp != NULL){
            if (temp->next->info == key){
                temp1 = temp->next;
                temp->next = temp->next->next;
                delete temp1;
                temp1 = NULL;
                check = true;
            }
            temp = temp->next;
        }

        if (check == false)
            cout << "Element Not Found!\n";
    }
}

List::~List(){
    delete head;
    delete temp;
    delete temp1;
}


int main(){
    List obj;
    int ch;
    char cha;

    do{
        cout << "\nUser Menu: \n\n1.Search\n2.Insert\n3.Print\n4.Deletion\n5.Exit\n> ";
        cin >> ch;
        switch(ch){
            case 1:
                obj.Search();
                break;
            case 2:
                obj.Insert();
                break;
            case 3:
                obj.Print();
                break;
            case 4:
                obj.Delete();
                break;
            default:
                break;
        }
        if (ch != 5){
            cout << "Menu(Y/N): ";
            cin >> cha;
        }
    }while(cha == 'Y' || cha == 'y');
}
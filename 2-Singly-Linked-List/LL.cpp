#include <iostream>

using namespace std;

struct node{
    int info;
    node* next;
};

class Array{
    private:
        node* head;
        node *temp, *temp1;
        int item;
    
    public:
        Array();
        void Display();
        void Add();
        void Find();
        void Delete();

};

Array::Array(){
    head = NULL;
    temp = NULL;
    temp1 = NULL;
}

void Array::Display(){
    if (head != NULL){
        temp = head;
        
        while(temp != NULL){
            cout << temp->info << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    else
        cout << "Link Array is empty.\n";
}

void Array::Find(){
    bool check = false;

    if(head != NULL){
        temp = head;
        cout << "Enter the item you want to Find: ";
        cin >> item;

        while (temp != NULL){
            if (temp->info == item){
                cout << item << " Found!\n";
                check = true;
            }
            temp = temp->next;
        }

        if (check == false){
            cout << "item not found!\n";
        }
        
    }

    else
        cout << "Link Array is empty.\n";

}

void Array::Add(){
    if (head == NULL){
        head = new node;
        cout << "Please Enter Data: ";
        cin >> head->info;
        head->next = NULL;
        return;
    }

    else{
        temp = head;
        cout << "Enter item after which You want to Add new data: ";
        cin >> item;

        while(temp != NULL){
            if (temp->info == item){
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

void Array::Delete(){
    if (head == NULL){
        cout << "No Element Found!\n";
        return;
    }

    else{
        temp = head;
        bool check = false;
        cout << "Enter the element you want to delete: ";
        cin >> item;

        while(temp != NULL){
            if (temp->next->info == item){
                temp1 = temp->next;
                temp->next = temp1->next;
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


int main(){

    Array obj;

    // obj.Find();
    // obj.Add();
    // obj.Display();
    // obj.Delete();


    
}
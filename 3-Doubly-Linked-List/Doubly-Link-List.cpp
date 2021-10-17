#include <iostream>

using namespace std;

struct node{
    int info;
    node* next;
    node* previous;
};

class List{

    private:
        node* head;
        node* temp, *temp1;
        int key;

    public:
        List();
        void Print();
        void Insert();
        void Search();
        void Delete();
        // ~List(); 
};

List::List(){
    head = temp = temp1 = NULL; 
}

void List::Insert(){
    if (head == NULL){
        head = new node;
        cout << "Enter any data: ";
        cin >> head->info;
        head->next = head->previous = NULL;
        return;
    }

    else{
        temp = head;
        cout << "Enter key after which you want to insert: ";
        cin >> key;

        while(temp != NULL){
            if (temp->info == key){
                temp1 = new node;
                cout << "Insert Data: ";
                cin >> temp1->info;
                // cout<<"Done\n";
                temp1->next = temp->next;
                // cout<<"Done1\n";
                temp1->previous = temp;
                // cout<<"Done2\n";
                if(temp1->next != NULL)
                    temp1->next->previous = temp1;
                // cout<<"Done3\n";
                temp->next = temp1;
                
            }
            temp = temp->next;
        }
    }
}

void List::Delete(){
    if (head == NULL){
        cout << "Nothing\n";
        return;
    }
    else{
        temp = head;
        cout << "Enter The Element You Want To Delete!: ";
        cin >> key;
        if (head->next == NULL){
            if(temp->info == key){
                delete temp;
                temp = head = NULL;
                return;
            }
        }
        else{

            while(temp != NULL){
                if(temp->info == key){
                    if (temp->previous == NULL){
                        head = head->next;
                        head->previous = NULL;
                        temp1 = temp;
                        temp = temp->next;
                        delete temp1; temp1  = NULL;
                    }
                    else if (temp->next == NULL){
                        temp->previous->next = NULL;
                        temp1 = temp;
                        temp = temp->previous;
                        delete temp1; temp1 = NULL;
                    }
                    else{
                        temp->previous->next = temp->next;
                        temp->next->previous = temp->previous;
                        temp1 = temp;
                        temp = temp->previous;
                        delete temp1; temp1 = NULL;
                    }

                }
                temp = temp->next;
            }
        }
    }
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

int main(){
    List obj;
    obj.Insert();
    // obj.Insert();
    // obj.Insert();
    obj.Delete();
    obj.Print();

}
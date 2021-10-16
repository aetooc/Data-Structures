#include <iostream>

using namespace std;

struct node{
    int info;
    node *next;
};

class Queue{
    private:
        node* front, *end, *temp;
        int count, limit, key;

    public:
        Queue();
        void Enqueue();
        void Dequeue();
        void Display();
        void Front();
        void End();
};

Queue::Queue(){
    front = end = NULL;
    count = key = 0;
    cout << "Set Limit: ";
    cin >> limit;
}

void Queue::Enqueue(){
    if(count == limit)
        cout << "Queue Overflows!\n";
    else{
        if(count == 0){
            temp = new node;
            cout << "Enter Data: ";
            cin >> temp->info;
            temp->next = end;
            front = end = temp;
            count++;
        }

        else{
            temp = new node;
            cout << "Enter Data: ";
            cin >> temp->info;
            end->next = temp;
            end = temp;
            end->next = NULL;
            count++;
        }
    }

}

void Queue::Dequeue(){
    if (count == 0)
        cout << "Queue Underflows!\n";
    else{
        temp = front;
        front = front->next;
        delete temp;
        temp = NULL;
        count--;
    }
}

void Queue::Front(){
    if (count != 0)
        cout << "The Front Element is " << front->info << endl;
    else
        cout << "Queue Underflows!\n";
}

void Queue::End(){
    if (count != 0)
        cout << "The End Element is " << end->info << endl;
    else
        cout << "Queue Underflows!\n";
}

void Queue::Display(){
    if (count == 0){
        return;
    }
    else{
        temp = front;
        while(temp != NULL){
            cout << temp->info << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main(){
    Queue q;
    for(int i = 0; i <= 10; i++ )
        q.Enqueue();
    q.Display();
    q.Dequeue();
    q.Dequeue();
    q.Display();
    q.Front();
    q.End();

}
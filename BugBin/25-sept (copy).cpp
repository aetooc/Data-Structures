#include <iostream>

using namespace std;

class List{

    private:
        int* ptr = NULL;
        int* currentPtr = NULL;
        int length = 0, size = 8, arr[8];

    public:
        List();
        void Add();
        void Add(int index);
        void Print();
        // ~List();

};

List::List(){
    ptr = arr;
    currentPtr = arr;
}

void List::Add(){
    if (currentPtr != (arr+7)){
        cout << "Please enter any number: ";
        cin >> *ptr;
        length++;
        currentPtr = ptr;
        ptr++;
    }

    else{
        cout << "No Access!";
        ptr = arr;
    }
}

void List::Add(int index){
    if (currentPtr != (arr+7)){
        for(int i = 0; i < length - index; i++ ){
            *ptr = *currentPtr;
            ptr--; currentPtr--;
        }
        cout << "Please enter any number: ";
        cin >> *ptr;
        length++;
        currentPtr = (currentPtr + length);
        ptr = (currentPtr + length + 1);
    }

    else{
        cout << "No Access!\n";
        ptr = arr;
    }
}

void List::Print(){
    cout << "--------------\n";
    cout << length;
    for(int i = 0; i < length; i++){
        cout << *(arr + i) << ", ";
    }
    cout << endl;
}

int main(){
    List l1;

    for(int i = 0; i < 6; i++)
        l1.Add();
    l1.Print();
    l1.Add(6);
    l1.Add(7);
    l1.Print();
    return 0;
}
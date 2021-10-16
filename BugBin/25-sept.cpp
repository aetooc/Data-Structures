#include <iostream>

using namespace std;

class List{

    private:
        int* ptr = NULL;
        int* currentPtr = NULL;
        int length = 0, size = 8, arr[8];

    public:
        List();
        void Get();
        void Update(int num);
        void Length();
        void Back();
        void Next();
        void Start();
        void End();
        void Remove(int index);
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

void List::Remove(int index){
    currentPtr = (arr + index);
    ptr = (arr + index + 1);
    for (int i = 0; i < length - index; i++){
        *currentPtr = *ptr;
        ptr++; currentPtr++;
    }
    length--;
    currentPtr = (arr + length);
    ptr = (arr + length + 1);
}

void List::Start(){
    currentPtr = (arr + 0);
    ptr = (arr + 0);
}

void List::End(){
    currentPtr = (arr + (size - 1));
    ptr = (arr + (size - 1));
}

void List::Print(){
    cout << "--------------\n";
    for(int i = 0; i < length; i++){
        cout << *(arr + i) << ", ";
    }
    cout << endl;
}

void List::Back(){
    if(currentPtr != (arr + 0)){
        currentPtr--; ptr--;
    }
    else
        cout<< "You're at index 0\n";
}

void List::Update(int num){
    bool check = false;
    for(int i = 0; i < length; i++){
        if(num == *(arr + i)){
            cin >> *(arr + i);
            check = true;
        }
    }
    if (check == false)
        cout << "Number Not Found!\n";

}

void List::Next(){
    if( ptr != (arr + (size-1))){
        currentPtr++; ptr++;
    }
    else
        cout<< "You're at last index\n";
}

int main(){
    List l1;

    for(int i = 0; i < 7; i++)
        l1.Add();
    l1.Print();
    l1.Add(2);
    l1.Print();
    l1.Remove(2);
    l1.Print();
    l1.Update(5);
    l1.Print();
    return 0;
}
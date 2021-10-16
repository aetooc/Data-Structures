#include <iostream>

using namespace std;

class Stack{
    private:
        int* top, *temp;
        int count, limit, key;
        int* stack;
    
    public:
        Stack();
        void Push();
        void Pop();
        void Top();
        void Print();
};

Stack::Stack(){

    count = key = 0;
    cout << "Set Limit for Stack: ";
    cin >> limit;
    stack = new int [limit];
    top = stack;
    for(int i = 0; i < limit; i++){
        *(stack + i) = 0;
    }

}

void Stack::Push(){
    if (count == limit)
        cout << "Stack Overflow!\n";
    else{
        cout << "Enter Data: ";
        cin >> *(stack + count);
        if(count != 0)
            top++;
        count++;
    }
}

void Stack::Pop(){
    if (count == 0)
        cout << "Stack Underflow!\n";
    else{
        *top = 0;
        top--;
        count--;
    }
}

void Stack::Top(){
    cout << "Top Element is : " << *top << endl;
}

void Stack::Print(){
    for(int i = count-1; i >= 0; i--){
        if(i != 0)
            cout << *(stack + i) << ", ";
        else
            cout << *(stack + i);
    }
    cout << endl;
}

int main(){
    Stack st;
    st.Push();
    st.Push();
    st.Pop();
    st.Push();
    st.Push();
    st.Pop();
    st.Push();
    st.Print();
    st.Top();
}
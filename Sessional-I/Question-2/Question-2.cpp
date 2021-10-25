/*

Q. 2) Consider that Doubly Link List (DLL) of some nodes exists in memory. Ther is a 'current' pointer
which points to some node in DLL. Write a program that tells wheter 'crrent' pointer is near to the 
end of DLL or near to the head of DLL or having same distance from both ends. 

*/

#include <iostream>

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
        int count = 1, len = 0;
    
    public:
        void Insert();
        void Function();
}

void List:: Function(){
            temp = head;

            while (temp != NULL){
                count++;
                temp = temp->next;
            }

            if (len != 0){

                if(count < (len/2))
                    cout << "Current pointer is near to head.\n";
                else if(count > (len/2))
                    cout << "Current pointer is near to end.\n";

                if(len % 2 != 0){
                    if (count == (len/2)+1)
                        cout << "It's having same distance.\n";
                }
            }

            else
                cout << "DLL is empty!\n";


        }

int main(){
    List DLL;
    for(int i = 0; i < 5; i++)
        DLL.Insert()
    DLL.Function()
}
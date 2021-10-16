//__________________________________________________
// Question 1

// #include <iostream>

// using namespace std;

// int main(){

//     int x = 5;
//     int *ptrr = NULL;
//     ptrr = &x;
//     cout << *ptrr << endl;
//     cout << x << endl;
//     *ptrr = 9;
//     cout << &x << endl;
//     cout << *&ptrr << endl;
//     cout << &*ptrr << endl;
//     cout << ptrr << endl;
//     cout << *ptrr << endl;
//     cout << x << endl;
    
//     return 0;
// }

//__________________________________________________
// Question 2

// #include <iostream>
// #include<string.h>

// using namespace std;

// int main(){
//     string str= "datastructure";
//     int* intptr = new int;
//     char* namestr = new char[8];
//     *intptr = 357;
//     strcpy(namestr, "datastructure");

//     cout << *intptr << "\n" << namestr << endl;

//     delete [] namestr;
// }

//__________________________________________________
// Question 3

// #include <iostream>
// #include<stdio.h>
// using namespace std;

// struct node{
//     char info[15];
// };

// class trial{
//     private:
//         node obj1, *temp1, *temp2, *temp3;
//         int I, length;
//         char *p, *q;
//     public:
//         trial();
//         ~trial();
//         void startin();
// };

// int main(){
//     trial Ink;
//     Ink.startin();
// }

// trial::trial(){
//     temp1 = temp2 = temp3 = NULL;
//     // p = q = NULL;
// }

// trial::~trial(){
//     delete temp1;
//     delete temp2;
//     delete temp3;
//     delete [] p;
//     delete [] q;
// }

// void trial::startin(){
//     cout << "\nMaking use of 'new' and 'delete' is follows:\n";
//     cout << "\n---------------------------------------------\n";
//     temp1 = new node;
//     temp2 = new node;
//     cout << "\nEnter information about temp1: ";
//     cin >> temp1->info;
//     cout << "\nEnter information about temp2: ";
//     cin >> temp2->info;
    
//     temp3 = &obj1;
//     cout << "\n Enter infromation about temp3: ";
//     cin >> temp3->info;

//     cout << "\n Showing Information of Temp1: \n";
//     cout << temp1->info;
//     cout << "\n Showing Information of Temp2: \n";
//     cout << temp2->info;
//     cout << "\n Showing Information of Temp3: \n";
//     cout << temp3->info;
//     cout << "\n---------------------------------------------\n";
//     cout << "Now enter the length: ";
//     cin >> length;

//     p = new char[length];
//     q = p;
//     cout << "Now enter " << length << "characters to fill an array.\n";

//     for(int i = 0; i < length; i++){
//         cin >> *p;
//         p = p+1;
//     }
//     p = q;
//     cout << "\nElements of array are follows: ";
//     cout << endl;
//     for(int i = 0; i < length; i++){
//         cout <<*p << ",";
//         p = p+1;
//     } 
//     p = q;

// }

//___________________________________

#include<iostream>

using namespace std;
class test{
    private:
        int *ptr;
        int *current,*temp;
        int arr[8];
        int siz,total;
    public:
        test(){
            temp=current=ptr=NULL;
            siz=5;
            ptr=&arr[0];
            for(int i=0; i<5; i++){
                cin>>*ptr;
                temp=ptr;
                ptr=ptr+1;
            }
           // cout<<"_______"<<endl;
            ptr=arr;

           // print();
            current=&arr[2];
        }

        void print(){
            for(int i=0 ; i<8 ; i++){
                cout<<*ptr<<",";
                ptr=ptr+1;
            }
            ptr=arr;
            cout<<endl;
        }

        void add(int x){
            cout<<"-------------------"<<endl;
            while(temp!=current){
                *(temp+1)=*temp;
                temp=temp-1;
            }
            *(temp+1)=x;
            current=temp+1;
            siz=siz+1;
            //cout<<"-----"<<*temp<<"---"<<endl;
            //print();

        }
        void next(){
            //total=sizeof(arr)/sizeof(*arr);
            if(current != &arr[siz]){
                current=current+1;
                cout<<"next value of current is "<<*current<<endl;
            }
        }

        void back_(){
            if(current!=arr){
                current=current-1;
                cout<<"back value of current is "<<*current<<endl;
            }
            else{
               cout<<"Current is at the start it has no back value"<<endl;
            }
        }

        void Remove(){
            int l=0;
            ptr=arr;
            temp=NULL;
            for( int i=0; i<total; i++ ) {
                //if( arr[i] != *current )
                //  arr[l++]=arr[i];
                if(ptr==current){
                    l++;
                    //temp=ptr+l;
                    //*ptr = *temp;
                    *ptr=*(ptr+l);
                    *(ptr+1)=NULL;
                    current=current-1;
                    //cout<<*current<<"-----"<<*temp<<endl;
                }
                else
                    ptr++;
                }
            ptr=arr;
            siz=siz-1;
            //cout<<"----"<<*current<<"....."<<*ptr<<endl;
            print();
        }
        bool find_(int x){
            temp=ptr;
            for(int i=0;i<siz;i++){
                if(*temp==x){
                    return true;
                }
                temp=temp+1;
            }
            return false;
        }
        int get(){
            cout<<"current is at "<<*current<<endl;
            return *current;
        }

        void update(int x){
            *current=x;
        }

        void start(){
            current=ptr;
            cout<<"Current is at the start : "<<*current<<endl;
        }

        void end_(){
            current=&arr[siz];
            cout<<"end value of array is "<<*current<<endl;
        }

        void length(){
            cout<<"length of an array is "<<siz<<endl;
        }

};
int main(){
    test obj;
    obj.add(9);
    obj.get();
    obj.next();
    obj.back_();
    obj.Remove();
    obj.update(8);
    obj.length();

    cout<<obj.get()<<endl;

    if(obj.find_(3))
        cout<<"Desired value is found"<<endl;
    else
        cout<<"Desired value is not found"<<endl;

    obj.end_();
    obj.start();

    return 0;
}
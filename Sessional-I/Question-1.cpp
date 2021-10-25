/*
Q. 1) Given two arrays a[] and b[], each containing N distinct integers. Write code to dtermine 
(i)  how many integers are placed at same lacations with same value in both arrays 
(ii) how many elements are common in both arrays.

a[] = { 2, 45, 5, 7, 4, 53 }  ;  b[] = { 52, 7, 5, 6, 4, 45 }

E.g answer for following two input arrays is (i) 2 (ii) 4

*/

#include <iostream>

using namespace std;

int main(){
    
    int lCount = 0, cCount = 0;
    int size = 6;

    // Let's suppose these are the arrays
    int a[6] = { 2, 45, 5, 7, 4, 53 }, b[6] = { 52, 7, 5, 6, 4, 45 };

    // cin>> size;

    if (size != 0){

        for (int i = 0; i < size; i++){
            if( *(a + i) == *(b + i))
                lCount++;
            
        }

        cout << "Integers at the same locations: " << lCount << endl;

        for (int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){

                if ( *(a + i) == *(b + j) )
                    cCount++;
            }
        }

        cout << "Common Elements: " << cCount << endl;
    }

    else{
        cout << "Array is Empty!\n";
    }


}
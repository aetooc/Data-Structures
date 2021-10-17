/*

ARRAY BASED LIST
*/



#include<iostream>
#include<string>
using  namespace std;

class list{
private:
	int *arr; //will be used to initialize an empty list and will always point to the first position.
	int size; //total capcity of the list
    int len; //number of current elements in the list
    int *current; //pointer to point the current position
    int *temp; //can be used for temporary works
public:

    //Constructor for initializing List
    //You can initialize size to any value
	list(){
	    current = temp = NULL;
        len = 0;
        // cout << "Enter the Size of arr: ";
        // cin >> size;
        size = 6;
        arr = new int[size];

        for(int i = 0; i < size; i++){
            arr[i] = 0;
        }
        current = arr;
        temp = arr;
	}


    //overloaded constructor
    //user will pass decided the size of the list
    list(int userSize){
        current = temp = NULL;
        len = 0;
        size = userSize;
        arr = new int[size];

        for(int i = 0; i < size; i++){
            arr[i] = 0;
        }
    }

    //Deep Copy Constructor
    //write code to create a new list and copy elements of the list passed in the parameter
	list(list& othrList){
        
    size = othrList.size;
    len = othrList.len;
    arr = new int[size];

    for(int i = 0; i < len; i++){
        arr[i] = othrList.arr[i];
    }
	
	}


    //Clear Or Empty the List
	void clear(){
        for(int i = 0; i < len; i++ )
            arr[i] = 0;
        len = 0;
        current = arr;
	}


    //Insert a Value at Specific Position
	void insert(int value,int pos){
        if (len >= size)
    	    cout << "Range Out of Bound\n";
        else{
            for (int i = len; i > pos; i--)
                    arr[i] = arr[i - 1]; 
                
                arr[pos] = value; 
                                            
                if(len != 0)
                    current++;	
                len++;
        }    

	}

    //Insert the given value in the list at the next available position
    void insert(int value){
        if (len >= size)
    	    cout << "Range Out of Bound\n";
        else{
            if (len != size){
                temp = (arr + len);
                *temp = value;
                if(len != 0)
                    current++;	
                len++;
            }
            else{
                cout << "Array is Full\n";
            }
        }
	}

    void print(){
    
        for(int i = 0; i < len; i++)
            cout << arr[i] << " ";
        cout << endl;
        // cout << *current << endl;
    }


//     //Remove a value at specific position
	void remove(int pos){
	if (pos < 0 || pos >= len)
    	cout << "Range Out of Bound\n";
	else
	{
   		for (int i = pos; i < len - 1; i++)
	 		arr[i] = arr[i+1];

		len--;
        current--;
	}
	

	}



    //Get value stored at a specific position
	int get(int pos){
        if (pos < 0 || pos > len)
    	    cout << "Range Out of Bound" << endl;
        else
            return arr[pos];
	}

//     //Update Existing value at a position
	void update(int value,int pos){
        if (pos < 0 || pos >= len)
    	    cout << "Range Out of Bound" << endl;
        else
            arr[pos] = value;

	}


//     //Find a value in the list
	bool find(int value){
        bool check = false;
        for(int i = 0; i < len; i++){
            if (arr[i] == value){
                check = true;
                return true;
        }
        return check;
    }

	}


//     //Return Current Length of the list
	int length(){
        return len;
	}


//     //Move to starting position of the list
	void start(){
	    current = (arr + 0); 
	}

//     //Move to the end of the list
	void end(){
        current = (arr + (len-1)); 
	}
    

//     //checks whehter the list is completely filled or not
    bool isFull(){
        return (len == size );
    }
    
//     //checks whehter the list is completely empty or not    
    bool isEmpty(){
        return (len == 0);
            
    }

    void Current(){
        cout << *current << endl;
    }

};

int main(){
    list obj, obj1;
    obj.insert(3);
    obj.insert(4);
    obj.insert(5);
    obj.insert(1,0);
    obj.insert(2,1);
    obj.print();
    obj.insert(6);
    obj.print();
    obj.remove(5);
    obj.print();
    obj.insert(7,5);
    obj.print();
    obj.update(6,5);
    obj.print();
    obj1 = obj;
    cout << "copy constructor\n";
    obj1.print();
    obj.Current();


	return 0;
}    

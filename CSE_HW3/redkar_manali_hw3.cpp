#include <math.h>
#include <stdio.h>   
#include <iostream>
#include <ostream>
#include <fstream>
#include <stdlib.h>
#include<ctime>

using namespace std;

int ch; //variable for choice
int op;//variable for option in SUB menu
char *letters;

    //signatures of all the  functions used
    int calculateRepeat(int* , int );
    int calculateUnique(int* , int );
    int calculateMedian(int* , int );
    int calculateAverage(int*, int );
    void sorting(int *, int );
    int RandomIntegers(int , int);
    void creatingArray(int ,int* , int , int );
    void doCase1();
    void sortArray(char* , int );
    void removeCharacter(char *, int, char);
    char getRandomChar();
    char* fillArray(char* , int );
    char* doCase2(char* ,int &);
    int getFrequencyOf(char *, int , char );
    void menu();
    void doOptionB(char* ,int);
    void doCase3();

//function for case 3 in the main menu for 2D array
void doCase3(){
int row,col;
string str;

cout<<"How many strings so you want to enter? ";
cin>>row;
cout<<"What's your max size of the strings? ";
cin>>col;
char elements [row][col];

//processing the array
for(int i=0;i<row;i++)
{
    cout<<"Enter your string #"<< (i+1) <<" :";
    cin>>str;
    //str = str + '\0';
    for(int j=0;j<col;j++)
    {
        elements[i][j]=str[j];
        //cout<<elements[i][j];
    }
    cout<<endl;
}

//outputting the final array
/*for(int i=0;i<row;i++){

    //cout<<elements[i][j];

    for(int j=0;j<col;j++){
        //if(str[j]=='\0')
          //  break;
        //else
            //str = str + '\0';
            cout<<elements[i][j]<<"\t";

    }
    cout<<endl;
}
*/

while(1==1){
    int choice;
    cout<<"1. Check frequency of a letter"<<endl;
    cout<<"2. Remove a letter"<<endl;
    cout<<"3.Return to main menu "<<endl;
    cout<<"Enter your choice ";
    cin>>choice;
    char item;
    int cSum=0;
    switch(choice){
        case 1: 
                //cout<<"This choice 1 for freq";
                cout<<"What's your letter of frequency-check ";
                cin>>item;
                //item = tolower(item);
                for(int i=0;i<row;i++){
                    cSum = cSum + getFrequencyOf(elements[i], col, item);
                }
                cout<<"There are "<<cSum<<" of the letter "<<item<<endl;
                
                break;
        case 2: //cout<<"This is choice 2 for remove "<<endl;
                cout<<"What's your letter for removing: ";
                cin>>item;
                for(int i=0;i<row;i++){
                    removeCharacter(elements[i],col, item);
                }
                break;
        case 3: //cout<<"This is choice 3 for: return menu";
                menu();
                cout<<endl;
                break;
        default:cout<<"Invalid choice "<<endl;
                break;
    }
}

}


// main function with all the working happening in the menu function
int main(){
    menu();
    return 0;
}

//function to calculate the repeated numbers
int calculateRepeat(int* numberList, int size){
    int repeatCount=0;
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(numberList[i]==numberList[j])
            repeatCount++;
        }
    }
    return repeatCount;
}


//function to calculate unique number
int calculateUnique(int* numberList, int size){
    int uniqueCount=0;
    int temp;
    for(int i=0;i<size-1;){
        if(numberList[i]==numberList[i+1])
        {
            temp=numberList[i];
            for(int j=i+1;j<size;j++)
            {
                if(temp!=numberList[j])
                {
                    i=j;
                    break;
                }
            }
              
        }
        else
        {
            i++;
            uniqueCount++;
        }
    }
    //cout<<numberList[size-1];
    //cout<<numberList[size-2];

    if(numberList[size-1]!=numberList[size-2])
    {
        uniqueCount++;
    }
return uniqueCount;

}


//function to calculate the median(for odd and even sizes)
int calculateMedian(int* numberList, int size){
    int medianSum,medianAct;
    if(size%2==0){
    for(int i=0;i<size;i++){
        medianSum = numberList[size/2]+numberList[(size/2)+1];
        medianAct=medianSum/2;
        return medianAct;
    }

    }
    else if(size%2!=0){
        for(int i=0;i<size;i++){
        medianAct = numberList[(size/2)];
        return medianAct;
    }

    }
}

//function to calculate the average of sorted elements
int calculateAverage(int* numberList, int size){
    int sum=0;
    double avg;
    for(int i=0;i<size;i++){
        sum = sum + numberList[i];
    }
    avg = sum/size;
    return avg;
}


//bubble sort for sorting the random numbers
void sorting(int *thatPointer, int thatSize){
    int tempVar; //this is a temporary variable for holding the buffer value till it gets assigned to the thatPointer
    for(int i=0;i<thatSize;i++)
    {
        for(int j=i+1;j<thatSize;j++)
        if(thatPointer[i]>thatPointer[j])
        {
            tempVar=thatPointer[i];
            thatPointer[i]=thatPointer[j];
            thatPointer[j]=tempVar;

        }
    }

    cout<<"My sorted array: ";
    for(int i=0;i<thatSize;i++){
        cout<< thatPointer[i]<<"\t";
    }
    cout<<endl<<endl;
}



//this is a function for generating random numbers with the pre-defined rand() function
int RandomIntegers(int mini, int maxi){
	 return rand()%(maxi-mini+1) + mini ;
 }
 

 //this function is for storing random integers between a specific range in the 'pointer'
void creatingArray(int size_DA1,int* pointer, int min, int max)
{     
    for(int i=0;i<size_DA1;i++)
    {
        pointer[i]= RandomIntegers(min, max);
        cout<<pointer[i]<<"\t";
    }
    cout<<endl;
    

 }


//this function is for driving case 1
void doCase1()
{
    int size_DyArray1; //size of the empty dynamic array(changeable)
    int* myArray; //empty dynamic array
    int maximum,minimum;
    //cout<<"This is op 1 and 1D array"<<endl;
    cout<<"Enter size: ";
    cin>>size_DyArray1;
    myArray=new int[size_DyArray1]; //an array is created with the specific size
    //creatingArray(size_DyArray1,myArray);
    //for(int i=0;i<size_DyArray1;i++){
    //cout<<myArray[i]<<endl;
    //}
    cout<< "min: ";
    cin>>minimum;
    cout<< "max: ";
    cin>>maximum;
    cout<<"My random array: ";
    creatingArray(size_DyArray1,myArray,minimum,maximum);
    //cout<<"Now the sorting:"<<endl;
    //cout<<"[ ";
    sorting(myArray,size_DyArray1);
    //cout<<" ]";
    cout<<"Average: "<<(calculateAverage(myArray, size_DyArray1))<<endl;
    cout<<"Median: "<<(calculateMedian(myArray, size_DyArray1))<<endl;
    cout<<"Uniques: "<<(calculateUnique(myArray, size_DyArray1))<<endl;
    cout<<"Non-uniques: "<<(calculateRepeat(myArray, size_DyArray1))<<endl;
    cout<<endl;
}



//function to sort the elements in an array:ascending array
 void sortArray(char* letters, int size){
     int* intarr = new int[size];
     for(int i=0;i<size;i++){
         intarr[i]=(int)letters[i];
         //cout<<endl;
     }
     //cout<<endl;
     for(int i=0;i<size;i++){
         //cout<<intarr[i]<<" ";
     }
    sorting(intarr, size);
    for(int i=0;i<size;i++){
        letters[i] = (char)intarr[i];
    }

    for(int i=0;i<size;i++){
        cout<<letters[i]<<" ";
    }

 }




//function to remove a character specified
void removeCharacter(char *letters, int size, char item){
    int del_value =item; 
    int countTemp=0;
    int sizeTemp;
    int k=0;
    /*for(int i=0;i<size;i++){
        cout<<letters[i]<<"\t";
    }
    cout<<endl;
    */
    //cout<<"The ascii value is "<<del_value<<endl;
    for(int i=0;i<size;i++)
    {
        if(item==letters[i])
        countTemp++;
    }
    sizeTemp=size-countTemp;
    char *tempA=new char[sizeTemp];

    for(int j=0;j<size;j++){
        if(letters[j]!=item){
            tempA[k] = letters[j];
            k++;
        }
    }
    letters=tempA;
    cout<<letters<<endl;
    
}


//used to generate random characters:only lower case
char getRandomChar(){

        //cout<<rand()%26;  
        return char('a'+rand()%26);
}
    

//function used to fill the array with random integers
 char* fillArray(char* letters, int size){
     
     for(int i=0;i<size;i++){
         letters[i]=getRandomChar();
         cout<<letters[i]<<"\t";
     }
     return letters;
     cout<<endl;
 }


//this function is for Case 2 in the main menu:
char* doCase2(char* ourArray,int &size)
{
    int size_DyArray2;
    char *store;

    //cout<<"This is op 2 and 1D character array"<<endl;
    cout<<"How many characters? ";
    cin>>size_DyArray2;
    size = size_DyArray2;
    cout<<"Filling the array: ";
    ourArray=new char[size_DyArray2];
    for(int i=0;i<size_DyArray2;i++){
        ourArray[i]='\0';
        //cout<<'\0'<<"\t";
    }
    cout<<endl;
    store = fillArray(ourArray,size_DyArray2);
    return store;
}


//this function is to calculate the the number of times an item apparears
int getFrequencyOf(char *letters, int size, char item){
        int countItem=0;
        //cout<<"this is first "<<letters[0];
        for(int i=0;i<size;i++)
        {
            if(letters[i]==item)
            {
                countItem++;                        
            }
        }
        return countItem;

        //cout<<"The final count is "<<countItem;
}



//the function that drives my main menu
void menu(){

 do{
    cout<<"Welcome to Assignment 3!"<<endl;
    cout<<"Menu:"<<endl;
    cout<<"1 – 1D Math"<<endl;
    cout<<"2 – Single Dimension Character Processing"<<endl;
    cout<<"3 – Two-D Character Processing"<<endl;
    cout<<"4 - Exit"<<endl;
    cout<<"Choose an option: ";
    char* ourArray;
    char* storeArray;

    int size;
    

    cin>>ch;

            switch(ch)
            {
                case 1:
                {
                    doCase1();
                    break;
                }    
                case 2:
                {
                    storeArray = doCase2(ourArray,size);
                    cout<<endl;
                    doOptionB(storeArray,size);
                    break;
                }
                        
                case 3:
                {
                    
                    //cout<<"This is op 3: 3d array"<<endl;
                    doCase3();
                    break;
                }
                        

                case 4:
                {
                    cout<<"This is op 4:exit "<<endl;
                    exit(0);
                    break;

                }
               

                default:cout<<"Invalid choice"<<endl;
                        break;

            }

    } while(ch!='4');
    

}


//function for sub-menu in case 2
void doOptionB(char* ourArray,int size){
    while(1==1){
        cout<<"What would you like to do? "<<endl;
        cout<<"1.   Check frequency of a letter "<<endl;
        cout<<"2.   Remove a letter "<<endl;
        cout<<"3.   Sort "<<endl;
        cout<<"4.   Return to main menu "<<endl;
        //cout<<"Choose a sub-MENU option:"<<endl;
        cout<<">>";
        cin>>op;

            switch(op)
            {
                case 1: char item;
                        //char *letters = '\0';
                        //char lowerAlpha;
                        //cout<<"Frequency option: "<<endl;
                        cout<<"Enter a character(lower-case): ";
                        cin>>item;
                        if(isupper(item))
                        {
                            cout<<"LETTER: ";
                            item =putchar(tolower(item));
                            cout<<endl;
                        }
                        
                        cout<<"There are "<<(getFrequencyOf(ourArray, size, item)) << " of the letter " << item ;
                        //cout<<item;
                        cout<<endl;
                        break;


                case 2: //cout<<"Remove a letter option"<<endl;
                        cout<<"Enter a character(lower-case)";
                        cin>>item;
                        if(isupper(item))
                        {
                            cout<<"LETTER: ";
                            item =putchar(tolower(item));
                            cout<<endl;
                        }
                        removeCharacter(ourArray,size,item);
                        cout<< item << " has been removed.";

                        break;

                case 3: cout<<"Sorting!"<<endl;
                        sortArray(ourArray,size);
                        //for(int i=0;i<size;i++){
                            //cout<<ourArray[i]<<" ";
                        //}
                        cout<<endl;
                        break;
                case 4:  cout<<"returns to the main menu "<<endl;
                          menu();
                         break;
            }
}
}


/* 
Name:Manali Redkar
Date: 4/10/2020
Description: This programs encryptes and decrytes the file given by the user and writes it to another file.
*/


#include<iostream>
#include<fstream>

using namespace std;

#define rowSize 128 //row size is the number of ascii value(0-127)
void printTable(char ** ,int , int ); 
char** makeTable(int);



/**
* Creates and opens the file
* @param file file object to be opened
* @param prompt string that asks the user for the name of the file
* @param filename the default file, where the user enters the filename
* @param flags defines the type of file stream(I/O, Binary, etc)
*/
void getfile(fstream& file, string prompt, string filename, ios_base::openmode flags) {
    if (filename.size())
        file.open(filename, flags);
    while (!file.is_open()) {
        cout << prompt;
        cin >> filename;
        file.open(filename, flags);
    }
}

//make a pointer char type 2D array and the allocate the dynamic sizes
char** makeTable(int colSize){
    char** table = new char*[rowSize];
    for(int i = 0; i < rowSize;i++)
        table[i] = new char[colSize];
    return table;
}
    

//prints the table, only for debugging
void printTable(char ** table,int row, int col) {

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++)
        {
            cout<<(int)table[i][j]<<"\t";
        }
        cout<<endl;
    }
}

//constants declared for user menu options
#define ENCRYPT 'e'
#define DECRYPT 'd'


//main method accept command line arguments in the given format
int main(int argc, char** argv){
    // <exe> <key> <flag> <input> <output>
    //  0     1      2      3       4


//set mode from command line args
    char mode;
    if (argc > 2 && argv[2][0] == '-') 
        mode = argv[2][1];


    while (mode != ENCRYPT && mode != DECRYPT) { 
        cout<<"1.Encryption "<<endl;
        cout<<"2.Decryption "<<endl;
        cout<<"Choose an option: (e) or (d) "<<endl;
        cin>>mode;
        mode = tolower(mode);
    }

    cout<< (mode == ENCRYPT ? "ENCRYPTING" : "DECRYPTING") <<endl;

    //default input for passing the file
    string inputArg;
    if (argc > 3) inputArg = string(argv[3]);

    //default output for passing the file
    string outputArg;
    if (argc > 4) outputArg = string(argv[4]);

    //file I/O obejcts are declared, and the respective functions for opening the files are called
    //Assume the encrypted files are binary and the non-encrypted is non-binary
    fstream inputFile, outputFile;
    getfile (inputFile, "What is the input file: ", inputArg, mode == ENCRYPT ? ios::in : (ios::in | ios::binary));
    getfile (outputFile, "What is the output file: ", outputArg, mode == ENCRYPT ? (ios::out | ios::binary) : ios::out);

    //taking any 'key' by the user as an input
   string key;
   if (argc > 1)
        key = string(argv[1]);
    else {
        cout<<"Enter your key: ";
        cin>>key;
    }

   if (key.size() > rowSize)
        key = key.substr(0, rowSize);
   
    char** table = makeTable(key.size());
    for (int j=0;j<key.size();j++) {
        //adding the key to the first row of the table, and if decrypting it does the inverse
        table[0][j] = mode == ENCRYPT ? key[j] : rowSize - key[j];
        for (int i=1; i<rowSize;i++) {
            unsigned char tableVal = table[i-1][j] + 1;
            if(tableVal>=rowSize)
                tableVal = 0;
            table[i][j] =  tableVal;
        }
    }

    //calling print function to debug 
    //printTable(table, rowSize, key.size());

   int keyEnd = key.size()-1;
   int indexKey = 0;
    
    char input;

    //reading files and shifting character
    int n = 0;
    while(inputFile.get(input)) {
        if (input < 0) {
            outputFile << input;
            continue;
        }
        outputFile<<table[input][indexKey++];
        if (indexKey > keyEnd)
            indexKey = 0;
    }

    inputFile.close();
    outputFile.close();


    //handles memory leaks
    for (int i = 0; i < rowSize; i++)
        delete [] table[i];
    delete [] table;
}



/*
NOTE:
ENCRYPTING
INPUT TYPE = ios::in
OUTPUT TYPE = ios::out | ios::binary
FIRST ELEMENT = key[j];

DECRYPTING
INPUT TYPE = ios::in | ios::binary
OUTPUT TYPE = ios::out
FIRST ELEMENT = 128 - key[j]
*/
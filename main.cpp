#include <iostream>
#include <vector>
#include "inversions.h"

using namespace std;

int main(){
    const string RESET = "\033[0m";
    const string MAGENTA = "\033[35m";

    cout << MAGENTA;
    cout << "Counting Inversions";
    cout << RESET;
    cout << endl;
    cout << endl;
    

    int numEle;

    // prompt for number of elements 
    cout << "Enter the number of elements you wish to include: " << endl;
    cin >> numEle;
    cout << endl;

    // validate if number and not negative 
    if(numEle < 0 || cin.fail()){
        cerr << "Invalid input. Enter positive integers." << endl;
        return 1; 
    }

    // validate there is data
    if(numEle == 0){
        cout << "You don't want to enter elements? Boo hoo, nothing to do here" << endl;
        return 1;
    }
    

    // now prompt user for the actual data to put in vector 
    vector<int> myArr(numEle);
    cout << "Enter " << numEle << " elements: ";
    for(int i = 0; i < numEle; i++){
        cin >> myArr[i];
    }
    cout << endl;

    // show the user what they input
    cout << "You entered: ";
    for(int i = 0; i < numEle; i++){
        cout << myArr[i] << " ";
    }
    cout << endl;
   
    // output text to teach user how the program starts
    cout <<"The inversion count algorithm starts by sending the entire array to be checked for any inversions" << endl;
    cout << "Total number of inversions: " << inversionCount(myArr) << endl;

    return 0;
}
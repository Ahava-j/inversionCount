#include "inversions.h"
#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

// ANSI escape codes for coloring
const std::string RESET = "\033[0m";
const std::string MAGENTA = "\033[35m";

// This function prints array in color 
void printArray(const vector<int>& arr, int lIndex, int rIndex) {
    for(int i = 0; i < arr.size(); ++i){
        if(i >= lIndex && i <= rIndex){
            cout << MAGENTA << arr[i] << " " << RESET;
        } else {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

/**
 * Prints the array with the specified range in color.
 * @param arr The array to be printed.
 * @param lIndex The starting index of the range to be colored.
 * @param rIndex The ending index of the range to be colored.
 */
int inversionCount(vector<int>& myArr){
    cout << "Starting inversion count for the entire array." << endl;
    return inversionRecursive(myArr, 0 , myArr.size() - 1);
}

/**
 * Recursively divides the array and counts inversions.
 * @param myArr The array for which inversions are to be counted.
 * @param lIndex The starting index of the current subarray.
 * @param rIndex The ending index of the current subarray.
 * @return int The number of inversions in the current subarray.
 */
int inversionRecursive(vector<int>& myArr, int lIndex, int rIndex){
    if(lIndex >= rIndex){
        cout << "Base case reached with lIndex: " << lIndex << " and rIndex: " << rIndex << ". No inversions needed." << endl;
        return 0;
    }

    int middleIndex = lIndex + (rIndex - lIndex) / 2;
    cout << "Dividing array from index " << lIndex << " to " << rIndex << " at middle index " << middleIndex << "." << endl;
    printArray(myArr, lIndex, rIndex);

    int leftSorted = inversionRecursive(myArr, lIndex, middleIndex);
    cout << endl;

    int rightSorted = inversionRecursive(myArr, middleIndex + 1, rIndex);
    cout << endl;

    int combineSorted = inversionCombine(myArr, lIndex, middleIndex, rIndex);

    cout << "Total inversions from index " << lIndex << " to " << rIndex << ": " << (leftSorted + rightSorted + combineSorted) << endl;
    return leftSorted + rightSorted + combineSorted;
}


/**
 * Combines two sorted subarrays and counts the inversions between them.
 * @param myArr The array containing the subarrays to be combined.
 * @param lIndex The starting index of the left subarray.
 * @param middleIndex The ending index of the left subarray and the starting index of the right subarray.
 * @param rIndex The ending index of the right subarray.
 * @return int The number of inversions found during the combination.
 */
int inversionCombine(vector<int>& myArr, int lIndex, int middleIndex, int rIndex){
    cout << "Combining arrays from index " << lIndex << " to " << middleIndex << " and " << (middleIndex + 1) << " to " << rIndex << "." << endl;

    int i = 0;
    int j = 0;
    int k = lIndex;
    int countInversions = 0;
    int lSize = middleIndex - lIndex + 1;
    int rSize = rIndex - middleIndex;

    vector<int> lArr(lSize);
    vector<int> rArr(rSize);

    for(int i = 0; i < lSize; i++){
        lArr[i] = myArr[lIndex + i];
    }

    for (int i = 0; i < rSize; i++){
        rArr[i] = myArr[middleIndex + 1 + i];
    }

    cout << "Left array: ";
    for(int i = 0; i < lSize; i++){
        cout << lArr[i] << " ";
    }
    cout << endl;

    cout << "Right array: ";
    for(int i = 0; i < rSize; i++){
        cout << rArr[i] << " ";
    }
    cout << endl;

    while(i < lSize && j < rSize){
        if(lArr[i] <= rArr[j]){
            myArr[k++] = lArr[i++];
        }
        else{
            myArr[k++] = rArr[j++];
            countInversions += (lSize - i);
            cout << "Inversion found. Count increased by " << (lSize - i) << "." << endl;
        }
    }

    while(i < lSize){
       myArr[k++] = lArr[i++];
    }
    while(j < rSize){
        myArr[k++] = rArr[j++];
    }

    cout << "Combined array: ";
    printArray(myArr, lIndex, rIndex);

    return countInversions;
}
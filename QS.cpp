#include "QS.h"
#include <string>

void QS::sortAll(){};

/*
* medianOfThree()
*
* The median of three pivot selection has two parts:
*
* 1) Calculates the middle index by averaging the given left and right indices:
*
* middle = (left + right)/2
*
* 2) Then bubble-sorts the values at the left, middle, and right indices.
*
* After this method is called, data[left] <= data[middle] <= data[right].
* The middle index will be returned.
*
* Returns -1 if the array is empty, if either of the given integers
* is out of bounds, or if the left index is not less than the right
* index.
*
* @param left
* 		the left boundary for the subarray from which to find a pivot
* @param right
* 		the right boundary for the subarray from which to find a pivot
* @return
*		the index of the pivot (middle index); -1 if provided with invalid input
*/
int QS::medianOfThree(int left, int right){
    //error catcher
    if ((left == right) || (left > right) || (left < 0) || (position_in_array_ == 0) || (right >= position_in_array_)) {
        return -1;
    }
    int middle = ((left + right)/2); //these aren't values, they are indices.
    int i = 1;
    while (i <= 2) {
        if (iArray[left] > iArray[middle]) {
            // cout << "the left value: " << iArray[left] << endl;
            // cout << "the middle value: " << iArray[middle] << endl;
            swapIndexValues(middle,left);
        }
        if (iArray[middle] > iArray[right]){
            swapIndexValues(middle,right);
        }
        i++;
    }
    cout << "left: " << iArray[left] << endl;
    cout << "middle: " << iArray[middle] << endl;
    cout << "right: " << iArray[right] << endl;

    if (middle != 0){
        return middle;
    }
    else {
        return -1;
    }
};

void QS::swapIndexValues(int index_one, int index_two) {
    // cout << "inside swapIndexValues" << endl;
    int tempvalue = 0;
    tempvalue = iArray[index_two];
    // cout << "tempvalue is " << tempvalue << endl;
    iArray[index_two] = iArray[index_one];
    iArray[index_one] = tempvalue;
    // cout << "middle value is now: " << iArray[index_one] << endl;
    // cout << "left value is now: " << iArray[index_two] << endl;

};

/*
* Partitions a subarray around a pivot value selected according to
* median-of-three pivot selection.  Because there are multiple ways to partition a list,
* we will follow the algorithm on page 611 of the course text when testing this function.
*
* The values which are smaller than the pivot should be placed to the left
* of the pivot; the values which are larger than the pivot should be placed
* to the right of the pivot.
*
* Returns -1 if the array is null, if either of the given integers is out of
* bounds, or if the first integer is not less than the second integer, or if the
* pivot is not within the sub-array designated by left and right.
*
* @param left
* 		the left boundary for the subarray to partition
* @param right
* 		the right boundary for the subarray to partition
* @param pivotIndex
* 		the index of the pivot in the subarray
* @return
*		the pivot's ending index after the partition completes; -1 if
* 		provided with bad input
*/
int QS::partition(int left, int right, int pivotIndex){
    if ((position_in_array_ == 0) || (left < 0) || (right == left) || (right >= position_in_array_) || (pivotIndex > right)) {
        return -1;
    }
    // cout << "the pivotIndex is: " << pivotIndex << "and the value is: " << iArray[pivotIndex] << endl;
    //step 1: swap pivotIndex and left
    swapIndexValues(left,pivotIndex);
    int going_up = (left + 1);
    int going_down = right;
    // cout << "the new pivotIndex is: " << pivotIndex << "and the value is: " << iArray[pivotIndex] << endl;
    do {
        while ((iArray[going_up] < iArray[left]) && (going_down > going_up) && (going_up != going_down)) {
            going_up++;
        }
        cout << "found value greater than pivot, it's: " << iArray[going_up] << endl;
        cout << "outside-----the current value of going down is: " << iArray[going_down] << endl;
        while ((iArray[going_down] > iArray[left])) {
            going_down--;
            cout << "going down" << endl;
            cout << "the current value of going down is: " << iArray[going_down] << endl;
        }
        cout << "going up value is: " << iArray[going_up] << endl;
        cout << "going down value is: " << iArray[going_down] << endl;
        if (iArray[going_down] == iArray[going_up]) {
            cout << "going down and going up are the same" << endl;
            break;
        }
        if (going_down > going_up){
            swapIndexValues(going_up,going_down);
        }
        else {
            break;
        }
    }
    while (going_down > going_up);
    cout << going_down << endl;
    cout << "left value: " << iArray[left] << endl;
    cout << "going down value: " << iArray[going_down] << endl;
    swapIndexValues(left,going_down);

    return going_down;
};

/*
* Produces a comma delimited string representation of the array. For example: if my array
* looked like {5,7,2,9,0}, then the string to be returned would look like "5,7,2,9,0"
* with no trailing comma.  The number of cells included equals the number of values added.
* Do not include the entire array if the array has yet to be filled.
*
* Returns an empty string, if the array is NULL or empty.
*
* @return
*		the string representation of the current array
*/
string QS::getArray() const {
    // cout << "array_size_ is " << array_size_ << endl;
    if ((array_size_ > 0) && (iArray != NULL)) {
        // cout << "inside arrayString creator" << endl;
        int i = 0;
        string array_to_print;
        // cout << "arraysize" << array_size_ << endl;
        while (i < position_in_array_) {
            int int_to_convert = iArray[i];
            string add_this = to_string(int_to_convert);
            if (i < (position_in_array_- 1)) {
                array_to_print = array_to_print + add_this + ",";
            }
            else {
                array_to_print = array_to_print + add_this;
            }
            i++;
        }
        return array_to_print;
    }
    else {
        // cout << "array was empty" << endl;
        string empty_string = "";
        return empty_string;
    }
};

/*
* Returns the number of elements which have been added to the array.
*/
int QS::getSize() const{
    return position_in_array_;
};

/*
* Adds the given value to the end of the array starting at index 0.
* For example, the first time addToArray is called,
* the give value should be found at index 0.
* 2nd time, value should be found at index 1.
* 3rd, index 2, etc up to its max capacity.
*
* If the array is filled, do nothing.
* returns true if a value was added, false otherwise.
*/
bool QS::addToArray(int value){
    if (position_in_array_ < array_size_) {
        iArray[position_in_array_] = value;
        position_in_array_++;
        return true;
    }
    else {
        return false;
    }
};
/*
* Dynamically allocates an array with the given capacity.
* If a previous array had been allocated, delete the previous array.
* Returns false if the given capacity is non-positive, true otherwise.
*
* @param
*		size of array
* @return
*		true if the array was created, false otherwise
*/
bool QS::createArray(int capacity){
    if (capacity > 0) {
        if (iArray != NULL) {
            clear();
        }
        array_size_ = capacity;
        iArray = new int[capacity];  //dynamically allocated array; created at runtime;
        return true;
    }
    else {
        return false;
    }
};

/*
* Resets the array to an empty or NULL state.
*/
void QS::clear(){
    cout << "inside clear function" << endl;
    delete[] iArray;
    iArray = NULL;
    array_size_ = 0;
    position_in_array_ = 0;
};

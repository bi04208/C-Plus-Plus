/**
 * @file
 * @brief [Dynamic Array](https://en.wikipedia.org/wiki/Dynamic_array)
 *
 * @details
 * The list_array is the implementation of list represented using array.
 * We can perform basic CRUD operations as well as other operations like sorting
 * etc.
 *
 * ### Algorithm
 * It implements various method like insert, sort, search etc. efficiently.
 * You can select the operation and methods will do the rest work for you.
 * You can insert element, sort them in order, search efficiently, delete values
 * and print the list.
 */

#include <array>     /// for std::array
#include <cassert>   /// for assert
#include <iostream>  /// for io operations
#include "list.hpp"


template <typename T>
void data_structures::list_array<T>::insert(const T val) { // function insert
    if (top == 49) {
        std::cout << "\n Overflow";
        return;
    }

    // if list is not sorted, insert at the last
    // otherwise place it to correct position
    if(!isSorted) {
        data[top] = val;
        top++;
    }
    else {
        int pos = 0; // Initialize the index variable
            
        // Going through each element and find correct position for element
        for (int i = 0; i < top - 1; i++){
            // check for the correct position
            if (data[i] <= val && val <= data[i + 1]) {
                pos = i + 1;  // assign correct pos to the index var
                break;        // to get out from the loop
            }
        }
        // if all elements are smaller than the element
        if (pos == 0) {
            pos = top - 1;
        }
        // shift all element to make a room for new element
        for (int i = top; i > pos; i--) {
            data[i] = data[i - 1];
        }
        top++;  // Increment the value of top.
        data[pos] = val;  // Assign the value to the correct index in the array
    }
} // function insert


template <typename T>
void data_structures::list_array<T>::remove(const T val) { //function remove
    int pos = search(val);  // search the index of the value
    // if search returns -1, element does not present in the list
    if (pos == -1) {
        std::cout << "\n Element does not present in the list ";
        return;
    }
    std::cout << "\n"
              << data[pos] << " deleted";  // print the appropriate message
    // shift all the element 1 left to fill vacant space
    for (T i = pos; i < top; i++) {
        data[i] = data[i + 1];
    }
    top--;  // decrement the top variable to maintain last index

} //function remove


template <typename T>
int data_structures::list_array<T>::search(const T val) { // function search
    int pos;  // pos variable to store index value of element.
            // if list is sorted, binary search works efficiently else linear search
            // is the only option
    if (isSorted) {
        pos = BinarySearch(0, top - 1, val);
    } else {
        pos = LinearSearch(val);
    }
    // if index is equal to -1 means element does not present
    // else print the index of that element
    if (pos != -1) {
        std::cout << "\nElement found at position : " << pos;
    } else {
        std::cout << "\nElement not found";
    }
    // return the index of element or -1.
    return pos;
} // function search


template <typename T>
int data_structures::list_array<T>::BinarySearch(const int first, const int last, const T val){ // function BinarySearch
    // If both pointer cross each other means no element present in the list
    // which is equal to the val
    if (last < first) {
        return -1;
    }
    int mid = (first + last) / 2;
    // check whether current mid pointer value is equal to element or not
    if (data[mid] == val)
        return mid;
    // if current mid value is greater than  element we have to search in
    // first half
    else if (val < data[mid])
        return (BinarySearch(first, mid - 1, val));
    // if current mid value is greater than  element we have to search in
    // second half
    else if (val > data[mid])
        return (BinarySearch(mid + 1, last, val));

    std::cerr << __func__ << ":" << __LINE__ << ": Undefined condition\n";
    return -1;
} // function BinarySearch


template <typename T>
int data_structures::list_array<T>::LinearSearch(const T val) {
    // Going through each element in the list
    for (int i = 0; i < top; i++) {
        if (data[i] == val) {
            return i;  // element found at ith index
        }
    }
    // element is not present in the list
    return -1;
}


template <typename T>
void data_structures::list_array<T>::print_list() { // function print_list
    // Going through each element in the list
    std::cout << '\n';
    for (int i = 0; i < top; i++) {
        std::cout << data[i] << " ";  // print the element
    }
} // function print_list


template <typename T>
void data_structures::list_array<T>::sort() { // function sort
    // Going through each element in the list
    for (int i = 0; i < top; i++) {
        int min_idx = i;  // Initialize the min variable
        for (int j = i + 1; j < top; j++) {
            // check whether any element less than current min value
            if (data[j] < data[min_idx]) {
                min_idx = j;  // update index accordingly
            }
        }
        // swap min value and element at the ith index
        std::swap(data[min_idx], data[i]);
    }
    // mark isSorted variable as true
    isSorted = true;
} // function sort


/**
 * @brief Test implementations
 * @returns void
 */
static void test() {
    data_structures::list_array<uint64_t> L;

    // Insert testing
    L.insert(11);
    L.insert(12);
    assert(L.size() == 2);
    L.insert(15);
    L.insert(10);
    L.insert(12);
    L.insert(20);
    L.insert(18);
    assert(L.size() == 7);
    L.print_list();  // To print the array

    // Remove testing
    L.remove(12);  // Remove Duplicate value in the list
    L.remove(15);  // Remove the existing value in the list
    assert(L.size() == 5);
    L.remove(50);  // Try to remove the non-existing value in the list
    assert(L.size() == 5);

    // LinearSearch testing
    assert(L.search(11) == 0);  // search for the existing element
    assert(L.search(12) == 2);
    assert(L.search(50) == -1);  // search for the non-existing element

    // Sort testing
    L.sort();
    assert(L.isSortedList() == true);
    L.print_list();

    // BinarySearch testing
    assert(L.search(11) == 1);  // search for the existing element
    assert(L.search(12) == 2);
    assert(L.search(50) == -1);  // search for the non-existing element
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main() {
    test();  // Execute the tests
    return 0;
}

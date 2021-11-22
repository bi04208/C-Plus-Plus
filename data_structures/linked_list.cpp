/**
 * @file
 * @brief Implementation of singly linked list algorithm.
 * @details
 * The linked list is a data structure used for holding a sequence of
 * values, which can be added, removed and displayed.
 * ### Algorithm
 * Values can be added by iterating to the end of a list(by following
 * the pointers) starting from the first link. Whichever link points to null
 * is considered the last link and is pointed to the new value.
 *
 * Values can be removed by also iterating through the list. When the node
 * containing the value is found, the node pointing to the current node is made
 * to point to the node that the current node is pointing to, and then returning
 * the current node to heap store.
 */
#include <iostream>
#include <memory>
#include <string>

#include "data_structure.hpp"

/**
 * function checks if list is empty
 * @returns true if list is empty
 * @returns false if list is not empty
 */
template <typename T>
bool data_structures::list<T>::isEmpty() {
    if (last == nullptr) {
        return true;
    } else {
        return false;
    }
}
/**
 * function adds new element to the end of the list
 * @param new_elem to be added to the end of the list
 */
template <typename T>
void data_structures::list<T>::push_back(T new_elem) {
    if (isEmpty()) {
        first->succ() = std::make_shared<link<T> >(new_elem);
        last = first->succ();
    } else {
        last->succ() = std::make_shared<link<T> >(new_elem);
        last = last->succ();
    }
}

/**
 * function adds new element to the beginning of the list
 * @param new_elem to be added to front of the list
 */
template <typename T>
void data_structures::list<T>::push_front(T new_elem) {
    if (isEmpty()) {
        first->succ() = std::make_shared<link>(new_elem);
        last = first->succ();
    } else {
        std::shared_ptr<data_structures::link<T> > t =
            std::make_shared<link>(new_elem);
        t->succ() = first->succ();
        first->succ() = t;
    }
}

/**
 * function erases old element from the list
 * @param old_elem to be erased from the list
 */
template <typename T>
void data_structures::list<T>::erase(T old_elem) {
    if (isEmpty()) {
        std::cout << "List is Empty!";
        return;
    }
    std::shared_ptr<link<T> > t = first;
    std::shared_ptr<link<T> > to_be_removed = nullptr;
    while (t != last && t->succ()->val() != old_elem) {
        t = t->succ();
    }
    if (t == last) {
        std::cout << "Element not found\n";
        return;
    }
    to_be_removed = t->succ();
    t->succ() = t->succ()->succ();
    to_be_removed.reset();
    if (t->succ() == nullptr) {
        last = t;
    }
    if (first == last) {
        last = nullptr;
    }
}

/**
 * function displays all the elements in the list
 * @returns 'void'
 */
template <typename T>
void data_structures::list<T>::print_list() {
    if (isEmpty()) {
        std::cout << "List is Empty!";
        return;
    }
    std::shared_ptr<link<T> > t = first;
    while (t->succ() != nullptr) {
        std::cout << t->succ()->val() << "\t";
        t = t->succ();
    }
}

/**
 * function searchs for @param find_elem in the list
 * @param find_elem to be searched for in the list
 * @return index of find_elem
 */
template <typename T>
int data_structures::list<T>::search(T find_elem) {
    int idx = 0;
    if (isEmpty() == true) {
        std::cout << "List is Empty!";
        return -1;
    }
    std::shared_ptr<link<T> > t = first;
    while (t != last && t->succ()->val() != find_elem) {
        t = t->succ();
        idx++;
    }
    if (t == last) {
        std::cout << "Element not found\n";
        return -1;
    }
    std::cout << "Element was found\n";
    return idx;
}
/**
 * Main function:
 * Allows the user add and delete values from the list.
 * Also allows user to search for and display values in the list.
 * @returns 0 on exit
 */
int main() {
    data_structures::list<int> L_int;

    std::cout << "\nTEST integer type" << std::endl;
    // Insert testing
    L_int.push_back(11);
    L_int.push_back(12);
    L_int.push_back(15);
    L_int.push_back(10);
    assert(L_int.size() == 4);

    L_int.push_front(12);
    L_int.push_front(20);
    L_int.push_front(18);
    assert(L_int.size() == 7);
    L_int.print_list();  // To print the array

    // Remove testing
    L_int.erase(12);  // Remove Duplicate value in the list
    L_int.erase(15);  // Remove the existing value in the list
    assert(L_int.size() == 5);
    L_int.erase(50);  // Try to remove the non-existing value in the list
    assert(L_int.size() == 5);

    // LinearSearch testing
    assert(L_int.search(11) == 0);  // search for the existing element
    assert(L_int.search(12) == 2);
    assert(L_int.search(50) == -1);  // search for the non-existing element

    return 0;
}

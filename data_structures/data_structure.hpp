

#include <array>    /// for std::array
#include <cassert>  /// for assert
#include <cstdio>
#include <cstdlib>
#include <iostream>  /// for io operations

namespace data_structures {

template <typename T>
class list_array {
 public:
    list_array() = default;

    /**
     * @brief Insert the new element in the list
     * @param val element that will be inserted
     * @returns void
     */
    void insert(const T val);

    /**
     * @brief To remove the element from the list
     * @param val element that will be removed
     * @returns void
     */
    void remove(const T val);

    /**
     * @brief Utility function to print array
     * @returns void
     */
    void print_list();

    /*
     * @brief Parent function of binarySearch and linearSearch methods
     * @param val element that will be searched
     * @return index of element in the list if present else -1
     */
    int search(const T val);

    /**
     * @brief Search an element in the list using binarySearch.
     * @param first pointer to the first element in the remaining list
     * @param last pointer to the last element in the remaining list
     * @param val element that will be searched
     * @return index of element in the list if present else -1
     */
    int BinarySearch(const int first, const int last, const T val);

    /**
     * @brief Search an element using linear search
     * @param val element that will be searched
     * @return index of element in the list if present else -1
     */
    int LinearSearch(const T val);

    /**
     * @brief Sort the list
     * @returns void
     */
    void sort();

    /**
     * @brief Get top element
     * @returns top element
     */
    T size() { return top; }

    /**
     * @brief Get whether list is sorted or not
     * @returns bool
     */
    bool isSortedList() { return isSorted; }

 private:
    std::array<T, 50> data;
    uint64_t top = 0;
    bool isSorted = false;
};  // class list_array

/**
 * A link class containing a value and pointer to another link
 */
template <typename T>
class link {
 private:
    T pvalue;                     ///< value of the current link
    std::shared_ptr<link> psucc;  ///< pointer to the next value on the list

 public:
    /**
     * function returns the value stored in the link.
     * @returns the value stored in the link.
     */
    T val() { return pvalue; }

    /**
     * function returns the pointer to next link
     * @returns the pointer to the next link
     * */
    std::shared_ptr<link> &succ() { return psucc; }

    /**
     * Creates link with provided value and pointer to next link
     * @param value is the integer stored in the link
     */
    explicit link(T value = 0) : pvalue(value), psucc(nullptr) {}
};

/**
 * A list class containing a sequence of links
 */
template <typename T>
class list {
 private:
    std::shared_ptr<link<T> > first;  ///< link before the actual first element
    std::shared_ptr<link<T> > last;   ///< last link on the list
    int list_size;

 public:
    /**
     * List constructor. Initializes the first and last link.
     */
    list() {
        // Initialize the first link
        first = std::make_shared<link<T> >();
        // Initialize the last link with the first link
        last = nullptr;
        list_size = 0;
    }

    bool isEmpty();

    void push_back(T new_elem);
    void push_front(T new_elem);
    void erase(T old_elem);
    void print_list();
    int search(T find_elem);
    void reverse();
    int size() { return list_size; }
};

template <typename T>
class stack_array {
 public:
    stack_array() { stack_idx = -1; }

    /*
     * @brief push element x into stack
     * @param val element that will be inserted.
     * @return void
     */
    void push(T x);

    /*
     * @brief pop element from stack and remove the element
     * @return element from stack
     */
    T pop();

    /*
     * @brief print every element in the stack
     * @return void
     */
    void print_stack();

    /*
     * @brief return element from top of the stack but not removed
     * @return element from top
     */
    T peek();

    /*
     * @brief return element at the bottom of the stack
     * @return element data[0]
     */
    T bottom();

    int size() { return stack_idx + 1; }

    bool isEmpty() { return stack_idx == -1; }

    bool isFull() { return stack_idx == 49; }

 private:
    std::array<T, 50> data;
    int stack_idx;
};

template <typename T>
struct node {
    T val;
    node *next;
};

template <typename T>
class stack_linked_list {
 public:
    stack_linked_list() {
        top_var = NULL;
        stack_size = 0;
    }

    /*
     * @brief push element x into stack
     * @param val element that will be inserted.
     * @return void
     */
    void push(T x);

    /*
     * @brief pop element from stack and remove the element
     * @return element from stack
     */
    T pop();

    /*
     * @brief print every element in the stack
     * @return void
     */
    void print_stack();

    int size() { return stack_size; }

    bool isEmpty() { return stack_size == 0; }

 private:
    node<T> *top_var;
    int stack_size;
};

}  // namespace data_structures

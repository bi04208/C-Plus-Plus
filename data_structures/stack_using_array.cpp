


#include "data_structure.hpp"
#include <cassert>

template <typename T>
void data_structures::stack_array<T>::push(T x) {
    if (isFull() == true) {
        std::cout << "\nOverflow";
    } else {
        data[++stack_idx] = x;
    }
}

template <typename T>
T data_structures::stack_array<T>::pop() {
    if (isEmpty() == true) {
        std::cout << "\nStack is empty;";
    } else {
        std::cout << "\n" << data[stack_idx] << "deleted from stack";
        return data[stack_idx--];
    }
}

template <typename T>
void data_structures::stack_array<T>::print_stack() {
    std::cout << "stack" << std::endl;
    for (int i = size() - 1; i >= 0; i--) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
T data_structures::stack_array<T>::peek() {
    if (isEmpty() == true) {
        std::cout << "\nStack is empty;";
    }
    std::cout << "\nTopmost element: " << data[stack_idx];
    return data[stack_idx];
}

template <typename T>
T data_structures::stack_array<T>::bottom() {
    if (isEmpty() == true) {
        std::cout << "\nStack is empty;";
    }
    std::cout << "\nBottom element: " << data[0];
    return data[0];
}

int main() {
    data_structures::stack_array<int> S_int;
    data_structures::stack_array<double> S_double;

    std::cout << "\nTEST integer type" << std::endl;
    // Push testing
    S_int.push(9);
    S_int.push(11);
    S_int.push(7);
    S_int.push(3);
    assert(S_int.size() == 4);
    S_int.print_stack();

    // Pop testing
    S_int.pop();
    S_int.pop();
    assert(S_int.size() == 2);
    
    // Peek, bottom testing
    S_int.peek();
    S_int.bottom();


    std::cout << "\n\nTEST double type" << std::endl;
    // Push testing
    S_double.push(9.3);
    S_double.push(11.5);
    S_double.push(7.6);
    S_double.push(3.11);
    S_double.push(1.52);
    assert(S_double.size() == 5);
    S_double.print_stack();

    // Pop testing
    S_double.pop();
    S_double.pop();
    assert(S_double.size() == 3);
    
    // Peek, bottom testing
    S_double.peek();
    S_double.bottom();


    return 0;
}

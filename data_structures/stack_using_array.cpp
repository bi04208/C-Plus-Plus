


#include "data_structure.hpp"

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
    for (int i = 0; i < size(); i++) {
        std::cout << data[i] << std::endl;
    }
}

int main() {
    data_structures::stack_array<int> stack;

    int ch, x;
    do {
        std::cout << "\n0. Exit";
        std::cout << "\n1. Push";
        std::cout << "\n2. Pop";
        std::cout << "\n3. Print";
        std::cout << "\n4. Print topmost element";
        std::cout << "\n5. Print Bottom element";
        std::cout << "\nEnter Your Choice : ";
        std::cin >> ch;
        if (ch == 1) {
            std::cout << "\nInsert : ";
            std::cin >> x;
            stack.push(x);
        } else if (ch == 2) {
            stack.pop();
        } else if (ch == 3) {
            stack.print_stack();
        } else if (ch == 4) {
            stack.peek();
        } else if(ch == 5) {
            stack.bottom();
        }
    } while (ch != 0);

    return 0;
}

#include"data_structure.hpp"

template <typename T>
void data_structures::stack_linked_list<T>::push(T x) {
    node<T> *n = (struct node<T> *)malloc(sizeof(node<T>));
    n->val = x;
    n->next = top_var;
    top_var = n;
}

// void push(int x) {
//     node *n = new node;
//     n->val = x;
//     n->next = top_var;
//     top_var = n;
// }

template <typename T>
T data_structures::stack_linked_list<T>::pop() {
    if (isEmpty() == true) {
        return 0;
    } else {
        node<T> *t = top_var;
        T ret = t->val;
        std::cout << "\n" << t->val << " deleted";
        top_var = top_var->next;
        delete t;
        return ret;
    }
}

// void pop() {
//     if (top_var == nullptr) {
//         std::cout << "\nUnderflow";
//     } else {
//         node *t = top_var;
//         std::cout << "\n" << t->val << " deleted";
//         top_var = top_var->next;
//         delete t;
//     }
// }

template <typename T>
void data_structures::stack_linked_list<T>::print_stack() {
    node<T> *t = top_var;
    while (t != NULL) {
        std::cout << t->val << " ";
        t = t->next;
    }
    std::cout << std::endl;
}

// void show() {
//     node *t = top_var;
//     while (t != nullptr) {
//         std::cout << t->val << "\n";
//         t = t->next;
//     }
// }

int main() {
    int ch = 0, x = 0;
    int t;
    data_structures::stack_linked_list<int> s;
    do {
        std::cout << "\n0. Exit or Ctrl+C";
        std::cout << "\n1. Push";
        std::cout << "\n2. Pop";
        std::cout << "\n3. Print";
        std::cout << "\nEnter Your Choice: ";
        std::cin >> ch;
        switch (ch) {
            case 0:
                break;
            case 1:
                std::cout << "\nInsert : ";
                std::cin >> x;
                s.push(x);
                break;
            case 2:
                t = s.pop();
                break;
            case 3:
                s.print_stack();
                break;
            default:
                std::cout << "Invalid option!\n";
                break;
        }
    } while (ch != 0);

    return 0;
}

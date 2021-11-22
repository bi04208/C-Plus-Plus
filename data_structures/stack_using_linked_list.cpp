#include"data_structure.hpp"

template <typename T>
void data_structures::stack_linked_list<T>::push(T x) {
    node<T> *n = (struct node<T> *)malloc(sizeof(node<T>));
    n->val = x;
    n->next = top_var;
    top_var = n;
    stack_size++;
}

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
        stack_size--;
        return ret;
    }
}

template <typename T>
void data_structures::stack_linked_list<T>::print_stack() {
    std::cout << std::endl;
    node<T> *t = top_var;
    while (t != NULL) {
        std::cout << t->val << " ";
        t = t->next;
    }
    std::cout << std::endl;
}


int main() {
    data_structures::stack_linked_list<int> S_int;
    data_structures::stack_linked_list<double> S_double;

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
    S_int.print_stack();

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
    S_double.print_stack();
    
    return 0;
}

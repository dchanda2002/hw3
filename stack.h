#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private std::vector<T>
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
};

template <typename T>
Stack<T>::Stack() {

}

template <typename T>
Stack<T>::~Stack() {

}

// returns if the stack is empty or not
template <typename T>
bool Stack<T>::empty() const {
    if(size() > 0){
        return false;
    }
    return true;
}

//uses vector::size() to return the size of the stack
template <typename T>
size_t Stack<T>::size() const {
    return std::vector<T>::size();
}

//pushes an item to the back of the vector ("top" of the stack)
template <typename T>
void Stack<T>::push(const T& item) {
    this->push_back(item);
}

//pops an item from the back of the vector ("top" of the stack), throws an exception
// if empty
template <typename T>
void Stack<T>::pop() {
    if(!empty()){  
        this->pop_back();
    } else {
        throw std::underflow_error("Empty Stack!");
    }
     
    return;
}

//returns the item at the back of the vector ("top" of the stack), throws an exception
// if empty
template <typename T>
const T& Stack<T>::top() const {
    if(!empty()){ 
        return this->back();
    } else {
        throw std::underflow_error("Empty Stack!");
    }
}


#endif
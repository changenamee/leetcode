//
// Created by sky on 2023/3/19.
//

#include "list.h"

#include <iostream>

template <class T>
List<T>::List() {
    first_ = new Node<T>;
    last_ = nullptr;
}

template<class T>
List<T>::~List() {
    Erase();
}

template<class T>
bool List<T>::IsEmpty() {
    return first_->next() == nullptr;
}

template<class T>
void List<T>::PushBack(T data) {
    Node<T>* node = new Node<T>(data);
    if (IsEmpty()) {
        first_->next() = node;
        node->prev() = first_;
        last_ = node;
    }
    else {
        node->prev() = last_;
        last_->next() = node;
        last_ = node;
    }
}

template<class T>
void List<T>::PushFront(T data) {
    Node<T>* node = new Node<T>(data);
    if (IsEmpty()) {
        first_->next() = node;
        node->prev() = first_;
        last_ = node;
    }
    else {
        node->prev() = first_;
        node->next() = first_->next();
        first_->next() = node;
    }
}

template<class T>
void List<T>::Erase() {
    if (IsEmpty()) {
        return;
    }

    Node<T>* cur = first_->next();
    while (cur) {
        Node<T>* next = cur->next();
        delete cur;
        cur = next;
    }
}

template<class T>
void List<T>::ShowData() {
    if (IsEmpty()) {
        std::cout << "list is null" << std::endl;
        return;
    }

    int cnt = 0;

    Node<T>* cur = first_->next();
    while (cur) {
        std::cout << cur << "\t" << cur->data() << "\t";
        if (++cnt % 10 == 0) {
            std::cout << std::endl;
        }
        cur = cur->next();
    }
}

template<class T>
Node<T> *List<T>::Search(T val) {
    if (IsEmpty()) {
        return nullptr;
    }

    Node<T>* cur = first_->next();

    while (cur) {
        if (cur->data() == val) {
            return cur;
        }

        cur = cur->next();
    }

    return nullptr;
}

template<class T>
void List<T>::Reverse() {
    if (IsEmpty()) {
        return;
    }

    Node<T>* pre = nullptr;
    Node<T>* cur = first_->next();

    while (cur) {
        Node<T>* next = cur->next();
        cur->next() = pre;
        pre = cur;
        cur = next;
    }

    first_->next() = pre;
}

int main() {
    // test list
    {
        List<int>* list = new List<int>;

        list->PushBack(3);
        list->PushBack(2);
        list->PushBack(1);
        list->PushFront(4);
        list->PushFront(5);
        list->ShowData();

        Node<int>* target = list->Search(2);
        if (nullptr != target) {
            std::cout << "target: " << target << "\tval is " << target->data() << std::endl;
        }

        list->Reverse();
        list->ShowData();

        target = list->Search(2);
        if (nullptr != target) {
            std::cout << "target: " << target << "\tval is " << target->data() << std::endl;
        }
    }

}
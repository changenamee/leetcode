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
        std::cout << cur << "\t" << cur->data() << "\n";
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

template<class T>
bool List<T>::HasCycle() {
    if (IsEmpty()) {
        return false;
    }

    Node<T>* first = first_->next();
    if (!first->next()) {
        return false;
    }

    Node<T>* second = first->next();

    if (first == second) {
        return true;
    }

    while (second && second->next()) {
        if (first == second) {
            return true;
        }

        first = first->next();
        second = second->next()->next();
    }

    return false;
}

template<class T>
List<T>* List<T>::MergeTwoList(List<T> *first, List<T> *second) {
    if (NULL == first->first_->next()) {
        return second;
    }

    if (NULL == second->first_->next()) {
        return first;
    }

    List<T>* result = new List<T>();
    Node<T>* result_head = result->first_;

    Node<T>* first_cur = first->first_->next();
    Node<T>* second_cur = second->first_->next();
    if (first_cur->data() < second_cur->data()) {
        result_head->next() = first_cur;
        result_head = first_cur;
        first_cur = first_cur->next();
    }
    else {
        result_head->next() = second_cur;
        result_head = second_cur;
        second_cur = second_cur->next();
    }

    std::cout << result_head->data() << std::endl;

    while (first_cur && second_cur) {
        std::cout << first_cur->data() << "\t" << second_cur->data() << std::endl;
        if (first_cur->data() < second_cur->data()) {
            result_head->next() = first_cur;
            result_head = first_cur;
            first_cur = first_cur->next();
        }
        else {
            result_head->next() = second_cur;
            result_head = second_cur;
            second_cur = second_cur->next();
        }
        std::cout << result_head->data() << std::endl;
    }

    if (first_cur) {
        result_head->next() = first_cur;
    }

    if (second_cur) {
        result_head->next() = second_cur;
    }

    return result;
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
        std::cout << "1" << std::endl;
        list->ShowData();

        // has cycle
        {
            // 5 4 3 2 1
            Node<int>* first = list->Search(2);
            std::cout << first << "\t" << first->data() << "\n";
            Node<int>* second = list->Search(5);
            std::cout << second << "\t" << second->data() << "\n";

            first->next() = second;

            bool if_crycle = list->HasCycle();
            if (if_crycle) {
                std::cout << "has crycle" << std::endl;
            }
            else {
                std::cout << "has no crycle" << std::endl;
            }
        }

        // merge
        {
            List<int>* list1 = new List<int>;
            List<int>* list2 = new List<int>;

            list1->PushBack(1);
            list1->PushBack(3);
            list1->PushBack(5);

            list2->PushBack(4);
            list2->PushBack(5);
            list2->PushBack(6);

            List<int>* merge_list = list1->MergeTwoList(list1, list2);
            if (!merge_list->IsEmpty()) {
                merge_list->ShowData();
            }
        }
    }

}
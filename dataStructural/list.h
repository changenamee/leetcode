//
// Created by sky on 2023/3/19.
//

#ifndef LEETCODE_LIST_H
#define LEETCODE_LIST_H

template<class T>
class Node {
private:
    T data_;
    Node<T>* next_;
    Node<T>* prev_;
public:
    Node(T data = 0, Node<T>* next = nullptr, Node<T>* prev = nullptr):
            data_(data), next_(next), prev_(prev){}
    ~Node(){};

    T data() {
        return data_;
    }

    void set_data(T data) {
        data_ = data;
    }

    Node<T>*& next() {
        return next_;
    }

    void set_next(Node<T>* next) {
        next_ = next;
    }

    Node<T>*& prev() {
        return prev_;
    }

    void set_prev(Node<T>* prev) {
        prev_ = prev;
    }
};

template<class T>
class List {
private:
    Node<T>* first_;
    Node<T>* last_;

public:
    List();
    virtual ~List();

    bool IsEmpty();
    void Erase();
    void ShowData();
    void PushBack(T data);
    void PushFront(T data);
    Node<T>* Search(T val);

    void Reverse();
};

#endif //LEETCODE_LIST_H

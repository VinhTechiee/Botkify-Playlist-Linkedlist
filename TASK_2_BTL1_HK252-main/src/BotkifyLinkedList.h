#ifndef BOTKIFY_LINKED_LIST_H
#define BOTKIFY_LINKED_LIST_H

#include "main.h"

template <class T>
class BotkifyLinkedList
{
private:
    class Node
    {
    public:
        T data;
        Node* next;
        Node* extra;

        Node();
        Node(const T& data, Node* next = nullptr, Node* extra = nullptr);
    };

    Node* head;
    Node* tail;
    int count;

public:
    BotkifyLinkedList();
    ~BotkifyLinkedList();

    void add(T e);
    void add(int index, T e);
    T removeAt(int index);
    bool removeItem(T item);

    bool empty() const;
    int size() const;
    void clear();

    T& get(int index) const;

    string toString() const;
};

template<class T>
BotkifyLinkedList<T>::Node::Node() : next(nullptr), extra(nullptr) {}

// TODO CODE
template<class T>
BotkifyLinkedList<T>::Node::Node(const T& data, Node* next, Node* extra)
    : data(data), next(next), extra(extra) {}

template<class T>
BotkifyLinkedList<T>::BotkifyLinkedList() {
    head = tail = nullptr;
    count = 0;
}

template<class T>
BotkifyLinkedList<T>::~BotkifyLinkedList() {
    clear();
}

template<class T>
void BotkifyLinkedList<T>::add(T e) {
    Node* node = new Node(e);

    if (count == 0) {
        head = tail = node;
        node->next = node;
        node->extra = node;
    } else {
        node->next = head;
        node->extra = tail;
        tail->next = node;
        head->extra = node;
        tail = node;
    }
    count++;
}

template<class T>
void BotkifyLinkedList<T>::add(int index, T e) {
    if (index < 0 || index > count)
        throw std::out_of_range("Index is invalid!");

    if (index == count) { 
        add(e);
        return;
    }

    Node* node = new Node(e);

    if (count == 0)
    {
        head = tail = node;
        node->next = node;
        node->extra = node;
        count = 1;
        return;
    }

    if (index == 0)
    {
        node->next = head;
        node->extra = tail;
        tail->next = node;
        head->extra = node;
        head = node;
        count++;
        return;
    }

    Node* cur = head;
    for (int i = 0; i < index; i++) cur = cur->next;

    node->next  = cur;
    node->extra = cur->extra;
    cur->extra->next = node;
    cur->extra = node;
    count++;
}

template<class T>
T BotkifyLinkedList<T>::removeAt(int index) {
    if (index < 0 || index >= count)
        throw std::out_of_range("Index is invalid!");

    Node* cur = head;
    for (int i = 0; i < index; i++) cur = cur->next;

    T val = cur->data;

    if (count == 1) {
        head = tail = nullptr;
    } else {
        cur->extra->next = cur->next;
        cur->next->extra = cur->extra;

        if (cur == head) head = cur->next;
        if (cur == tail) tail = cur->extra;
    }

    delete cur;
    count--;
    return val;
}

template<class T>
bool BotkifyLinkedList<T>::removeItem(T item) {
    Node* cur = head;

    for (int i = 0; i < count; i++) {
        if (cur->data == item) {
            removeAt(i);
            return true;
        }
        cur = cur->next;
    }
    return false;
}

template<class T>
bool BotkifyLinkedList<T>::empty() const {
    return count == 0;
}

template<class T>
int BotkifyLinkedList<T>::size() const {
    return count;
}

template<class T>
void BotkifyLinkedList<T>::clear() {
    while (count > 0) removeAt(0);
}

template<class T>
T& BotkifyLinkedList<T>::get(int index) const {
    if (index < 0 || index >= count)
        throw std::out_of_range("Index is invalid!");

    Node* cur;

    if (index <= count / 2) {
        cur = head;
        for (int i = 0; i < index; i++) cur = cur->next;
    } else {
        cur = tail;
        for (int i = count - 1; i > index; i--) cur = cur->extra;
    }

    return cur->data;
}

template<class T>
string BotkifyLinkedList<T>::toString() const {
    if (count == 0) return "";

    stringstream ss;
    Node* cur = head;

    for (int i = 0; i < count; i++) {
        ss << cur->data;
        if (i != count - 1) ss << ",";
        cur = cur->next;
    }
    return ss.str();
}

#endif // BOTKIFY_LINKED_LIST_H

#pragma once

#include <iostream>
#include <stdexcept>

template <typename T>
class MyList {
private:
    struct Node {
        Node* next; // указатель на следующий элемент Node
        Node* prev; // указатель на предыдущий элемент Node
        T data; // пользовательские данные (хранимый объект)

        Node(const T& value, Node* p = nullptr, Node* n = nullptr)
            : data(value), prev(p), next(n) {}
    };

    Node* head;
    Node* tail;
    size_t list_size;

public:
    MyList() : head(nullptr), tail(nullptr), list_size(0) {}

    ~MyList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next_node = current->next;
            delete current;
            current = next_node;
        }
        head = nullptr;
        tail = nullptr;
        list_size = 0;
    }

    void push_back(const T& value) {
        Node* new_node = new Node(value, tail, nullptr);

        if (list_size == 0) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }

        ++list_size;
    }

    T& insert(size_t index, const T& value) {
        if (index > list_size) {
            throw std::out_of_range("List insert index out of range!");
        }

        Node* pos = head;
        for (size_t i = 0; i < index; ++i) {
            pos = pos->next;
        }

        if (pos == nullptr) {
            push_back(value);
            return tail->data;
        }
        if (pos == head) {
            Node* new_node = new Node(value, nullptr, head);
            head->prev = new_node;
            head = new_node;
            ++list_size;
            return head->data;
        }
        Node* prev_node = pos->prev;
        Node* new_node = new Node(value, prev_node, pos);
        prev_node->next = new_node;
        pos->prev = new_node;
        ++list_size;
        return new_node->data;
    }

    size_t erase(size_t index) {
        if (index >= list_size) {
            throw std::out_of_range("List erase index out of range!");
        }

        Node* pos = head;
        for (size_t i = 0; i < index; ++i) {
            pos = pos->next;
        }

        Node* next_node = pos->next;

        if (pos == head && pos == tail) {
            head = nullptr;
            tail = nullptr;
        }
        else if (pos == head) {
            head = pos->next;
            head->prev = nullptr;
        }
        else if (pos == tail) {
            tail = pos->prev;
            tail->next = nullptr;
        }
        else {
            pos->prev->next = pos->next;
            pos->next->prev = pos->prev;
        }

        delete pos;
        --list_size;

        return index;
    }

    size_t size() const { return list_size; }

    T& operator[](size_t index) {
        if (index >= list_size) {
            throw std::out_of_range("List index out of range!");
        }

        Node* current = head;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }

        return current->data;
    }

    void print_elements() const {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void print_size() const {
        std::cout << list_size << std::endl;
    }

};
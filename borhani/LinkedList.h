
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <functional>

template<typename T>
struct Node {
    T* data;
    Node* next = nullptr;
    Node(T* d): data(d) {}
};

template<typename T>
class LinkedList {
public:
    LinkedList() = default;
    ~LinkedList() {
        Node<T>* cur = head;
        while (cur) {
            Node<T>* tmp = cur;
            cur = cur->next;
            delete tmp->data;
            delete tmp;
        }
    }

    void append(T* item) {
        if (!head) {
            head = new Node<T>(item);
        } else {
            Node<T>* cur = head;
            while (cur->next) cur = cur->next;
            cur->next = new Node<T>(item);
        }
    }
    Node<T>* getHead() const { return head; }

    T* find(std::function<bool(const T*)> predicate) const {
        for (Node<T>* cur = head; cur; cur = cur->next) {
            if (predicate(cur->data))
                return cur->data;
        }
        return nullptr;
    }

private:
    Node<T>* head = nullptr;
};

#endif // LINKEDLIST_H

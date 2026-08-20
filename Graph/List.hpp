#ifndef LIST_HPP
#define LIST_HPP

template <class T>
class List {
private:
    struct Node {
        T data;
        Node* next;
        Node(T d, Node* n = nullptr) : data(d), next(n) {}
    };
    Node* head;
    Node* iter; // For iteration

public:
    List() : head(nullptr), iter(nullptr) {}

    // Add to front
    void add(T elt) {
        head = new Node(elt, head);
    }

    // Begin iteration, set iter to head, return true if not empty
    bool begin(T& out) {
        iter = head;
        if (iter) {
            out = iter->data;
            return true;
        }
        return false;
    }

    // Move to next, return true if next exists
    bool getNext(T& out) {
        if (iter && iter->next) {
            iter = iter->next;
            out = iter->data;
            return true;
        }
        return false;
    }

    // Destructor to free memory
    ~List() {
        Node* curr = head;
        while (curr) {
            Node* tmp = curr;
            curr = curr->next;
            delete tmp;
        }
    }
};

#endif
class Node {
public:
    int value;
    Node *next;
    Node *prev;
    Node(int val): value(val), next(nullptr), prev(nullptr){}
};

class Deque {
private:
    Node *left;
    Node *right;
public:
    Deque() {
        left = new Node(-1);
        right = new Node(-1);
        left->next = right;
        right->prev = left;
    }

    bool isEmpty() {
        return (left->next == right);
    }

    void append(int value) {
        Node *newNode = new Node(value);
        Node *lastNode = right->prev;

        newNode->prev = lastNode;
        newNode->next = right;
        lastNode->next = newNode;        
        right->prev = newNode;
    }

    void appendleft(int value) {
        Node *newNode = new Node(value);
        Node *leftNode = left->next;

        newNode->next = leftNode;
        newNode->prev = left;
        leftNode->prev = newNode;
        left->next = newNode;
    }

    int pop() {
        if (isEmpty()) return -1;
        Node *targetNode = right->prev;
        Node *newLastNode = targetNode->prev;
        int value = targetNode->value;

        newLastNode->next = right;
        right->prev = newLastNode;
        delete targetNode; // Free the memory
        return value;
    }

    int popleft() {
        if (isEmpty()) return -1;
        Node *targetNode = left->next;
        Node *newFirstNode = targetNode->next;
        int value = targetNode->value;

        newFirstNode->prev = left;
        left->next = newFirstNode;
        delete targetNode;
        return value;
    }
};

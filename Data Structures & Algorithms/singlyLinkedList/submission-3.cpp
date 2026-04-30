class ListNode {
public:
    int value;
    ListNode *next;

    ListNode (int val) : value(val), next(nullptr) {}
    ListNode (int val, ListNode* nextNode) : value(val), next(nextNode) {} // short version of doing like create node and connect to anothor
};

class LinkedList {
private: 
    ListNode *head;
    ListNode *tail;

public:
    LinkedList() : head(new ListNode(-1)), tail(head) {}

    int get(int index) {
        ListNode *current = head->next;
        int i = 0;
        while (current != nullptr) {
            if (i == index) {
                return current->value;
            }
            i++;
            current = current->next;
        }
        return -1;
    }

    void insertHead(int val) {
        ListNode *newNode = new ListNode(val);
        newNode->next = head->next;
        head->next = newNode;
        if (newNode->next == nullptr) tail = newNode;
    }
    
    void insertTail(int val) {
        tail->next = new ListNode(val);
        tail = tail->next;
    }

    bool remove(int index) {
        ListNode *current = head;
        int i = 0;
        while (i < index && current != nullptr) {
            current = current->next;
            i++;
        }

        if (current != nullptr && current->next != nullptr) {
            if (tail == current->next){
                tail = current;
            }
            ListNode *deleteNode = current->next;
            current->next = current->next->next;
            delete deleteNode;
            return true;
        }

        return false;
    }

    vector<int> getValues() {
        vector<int> LinklistToArray;
        ListNode *current = head->next;
        while (current != nullptr) {
            LinklistToArray.push_back(current->value);
            current = current-> next;
        }
        return LinklistToArray;
    }
};

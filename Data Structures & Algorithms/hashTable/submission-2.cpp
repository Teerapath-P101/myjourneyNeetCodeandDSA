class Node {
public:
    int key;
    int value;
    Node* next;

    Node(int key, int value) : key(key), value(value), next(nullptr) {}
};

class HashTable {
private:
    int size;
    int capacity;
    vector<Node*> table;
    int hash_function(int key) {
        return abs(key) % capacity;
    }
public:
    HashTable(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        table.resize(capacity, nullptr);
    }

    void insert(int key, int value) {
        int index = hash_function(key);
        Node* node = table[index];
        if (!node) {
            table[index] = new Node(key, value);
        } else {
            Node* prev = nullptr;
            while(node) {
                if (node->key == key) {
                    node->value = value;
                    return;
                }
                prev = node;
                node = node->next;
            }
            prev->next = new Node(key, value); 
        }
        size++;
        if ((double)size / capacity >= 0.5) resize();
    }

    int get(int key) {
        int index = hash_function(key);
        Node* node = table[index];
        while(node) {
            if (key == node->key) return node->value;
            node = node->next;
        }
        return -1;
    }

    bool remove(int key) {
        int index = hash_function(key);
        Node* node = table[index];
        Node* prev = nullptr;
        while (node) {
            if (key == node->key) {
                if (prev) {
                    prev->next = node->next;
                } else {
                    table[index] = node->next;
                }
                delete node;
                size--;
                return true;
            }
            prev = node;
            node = node->next;
        }
        return false;
    }

    int getSize() const {
        return size;
    }

    int getCapacity() const {
        return capacity;
    }

    void resize() {
        int newCapa = capacity * 2;
        vector<Node*> newTable(newCapa, nullptr);
        for(Node* node : table) {
            while (node) {
                int index = node->key % newCapa;
                if (!newTable[index]) {
                    newTable[index] = new Node(node->key, node->value);
                } else {
                    Node* newNode = newTable[index];
                    node->next = newNode;
                    newTable[index] = node;
                }
                Node* toDelete = node;
                node = node->next;
                delete toDelete;
            }
        }
        table = newTable;
        capacity = newCapa;
    }
};

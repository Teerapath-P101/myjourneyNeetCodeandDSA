class MinHeap {
private:
    vector<int> heap;

    void percolateUp(int index) {
        int parent = index / 2;
        while(index > 1 && heap[index] < heap[parent]) {
            swap(heap[parent], heap[index]);
            index = parent;
            parent = index / 2;
        }
    }
    void percolateDown(int index) {
        int child = index * 2;
        while (child < heap.size()) {
            if (child + 1 < heap.size() && heap[child + 1] < heap[child]) { // right child is smaller
                child++;
            }
            if (heap[index] <= heap[child]) return; // Return if it's already get the right order property
            swap(heap[child], heap[index]);
            index = child;
            child = index * 2;
        }
    }
public:
    MinHeap() {
        heap.push_back(0);
    }

    void push(int val) {
        heap.push_back((val));
        percolateUp(heap.size() - 1);
    }

    int pop() {
        if (heap.size() == 1) return -1;
        if (heap.size() == 2) {
            int root = heap.back();
            heap.pop_back();
            return root;
        }
        int root = heap[1];
        heap[1] = heap.back();
        heap.pop_back();
        percolateDown(1);
        return root;
    }

    int top() {
        return (heap.size() == 1) ? -1 : heap[1];
    }

    void heapify(const vector<int>& arr) {
        heap.clear();
        heap.push_back(0);
        heap.insert(heap.end(), arr.begin(), arr.end());

        for (int i=(heap.size() - 1)/2; i>0; i--) {
            percolateDown(i);
        }
    }
};

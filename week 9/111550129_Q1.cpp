#include <iostream>
#include <vector>

using namespace std;

class MinHeap {
public:
    void push(int value) {
        // TODO
        heap.push_back(value);
        int index = size() - 1;
        siftUp(index);

    }

    int top() {
        // TODO
        if (size() == 0)
            {
                throw out_of_range("Vector<X>::at() : "
                        "index is out of range(Heap underflow)");
            }
            return heap.at(0);
    }

    void pop() {
        // TODO
        if (size() == 0)
            {
                throw out_of_range("Vector<X>::at() : "
                        "index is out of range(Heap underflow)");
            }
            heap[0] = heap.back();
            heap.pop_back();
            siftDown(0);
    }

    int size() {
          // TODO
          return heap.size();
    }

private:
    vector<int> heap;

    int PARENT(int i){
        return (i-1)/2;
    }
    int LEFT(int i){
        return(2*i+1);
    }
    int RIGHT(int i){
        return(2*i+2);
    }

    void siftUp(int index) {
            // TODO
            if (index && heap[PARENT(index)] > heap[index]){
                swap(heap[index], heap[PARENT(index)]);
                siftUp(PARENT(index));
            }

    }

    void siftDown(int index) {

            // TODO
            int left = LEFT(index);
            int right = RIGHT(index);

            int smallest = index;

            if (left < size() && heap[left] < heap[index]) {
                smallest = left;
            }

            if (right < size() && heap[right] < heap[smallest]) {
                smallest = right;
            }

            if (smallest != index)
            {
                swap(heap[index], heap[smallest]);
                siftDown(smallest);
            }

    }
};
int main() {
    int N;
    while (cin >> N && N != 0) {
        MinHeap min_heap;
        int num;
        for (int i = 0; i < N; i++) {
            cin >> num;
            min_heap.push(num);
        }

        int total_cost = 0;
        while (min_heap.size() > 1) {
            int a = min_heap.top();
            min_heap.pop();
            int b = min_heap.top();
            min_heap.pop();
            int cost = a + b;
            total_cost += cost;
            min_heap.push(cost);
        }
        cout << total_cost << endl;
    }
    return 0;
}

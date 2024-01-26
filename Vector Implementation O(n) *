#include <iostream>
#include <cassert>

using namespace std;

class Vector {
private:
    int *arr = nullptr;
    int size = 0;
    int capacity;

    void enlarge() {
        capacity *= 2;
        int *arr2 = new int[capacity]{};
        for (int i = 0; i < size; ++i) {
            arr2[i] = arr[i];
        }
        swap(arr, arr2);
        delete[] arr2;
    }

public:
    Vector(int size) : size(size) {
        if (size < 0)
            size = 1;
        capacity = size + 10;
        arr = new int[capacity]{};
    }

    ~Vector() {
        delete[]arr;
        arr = nullptr;
    }

    void setValue(int index, int val) {
        assert(0 <= index && index < size); //used to state or assert that the expression must be true
        arr[index] = val;
    }

    int getindex(int index) {
        assert(0 <= index && index < size); //used to state or assert that the expression must be true
        return arr[index];
    }

    int getFront() {
        return arr[0];
    }

    int getBack() {
        return arr[size - 1];
    }

    void push_back(int val) {
        if (size == capacity)
            enlarge();
        arr[size++] = val;
    }

    void insert(int index, int value) {
        if (size == capacity)
            enlarge();
        for (int i = size - 1; i >= index; --i)
            arr[i + 1] = arr[i];
        arr[index] = value;
        ++size;
    }

    void display() {
        for (int i = 0; i < size; ++i)
            cout << arr[i] << " ";
        cout << '\n';
    }

    int search(int val) {
        for (int i = 0; i < size; ++i)
            if (arr[i] == val)
                return i + 1;
        return -1;
    }
};

int main() {
    int n;
    cin >> n;
    Vector v(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        v.setValue(i, x);
    }
    v.display();
    v.push_back(23);
    v.push_back(22);
    v.push_back(11);
    v.display();
    for (int i = 0; i < 1000; ++i) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    v.display();
    cout << v.search(33); //-1 if val not found
    return 0;
}

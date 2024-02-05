#include <iostream>
using namespace std;

class Vector {
private:
    int m_size = 0;
    int m_capacity = 4;
    int *m_data = new int[4];

    void enlarge() {
        int *tmp = new int[m_capacity * 2];
        memcpy(tmp, m_data, m_size * sizeof(m_data[0])); // tmp: destination || m_data: source || n of bytes to copy
        // memcpy(tmp, m_data, m_size * sizeof(int)); // tmp: destination || m_data: source || n of bytes to copy
        delete[] m_data;
        m_data = tmp;
        m_capacity *= 2;
    }
    void shrink() {
        int *tmp = new int[m_capacity /= 2];
        memcpy(tmp, m_data, m_size * sizeof(m_data[0])); // tmp: destination || m_data: source || n of bytes to copy
        // memcpy(tmp, m_data, m_size * sizeof(int)); // tmp: destination || m_data: source || n of bytes to copy
        delete[] m_data;
        m_data = tmp;
    }

public:
    void push_back(int data) {
        if (m_size == m_capacity)
            enlarge();
        m_data[m_size++] = data;
    }
    void pop_back() {
        --m_size;
        if (m_capacity > 4 && m_size * 2 < m_capacity)
            shrink();
    }
    int &operator[](int i) {
        return m_data[i];
    }
    int operator[](int i) const { //to can call it as a const complex
        return m_data[i];
    }
    int size() const {
        return m_size;
    }
    int capacity() const {
        return m_capacity;
    }
    bool is_Empty() const {
        return m_size == 0;
    }
    ~Vector(){
        delete[] m_data;
        m_data = nullptr;
        m_size = m_capacity = 0;
    }
};

int main() {
    Vector v;
    int n;
    cin >> n;
    for (int data, i = 0; i < n; ++i) {
        cin >> data;
        v.push_back(data);
    }
    for (int i = 0; i < v.size(); ++i) {
        cout<<v[i]<<' ';
    }
    return 0;
}

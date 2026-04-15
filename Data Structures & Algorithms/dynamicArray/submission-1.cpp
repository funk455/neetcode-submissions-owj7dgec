class DynamicArray {
public:
    int m_capacity;
    int * m_vec;
    int len;
    DynamicArray(int capacity) {
        m_capacity = capacity;
        m_vec = new int[m_capacity];
        len = 0;
    }

    int get(int i) {
        return m_vec[i];
    }

    void set(int i, int n) {
        m_vec[i] = n;
    }

    void pushback(int n) {
        if (len == m_capacity){
            resize();
        }
        m_vec[len] = n;
        len++;
    }

    int popback() {
        if (len > 0) len--;
        return m_vec[len];
    }

    void resize() {
        m_capacity *= 2;
        int * newvec = new int[m_capacity];
        for (int i = 0; i < len; i++) {
            newvec[i] = m_vec[i];
        }
        delete[] m_vec;
        m_vec = newvec;
    }

    int getSize() {
        return len;
    }

    int getCapacity() {
        return m_capacity;
    }
};

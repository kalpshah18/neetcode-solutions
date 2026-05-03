class DynamicArray {
private:
    int* arr;
    int size;
    int cap;
public:

    DynamicArray(int capacity) {
        arr = (int*)malloc(capacity * sizeof(int));
        size = 0;
        cap = capacity;
    }

    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
        if(size == cap) resize();
        arr[size++] = n;
    }

    int popback() {
        size -= 1;
        return arr[size];
    }

    void resize() {
        arr = (int*)realloc(arr, cap * 2 * sizeof(int));
        cap *= 2;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return cap;
    }
};

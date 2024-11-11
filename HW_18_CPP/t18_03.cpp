#include <iostream>
#include <vector>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

using namespace std;

template <typename T>
class BlackBox {
private:
    vector<T> elements;
    static const int MAX_ELEMENTS = 100;

public:
    BlackBox() {
        srand(static_cast<unsigned int>(time(nullptr)));
    }

    BlackBox(T* arr, int size) {
        if (size > MAX_ELEMENTS) {
            throw overflow_error("Array size exceeds maximum allowed elements.");
        }
        elements.assign(arr, arr + size);
        srand(static_cast<unsigned int>(time(nullptr)));
    }

    void push(const T& element) {
        if (elements.size() >= MAX_ELEMENTS) {
            throw overflow_error("Cannot add more elements, BlackBox is full.");
        }
        elements.push_back(element);
    }

    T pop() {
        if (elements.empty()) {
            throw underflow_error("Cannot pop from an empty BlackBox.");
        }
        int index = rand() % elements.size();
        T element = elements[index];
        elements.erase(elements.begin() + index);
        return element;
    }

    T xpop() const {
        if (elements.empty()) {
            throw underflow_error("Cannot xpop from an empty BlackBox.");
        }
        int index = rand() % elements.size();
        return elements[index];
    }
};

int main() {
    try {
        int arr[] = {1, 2, 3, 4, 5};
        BlackBox<int> box(arr, 5);

        box.push(6);
        cout << "Random element (xpop): " << box.xpop() << endl;
        cout << "Random element removed (pop): " << box.pop() << endl;
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }
}

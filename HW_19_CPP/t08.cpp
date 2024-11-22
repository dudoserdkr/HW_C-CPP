#include <iostream>
#include <list>

using namespace std;

template <typename T>
class MyList {
    list<T> data;
public:
    MyList(initializer_list<T> init) : data(init) {}

    void add(T &element) {
        data.push_back(element);
    }

    void pop() {
        data.pop_back();
    }

    T find_nearest_number(const T &numb) {
        if (data.empty()) {
            cerr << "Error: the list is empty." << endl;
            exit(-1);
        }

        T min_el = data.front();
        T diff = abs(numb - min_el);

        for (const T &el : data) {
            T current_diff = std::abs(numb - el);
            if (current_diff < diff) {
                diff = current_diff;
                min_el = el;
            }
        }
        return min_el;
    }
};
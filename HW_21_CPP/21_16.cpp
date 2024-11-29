#include <iostream>
#include <vector>


template<typename InputIt, typename OutputIt, typename UnaryPredicate, typename UnaryOperation>
OutputIt transform_if(InputIt first, InputIt last, OutputIt d_first, UnaryPredicate pred, UnaryOperation op) {
    while (first != last) {
        if (pred(*first)) {
            *d_first++ = op(*first);
        }
        ++first;
    }
    return d_first;
}

int main() {
    std::vector<int> src = {1, 2, 3, 4, 5, 6};
    std::vector<int> dst;

    // Приклад використання transform_if: вибираємо і множимо на 2 лише парні числа
    transform_if(src.begin(), src.end(), std::back_inserter(dst),
                 [](int x) { return x % 2 == 0; },
                 [](int x) { return x * 2; });

    std::cout << "Result: ";
    for (int x : dst) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}

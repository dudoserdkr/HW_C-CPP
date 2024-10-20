#include <iostream>

using namespace std;

void initialize_ptr(unsigned long* ptr, int n) {
    for (int i = 0; i < n; i++) {
        ptr[i] = 0;
    }
}

int main() {
    int n;
    cin >> n;

    auto* ptr = new unsigned long[n];
    initialize_ptr(ptr, n);

    for (int i = 0; i < n; i++) {
        for(int j = 0; j < 10; j++) {
            short unsigned digit;
            cin >> digit;
            ptr[i] = ptr[i] * 10 + digit;

        }
    }

    unsigned long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += ptr[i];
        cout << ptr[i] << " ";
    }
    delete [] ptr;
    cout << endl << sum;
}
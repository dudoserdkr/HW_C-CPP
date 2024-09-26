#include <iostream>
#include <stdint.h>
#include <bitset>

using namespace std;

int main() {
    unsigned int n;
    int counter = 0;

    cin >> n;
    cout << bitset<32>(n) << endl;

    while(n) {
        if ((n & 1) == 1) {
            counter++;
        }
        n >>= 1;
    }
    cout << counter;
}
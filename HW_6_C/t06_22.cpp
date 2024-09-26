#include <iostream>
#include <bitset>
#include <stdint.h>

using namespace std;

long int foo(long int n, unsigned k) {
    long int a = ~0;
    a = a << k;
    return n | a;
}

int main() {
    long int n;
    unsigned k;

    cin >> n >> k;
    cout << bitset<64>(n) << endl;
    cout << bitset<64>(foo(n, k)) << endl;
}
#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

void print_pluses(int total_width) {
    cout << string(total_width, '+') << endl;
}

int main() {
    int n;
    cin >> n;
    int const max_width = log10(n) + 1 + 7;
    int const total_width = max_width * n;

    print_pluses(total_width);

    for (int i = 1; i <= n; i++) {
        cout << setw(max_width) << i;
    }
    cout << endl;

    print_pluses(total_width);

    cout << endl << setprecision(3);

    for (int i = 1; i <= n; i++) {
        cout << setw(max_width) << sqrt(i);
    }
    cout << endl;

    print_pluses(total_width);
}
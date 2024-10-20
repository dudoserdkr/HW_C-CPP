#include <iostream>
#include <math.h>

using namespace std;

int main() {
    double x, y;
    cin >> x >> y;
    double num = pow(x, y);
    cout << num << endl;
    cout << scientific << num;
}
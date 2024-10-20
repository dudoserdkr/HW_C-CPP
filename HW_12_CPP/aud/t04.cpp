#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ifstream file("HW_12_C/aud/t04.txt");
    if (!file) {
        cerr << "Error opening file" << endl;
        delete[] arr;
        return 1;
    }

    double* ptr = new double[n];
    double number;
    int counter = 0;
    while (file >> number && counter < n) {
        ptr[counter] = pow(number, arr[counter]);
        counter++;
    }
    file.close();

    ofstream f("HW_12_C/aud/outputt04.txt");
    if (!f) {
        cerr << "Error opening output file" << endl;
        delete[] arr;
        delete[] ptr;
        return 1;
    }

    for (int i = 0; i < counter; i++) {
        f << ptr[i] << " ";
    }
    f.close();

    delete[] arr;
    delete[] ptr;

    return 0;
}
#include <iostream>
#include <map>
#include <fstream>

using namespace std;

int main() {
    map<string, int> months = {
        {"january", 1},
        {"february", 2},
        {"march", 3},
        {"april", 4},
        {"may", 5},
        {"june", 6},
        {"july", 7},
        {"august", 8},
        {"september", 9},
        {"october", 10},
        {"november", 11},
        {"december", 12}
    };
    map<int, string> months2 = {
        {1, "january"},
        {2, "february"},
        {3, "march"},
        {4, "april"},
        {5, "may"},
        {6, "june"},
        {7, "july"},
        {8, "august"},
        {9, "september"},
        {10, "october"},
        {11, "november"},
        {12, "december"}
    };

    vector<array<int, 3>> dates;

    ifstream file("HW_21_CPP/t21_14.txt");

    if (!file.is_open()) {
        cout << "File not found" << endl;
        return 1;
    }

    int day, int_month, year;
    string month;

    while (file >> day >> month >> year) {
        dates.push_back({day, months[month], year});
    }

    sort(dates.begin(), dates.end(), [](const array<int, 3>& arr1, const array<int, 3>& arr2) {
        if (arr1[2] != arr2[2]) {
            return arr1[2] < arr2[2];
        } else if (arr1[1] != arr2[1]) {
            return arr1[1] < arr2[1];
        } else {
            return arr1[0] < arr2[0];
        }
    });

    for (const auto& [day, int_month, year] : dates) {
        cout << year << "/" << months2[int_month] << "/" << day << endl;
    }
}
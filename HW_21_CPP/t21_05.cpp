#include <cctype>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

using namespace std;

int main() {
    string word;

    getline(cin, word);

    transform(word.begin(), word.end(), word.begin(), [](char c){return toupper(c);}); // Працює тільки з англійськими літерами

    cout << word;


}
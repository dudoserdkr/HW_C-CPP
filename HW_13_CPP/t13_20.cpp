#include <iostream>
#include <string>
#include <sstream>

using namespace std;

bool is_letter(char c) {
    return ('A' <= c and c <= 'Z') or ('a' <= c and c <= 'z');
}

int main() {
    string line, word;

    getline(cin, line);

    istringstream stream(line);

    while(stream >> word) {
        for (int i = 0; i < word.length(); i++) {
            if (is_letter(word[i] + 1)) {
                word[i] = word[i] + 1;
            }
            else {
                word[i] = word[i] - 25;
            }
        }
        cout << word << " ";
    }
}
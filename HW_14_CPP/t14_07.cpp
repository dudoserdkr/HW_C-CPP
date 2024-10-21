#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Tag {
    unsigned short tag_count = 0;
    string name;
};

int find_tag_index(const string& word, const vector<Tag>& tags) {
    string clean_word = word.substr(1, word.length() - 2);
    for (int i = 0; i < tags.size(); ++i) {
        if (tags[i].name == clean_word) {
            return i;
        }
    }
    return -1;
}

void print_tags(const vector<Tag>& tags) {
    for (const auto& tag : tags) {
        if (tag.tag_count > 1) {
            cout << tag.name << " - має обернений" << endl;
        }
    }
}

int main() {
    ifstream file("HW_14_CPP/t14_07.txt");
    if (!file) {
        cerr << "Error opening file" << endl;
        return 1;
    }

    vector<Tag> tags;
    string word;

    while (file >> word) {
        if ((word.front() == '<' && word.back() == '>') || (word.front() == '/' && word.back() == '/')) {
            int tag_index = find_tag_index(word, tags);
            if (tag_index == -1) {
                tags.push_back({1, word.substr(1, word.length() - 2)});
            }
            else {
                tags[tag_index].tag_count++;
            }
        }
    }
    file.close();

    print_tags(tags);
}
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
bool areAnagrams(string str1, string str2) {
    if (str1.length() != str2.length()) {
        return false;
    }

    sort(str1.begin(),str1.end());
    sort(str2.begin(),str2.end());

    return str1 == str2;
}

int main() {
    string word1 = "silent";
    string word2 = "listen";

    if (areAnagrams(word1, word2)) {
        cout << "The words are anagrams." << endl;
    } else {
    cout << "The words are not anagrams." << endl;
    }

    return 0;
}
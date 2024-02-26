#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
    int n;
    cin >> n;
    string str;

    unordered_set<string> exist;
    unordered_set<string> existAgain;
    while(n--) {
        cin >> str;
        if(exist.count(str)) existAgain.insert(str);
        else exist.insert(str);
    }

    cout << exist.size() - existAgain.size() << "\n";

    return 0;
}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

inline int h1(int num, int size) { return num % size; }
inline int h2(int num) { return 7 - (num % 7); }

int main() {
    int size, n;
    scanf("%d %d", &size, &n);

    vector<int> result(size);
    vector<bool> isEmpty(size, true);

    int input;
    int step;
    while(n--) {
        scanf("%d", &input);
        step = h2(input);

        for(int i = h1(input, size); ; i = (i + step) % size) {
            if(isEmpty[i]) {
                result[i] = input;
                isEmpty[i] = false;
                break;
            }
        }
    }

    for(int i = 0; i < size; i++) {
        if(isEmpty[i]) printf("- ");
        else printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}

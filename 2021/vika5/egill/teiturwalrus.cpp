#include <iostream>
using namespace std;

int main() {
    int goal = 1000;
    int roof = 2001;

    int n;
    cin >> n;
    int lst[n];

    for (int i = 0; i < n; i++) {
        cin >> lst[i];
    }

    bool boolst[roof];
    for (int i = 0; i < roof; i++) {
        boolst[i] = false;
    }
    boolst[0] = true;

    int i = 0;

    while (i < n) {
        int temp = lst[i];
        int top = roof - temp;

        for (int j = top; j >= 0; j--) {
            if (boolst[j]) { 
                boolst[j+temp] = 1;
            }
        }
        i++;
    }

    for (i = 0; i < roof; i++) {
        if (boolst[goal + i]) {
            cout << goal+i << endl;
            break;
        } else if (boolst[goal-i]) {
            cout << goal-i << endl;
            break;
        }
    }
}


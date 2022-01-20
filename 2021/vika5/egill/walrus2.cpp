#include <iostream>

using namespace std;

#define goal 1000
#define limit 2001

int main()
{
    int n, i, j;
    cin >> n;
    int w[n];
    for(i = 0; i < n; i++) {
        cin >> w[i];
    }

    bool check[limit] = {false};
    check[0] = 1;

    i = 0;
    while (i < n) {
        int curr = w[i];
        int top = limit - curr;

        for (j = top; j >= 0; j--) {
            if (check[j]) check[j+curr] = 1;
        }
        i++;
    }



    for (i = 0; i < limit; i++) {
        if (check[goal + i]) {
            int output = goal+i;
            cout << output << '\n';
            break;
        } else if (check[goal-i]) {
            int output = goal-i;
            cout << output << '\n';
            break;
        }
    }

    return 0;
}


#include<iostream>
using namespace std;

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void run(int n, int p[], int q[]) {
    int dic[] = {0,0,0};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dic[(i+j) % 3] += p[i] * q[j];
        }
    }

    //print_array(dic,3);
    cout << dic[1] <<  " " << dic[2] << " " << dic[0] << endl;
}

int main() {
    int n;
    cin >> n;

    int p[n];
    int q[n];

    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> q[i];
    }
/*
    cout << n << endl;
    print_array(p,n);
    print_array(q,n);
*/
    run(n,p,q);
    return 0;
}

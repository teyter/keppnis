#include <iostream>
#include <vector>

using namespace std;

int sum(vector<int>& fenwick, int index) {
    int total = 0;
    for(int i = index; i > 0; i &= i-1) {
        total += fenwick[i-1];
    }
    return total;
}

void update(vector<int>& fenwick, int index, int value) {
    for(int i = index; i < fenwick.size(); i |= i+1) {
        fenwick[i] += value;
    }
}

int getval(vector<int>& fenwick, int index) {
    return sum(fenwick, index+1) - sum(fenwick, index);
}

int main() {

  vector<int> bitvec(10+1, 0);

  bitvec[5] = 1;
  bitvec[6] = 1;
  bitvec[2] = 1;

  for (int i = 0; i < bitvec.size(); i++) {
    cout << bitvec[i];
  }
  cout << '\n';

  int bla = getval(bitvec, 5);
  update(bitvec, 5, -1);
  
  for (int i = 0; i < bitvec.size(); i++) {
    cout << bitvec[i];
  }
  cout << '\n';



    // int n, k;
    // cin >> n >> k;

    // vector<int> fenwick(n+1, 0);

    // for(int i = 0; i < k; i++) {
    //     char c;
    //     cin >> c;

    //     if(c == 'F') {
    //         int x;
    //         cin >> x;
    //         int val = getval(fenwick, x);

    //         if(val == 0) {
    //             val = 1;
    //         }
    //         else {
    //             val = -1;
    //         }
    //         update(fenwick, x, val);

    //         val = getval(fenwick, x);
    //     }
    //     if(c == 'C') {
    //         int x, y;
    //         cin >> x >> y;
    //         cout << sum(fenwick, y+1) - sum(fenwick, x) << endl;
    //     }
    // }
}

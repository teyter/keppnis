#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

typedef vector<int> vi;

vector<int> vecA, vecB;
unordered_set<int> mem;

int inline pairs(int i, int a) { 
  return i * 3001 + a;
}

bool rec(int arr[], int i, int n, int t, int a, int b)
{
  if (i == n) return 1;

  int x = pairs(i, a);
  if (mem.count(x)) return 0;

  if (t >= a+arr[i]) {
    vecA.push_back(i);
    if (rec(arr, i+1, n, t, a+arr[i], b)) {
      return 1;
    }
    vecA.pop_back();
  }
  if (t >= b+arr[i]) {
    vecB.push_back(i);
    if (rec(arr, i+1, n, t, a, b+arr[i])) {
      return 1;
    }
    vecB.pop_back();
  }
  mem.insert(x);

  return 0;
}

int main()
{
  int t, n, i;
  cin >> t >> n;

  int breaks[n];
  for(i = 0; i < n; i++) cin >> breaks[i];

  bool res = rec(breaks, 0, n, t, 0, 0);

  int ba=0, bb=0, ca=0;
  for (i = 0; i < n; i++) {
    if (i == vecA[ca] && ca < vecA.size()) {
      cout << ba << " ";
      ba += breaks[i];
      ca++;
    } else {
      cout << bb << " ";
      bb += breaks[i];
    }
  }
  cout << '\n';

  return 0;
}

#include <iostream>
#include <climits>

#define goal 1000
#define arrSize 1101
#define maxSum 100000

using namespace std;

int store[arrSize][maxSum];
bool done[arrSize][maxSum];

int closest(int a, int b, int x) {

  // cout << "comparing: " << a << " and " << b << '\n';

  if (abs(a-x) > abs(b-x)) {
    return b;
  } else if (abs(a-x) < abs(b-x)) {
    return a;
  } else {
    if (a > b) {
      return a;
    } else {
      return b;
    }
  }
}

int finder(int i, int sum, int arr[], int n) {
  if (i == n) return 0;

  if (done[i][sum]) return store[i][sum];

  done[i][sum] = 1;

  store[i][sum] = closest(arr[i] + finder(i+1, sum + arr[i], arr, n),
                                      finder(i+1, sum, arr, n), goal - sum);

  return store[i][sum];

}

int main()
{
  int n, i;
  cin >> n;
  int w[n];

  for(i = 0; i < n; i++) cin >> w[i];

  int sum = 0;

  for (i = 1; i <= n; i++) {
    sum = closest(w[i-1] + finder(i, w[i-1], w, n), sum, goal);
  }

  cout << sum << '\n';

  return 0;
}

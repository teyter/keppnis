#include <iostream>
#include <vector>
using namespace std;

int count(vector<int>& bitvec, int i) 
{
    int sum = 0;
    for (int k = i; k > 0; k &= k-1) 
    {
        sum += bitvec[k-1];
    }
    return sum;
}

int get(vector<int>& bitvec, int i) 
{
  return count(bitvec, i+1) + count(bitvec, i);
}

void flip(vector<int>& bitvec, int i) 
{
  int value = get(bitvec, i);

  if (value == 1) 
  {
      value = -1;
  } 
  else 
  {
    value = 1;
  }

  for (int k = i; k < bitvec.size(); k |= k+1) 
  {
      bitvec[k] += value;
  }
}

int main()
{
  int bits, queries;
  cin >> bits >> queries;
  vector<int> bitvec(bits, 0);

  for (int i = 0; i < queries; i++) 
  {
    char q;
    cin >> q;

    if (q == 'F') 
    {
      int index;
      cin >> index;
      flip(bitvec, index);
    } 
    else if (q == 'C')
    {
      int l, r;
      cin >> l >> r;

      cout << count(bitvec, r+1) - count(bitvec, l) << endl;
    }
  }
}

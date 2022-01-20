#include <iostream>
#include <vector>
using namespace std;

int count(vector<int>& bitvec, int index) 
{
    int sum = 0;
    for (int i = index; i > 0; i &= i-1) 
    {
        sum += bitvec[i-1];
    }
    return sum;
}

void flip(vector<int>& bitvec, int index, int value) 
{
    int len = bitvec.size();
    for (int i = index; i < len; i |= i+1) 
    {
        bitvec[i] += value;
    }
}

int get(vector<int>& bitvec, int index) 
{
    return count(bitvec, index+1) - count(bitvec, index);
}

int main() 
{
    int bits, queries;
    cin >> bits >> queries;

    vector<int> bitvec(bits+1, 0);

    for (int i = 0; i < queries; i++) 
    {
        char q;
        cin >> q;

        if (q == 'F') 
        {
            int index;
            cin >> index;
            int val = get(bitvec, index);
            if (val == 0) 
            {
                val = 1;
            }
            else 
            {
                val = -1;
            }
            flip(bitvec, index, val);
            val = get(bitvec, index);
        }
        if (q == 'C') 
        {
            int l, r;
            cin >> l >> r;
            cout << count(bitvec, r+1) - count(bitvec, l) << endl;
        }
    }
}

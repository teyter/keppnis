#include <iostream>
#include <vector>
using namespace std;

int count(int bitvec[], int l, int r) 
{
    int sum = 0;
    for (int i = l; i < r+1; i++) 
    {
        sum += bitvec[i];
    }
    return sum;
}

void flip(int bitvec[], int i) 
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
    int bitvec[bits] = {0};

    for (int i = 0; i < queries; i++) 
    {
        char q;
        cin >> q;

        if (q == 'F') 
        {
            int index;
            cin >> index;
            flip(bitvec,index);
        } 
        else if (q == 'C')
        {
            int l, r;
            cin >> l >> r;

            cout << count(bitvec,l,r) << endl;
        }
    }
}

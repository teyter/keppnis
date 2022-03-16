#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int swaps(int left, int right, vector<int>& v, vector<int>& temp) 
{
    if (left == right) return 0;

    int M = (left + right) / 2;
    int count = 0;
    count += swaps(left, M, v, temp);
    count += swaps(M + 1, right, v, temp);

    int index1 = left, index2 = M + 1, index3 = 0;
    while (index1 <= M && index2 <= right) 
    {
        if (v[index1] <= v[index2]) 
        {
            temp[index3++] = v[index1++];
        } 
        else 
        {
            count += M - index1 + 1;
            temp[index3++] = v[index2++];
        }
    }
    while (index1 <= M)
    {
        temp[index3++] = v[index1++];
    }

    while (index2 <= right)
    {
        temp[index3++] = v[index2++];
    }

    memcpy(v.data() + left, temp.data(), index3 * sizeof(int));
    return count;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> temp(n);
    for (int i = 0; i < n; ++i) 
    {
        cin >> v[i];
    }
    cout << swaps(0, n - 1, v, temp) << endl;
	return 0;
}

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int char2int(char c) { return (int)c - 48; }

int str2int(string s, int len)
{
    int e = len-1;
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        sum +=  char2int(s[i])*pow(10,e--);
    }
    return sum;
}

int main()
{
    string a = "99999";
    cout << str2longlong(a,a.length()) << endl;
    //cout << stoi(a) << endl;
}

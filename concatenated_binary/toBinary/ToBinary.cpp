#include <iostream>
#include <bitset>
#include <cmath>

// #include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int toInteger(unsigned n)
    {
        int dec = 0, i = 0, rem;

        while (n != 0)
        {
            rem = n % 10;
            n /= 10;
            dec += rem * pow(2, i);
            ++i;
        }

        return dec;
    }

    int toBinary(unsigned n)
    {
        int bin = 0;
        int rem, i = 1;

        while (n != 0)
        {
            rem = n % 2;
            n /= 2;
            bin += rem * i;
            i *= 10;
        }

        return bin;
    }

    void bitsetFun(unsigned number)
    {
        // auto result = bitset<8>(number);

        cout << "a = " << bitset<8>(number) << endl;
    }
};

int main()
{
    int input = 3;
    Solution s;
    int i = 0;
    i = s.toBinary(input);
    cout << i << endl;
    // s.bitsetFun(input);
}
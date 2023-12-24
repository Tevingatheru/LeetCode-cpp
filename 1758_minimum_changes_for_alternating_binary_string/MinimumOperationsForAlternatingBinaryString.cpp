#include <string>
#include <iostream>
#include <cstring>

using namespace std;

/**
 * Time complexity and memory complexity are both O(n)
 *
 */
class Solution
{

public:
    int minOperations(string s)
    {
        int countZeroOneList = 0;
        int countOneZeroList = 0;

        for (int i = 0; i < s.size(); ++i)
        {
            char expectedZeroOne = (i % 2 == 0) ? '0' : '1';
            char expectedOneZero = (i % 2 == 0) ? '1' : '0';

            if (s[i] != expectedZeroOne)
            {
                ++countZeroOneList;
            }

            if (s[i] != expectedOneZero)
            {
                ++countOneZeroList;
            }
        }

        return min(countZeroOneList, countOneZeroList);
    }

};

int main()
{
    Solution *solution = new Solution();

    cout << solution->minOperations("10010100") << " but expected: " << 3 << endl;

    cout << solution->minOperations("1111") << " but expected: " << 2 << endl;
}

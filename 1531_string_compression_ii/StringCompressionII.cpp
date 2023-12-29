#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

/***
 * This is still unsolved
*/
class Solution
{
public:
    int getLengthOfOptimalCompression(string s, int k)
    {
        int count = 0;
        int alphabet[26];
        fill_n(alphabet, 26, -1);
        int size = s.length();
        cout << "size: " << size << endl;
        if (size < 2)
        {
            return count;
        }

        int check = 2;

        cout << sizeof(check) - 1 << " length" << endl;
        for (char letter : s)
        {
            cout << letter << " : " << letter - 'a' << " sum->" << alphabet[letter - 'a'] << endl;
            alphabet[letter - 'a']++;
        }

        for (int i = 1; i <= k; i++)
        {
            for (int j = 0; j < 26; j++)
            {

                if ((i - 1) == alphabet[j])
                {
                    alphabet[j] = alphabet[j] - i;
                    k = k - i;
                }
                if (k == 0)
                {
                    break;
                }
            }
        }

        string compressed_str;
        int arr_size = sizeof(alphabet) / sizeof(alphabet[0]);
        if (arr_size < 2)
        {
            return count;
        }

        for (int j = 0; j < 26; j++)
        {
            if (alphabet[j] > -1)
            {
                string str = to_string(alphabet[j] + 1);
                if (str != "0" && alphabet[j] != 0)
                {
                    compressed_str.append(str);
                }

                count++;
            }
        }

        count = count + compressed_str.length();

        return count;
    }
};

void test_1()
{
    string sample_1 = "a";
    int expected_1 = 0;

    Solution solution;
    int result = solution.getLengthOfOptimalCompression(sample_1, 1);
    cout << "Results "
         << "actual-> " << result << " expected-> " << expected_1 << endl;
}

void test_2()
{
    string sample_1 = "abc";
    int expected_1 = 1;

    Solution solution;
    int result = solution.getLengthOfOptimalCompression(sample_1, 2);
    cout << "Results "
         << "actual-> " << result << " expected-> " << expected_1 << endl;
}

void test_3()
{
    string sample_1 = "abbbbbbbbbba";
    int expected_1 = 3;
    int k = 2;

    Solution solution;
    int result = solution.getLengthOfOptimalCompression(sample_1, k);
    cout << "Results "
         << "actual-> " << result << " expected-> " << expected_1 << endl;
}

void test_4()
{
    string sample_1 = "llllllllllttttttttt";
    int expected_1 = 4;
    int k = 1;

    Solution solution;
    int result = solution.getLengthOfOptimalCompression(sample_1, k);
    cout << "Results "
         << "actual-> " << result << " expected-> " << expected_1 << endl;
}

int main()
{
    // test_1();
    // test_2();
    // test_3();
    test_4();
}
#include <string>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxLengthBetweenEqualCharacters(string s)
    {
        int size = s.length();
        // check if input length is x < 1
        if (size < 1)
        {
            return -1;
        }
        else if (size == 2)
        {
            if (s[0] == s[1])
            {
                return 0;
            }
            else
            {
                return -1;
            }
        }
        int alphabet_arr[26] = {0};
        int largerst_substring = 0;
        // count letters
        for (char letter : s)
        {
            alphabet_arr[letter - 'a']++;
        }
        // check if any letter appears twice
        bool appears_twice = false;
        for (int letter_count : alphabet_arr)
        {
            if (letter_count >= 2)
            {
                appears_twice = true;
            }
        }

        if (!appears_twice)
        {
            return -1;
        }

        // map index to char
        // map char(index) by letter(position)
        map<int, vector<int>> map;
        vector<int> keys_appearing_twice;
        for (int i = 0; i < size; i++)
        {
            char letter = s[i];
            if (alphabet_arr[letter - 'a'] > 1)
            {
                keys_appearing_twice.push_back(letter - 'a');
            }

            map[letter - 'a'].push_back(i);
        }

        // find largest substring
        for (int equal_char : keys_appearing_twice)
        {
            // check size between char
            int min = map[equal_char][0];
            int size = map[equal_char].size();
            int max = map[equal_char][size - 1] - 1;
            if (max - min > largerst_substring)
            {
                largerst_substring = max - min;
            }
        }

        return largerst_substring;
    }
};

int main()
{
    Solution solution;
    int result = solution.maxLengthBetweenEqualCharacters("abca");

    cout << "expected: " << 2 << " actual: " << result << endl;
}
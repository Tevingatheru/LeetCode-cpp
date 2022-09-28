#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<vector<int>> palindromePairs(vector<string> &words)
    {
        vector<vector<int>> result;
        if (words.empty() || words.size() < 1) return result;
        int n = words.size();

        for (int a = 0; a < n; a++)
        {
            for (int b = 0; b < n; b++)
            {
                if (a != b)
                {
                    string word = words[a] + words[b];
                    // to use reverseString method
                    // string wordB = reverseString(word);
                    // if (word == wordB)
                    // {
                    //     result.push_back({a, b});
                    // }

                    // to use isPalindrome method
                    if (isPalindrome(word, 0, word.size() - 1))
                    {
                        result.push_back({a, b});
                    }
                }
            }
        }
        return result;
    }

private:
    bool isPalindrome(string &s, int start, int end)
    {
        while (start < end)
        {
            if (s[start++] != s[end--])
            {
                return false;
            }
        }
        return true;
    }

    string reverseString(string word)
    {
        int n = word.length();
        for (int i = 0; i < n / 2; i++)
        {
            swap(word[i], word[n - i - 1]);
        }
        return word;
    }
};

class Solution2
{
public:
    vector<vector<int>> palindromePairs(vector<string> &words)
    {
    }
};

int main()
{
    vector<string> input{"abcd", "dcba", "lls", "s", "sssll"};
    Solution s;
    vector<vector<int>> ouput = s.palindromePairs(input);
    for (vector<int> response : output)
    {
        for (int responseOut : response)
        {
            cout << responseOut << endl;
        }
    }
}
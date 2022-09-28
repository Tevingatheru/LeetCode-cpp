#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        // remove special characters and remove whitespace
        string word = removeSpecialCharacters(s);
        // validate if palindrome
        string reverseWord = reverseString(word);
        return word == reverseWord;
    }

private:
    string reverseString(string s)
    {
        int n = s.size();
        for (int i = 0; i < n / 2; i++)
        {
            swap(s[i], s[n - 1 - i]);
        }
        return s;
    }
    string removeSpecialCharacters(string s)
    {
        string temp;
        for (int i = 0; i < s.size(); i++)
        {
            if ((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
            {
                char letter;
                if ((s[i] >= 'A' && s[i] <= 'Z'))
                {
                    letter = s[i] += 32;
                }
                else
                {
                    letter = s[i];
                }
                temp = temp + s[i];
            }
        }
        return temp;
    }
};

int main()
{
    string input0 = "A man, a plan, a canal: Panama";
    string input1 = "0P";
    Solution s;
    bool response = s.isPalindrome(input1);
    cout << "response: " << boolalpha << response << endl;
    return 0;
}
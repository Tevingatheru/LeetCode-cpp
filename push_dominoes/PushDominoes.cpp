#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    string pushDominoes(string dominoes)
    {
        int n = dominoes.size();
        vector<int> indexes(n + 2);
        vector<char> symbols(n + 2);
        int len = 1;
        indexes[0] = -1;
        symbols[0] = 'L';

        for (int i = 0; i < n; i++)
        {
            if (dominoes[i] != '.')
            {
                indexes[len] = i;
                symbols[len++] = dominoes[i];
            }
        }

        indexes[len] = n;
        symbols[len++] = 'R';
        vector<char> ans(dominoes.begin(), dominoes.end());

        for (int i = 0; i < len - 1; i++)
        {
            int index = indexes[i];
            int j = indexes[i + 1];
            char x = symbols[i];
            char y = symbols[i + 1];
            char write;

            if (x == y)
            { // .. or RR or LL
                for (int k = index + 1; k < j; k++)
                {
                    ans[k] = x;
                }
            }
            else if (x > y)
            { // R>L
                for (int k = index + 1; k < j; ++k)
                {
                    ans[k] = k - index == j - k ? '.' : k - index < j - k ? 'R'
                                                                          : 'L';
                }
            }
        }
        string answer(ans.begin(), ans.end());
        return answer;
    }
};

class ForceSolution
{
public:
    string pushDominoes(string dominoes)
    {
        vector<char> a(dominoes.begin(), dominoes.end());
        int n = dominoes.size();
        vector<int> forces(n, 0);
        int force = 0;
        for (int i = 0; i < n; ++i)
        {
            if (a[i] == 'R')
            {
                force = n;
            }
            else if (a[i] == 'L')
            {
                force = 0;
            }
            else
            {
                force = max(force - 1, 0);
            }
            forces[i] += force;
        }

        for (int i = n - 1; i >= 0; --i)
        {
            if (a[i] == 'L')
            {
                force = n;
            }
            else if (a[i] == 'R')
            {
                force = 0;
            }
            else
            {
                force = max(force - 1, 0);
            }
            forces[i] -= force;
        }

        vector<char> ans;
        for (int f : forces)
        {
            ans.push_back((f > 0) ? 'R' : (f < 0) ? 'L'
                                                  : '.');
        }
        string answer(ans.begin(), ans.end());
        return answer;
    }
};

int main()
{
    string testCase1 = "RR.L";
    string output1 = "RR.L";
    string testCase2 = ".L.R...LR..L..";
    string output2 = "LL.RR.LLRRLL..";
    // Solution s;
    // string actualOutput1 = s.pushDominoes(testCase1);

    // cout << "input: " << testCase1 << "\n"
    //      << "your output: " << actualOutput1 << "\n"
    //      << "expected ouput: " << output1 << "\n"
    //      << endl;

    ForceSolution s;
    string actualOutput2 = s.pushDominoes(testCase2);

    cout << "input: " << testCase2 << "\n"
         << "your output: " << actualOutput2 << "\n"
         << "expected ouput: " << output2 << "\n"
         << endl;
}

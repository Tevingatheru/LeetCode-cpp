#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
private:
    /*
     * Recursivly find the root
     * @param i index of array
     * @return root
     */
    int find(vector<int> indexMap, int i)
    {
        return indexMap[i] < 0 ? i : indexMap[i] = find(indexMap, indexMap[i]);
    }
    bool sameRoot(int i, int j)
    {
        return i == j;
    }

public:
    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs)
    {
        // identify the groups
        vector<int> parentIndex(s.size(), -1);

        vector<vector<int>> groupSets(s.size());

        for (auto &pair : pairs)
        {
            auto i = find(parentIndex, pair[0]), j = find(parentIndex, pair[1]);

            if (!sameRoot(i, j))
            {
                // set index of parent to list
                parentIndex[j] = i;
            }
        }
        for(auto i =0 ; i < s.size(); i++) {
            groupSets[find(parentIndex, i)].push_back(i);
        }
        // order the pairs individually
        for (auto &groupOfChar : groupSets)
        {
            string ss = "";
            for (auto characterIndex : groupOfChar)
            {
                ss += s[characterIndex];
            }
            sort(begin(ss), end(ss));
            // rearrange character back in respective position
            for (auto i = 0; i < groupOfChar.size(); ++i)
            {
                s[groupOfChar[i]] = ss[i];
            }
        }

        return s;
    }
};

string testCase0String;
vector<vector<int>> pairs;

void testCase0()
{
    testCase0String = "dcab";
    pairs = {{0, 3}, {1, 2}};
}

int main()
{
    testCase0();

    Solution s;
    string result = s.smallestStringWithSwaps(testCase0String, pairs);
    cout << result << endl;
    return 0;
}
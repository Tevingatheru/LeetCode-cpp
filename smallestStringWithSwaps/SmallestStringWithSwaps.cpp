#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 

using std::vector;
using namespace std;

class Solution
{
private:
    int find(vector<int> &ds, int i)
    {
        return ds[i] < 0 ? i : ds[i] = find(ds, ds[i]);
    }

public:
    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs)
    {
        // identify the groups
        vector<int> nodes(s.size(), 0);
        vector<vector<int>> groups(s.size());
        for (auto &pair : pairs)
        {
            auto i = find(nodes, pair[0]), j = find(nodes, pair[1]);
            if (i != j)
            {
                nodes[j] = i;
            }
        }

        for (auto i = 0; i < s.size(); ++i)
        {
            groups[find(nodes, i)].push_back(i);
        }
        // order the pairs individually
        for (auto &groupOfChar : groups)
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
int main()
{
    vector<vector<int>> pairs{{0, 3}, {1, 2}}; // test case 0

    Solution s;
    string result = s.smallestStringWithSwaps("dcab", pairs);
    cout << "result: " << result << endl;
    return 0;
}
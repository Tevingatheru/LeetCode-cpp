#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;
using std::vector;

class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        vector<unordered_set<int>> graph(n + 1, unordered_set<int>());
        for (auto &edge : trust)
        {
            int a = edge[0], b = edge[1];
            graph[a].insert(b); // a trust b
        }
        for (int cand = 1; cand <= n; ++cand)
        {
            if (graph[cand].size() == 0)
            {
                bool isGood = true;
                for (int other = 1; other <= n; ++other)
                {
                    if (other == cand)
                    {
                        continue;
                    }
                    if (graph[other].count(cand) == 0)
                    {
                        isGood = false;
                        break;
                    }
                }
                if (isGood)
                {
                    return cand;
                }
            }
        }
        return -1;
    }
};

class SolutionModified
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        vector<vector<int>> graph(n + 1, vector<int>());
        for (auto &edge : trust) // UnionSet: loop edges
        {
            int a = edge[0], b = edge[1];
            graph[a].push_back(b); // a trusts b
        }
        for (int cand = 1; cand <= n; ++cand) // find:
        {
            if (graph[cand].size() == 0)
            {
                return cand;
            }
        }
        return -1;
    }
};

class InDegreeOutDegree
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        vector<int> degree(n + 1);
        for (auto &edge : trust)
        {
            int truster = edge[0], trusted = edge[1];
            --degree[truster];
            ++degree[trusted];
        }
        for (int i = 1; i <= n; ++i)
        {
            if (degree[i] == n - 1) // if degree is in
                return i;
        }
        return -1;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> input{{1, 3}, {2, 3}};
    int response = s.findJudge(3, input);
    cout << response << endl;
    SolutionModified sm;
    int responseModified = sm.findJudge(3, input);
    cout << responseModified << endl;
    InDegreeOutDegree iDoD;
    int responseIdOd = iDoD.findJudge(3, input);
    cout << responseIdOd << endl;

    return 0;
}
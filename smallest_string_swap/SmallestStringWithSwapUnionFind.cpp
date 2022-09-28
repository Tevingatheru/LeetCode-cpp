#include <string>
#include <iostream>
#include <vector>

using namespace std;

string testCase0String;
vector<vector<int>> pairs;

class UnionFind
{
    UnionFind(int size)
    {
        // initialize an array with each index as it's own root
        for (int i = 0; i < size; i++)
        {
            root[i] = i;
        }
    }

private
    int[] root;

public:
    /**
     * find root of  number in index
     *
     * **/
    int find(int x)
    {
        return root[x];
    }

    unionSet(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        if (rootIsSame(rootX, rootY))
        {
            for (int i = 0; i < root.size(); i++)
            {
                if (root[i] == rootY)
                {
                    root[i] = rootX;
                }
            }
        }
    }

    void union(int x, int y)
    {
        // node x to y
        int rootX = find(x);
        int rootY = find(y);

        if (!rootIsSame(rootX, rootY))
        {
            rootX = rootY;
        }
    }

    bool rootIsSame(int rootX, int rootY)
    {
        return rootX != rootY;
    }
};

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
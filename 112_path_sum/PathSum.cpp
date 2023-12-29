
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <vector>
#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {

        int sum = 0;
        bool pathExists = false;
        return dfs(root, targetSum, sum, pathExists);
    }

private:
    bool dfs(TreeNode *root, int targetSum, int totalSum, bool pathExists)
    {
        if (root == nullptr)
        {
            return pathExists;
        }
        int val = root->val;
        totalSum += val;

        if (root->left == nullptr && root->right == nullptr)
        {
            if (totalSum == targetSum)
            {
                cout << "true" << endl;
                pathExists = true;
            }

            totalSum = 0;
        }
        else if (!pathExists)
        {
            dfs(root->left, targetSum, totalSum, pathExists);
            dfs(root->right, targetSum, totalSum, pathExists);
        }

        return pathExists;
    }
};

int main()
{
    root =
        [ 5, 4, 8, 11, null, 13, 4, 7, 2, null, null, null, 1 ];

    hasPathSum(TreeNode * root, int targetSum);
}
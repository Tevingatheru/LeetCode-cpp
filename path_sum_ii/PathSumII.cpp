#include <vector>

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

class DFSSolution
{
public:
    vector<vector<int>> ans;
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<int> path;
        dfs(root, targetSum, path);
        return ans;
    }

    void dfs(TreeNode* root, int targetSum, vector<int>& visited){
        if (root == nullptr) {
            return;
        }

        visited.push_back(root->val);
        targetSum -= root->val;
        if (root->left == nullptr && root->right == nullptr) {
            if (targetSum == 0) {
                ans.push_back(visited);
            }
        } else {
            dfs(root->left, targetSum, visited);
            dfs(root->right, targetSum, visited);
        }

    }
};

int main()
{
    TreeNode tn;
}
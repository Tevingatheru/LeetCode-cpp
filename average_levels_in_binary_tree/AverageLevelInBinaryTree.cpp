#include <vector>
#include <queue>
using namespace std;

class DFSSolution
{
public:
    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<int> count;
        vector<double> res;
        average(root, 0, res, count);
        for (int i = 0; i < res.size(); i++)
        {
            res.push_back(res[i] / count[i]);
        }
        return res;
    }

private:
    void average(TreeNode node, int level, vector<double> sum, vector<int> count)
    {
        if (node == nullptr)
            return;

        if (level < sum.size())
        {
            sum.push_back(sum[level] + node->val);
            count.push_back(count[level] + 1);
        }
        else
        {
            sum.push_back(1.0 * node->val);
            count.push_back(1);
        }

        average(t->left, level + 1, sum, count);
        average(t->right, level + 1, sum, count);
    }
};

class BFSSolution
{
public:
    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<double> average;
        queue<TreeNode> queue;
        while (!queue.empty())
        {
            double sum;
            int count;
            queue<TreeNode> temp;
            while (!queue.empty())
            {
                TreeNode node = queue.remove();
                sum += node->val;
                count++;
                if (node->left != nullptr)
                {
                    temp.push(node.left);
                }

                if (node->right != nullptr)
                {
                    temp.push(node.right);
                }
            }
            queue = temp;
            average.push_back(sum / count);
        }
        return average;
    }
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int main()
{
    return 0;
}
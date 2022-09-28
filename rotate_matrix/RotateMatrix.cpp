#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<vector<int>> rotate(vector<vector<int>> &matrix)
    {
        // i,j -> i,j
        // 0,0 -> 0,2
        // 1,0 -> 0,1
        // 2,0 -> 0,0
        int n = matrix.size();
        for (int layer = 0; layer < n / 2; layer++)
        {
            int first = layer;
            int last = n - 1 - layer;
            for (int j = first; j < last; j++)
            {
                int offset = j - first;
                int top = matrix[first][j];
                // left -> top
                matrix[first][j] = matrix[last - offset][first];
                // bottom -> left
                matrix[last - offset][first] = matrix[last][last - offset];
                // right -> bottom
                matrix[last][last - offset] = matrix[j][last];
                // top -> right
                matrix[j][last] = top;
            }
        }
        return matrix;
    }

    vector<vector<int>> reverse(vector<vector<int>> &matrix)
    {
        transpose(matrix);
        return reflect(matrix);
    }

private:
    vector<vector<int>> transpose(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int left = matrix[j][i];

                // left -> right
                matrix[j][i] = matrix[i][j];
                // left -> right
                matrix[i][j] = left;
            }
        }
        return matrix;
    }

    vector<vector<int>> reflect(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n/2; j++)
            {
                int last = n - j -1;
                int left = matrix[i][j];

                matrix[i][j] = matrix[i][last];
                matrix[i][last] = left;
            }
        }
        return matrix;
    }
};

int main()
{
    vector<vector<int>> input{
        {5, 1, 9, 11},
        {2, 4, 8, 10},
        {13, 3, 6, 7},
        {15, 14, 12, 16}};
    Solution s;
    vector<vector<int>> output = s.rotate(input);
    input = {
        {5, 1, 9, 11},
        {2, 4, 8, 10},
        {13, 3, 6, 7},
        {15, 14, 12, 16}};
    vector<vector<int>> output2 = s.reverse(input);
    cout << "check: "<< boolalpha << (output == output2) << endl;
    return 0;
}
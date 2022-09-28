#include <vector>
#include <iostream>
#include <stack>
using namespace std;

class BruteForceSolution
{
public:
    /**
     * O(N^2) time complexity
     * O(1) space complexity
     */
    int trap(vector<int> &height)
    {
        int result = 0;
        int n = height.size();
        if (n <= 2)
            return 0;
        for (int i = 0; i < n; i++)
        {
            int leftMaxHeight = 0;
            for (int j = 0; j <= i - 1; j++)
            {
                leftMaxHeight = max(leftMaxHeight, height[j]);
            }
            int rightMaxHeight = 0;
            for (int j = i + 1; j < n; j++)
            {
                rightMaxHeight = max(rightMaxHeight, height[j]);
            }
            int water = min(leftMaxHeight, rightMaxHeight) - height[i];
            result += (water > 0) ? water : 0;
        }
        return result;
    }
};

class DynamicSolution
{
public:
    int trap(vector<int> &height)
    {
        if (height.empty())
            return 0;
        int ans = 0;
        int size = height.size();
        vector<int> left_max(size), right_max(size);
        left_max[0] = height[0];
        for (int i = 1; i < size; i++)
        {
            left_max[i] = max(height[i], left_max[i - 1]);
        }
        // right_max[size - 1] = height[size - 1];
        // for (int i = size - 2; i >= 0; i--)
        for (int i = size - 1; i >= 0; i--)
        {
            right_max[i] = max(height[i], right_max[i + 1]);
        }
        for (int i = 1; i < size - 1; i++)
        {
            ans += min(left_max[i], right_max[i]) - height[i];
        }
        return ans;
    }
};

class PreCompute
{
public:
    /**
     * time complexity O(n)
     * space complexity O(n)
     */
    int trap(vector<int> &height)
    {
        int result = 0;
        int n = height.size();

        if (n <= 2)
            return 0;

        vector<int> leftMaxHeight(n);
        vector<int> rightMaxHeight(n);

        leftMaxHeight[0] = height[0];
        rightMaxHeight[n - 1] = height[n - 1];

        for (int i = 1; i < n - 1; i++)
        {
            int j = n - i - 1;
            leftMaxHeight[i] = max(leftMaxHeight[i - 1], height[i]);
            rightMaxHeight[j] = max(rightMaxHeight[j + 1], height[j]);
        }

        for (int i = 1; i < n - 1; i++)
        {
            int water = min(leftMaxHeight[i - 1], rightMaxHeight[i + 1]) - height[i];
            result += (water > 0) ? water : 0;
            // result += min(leftMaxHeight[i - 1], rightMaxHeight[i + 1]) - height[i];
        }
        return result;
    }
};

class UsingStacks
{
public:
    int trap(vector<int> &height)
    {
        if (height.empty())
            return 0;
        int result = 0;
        stack<int> barIndexStack;
        int n = height.size();
        for (int i = 0; i < n; i++)
        {
            while (!barIndexStack.empty() && (height[i] > height[barIndexStack.top()]))
            {
                int top = barIndexStack.top();
                barIndexStack.pop();

                if (barIndexStack.empty())
                {
                    break;
                }
                int distance = i - barIndexStack.top() - 1;
                int boundedHeight = min(height[i], height[barIndexStack.top()]) - height[top];
                result += distance * boundedHeight;
            }
            barIndexStack.push(i);
        }
        return result;
    }
};

class RunnerTechnique
{
public:
    int trap(vector<int> &height)
    {
        int left = 0, right = height.size() - 1;
        int ans = 0;
        int left_max = 0, right_max = 0;
        while (left < right)
        {
            if (height[left] < height[right])
            {
                height[left] >= left_max ? (left_max = height[left]) : ans += (left_max - height[left]);
                ++left;
            }
            else
            {
                height[right] >= right_max ? (right_max = height[right]) : ans += (right_max - height[right]);
                --right;
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> sample1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int sample1Result = 6;
    BruteForceSolution bfs;
    PreCompute pc;
    UsingStacks us;
    DynamicSolution ds;
    RunnerTechnique rt;

    cout << "Sample 1 "
         << "Bruteforce: " << bfs.trap(sample1) << endl;
    cout << "Sample 1 "
         << "Precompute: " << pc.trap(sample1) << endl;
    cout << "Sample 1 "
         << "UsingStacks: " << us.trap(sample1) << endl;
    cout << "Sample 1 "
         << "DynamicSolution: " << ds.trap(sample1) << endl;
    cout << "Sample 1 "
         << "RunnerTechnique: " << rt.trap(sample1) << endl;

    vector<int> sample2 = {4, 2, 0, 3, 2, 5};
    int sample2Result = 9;
    cout << "Sample 2 "
         << "Bruteforce: " << bfs.trap(sample2) << endl;
    cout << "Sample 2 "
         << "Precompute: " << pc.trap(sample2) << endl;
    cout << "Sample 2 "
         << "UsingStacks: " << us.trap(sample2) << endl;
}
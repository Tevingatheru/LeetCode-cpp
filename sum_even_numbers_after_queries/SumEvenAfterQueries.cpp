#include <iostream>
#include <vector>

using namespace std;

class BruteForceSolution
{
public:
    /**
     * time complexity O(n*m)
     * space complexity O(n)
     */
    vector<int> sumEvenAfterQueries(vector<int> &nums, vector<vector<int>> &queries)
    {
        vector<int> result;
        int n = queries.size();
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            vector<int> query = queries[i];
            int value = query[0];
            int index = query[1];

            nums[index] += value;
            for (int number : nums)
            {
                if (number % 2 == 0)
                {
                    sum += number;
                }
            }
            result.push_back(sum);
        }
        return result;
    }
};

class MaintainArraySumSolution
{
public:
    /**
     * time complexity O(n+m)
     * space complexity O(n)
     */
    vector<int> sumEvenAfterQueries(vector<int> &nums, vector<vector<int>> &queries)
    {
        int sum = 0;
        for (int number : nums)
        {
            if (number % 2 == 0)
            {
                sum += number;
            }
        }
        vector<int> result;
        int n = queries.size();
        for (int i = 0; i < n; i++)
        {
            vector<int> query = queries[i];
            int value = query[0];
            int index = query[1];
            int temp = nums[index];
            if (nums[index] % 2 == 0)
            {
                sum -= temp;
            }
            nums[index] += value;
            if (nums[index] % 2 == 0)
            {
                sum += nums[index];
            }
            result.push_back(sum);
        }
        return result;
    }
};

void printOutput(vector<int> result)
{
    cout << "[";
    int n = result.size();
    for (int i = 0; i < n; i++)
    {
        cout << result[i];
        if (i != n - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int main()
{
    BruteForceSolution bfs;
    vector<int> nums1{1, 2, 3, 4};
    vector<vector<int>> queries1{{1, 0}, {-3, 1}, {-4, 0}, {2, 3}};
    vector<int> results1 = bfs.sumEvenAfterQueries(nums1, queries1);

    printOutput(results1);

    vector<int> numsMass{1, 2, 3, 4};
    MaintainArraySumSolution mass;
    vector<int> resultsMass = mass.sumEvenAfterQueries(numsMass, queries1);

    printOutput(resultsMass);
}
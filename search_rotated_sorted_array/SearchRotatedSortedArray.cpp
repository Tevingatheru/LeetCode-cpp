#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int rightIndex = nums.size() - 1;
        int leftIndex = 0;

        while (leftIndex < rightIndex)
        {
            int midIndex = (leftIndex + rightIndex) / 2;
            bool rotated = nums[leftIndex] > nums[rightIndex] ? true : false;

            // move right if target >= nums[midIndex] && rotate =  midIndex + 1 or  target < nums[midIndex] && !rotate
            if (target >= nums[midIndex])
            {
                if (rotated)
                {
                    rightIndex = midIndex + 1;
                }
                else
                {
                    leftIndex = midIndex;
                }
            }
            else
            {
                if (rotated)
                {
                    leftIndex = midIndex + 1;
                }
                else
                {
                    rightIndex = midIndex - 1;
                }
            }
        }
        return nums[leftIndex] == target ? leftIndex: -1;
    }
};

int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    Solution s;
    int response = s.search(nums, target);
    cout << response << endl;
}
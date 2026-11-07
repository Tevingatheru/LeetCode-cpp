#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int maxCount = 0;
        for (int i = 0; i < n; i++) {
            if(nums[i] == 1) {
                count++;
            } else if(nums[i] == 0) {
                count = 0;
            }
            if (count > maxCount) {
                maxCount = count;
            }
        }
        return maxCount;
    }
};

int main() {
    Solution sol;
    vector<int> nums= {1,0,1,1,0,1};
    int ans = sol.findMaxConsecutiveOnes(nums);
    cout<<"Answer is "<< ans << endl;   
}
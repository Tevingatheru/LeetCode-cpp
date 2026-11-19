#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();     
        vector<int> miss;

        for (int num: nums) {
            if (nums[abs(num) - 1] > 0) {
                nums[abs(num) - 1] = -nums[abs(num) - 1];
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                miss.push_back(i + 1) ;                
            }
        }
        return miss;
    }
};

int main() {
    Solution sol;
    vector<int> nums= {4,3,2,7,8,2,3,1};
    vector<int> ans = sol.findDisappearedNumbers(nums);
    cout<<"Answer"<< endl;
    for(int val: ans) {
        cout<<val<< endl;
    }
}
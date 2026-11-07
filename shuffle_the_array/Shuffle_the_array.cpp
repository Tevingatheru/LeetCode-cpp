#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(n*2);
        for(int x = 0; x < n; ++x) {
            int startIndex = x * 2;
            int y = x + n;
            ans[startIndex] = nums[x];
            ans[startIndex + 1] = nums[y];
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums= {2,5,1,3,4,7};
    vector<int> ans = sol.shuffle(nums,3);
    cout<<"Answer"<< endl;
    for(int val: ans) {
        cout<<val<< endl;
    }
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans(2);
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++) {
            int position = i + 1;
            
            if(nums[abs(nums[i]) - 1] < 0) {
                ans[0] = abs(nums[i]);
            }

            cout<< (abs(nums[i]) != ans[0]);

            if(position != abs(nums[i]) && ans[1] == 0 
             && abs(nums[i]) != ans[0]
            ) {
                cout<< "set p "<< position<< endl;
                ans[1] = position;
            }
            

            nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
            for(int num: nums) {
                cout<<num;
            }
            cout<<endl;
        }
        
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums= {1,2,2,4};
    vector<int> ans = sol.findErrorNums(nums);
    cout<<"Answer"<< endl;
    for(int val: ans) {
        cout<<val<< endl;
    }
}
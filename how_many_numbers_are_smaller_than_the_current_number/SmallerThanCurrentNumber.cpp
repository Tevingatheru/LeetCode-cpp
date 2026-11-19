#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        unordered_map<int, int> hashMap;
        int size = nums.size();
        vector<int> result(size);

        for (int i = 0; i < size; i++) {
            int smallerNumsCount = 0;
            int currentNum = nums[i];
            
            for (int num : nums) {
                if (num < currentNum) {
                    smallerNumsCount++;
                }
            }
            result[i] = smallerNumsCount;
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums= {7,7,7,7};
    vector<int> ans = sol.smallerNumbersThanCurrent(nums);
    cout<<"Answer"<< endl;
    for(int val: ans) {
        cout<<val<< endl;
    }
}
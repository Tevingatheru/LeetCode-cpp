#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int targetSize = target[target.size() - 1];

        for (int i = 1; i <= n; i++) {
            auto it = find(target.begin(), target.end(), i);

            if (it != target.end()) {                
                res.push_back("Push");
            } else if (i > targetSize) {                
            } else {                
                res.push_back("Push");
                res.push_back("Pop");
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums= {3,4,5,6,8,9};
    vector<string> ans = sol.buildArray(nums, 9);
    cout<<"Answer"<< endl;
    for(string val: ans) {
        cout<<val<< endl;
    }
}
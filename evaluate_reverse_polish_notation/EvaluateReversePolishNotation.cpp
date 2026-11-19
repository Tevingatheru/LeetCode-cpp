#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> res;
        int n = tokens.size();

        for (int i = 0; i < n; i++) {
            string val = tokens[i];
            if ("+" != val && "-" != val && "*" != val && "/" != val) {
                res.push(stoi(val));
            } else {
                int sum = 0;
                int a = res.top();
                res.pop();
                int b = res.top();
                res.pop();

                if ("+" == val) {
                    sum = b + a;
                } else if ("-" == val) {
                    sum = b - a;
                } else if ("*" == val) {
                    sum = b * a;
                } else if ("/" == val) {
                    sum = round(b / a);
                }
                res.push(sum);
            }
        }

        int result;

        result = res.top();
        res.pop();

        return result;
    }
};

int main() {
    Solution sol;
    vector<string> nums= {"4","13","5","/","+"};
    int ans = sol.evalRPN(nums);
    cout<< "Answer = " << ans;
}

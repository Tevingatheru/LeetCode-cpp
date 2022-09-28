#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
return n % 4 == 0 && n > 0 ? true: n == 1? true: false;    }
};

int main() {
    Solution s;
    bool result = s.isPowerOfFour(8);
    cout << boolalpha << result << endl;
    return 0;
}
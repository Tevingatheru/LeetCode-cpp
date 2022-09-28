#include <vector>

using namespace std;
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int richest = 0;
        for(vector<int> account: accounts) {
            int sum = 0;
            for (int amount : account) {
                sum += amount;
            }
            
            if(sum > richest) {
                richest = sum;
            }
        }
        return richest;
    }
};

int main() {
    
}
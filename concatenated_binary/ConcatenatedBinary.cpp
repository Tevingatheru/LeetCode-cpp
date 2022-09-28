#include <string>
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int concatenatedBinary(int n) {
        string concatBinary;
        int bin = 0;
        int tenth = 1;
        // for (int i = 1; i <= n; i++) {
        //     bin += toBinary(i) * i;
        //     tenth *= 10;
        // }
        bin = toBinary(n);
        return toInteger(bin);
    }
    private:
    int toBinary(unsigned number){
        int result = 0;
        int i =1;
        while(number > 0) {
            result += (number % 2) * i;
            i *=10;
            number /=2;
        }
      
        return result;
    }
    
    int toInteger(unsigned n) {
        int dec = 0, i = 0, rem;

        while (n != 0)
        {
            rem = n % 10;
            n /= 10;
            dec += rem * pow(2, i);
            ++i;
        }
        return dec;
    }
};

int main () {
    Solution s;
    int result = s.concatenatedBinary(3);
    cout << result << endl;
}
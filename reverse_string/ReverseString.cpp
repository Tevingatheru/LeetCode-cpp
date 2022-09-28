
class Solution {
public:
    string reverseWords(string s) {
        string temp;
        vector<string> result;
        
        reverse(s.begin(), s.end());
        for (auto letter: s) {
            if (letter == ' ') {
                result.push_back(temp + " ");
            } else {
                temp += letter ;
            }
        }
        string stringResult;
        int n = result.size();
        for (int i = n-1; i >= 0; i--) {
            stringResult += result[i] ;
        }
        return stringResult;
    }
    
 
};
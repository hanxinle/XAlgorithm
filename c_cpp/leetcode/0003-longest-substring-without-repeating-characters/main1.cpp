class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 0)
            return 0;
         // hash
        int freq[256] = { 0 }; 
        int l = 0,r = -1;
        int res = 0;
        
        while (r+1<s.size()) {
            if (freq[s[r + 1]] == 0)
                freq[s[++r]]++;
            else 
                freq[s[l++]]--;
            
            res = max (res, r - l + 1);
        }
        
        return res;   
    }
};
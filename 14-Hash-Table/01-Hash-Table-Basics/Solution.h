class Solution {
public:
    int firstUniqChar(string s) {
        int *freq = new int[26];
        for (int i = 0; i < 26; i++) {
            freq[i] = 0;
        }
        for (int i = 0; i < s.size(); i++) {
            freq[s.at(i) - 'a'] ++;
        }

        for (int i = 0; i < s.size(); ++i) {
            if (freq[s.at(i) - 'a'] == 1) {
                return i;
            }
        }
        return -1;        
    }
};

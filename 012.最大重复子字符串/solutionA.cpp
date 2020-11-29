
class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int n = sequence.size(), m = word.length();
        int ans = 0,cur = 0;

        
        
        for(int i = 0; i < n; i++){
            cur = -1;
            for(int k = 0; i+k < n; k++ ){
                if(word[k % m] != sequence[i + k]) break;
                cur = k;
            }

            cur = (cur + 1) / m;
            ans = max(ans, cur);

        }
        return ans;

    }
};




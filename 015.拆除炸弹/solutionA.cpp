class Solution {
public:
    int sgn(int k) {return k > 0 ? 1: -1;}
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size(); 
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(k == 0) ans.push_back(0);
            else{
                int sum = 0, step = sgn(k), cur = i;
                for(int j = 0; j < k * step; j++){
                    cur = (cur + step +n) % n;  // 取余数操作记得+n， 防止负数的情况出现
                    sum+=code[cur];

                }
                ans.push_back(sum);
            }
        }
        return ans;
    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       int len=nums.size();

       reverse(nums.begin(), nums.end() - k%len); //reverse翻转的是[begin,end)区间
       reverse(nums.end()- k%len,nums.end());
       reverse(nums.begin(),nums.end());
    }
};

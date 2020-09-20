![在这里插入图片描述](https://github.com/fang0jun/myLeetCode/blob/master/images/20200121233800289.png)


@[toc]

-----------
# 法一：经典双指针
```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        int i = 0, j = len - 1;
        while(i <= j){
            if(nums[i] == val){
                swap(nums[i], nums[j]);
                len--;
                j--;
            }
            else{
                i++;
            }
            
        }
        return len;
    }
};
```

---------------------
# 总结：
无
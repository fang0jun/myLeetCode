![](https://github.com/fang0jun/myLeetCode/blob/master/images/2020080809203585.png)

<br/><br/><br/>


# 三次旋转
> 三次旋转
> 观察可得：数组的翻转中，有（k % Size）个尾部元素将会移动到数组头部，其余的头部元素会后移成为尾部元素
> 因此：**我们首先将整个数组翻转，然后将头部(k % l)个头部元素翻转，最后再将其余尾部元素翻转** （3次旋转）

c
```c
void reverse(int *a, int l, int h)
{
    for(int i = 0; i < (h - l + 1) / 2; i++){
        int t = a[l + i];
        a[l + i] = a[h - i];
        a[h - i] = t;
    }
}
void rotate(int* nums, int numsSize, int k){
    if(!nums || numsSize == 0)
        return;
    k = k % numsSize;
    reverse(nums, 0, numsSize - 1 - k);
    reverse(nums, numsSize - k, numsSize - 1);
    reverse(nums, 0, numsSize - 1);
}
```
执行结果：

![](https://github.com/fang0jun/myLeetCode/blob/master/images/20200121234906454.png)

c++

```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       int len=nums.size();

       reverse(nums.begin(), nums.end() - k%len); //reverse翻转的是[begin,end)区间
       reverse(nums.end()- k%len,nums.end());
       reverse(nums.begin(),nums.end());
    }
};

```
执行结果：

![](https://github.com/fang0jun/myLeetCode/blob/master/images/20200121233800289.png)

----------

--------------------------------
# 总结：
1. 若要在函数中创建一个数组，不能直接使用（int arr[N]）创建，这样创建出来的数组只是一个局部变量，无法传出来，而应该使((int*) malloc（sizeof())）动态创建。

2. 原地翻转一个数组的方法 ： 三次旋转法 环形旋转

3. vector的翻转函数 `resever(vec.begin(), vec.end() )`
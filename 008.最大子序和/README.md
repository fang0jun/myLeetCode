
![在这里插入图片描述](httpsimg-blog.csdnimg.cn20200819081554709.pngx-oss-process=imagewatermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2ExMzM1MjkxMjYzMg==,size_16,color_FFFFFF,t_70#pic_center)
- [法一：DP标准解法：](#法一dp标准解法)
- [法二：再次优化：以int dp 代替 数组dp](#法二再次优化以int-dp-代替-数组dp)
- [总结：](#总结)

----------
# 法一：DP标准解法：

 1，定关系：自变量为x，f（x）是以x为结尾的数组中的最大子序和；f(x) = max(f(x - 1)+nums[x], nums[x])
 2，表格优化代码：结果即为数组f中的最大值
    ---》再优化，其实我们只需要f中的前一个元素，来做比较就好

```cpp
class Solution
{
public
    int maxSubArray(vectorint &nums)
    {
        类似寻找最大最小值的题目，初始值一定要定义成理论上的最小最大值
        int result = INT_MIN;
        int numsSize = int(nums.size());
        dp[i]表示nums中以nums[i]结尾的最大子序和
        vectorint dp(numsSize);
        dp[0] = nums[0];
        result = dp[0];
        for (int i = 1; i  numsSize; i++)
        {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            result = max(result, dp[i]);
        }

        return result;
    }
};
```
# 法二：再次优化：以int dp 代替 数组dp
```cpp
class Solution
{
public
    int maxSubArray(vectorint &nums)
    {
        类似寻找最大最小值的题目，初始值一定要定义成理论上的最小最大值
        int result = INT_MIN;
        int numsSize = int(nums.size());
        因为只需要知道dp的前一项，我们用int代替一维数组
        int dp(nums[0]);
        result = dp;
        for (int i = 1; i  numsSize; i++)
        {
            dp = max(dp + nums[i], nums[i]);
            result = max(result, dp);
        }

        return result;
    }
};
```

# 总结：
1. c++中的理论最小大值：INT_MIN   INT_MAX
2. 关于数组声明大小的问题！！！
	一：如果想要像使用数组一样的赋值方式，如indexForNearest[0]=5。vector申明时必须指定大小如vector indexForNearest(3)。
	二：int len = 1；--》 vectorint f(len);  int f[len];  数组的初始化vector声明可以接收变量，但是传统数组声明不可以接受变量
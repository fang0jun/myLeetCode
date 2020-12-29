![image-20201229233143375](C:\Users\fang0jun\AppData\Roaming\Typora\typora-user-images\image-20201229233143375.png)

![image-20201229233023491](C:\Users\fang0jun\AppData\Roaming\Typora\typora-user-images\image-20201229233023491.png)







**贪心**

```cpp
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int patches = 0;
        long long x = 1;
        int length = nums.size(), index = 0;
        while (x <= n) {
            if (index < length && nums[index] <= x) {
                x += nums[index];
                index++;
            } else {
                x <<= 1;
                patches++;
            }
        }
        return patches;
    }
};

```





贪心
对于正整数 xx，如果区间 [1,x-1][1,x−1] 内的所有数字都已经被覆盖，且 xx 在数组中，则区间 [1,2x-1][1,2x−1] 内的所有数字也都被覆盖。证明如下。

对于任意 1 \le y<x1≤y<x，yy 已经被覆盖，xx 在数组中，因此 y+xy+x 也被覆盖，区间 [x+1,2x-1][x+1,2x−1]（即区间 [1,x-1][1,x−1] 内的每个数字加上 xx 之后得到的区间）内的所有数字也被覆盖，由此可得区间 [1,2x-1][1,2x−1] 内的所有数字都被覆盖。

假设数字 xx 缺失，则至少需要在数组中补充一个小于或等于 xx 的数，才能覆盖到 xx，否则无法覆盖到 xx。

如果区间 [1,x-1][1,x−1] 内的所有数字都已经被覆盖，则从贪心的角度考虑，补充 xx 之后即可覆盖到 xx，且满足补充的数字个数最少。在补充 xx 之后，区间 [1,2x-1][1,2x−1] 内的所有数字都被覆盖，下一个缺失的数字一定不会小于 2x2x。

由此可以提出一个贪心的方案。每次找到未被数组 \textit{nums}nums 覆盖的最小的整数 xx，在数组中补充 xx，然后寻找下一个未被覆盖的最小的整数，重复上述步骤直到区间 [1,n][1,n] 中的所有数字都被覆盖。

具体实现方面，任何时候都应满足区间 [1,x-1][1,x−1] 内的所有数字都被覆盖。令 xx 的初始值为 11，数组下标 \textit{index}index 的初始值为 00，则初始状态下区间 [1,x-1][1,x−1] 为空区间，满足区间内的所有数字都被覆盖。进行如下操作。

如果 \textit{index}index 在数组 \textit{nums}nums 的下标范围内且 \textit{nums}[\textit{index}] \le xnums[index]≤x，则将 \textit{nums}[\textit{index}]nums[index] 的值加给 xx，并将 \textit{index}index 的值加 11。

被覆盖的区间从 [1,x-1][1,x−1] 扩展到 [1,x+\textit{nums}[\textit{index}]-1][1,x+nums[index]−1]，对 xx 的值更新以后，被覆盖的区间为 [1,x-1][1,x−1]。
否则，xx 没有被覆盖，因此需要在数组中补充 xx，然后将 xx 的值乘以 22。

在数组中补充 xx 之后，被覆盖的区间从 [1,x-1][1,x−1] 扩展到 [1,2x-1][1,2x−1]，对 xx 的值更新以后，被覆盖的区间为 [1,x-1][1,x−1]。
重复上述操作，直到 xx 的值大于 nn。

由于任何时候都满足区间 [1,x-1][1,x−1] 内的所有数字都被覆盖，因此上述操作可以保证区间 [1,n][1,n] 内的所有数字都被覆盖。

又由于上述操作只在 xx 不被覆盖时才在数组中补充 xx，如果不补充 xx 则 xx 无法被覆盖，因此可以保证补充的数字个数最少。如果减少补充的数字个数，则无法覆盖区间 [1,n][1,n] 内的所有数字。

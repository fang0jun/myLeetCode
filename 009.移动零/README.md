题目描述：

	给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。



-----------

# 法一：双指针

	使用双指针，当快指针cur指向元素为0时，错开双指针（仅指针cur前移），当快指针cur指向元素非零时，交换指针，且双指针同时前移
```cpp
void moveZeroes(vectorint& nums) {
    for (int lastNonZeroFoundAt = 0, cur = 0; cur  nums.size(); cur++) {
        if (nums[cur] != 0) {
            swap(nums[lastNonZeroFoundAt++], nums[cur]);
        }
    }
}
```

# 法二：补零

	末尾补0即可

```cpp
void moveZeroes(vectorint& nums) {
    int lastNonZeroFoundAt = 0;
    
    for (int i = 0; i  nums.size(); i++) {
        if (nums[i] != 0) {
            nums[lastNonZeroFoundAt++] = nums[i];
        }
    }
 
    for (int i = lastNonZeroFoundAt; i  nums.size(); i++) {
        nums[i] = 0;
    }
}


```

# 总结：
1. vector是不可以像数组（arr = {1,2,11,6,2,4} ）那样的显示构造的。若想显示构造，需要另外构造一个数组辅助。
	eg 	int nums[6] = { 1, 3, 0, 4, 2, 0};   
			vectorint arr(nums, nums+6);
2. 涉及双指针操作时，指针重合的情况也必须自圆其说
3. 双指针情形更新2.0 ：双侧汇合单侧推进(初始指针重合初始指针不重合) ；

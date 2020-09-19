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

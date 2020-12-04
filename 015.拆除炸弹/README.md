![在这里插入图片描述](https://img-blog.csdnimg.cn/20201204103151896.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2ExMzM1MjkxMjYzMg==,size_16,color_FFFFFF,t_70)


```cpp
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
```

总结：
取余数操作记得 + 除数， 防止负数的情况出现 eg:  cur += (step +n) % n;
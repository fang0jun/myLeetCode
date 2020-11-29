![在这里插入图片描述](https://img-blog.csdnimg.cn/20201129193530996.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2ExMzM1MjkxMjYzMg==,size_16,color_FFFFFF,t_70)

暴力匹配, 单指针操作
```cpp
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
```
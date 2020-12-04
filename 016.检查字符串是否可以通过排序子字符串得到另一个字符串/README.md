![在这里插入图片描述](https://img-blog.csdnimg.cn/20201204105424472.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2ExMzM1MjkxMjYzMg==,size_16,color_FFFFFF,t_70)

```cpp
class Solution {
public:
    bool isTransformable(string s, string t) {
        int n = s.size();
        vector<queue<int>> pos(10);
        for (int i = 0; i < n; ++i) {
            pos[s[i] - '0'].push(i);
        }
        for (int i = 0; i < n; ++i) {
            int digit = t[i] - '0';
            if (pos[digit].empty()) {
                return false;
            }
            for (int j = 0; j < digit; ++j) {
                if (!pos[j].empty() && pos[j].front() < pos[digit].front()) {
                    return false;
                }
            }
            pos[digit].pop();
        }
        return true;
    }
};

```
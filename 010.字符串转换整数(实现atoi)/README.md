@[toc]

<br/>

|| 相关知识的复习跳转链接 ---> [Engineering a Compiler读书笔记(2)：词法分析器](https://blog.csdn.net/a13352912632/article/details/105567057)

<br/><br/>

# 题目描述
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200912153056180.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2ExMzM1MjkxMjYzMg==,size_16,color_FFFFFF,t_70#pic_center)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200912153120622.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2ExMzM1MjkxMjYzMg==,size_16,color_FFFFFF,t_70#pic_center)

# 法一：确定有限自动状态机（DFA）

```cpp
class Automaton {
    string state = "start";
    unordered_map<string, vector<string>> table = {
        {"start", {"start", "signed", "in_number", "end"}},
        {"signed", {"end", "end", "in_number", "end"}},
        {"in_number", {"end", "end", "in_number", "end"}},
        {"end", {"end", "end", "end", "end"}}
    };

    int get_col(char c) {
        if (isspace(c)) return 0;
        if (c == '+' or c == '-') return 1;
        if (isdigit(c)) return 2;
        return 3;
    }
public:
    int sign = 1;
    long long ans = 0;

    void get(char c) {
        state = table[state][get_col(c)];
        if (state == "in_number") {
            ans = ans * 10 + c - '0';
            ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, -(long long)INT_MIN);
        }
        else if (state == "signed")
            sign = c == '+' ? 1 : -1;
    }
};



class Solution {
public:
    int myAtoi(string str) {
        Automaton automaton;
        for (char c : str)
            automaton.get(c);
        return automaton.sign * automaton.ans;
    }
};
```

# 总结：
为了有条理地分析每个输入字符的处理方法，我们可以使用自动机这个概念。

复习跳转链接 ---> [Engineering a Compiler读书笔记(2)：词法分析器](https://blog.csdn.net/a13352912632/article/details/105567057)
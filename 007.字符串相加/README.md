- [法一：短的补零，壹壹对应相加](#法一短的补零壹壹对应相加)
- [法二：短的跳过，直接相加](#法二短的跳过直接相加)
- [总结：](#总结)

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200908171216726.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2ExMzM1MjkxMjYzMg==,size_16,color_FFFFFF,t_70#pic_center)
# 法一：短的补零，壹壹对应相加
```cpp
class Solution {
public:
    string addStrings(string num1, string num2) {
        //if(num1 == "0" || nums == "0") return (num1 == "0") ? num2 : num1;
        int size1 = num1.size();
        int size2 = num2.size();

        string res;
        int carry = 0;
        int sum = 0;
        // 1补0法，2直加法
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        string longer = (size1 >= size2) ? num1 : num2;
        string shorter = (size1 >= size2) ? num2 : num1;
        
        for(int i = 0; i < abs(size1 - size2); i++){
            shorter.push_back('0');
        }

        for(int i = 0; i < longer.size(); i++){
            sum = (longer[i] - '0') + (shorter[i] - '0') + carry;
            carry = (sum >= 10) ?  1: 0;
            res.push_back(sum % 10 + '0');
            if(i == longer.size() - 1 && carry == 1) res.push_back('1');
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
```

# 法二：短的跳过，直接相加
```cpp
class Solution {
public:
    string addStrings(string num1, string num2) {
        //if(num1 == "0" || nums == "0") return (num1 == "0") ? num2 : num1;
        int size1 = num1.size();
        int size2 = num2.size();

        string res;
        int carry = 0;
        int sum = 0;
        // 1补0法，2直加法
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        string longer( (size1 >= size2) ? num1 : num2 );
        string shorter((size1 >= size2) ? num2 : num1);
        for(int i = 0; i < longer.size(); i++){
            if(i > shorter.size() - 1) sum = (longer[i]-'0') + carry; 
            else sum = (longer[i] - '0')+ (shorter[i] - '0') + carry;
            carry = (sum >= 10) ?  1: 0;
            res.push_back(sum % 10 + '0');
            if(i == longer.size() - 1 && carry == 1) res.push_back('1');
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
```


# 总结：
- 字符串的reverse翻转： `reverse(arr.begin(), arr.end() )`
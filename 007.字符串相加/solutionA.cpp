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
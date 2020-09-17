# 法一：补0使之同位数

	将两个数转换成同位数（即位数少的数补零填充位数），之后按同位数相加操作

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* p, ListNode* q) {
       bool more = false;
       int len1 =1,len2=1;
       ListNode* l1=p;
        ListNode* l2=q;
       while(l1->next != NULL){l1 = l1->next; len1++;}
       while(l2->next != NULL){l2 = l2->next; len2++;}
       if(len1 > len2)
           for(int i = 0; i < len1 - len2; i++){
                l2->next = new ListNode(0);
                l2 = l2->next;
           }
       else if(len1 < len2)
           for(int i = 0; i < len2 - len1; i++){
                l1->next = new ListNode(0);
                l1 = l1->next;
           }
       
        l1=p;
        l2=q;
        ListNode * l = new ListNode(0);
        ListNode * l3 = l;
        int add;
        while(l1 != NULL && l2 != NULL){
            add = l3->val + (l1->val + l2->val) ;
            l3->val += (l1->val + l2->val) % 10;
           
            more = (add >= 10) ? true:false;
            if(more){
                if(l3->val>=10) l3->val = l3->val%10;
                l3 = l3->next = new ListNode(1);
                
            }
            else if(more == false && l1->next != NULL && l2->next != NULL)
                l3 = l3->next = new ListNode(0);

                

            l1 = l1->next;
            l2 = l2 ->next;
        }
       
        return l;
    }
};
```
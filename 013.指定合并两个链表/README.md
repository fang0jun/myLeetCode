![在这里插入图片描述](https://img-blog.csdnimg.cn/20201129204444448.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2ExMzM1MjkxMjYzMg==,size_16,color_FFFFFF,t_70)


设置两个指针分别移动到指定结点，再进行操作
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* A = list1;
        for(int i = 0; i < a - 1; i++) A = A->next;
        ListNode* B = list1;
        for(int i = 0; i < b + 1; i++) B = B->next;
        ListNode* C = list2;
        while(C ->next != nullptr) C = C->next;

        A->next = list2;
        C->next = B;

        return list1;


    }
};
```
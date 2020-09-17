![在这里插入图片描述](https://github.com/fang0jun/myLeetCode/blob/master/images/20200818125209700.png)

-----

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


------------
# 法二：优化法一

	优化上面的代码，既然位数少的数字位数不足，那干脆连0都不补上去了，直接不加它不就好
```python
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head=new ListNode(-1);//存放结果的链表
        ListNode* h=head;//移动指针
        int sum=0;//每个位的加和结果
        bool carry=false;//进位标志
        while(l1!=NULL||l2!=NULL)
        {
            sum=0;
            if(l1!=NULL)
            {
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL)
            {
                sum+=l2->val;
                l2=l2->next;
            }
            if(carry)
                sum++;
            h->next=new ListNode(sum%10);
            h=h->next;
            carry=sum>=10?true:false;
        }
        if(carry)
        {
            h->next=new ListNode(1);
        }
        return head->next;
    }
};

```



# 总结：
	
1. 操作一个目标链表的时候一定一定记得用一个指针副本来代替原本的参数指针！！！最好不要直接操作参数指针
2. 多使用三目判断符可以很好的简化代码 carry=（sum>=10）?true:false;
3. 链表构建中可以使用c++特有语法：构造函数 来构建（使用初始化列表的话会更方便）
以下是c++链表模板
	

```cpp
		// c++链表模板
 		struct ListNode {
 			 int val;
			 ListNode *next;
			 ListNode(int x) : val(x), next(NULL) {}
		};
 
```

4. 重复使用某一指针时记得重置指针（复位指针），这个时候就要用到参数指针了（所以第一点没做到的话就没参数咯）
![](https://github.com/fang0jun/myLeetCode/blob/master/images/20200818124109167.png)
5. 注意！以下两行代码中要注意的事项：
 ![](https://github.com/fang0jun/myLeetCode/blob/master/images/20200818124337528.png)
<font color = bule size = 2>节点全部扔进循环后，最终的节点停在了链表尾节点的下一位！
![](https://github.com/fang0jun/myLeetCode/blob/master/images/20200818124859753.png)
节点全部扔进循环后，最终的节点停在了链表尾节点上！

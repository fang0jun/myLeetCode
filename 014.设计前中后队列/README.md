![在这里插入图片描述](https://img-blog.csdnimg.cn/20201201233516514.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2ExMzM1MjkxMjYzMg==,size_16,color_FFFFFF,t_70)


```cpp
class FrontMiddleBackQueue {
public:
    int arr[1050];
    int len = 0;
    FrontMiddleBackQueue() {
        len = 0;
    }
    
    // 添加两个移动功能，方便调用
    // 后移需要从后往前操作数组，前移需要从前往后操作数组
    void moveBack(int x){if(len < x) return ; for(int i = len; i>=x; i--) arr[i+1] = arr[i];}
    void moveFront(int x) { if(len < x) return ; for(int i = x; i < len; i++) arr[i] = arr[i+1]; }


    void pushFront(int val) {
        moveBack(1); len++;
        arr[1] = val; 
    }
    
    void pushMiddle(int val) {
        int p = (len + 2) / 2; len++;
        moveBack(p); 
        arr[p] = val;
    }
    
    void pushBack(int val) {
        len++; arr[len] = val;
    }
    
    int popFront() {
        if (len == 0) return -1;
        int ret = arr[1]; 
        moveFront(1);len--;
        return ret;

    }
    
    int popMiddle() {
        if(len == 0) return -1;
        int p = (len + 1) / 2;
        int ret = arr[p];
        moveFront(p); len--;
        return ret;
    }
    
    int popBack() {
        if(len == 0) return -1;
        int ret = arr[len];
        len--;
        return ret;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
```
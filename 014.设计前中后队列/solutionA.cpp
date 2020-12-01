
class FrontMiddleBackQueue {
public:
    int arr[1050];
    int len = 0;
    FrontMiddleBackQueue() {
        len = 0;
    }
    
    // ��������ƶ����ܣ��������
    // ������Ҫ�Ӻ���ǰ�������飬ǰ����Ҫ��ǰ�����������
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



题目描述：
![在这里插入图片描述](https://img-blog.csdnimg.cn/20201125203906268.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2ExMzM1MjkxMjYzMg==,size_16,color_FFFFFF,t_70#pic_center)

```cpp
class SubrectangleQueries {


private:
    vector<vector<int>> rectangle;
    vector<vector<int>> history;

public:
    SubrectangleQueries(vector<vector<int>>& rectangle) : rectangle(rectangle) {}

    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        history.push_back({row1, col1, row2, col2, newValue});
    }

    int getValue(int row, int col) {

        for(int i = history.size() - 1; i >= 0; i --)
            if(history[i][0] <= row && row <= history[i][2] &&
               history[i][1] <= col && col <= history[i][3])
                return history[i][4];
        return rectangle[row][col];
    }
};



/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */
```

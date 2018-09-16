# 171. Excel表列序号

给定一个Excel表格中的列名称，返回其相应的列序号。

例如，

```
    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...

```

**示例 1:**

```
输入: "A"
输出: 1

```

**示例 2:**

```
输入: "AB"
输出: 28

```

**示例 3:**

```
输入: "ZY"
输出: 701
```

## 解决方案

26进制，[168-Excel表列名称](./168-Excel表列名称.md)的逆运算。

```c++
class Solution {
public:
    int titleToNumber(string s) {
        int ret = 0, carry = 1;
        
        for (int i = s.size()-1; i>=0; --i){
            ret += carry * (s[i] - 'A' + 1);
            carry *= 26;
        }
        return ret;
    }
};
```


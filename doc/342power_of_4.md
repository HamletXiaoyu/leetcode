# 342. power of 4

给定一个整数 (32 位有符号整数)，请编写一个函数来判断它是否是 4 的幂次方。

**示例 1:**

```
输入: 16
输出: true

```

**示例 2:**

```
输入: 5
输出: false
```

**进阶：**
你能不使用循环或者递归来完成本题吗？

## 解决方案

方案1:换底公式

```c++
class Solution {
public:
    bool isPowerOfFour(int num) {
        return num > 0 && int(log10(num) / log10(4)) - log10(num) / log10(4) == 0;
    }
};
```

方案2:

首先根据[Power of Two](./231-2的幂.md)中的解法，我们知道num & (num - 1)可以用来判断一个数是否为2的次方数，更进一步说，就是二进制表示下，只有最高位是1，那么由于是2的次方数，不一定是4的次方数，比如8，所以我们还要其他的限定条件，我们仔细观察可以发现，4的次方数的最高位的1都是计数位，那么我们只需与上一个数(0x55555555) <==> 1010101010101010101010101010101，如果得到的数还是其本身，则可以肯定其为4的次方数：

```c++
class Solution {
public:
    bool isPowerOfFour(int num) {
        return num > 0 && !(num & (num - 1)) && (num & 0x55555555) == num;
    }
};
```

方案3:

在确定其是2的次方数了之后，发现只要是4的次方数，减1之后可以被3整除。

```c++
class Solution {
public:
    bool isPowerOfFour(int num) {
        return num > 0 && !(num & (num - 1)) && (num - 1) % 3 == 0;
    }
};
```


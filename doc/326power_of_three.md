# 326. power of three

给定一个整数，写一个函数来判断它是否是 3 的幂次方。

**示例 1:**

```
输入: 27
输出: true

```

**示例 2:**

```
输入: 0
输出: false
```

**示例 3:**

```
输入: 9
输出: true
```

**示例 4:**

```
输入: 45
输出: false
```

**进阶：**
你能不使用循环或者递归来完成本题吗？

## 解决方案

由于输入是int，正数范围是0-2的31次方，在此范围中允许的最大的3的次方数为3的19次方=1162261467，那么我们只要看这个数能否被n整除即可。

```c++
class Solution {
public:
    bool isPowerOfThree(int n) {
        return (n > 0 && 1162261467 % n == 0);
    }
};
```

方案2:

利用对数的换底公式来做，高中学过的换底公式为logab = logcb / logca，那么如果n是3的倍数，则log3n一定是整数，我们利用换底公式可以写为log3n = log10n / log103。

现在问题就变成了判断log10n / log103是否为整数，在c++中判断数字a是否为整数，我们可以用 a - int(a) == 0 来判断，参见代码如下：

```c++
class Solution {
public:
    bool isPowerOfThree(int n) {
        return (n > 0 && int(log10(n) / log10(3)) - log10(n) / log10(3) == 0);
    }
};
```


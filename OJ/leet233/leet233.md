# 公式推导
## LeetCode 233 计算 1 的个数

用 `f(x)` 表示 **小于 `x`** 的数字中 1 的个数

$$
\begin{aligned}
    f(x) = f(\overline{a_n \ldots a_0}) &= 
\begin{cases}
    0 * f(10^n) + 0 + f(x \% 10^n) & \text{if\;\;} a_n = 0 \\
    f(10^n) + x - 10^n + f(x \% 10^n) & \text{if\;\;} a_n = 1 \\ 
   a_n f(10^n) +  10^n + f(x \% 10^n) & \text{if\;\;} a_n \ge 2
\end{cases} \\ 
    \\
    &= a_n f(10^n) + f(x  \% 10^n) + \Big[\min(10^n, x - 10^n) \Big ]_+
\end{aligned}
$$

其中 $[ x ]_+ = \max(x, 0)$。 又注意到  

$$
f(10^{n+1}) =  10 f(10^n) + 10^n
$$

因此

$$
\begin{aligned}
    f(x) &= f(\overline{a_n \ldots a_0})
    = a_n f\left( 10^n \right) + f(x  \% 10^n) + \Big[\min(10^n, x - 10^n) \Big ]_+ \\ 
    &= \underbrace{a_n f(10^n) + a_{n-1} f(10^{n-1}) +  \ldots a_0 f(10^0)}_{\text{part I}} \\&\;\;\;\;+ \sum_{i=0}^n \Big[\min(10^i, \overline{a_i \ldots a_0} - 10^i) \Big ]_+ 
\end{aligned}
$$

其中 $\overline{a_i \ldots a_0} = x \% 10^{i+1}$, $f(1) = 0$

注意第一部分等于

$$
\begin{aligned}
&a_n f(10^n) + a_{n-1} f(10^{n-1}) +  \ldots a_0 f(10^0) \\
    &= \overline{a_n a_{n-1}} f(10^{n-1}) + a_n 10^{n-1} + \ldots   a_0 f(10^0) \\
    &= \overline{a_n \ldots a_0} f(10^0) + \sum_{i=1}^n \overline{a_n \ldots a_i} 10 ^ {i-1} \\
    &= \sum_{i=1}^n \overline{a_n \ldots a_i} 10 ^ {i-1} 
\end{aligned}
$$

因此

$$
\begin{aligned}
    f(x) &= \sum_{i=1}^n \overline{a_n \ldots a_i} 10 ^ {i-1}  + \sum_{i=0}^n \Big[ \min(10^i, x \% 10^{i+1}-10^i) \Big]_+  \\
        &= \sum_{i=1}^n x / 10^i * 10 ^ {i-1}  + \sum_{i=0}^n \Big[ \min(10^i, x \% 10^{i+1}-10^i) \Big]_+  \\ 
        &= \sum_{i=0}^n  \Bigg\{ x / 10^{i+1} * 10 ^ i  +  \Big[ \min(10^i, x \% 10^{i+1}-10^i) \Big]_+   \Bigg\} \\
\end{aligned}
$$


由此，写出代码
```cpp
class Solution {
public:

    int countDigitOne(int n) {
        int x = n + 1;
        
        int ans = 0;
        for (auto ten = 1LL; ten <= x; ten *= 10) {
            auto div = ten * 10;
            ans += x / div * ten + max(min(ten, x % div - ten), 0LL);
        }
        
        return ans;
    }
};
```
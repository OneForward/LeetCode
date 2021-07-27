# [Leet168 | B进制内数位取值为 [1, B]](https://leetcode-cn.com/problems/excel-sheet-column-title/solution/leet168-bjin-zhi-nei-shu-wei-qu-zhi-wei-00hb7/)

```
A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...
ZA -> 26 * 26 + 1
```

令



$$
\begin{aligned}
    f(x) &= f(\overline{x_M \ldots x_0}) = \sum_{m=0}^M x_m B^m  \\
    &= x_M B^M + \cdots + x_1 B + x_0, \;\; \text{where }\; x_m \in [1, B]
\end{aligned}
$$





则有

$$
\begin{aligned}
x_0 &\equiv f_0 \coloneqq f(x) \pmod B \\ 
x_1 &\equiv f_1 \coloneqq \frac{f_0 - x_0}{B} \pmod B \\
% \vdots \\ 
% equiv f_M \coloneqq \frac{f_{M-1} - x_{M-1}}{B} \pmod B \\
\end{aligned}
$$



做变换函数 
$$
\begin{aligned}
    \Tau (f) &= \begin{cases}
    x - 1 + \text{'A'} &\text{if } x \in [1, B) \\
    \text{'Z'} &\text{if } x = 0
\end{cases}, \text{where } x = f \% B \\ 
\Harr \Tau (f) &= (f - 1) \% B + \text{'A'} 
\end{aligned}

$$



注意到

$$
\begin{aligned}
    f_1 &= \frac{f_0 - x_0}{B} = \begin{cases}
    \left \lfloor 
    f_0 / B
    \right \rfloor & \text{if } x_0 \in [1, B) \\
    \left \lfloor 
    f_0 / B
    \right \rfloor - 1 & \text{if } x_0 = B
\end{cases} \\

\Harr

f_1 &= \left \lfloor 
    (f_0 - 1) / B
\right \rfloor
\end{aligned}
$$


则有算法

$$
\begin{aligned}
s_0 & \coloneqq (f_0 - 1) \% B + \text{'A'}  \\ 
f_1 & \coloneqq \lfloor (f_0 - 1) / B \rfloor\\
\\
s_1 & \coloneqq (f_1 - 1) \% B + \text{'A'}  \\
\vdots
\end{aligned}
$$

```cpp
string convertToTitle(int f) {
    // 0ms
    string s;
    while (f) {
        s.push_back((f-1) % 26 + 'A'); 
        f = (f-1) / 26;
    };
    return string(s.rbegin(), s.rend());
}
```





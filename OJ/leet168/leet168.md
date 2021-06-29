# Leet168

```
ZA -> 26 * 26 + 1
```

$$
x_m \in [1, B]
$$

$$
\begin{aligned}
    f(x) &= f(\overline{x_M \ldots x_0}) = \sum_{m=1}^M x_m B^m  \\
    &= x_M B^M + \cdots + x_1 B + x_0
\end{aligned}
$$


$$
x_0 = f(x) \;\text{mod}\; B  \\ 
(1 \to A, 26 \to 0 \to Z) \\ 
((f(x) - 1) \;\text{mod} \; B \mapsto 0  \to A, 25 \to 0 \to Z) \\ 
x_1 = \frac{f(x) - x_0}{B}  \;\text{mod} B \\
\ldots
$$


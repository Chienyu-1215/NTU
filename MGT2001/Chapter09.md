###### tags: `MGT2001 Statistics` `Notes`
# Statistics: Chapter 9 Sampling Distribution
## Why Sampling?
Calculating parameters of populations may be **prohibitively expensive** because populations are very **large** or the examining process may damage the selected unit.  

Rather than investigating the whole population, we take a sample, calculate a **statistic** related to the **parameter** of interest, and make an **inference**.


## Sampling Distribution
The **sampling distribution** of the **statistic** (such as mean, variance, proportions, etc.) is the tool that tells us how close is the statistic to the **parameter**.


## Agenda
* Sampling Distribution of the mean
* Sampling Distribution of a proportion
* Sampling Distribution of the Difference Between Two Means


# Sampling Distribution of the mean
## Process of Statistical Inference for $\mu$
![](https://i.imgur.com/mOpQWSJ.png)


## Sampling Distributions
* A sampling distribution of a statistic is a ==probability distribution== of the statistics created by the **sampling** process. 
* The method we will employ on the ==rules of probability== and the ==laws of expected value and variance== to derive the sampling distribution.
* The ==sampling distribution of the mean== will tell us how close the sample mean is to the **population mean**.

* 取均數變異數會變小


## Mean and Variance of $\bar{x}$
* Consider two **identical** and **independent** by distribution (IID) variables $𝑥_1$ and $𝑥_2$.
* Both have the same mean and variance
    * $E[x_1] = E[x_2] = \mu$
    * $Var[x_1] = Var[x_2] = \sigma^2$
* What is the mean and variance of $𝑥 = \frac{(𝑥_1+𝑥_2)}{2}$?

![](https://i.imgur.com/KesGM05.png)
![](https://i.imgur.com/cYL3zYE.png)


## Comparison
![](https://i.imgur.com/3dBu00d.png)


## The Die Rolling Problem
$𝑥=1, 2, 3, 4, 5, 6$, each with probability $\frac{1}{6}$.
* Rolling the die twice
    *　$𝑥_1,𝑥_2; 𝑥_1\in \{1,2,3,4,5,6\}, 𝑥_2 \in\{1,2,3,4,5,6\}$.
    * $\bar{𝑥} = \frac{x_1 + x_2}{2}$
    * Since the two events are independent, each possible combination has equal probability $\frac{1}{36}$.
* Rolling the die for three times, 
    * $𝑥_1, 𝑥_2, 𝑥_3, \bar{x} \frac{x_1 + x_2 + x_3}{3}$
    * Each possible combination has a probability of $\frac{1}{6^3}$.


## Compute the Distribution of $\bar{x}$
### 列出可能組合
```python=
import itertools

list1 = ['a', 'b', 'c']
for aelem in itertools.product(list1, list1):
    print(aelem)
```
### 計算機率分布
```python=
# count frequence and prob of each xbar value
def tofreq(x_bar_all):
    xbar_df = pd.DataFrame({'xbar': xbar_all})
    xbar_freq = xbar_df.xbar.value_counts()
    xbar_freq = xbar_freq.to_frame().reset_index()
    xbar_freq = xbar_freq.sort_values(by = "index")
    xbar_freq = xbar_freq.rename(columns = {'index': 'x', 'xbar': 'freq'})
    tmp1 = xbar_freq.freq.sum()
    xbar_freq['prob'] = xbar_freq.freq / tmp1
    return xbar_freq

#all possible dice outcomes
dpoints = [1, 2, 3, 4, 5, 6]

#one dice
xbar_all = []
for aelem in itertools.product(dpoints):
    #print(np.mean(aelem))
    xbar_all.append(np.mean(aelem))
xfreq1 = tofreq(xbar_all)

#two dices
xbar_all = []
for aelem in itertools.product(dpoints, dpoints):
    #print(np.mean(aelem))
    xbar_all.append(np.mean(aelem))
xfreq2 = tofreq(xbar_all)

#three dices
xbar_all = []
for aelem in itertools.product(dpoints, dpoints, dpoints):
    #print(np.mean(aelem))
    xbar_all.append(np.mean(aelem))
xfreq3 = tofreq(xbar_all)

#four dices
xbar_all = []
for aelem in itertools.product(dpoints, dpoints, dpoints, dpoints):
    #print(np.mean(aelem))
    xbar_all.append(np.mean(aelem))
xfreq4 = tofreq(xbar_all)

#five dices
xbar_all = []
for aelem in itertools.product(dpoints, dpoints, dpoints, dpoints, dpoints):
    #print(np.mean(aelem))
    xbar_all.append(np.mean(aelem))
xfreq5 = tofreq(xbar_all)
```
![](https://i.imgur.com/4qekIZh.png)
![](https://i.imgur.com/OC3c0pw.png)

### 畫出機率分布
```python=
plt.plot(xfreq5.x.values, xfreq5.prob.values)
plt.plot(xfreq4.x.values, xfreq4.prob.values)
plt.plot(xfreq3.x.values, xfreq3.prob.values)
plt.plot(xfreq2.x.values, xfreq2.prob.values)
plt.plot(xfreq1.x.values, xfreq1.prob.values)
```
![](https://i.imgur.com/cxRgFXv.png)
* 均數可能性越多，造成圖形高度漸低，且較集中。


## Sampling Distribution of $\bar{x}$
The probability distribution of all possible values of $\bar{x}$(the sample mean) has $E(\bar{x}) = \mu$ and $\sigma_x = \frac{\sigma}{\sqrt{n}}$
* $\mu$ = the population mean, 
* $\sigma$ is the population standard deviation, 
* $n$ is the sample size 
* $\sigma_{\bar{x}}$ is referred to as the **standard error of the mean**

### Note
* Notice that ${\sigma_{\bar{x}}}^2$ is smaller than $𝜎_{𝑥}^2$.  
* The larger the sample size the smaller ${\sigma_{\bar{x}}}^2$.  
* Therefore, $\bar{x}$ tends to fall closer to $\mu$, as the sample size increases. 


## Distribution of Sample Means for Various Sample Sizes
![](https://i.imgur.com/rIkfzYs.png)
![](https://i.imgur.com/grOQcys.png)

* 對任何機率分布皆成立，皆會往母體均數集中。


## Central Limit Theorem 中央極限定理 
* If a **random** sample is drawn from any population, the sampling distribution of the **sample mean** is approximately normal for a ==sufficiently large sample size==.
* The ==larger== the sample size, the more closely the sampling distribution of $\bar{x}$ will resemble a **normal** distribution.

If we have $x_1, x_2, …, x_n$ independent, identically distributed random variables, with mean $\mu$ and variance $\sigma^2$, then, $\bar{x_n} = (\frac{1}{n)\sum_{i = 1}^n{x_i}$ is approximately **Normally Distributed**, with mean = $\mu$ and variance = $\frac{\sigma^2}{n}$. (For $n$ large, say $n \ge 30$)
 
![](https://i.imgur.com/FlHLdw8.png)


## Small and Large Sample Size 
* When the simple random sample is **small** $(n \lt 30)$, the sampling distribution of $\bar{x}$ can be considered normal ==only if== we assume the ==population is close to a normal probability distribution==.

* If a large $(n \ge 30)$ simple random sample is used, the Central Limit Theorem enables us to conclude that the sampling distribution of $\bar{x}$ can be approximated by a **normal** probability distribution.


## Comments about CLT
![](https://i.imgur.com/SXBuWWX.png)


## Sampling from Non-Normal Populations
![](https://i.imgur.com/5CxzyOY.png)


## Cumulative Distribution in Python
`scipy.stats` has a collection of probability distributions.  
E.g. `scipy.stats.norm` is a collection of functions for **normal distributions**.
#### Useful methods:
* `rvs`: random variable
* `pdf`: Probability density function
* `cdf`: Cumulative distribution function
* `ppf`: Percent point function (Inverse CDF)

![](https://i.imgur.com/JuhO0aN.png)


## Sampling Distribution if 𝑥~𝑁𝑜𝑟𝑚𝑎𝑙
* $𝑥 \sim 𝑁𝑜𝑟𝑚(0,1)$
* If $\bar{x}$ is the mean of $𝑛$ identical and independent random variables from $𝑁𝑜𝑟𝑚(0,1)$, then 
    * $𝐸[\bar{x}] = 0$
    * $𝑉𝑎𝑟[\bar{x}]= \frac{1}{n}$
* We know that $\bar{x}$ is a normal distribution since $\bar{x}$ is a weighted averaged of variables following normal distributions. 
* Since the combination of mean and variance uniquely determine a normal distribution, we know that
    * $\bar{x} \sim 𝑁𝑜𝑟𝑚(0, \frac{1}{n})$


## Plot Normal Density
Mean $= 0$, Std dev. = $1, \frac{1}{\sqrt{2}}, \frac{1}{2}, \frac{1}{\sqrt{8}}$
```python=
x = np.arange(-3, 3, 0.01)
y1 = stats.norm.pdf(x, scale = 1)
y2 = stats.norm.pdf(x, scale = 1 / 2**0.5)
y3 = stats.norm.pdf(x, scale = 1 / 2)
y4 = stats.norm.pdf(x, scale = 1 / 8**0.5)

plt.plot(x, y1)
plt.plot(x, y2)
plt.plot(x, y3)
plt.plot(x, y4)
```

![](https://i.imgur.com/sTg1ZVk.png)


## Using Sampling Distributions for Inference
The symmetry of the normal distribution along with the sample distribution of the mean lead to:
![](https://i.imgur.com/oWlqtSi.png)

### Standardize the Sample Mean
![](https://i.imgur.com/9yh7e2X.png)


## General Form
![](https://i.imgur.com/lqj87uv.png)


## Standard Deviation of $\bar{x}$
![](https://i.imgur.com/unCu4sZ.png)


# Sampling Distribution of a proportion
## Analysis for Nominal data
The most common (often the only) calculation on nominal data is to count the **frequency** of each value of a variable and compute the **proportion (relative frequency)**


## Binomial Experiment
* There are $n$ Bernoulli trials ($n$ is finite and fixed).
* Each trial can result in a success or a failure (**two outcomes**).
* The probability $p$ of success is the same for all the trials.
* All the trials of the experiment are **independent**.
***
* The binomial random variable **counts the number of successes** in $n$ trials of the binomial experiment.
* By definition, this is a ==discrete random variable==.

### Calculating the Binomial Probability
![](https://i.imgur.com/yfZtKkw.png)

### Different Shapes
![](https://i.imgur.com/Xrn3AuJ.png)


## Normal Approximation to the Binomial
Normal approximation to the binomial works best when
* the number of experiments (sample size) is **large**, and
* the probability of success, $p$, is close to $0.5$.

* From the laws of expected value and variance, it can be shown that 
    * $E(X) = \mu =np$, 
    * $V(X) = \sigma^2 = np(1 – p)$
    * $\sigma = \sqrt{np(1 - p)}$ 


## Population and Sampling Proportion
* The parameter of interest for nominal data is the **proportion of times** a particular outcome (success) occurs.
* To estimate the population proportion ‘$p$’, we use the sample proportion.
![](https://i.imgur.com/mE96qHR.png)

### Sampling Distribution of Proportion
* Since $X$ is binomial, probabilities about 𝑝 ̂ can be calculated from the binomial distribution.
* Yet, for inference about $\hat{p}$ we prefer to use **normal approximation** to the binomial.


## Sampling Distribution of $\hat{p}$
The sampling distribution of $\hat{p}$ is the probability distribution of all possible values of the sample proportion.
![](https://i.imgur.com/BekGtQe.png)
### Normal Statistics
If both $np \gt 5$ and $n(1-p) \gt 5$, then $z = \frac{\hat{p} - p}{\sqrt{\frac{p(1 - p)}{n}}}$
* $Z$ is approximately standard normally distributed.


## Standard Deviation of Sampling Distribution of $\hat{p}$
![](https://i.imgur.com/buK5cOW.png)


# Sampling Distribution of the Difference Between Two Means
## The Difference between Two Means
* Independent samples are drawn from each of **two normal populations**
* We’re interested in the sampling distribution of the difference between the two sample means $\bar{x_1} - \bar{x_2}$.
* The distribution of $\bar{x_1} - \bar{x_2}$ is normal if
    * The two samples are **independent**, and
    * The parent populations are **normally** distributed.
* If the two populations are not normally distributed, but the ==sample sizes are $30$ or more==, the distribution of $\bar{x_1} - \bar{x_2}$ is approximately **normal**.


## Sampling Distribution of $\bar{x_1} - \bar{x_2}$ vs. Sample Size
![](https://i.imgur.com/oIZcGib.png)
![](https://i.imgur.com/rlyZxnn.png)

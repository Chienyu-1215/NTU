###### tags: `MGT2001 Statistics` `Notes`
# Statistics: Chapter 7 Random Variables and Discrete Probability Distributions
## Agenda
* Random Variables and Probability Distributions
* Bivariate Distributions
* Known Theoretical Discrete Probability Distributions


# Random Variables and Probability Distributions
## Random Variables
* A **function** that assigns a **numerical value** to each outcome of a **random experiment** in a sample space.
* A **random variable** reflects the aspect of a random experiment that is of interest to us.

### Random Experiment 隨機實驗
A process or course of action, whose outcome is uncertain
![](https://i.imgur.com/MNTbzZY.png)

### Random Variables 隨機變數
指定值的一個函數
* $X$ is the number of head for flipping a coin once (value of X could be $1$ or $0$)
* $Y$ is the test score of a Statistics class ($0 \le Y \le 100$)
* $Z$ is the time to assemble a PC ($50 \le Z \le 200$)


## Types of Random Variables
There are two types of random variables based on their value ranges
* Discrete random variable
* Continuous random variable.  
![](https://i.imgur.com/UTnyJPG.png)

### Discrete Random Variable 不連續隨機變數
A random variable is discrete if it can assume only a **countable** number of values.  
*After the first value is defined, the second value and any value thereafter are known.*
#### Example
Number of points on the rolling of 2 dices: 2, 3, 4, …, 12

### Continuous Random Variable 連續隨機變數
A random variable is continuous if it can assume an **uncountable** number of values.  
*After the first value is defined, any number can be the next one.*
#### Example
time ($30.1$ minutes $\ne 30.10000001$ minutes)


## Probability Distribution
A probability distribution is a **table**, **formula**, or **graph** that describes the values of a **random variable** and the **probability** associated with these values.


## Type of Probability Distribution
Since we’re describing a random variable, we have two types of probability distributions:
* Discrete probability distribution
* Continuous probability distribution


## Discrete Probability Distribution
To calculate $P(X = x)$, the probability that the random variable $X$ assumes the value $x$, add the probabilities of all the simple events for which $X$ is equal to $x$.
### Example
Consider the random experiment of flipping a coin twice.  
$X$: The number of heads that turn-up when a coin is flipped twice.

![](https://i.imgur.com/Q1w86XT.png)
![](https://i.imgur.com/8x0mbp7.png)


## Requirements of Discrete Probability Distribution
If a random variable can take values $x_i$, then the following must be true:
1. $0 \le p(x_i) \le 1$ for all $x_i$.
2. $\sum_{\text{all }x_i} {p(x_i)} = 1$
### Example
The probability of getting at least one head when flipping a coin twice.
$P(1 \le X \le 2) = P(X = 1) + P(X = 2) = \frac{1}{2} + \frac{1}{4} = \frac{3}{4}$


## Probability as Relative Frequency
In practice, often **probabilities** are estimated from **relative frequencies** based on survey, historical data, or subjective approach


## Probability Trees
There is no requirement that the branches splits be binary, nor that the tree only goes two levels deep, or that there be the same number of splits at each sub node…


## Describing the Population by a Probability Distribution
* The **probability distribution** represents a **population**
* Describing the population by computing various **parameters**: specifically, the population mean and population variance


## Expected Value
The expected value (mean, $\mu$) of a random variable $X$ is the **weighted average** of the possible values it can assume, where the weights are the corresponding probabilities of each $x_i$.  
Given a discrete random variable $X$ with values $x_i$, that occur with probabilities $P(x_i)$, the expected value of $X$ is $$\mu = E(X) = \sum_{\text{all }x_i}{x_i  p(x_i)}$$


## Variance
The variance is the **weighted average** of the squared deviations of the values of $X$ from their mean $m$, where the weights are the corresponding probabilities of each $x_i$.
Let $X$ be a discrete random variable with possible values $x_i$ that occur with probabilities $P(x_i)$, and let $E(x_i) = m$. The variance of $X$ is defined to be $$\sigma^2 = E[(X - \mu)^2] = \sum_{\text{all } x_i}(x_i - \mu)^2p(x_i) = E(X^2) - \mu^2 = \sum_{\text{all } x_i} x_i^2 p(x_i) - \mu^2$$


## Standard Deviation
The standard deviation of a random variable $X$, denoted $\sigma$, is the positive square root of the variance of $X$. $$\sigma = \sqrt{\sigma^2}$$


## Laws of Expected Value
Let $c$ be a constant and $X$ be a random variable.
* $E(c) = c$
* $E(c + X) = c + E(X)$
* $E(cX) = c E(X)$


## Laws of Variance
Let $c$ be a constant and $X$ be a random variable.
* $Var(c) = 0 $
* $Var(cX) = c^2 Var(X)$
* $Var(X + c) = Var(X)$


# Bivariate Distributions
## Bivariate Joint Distribution
* Used when the relationship between two random variables is studied.
* The probability that $X$ assumes the value $x$, and $Y$ assumes the value $y$ is denoted $p(x, y) = P(X = x \text{ and } Y = y)$
* The Bivariate (Joint) probability function must satisfy the following conditions:
    * $0 \le p(x,y) \le 1$
    * $\sum_{\text{all }x}{\sum_{\text{all } y}{p(x, y)}} = 1$


## Covariance
The covariance is a measure of the direction to which two random variables tend to move at the same time.
$\sum_{\text{all }y}{\sum_{\text{all }x}{(x - \mu_x)(y - \mu_y)p(x,y)}} = E[(X - \mu_x)(Y - \mu_y)] = E(XY) - \mu_x \mu_y = E(XY) - E(X)E(Y) = \sum_{\text{all }y}{\sum_{\text{all }x}{xyp(x,y) - \mu_x \mu_y}}$


## The Coefficient of Correlation
Measure how strong and the direction of the linear relationship between $X$ and $Y$ $$\rho = \frac{COV(X, Y)}{\sigma_x \sigma_y}$$
### Linear Relationship
* $|\rho| \lt 0.25$ : very weak
* $0.25 \le |\rho| \lt 0.5$: moderately weak
* $0.5 \le |\rho| \lt 0.75$: moderately strong
* $0.75 \le |\rho| \le 1$: very strong
* Positive or Negative linear relation


## Calculating Conditional Probability
Based on a joint probability distribution, the conditional probability is computed as: $$P(X = x | Y = y) = \frac{P(X = x \text{ and } Y = y)}{P(Y = y)}$$


## Condition for Independence
Two random variables, $X$ and $Y$, are said to be independent when 
* $$P(X = x | Y = y) = P(X = x)$$
* $$P(Y = y | X = x) = P(Y = y)$$


## In General
* $E(aX+bY) = aE(X) + bE(Y)$ 
* $Var(aX + bY) = a^2Var(X) + b^2Var(Y) + 2abCOV(X,Y) = a2Var(X) + b2Var(Y) + 2 ab \rho \sigma_x \sigma_y$ 


## The Expected Value and Variance of $\sum_{c_i}{X_i}$
* $E(\sum_{c_i}{X_i}) = \sum_{c_i}{E(X_i)}$
* $Var(\sum_{c_i}X_i) = \sum_{c_i^2}{Var(X_i)} + 2 \sum_{c_i c_j} {COV(X_i, X_j)} = 2 \sum_{c_ic_j} {\rho \sigma_{x_i} \sigma_{x_j}}$


# Known Theoretical Discrete Probability Distributions
## The Bernoulli Trial
Result in only one out of two outcomes
* A coin flipped (heads or tails)
* An election candidate (wins or loses)
* An employee is male or female
* A car uses 87 octane gasoline, or another gasoline.

### Binomial Experiment
* There are $n$ trials ($n$ is finite and fixed).
* Each trial is a Bernoulli trial with** two outcomes** (success and failure).
* The probability $p$ of success is **the same** for all the trials.
* All the trials of the experiment are **independent**.

### Binomial Random Variable
* The binomial random variable **counts the number of successes** in $n$ trials of the binomial experiment.
* By definition, this is a **discrete random variable**.

### Calculating the Binomial Probability
In general, The binomial probability is calculated by $P(X = x) = p(x) = C^n_x p^x (1 - p)^{n - x}$

### Mean and Variance of Binomial Random Variable
* $E(X) = \mu = np$
* $Var(X) = \sigma^2 = np(1 - p)$


## The Poisson Distribution
The Poisson experiment typically fits cases of **rare events** that occur over a **fixed amoun**t of time or within a specified region.

### Typical Poisson Experiment
* The number of errors a typist makes per page
* The number of customers entering a service station per hour
* The number of telephone calls received by a server per hour

### Properties of the Poisson Experiment
* The number of successes (events) that occur in a certain time interval is independent of the number of successes that occur in another time interval.
* The probability of a success in a certain time interval is
    * **the same** for all time intervals of the same size,
    * **proportional** to the length of the interval.
* The probability that two or more successes will occur in an interval approaches **zero** as the interval becomes **smaller**.

### Poisson Random Variables
The Poisson randon variable indicates **the number of successes** that occur during a given time interval or in a specific region in a Poisson experiment

### Probability Distribution
Let $x$ be the number of success and $\mu$ is the average number of success or arrival rate.
$P(X = x) = p(x) = \frac{e^{-\mu} \mu^x}{x!!} \\ E(X) = Var(X) = \mu$

### Poisson Approximation of the Binomial
* When $n$ is very large, binomial probability table may not be available.
* If $p$ is very small $(p < .05)$, the binomial probabilities can be approximated by the Poisson distribution.
Use $\mu = np$ and make the following approximation: $$P(X_{Binominal} = x) \simeq P(X_{Poisson} = x)$$ 


## Geometric Probability Distribution
### Geometric Random Variables 幾何
Number of failures, $X$, in the Geometric Experiment or **number of failures** before the first success.

### Geometric Experiment
* The success occurs at $X + 1$ (first successful) trial or the last trial.
* Each trial is an Independent Bernoulli Trial.
    * The success probability $p$ is the **same** at each trial.
    * Each trial has only **two** outcomes (success or failure).

### Geometric Distribution
$P(X = x) = p(1 – p)^x$ where $p$ = the probability of success and $x$ = the number of failures before success
#### Shapes of $G(X)$ given $p$
![](https://i.imgur.com/zrDha9s.png)

### Expected Value and Variance of Geometric Distribution
$X \thicksim G(p)$ where $p$ is the input parameter
* $E(X) = \frac{(1 - p)}{p}$
* $Var(X) = \frac{(1 - p)}{p^2}$

#### Note
* If $p \gt 0.5$, then $E(X) \lt 1$. Otherwise, if $p \le 0.5$, then $E(X) \ge 1$.
* Geometric Distribution has **memoryless property**. Whenever a success occur, all the conditions are reset. The counting starts again.
* 要用 Chebyshev’s Theorem -> 因為必為Positively Skewed


## Hypergeometric Probability Distribution
### Hypergeometric Experiment
If $n$ items are selected from population with totally $N$ items (**Finite Population**), within which, $r$ items are “successful”, **count the number** of “successful” items, $X$. 

### Hypergeometric Random Variable
There are totally $N$ items in a population within which, $r$ items are successful.  
Let $X$ be the number of successes in $n$ Bernoulli trials.  
$X$ is a Hypergeometric random variable. 

### Hypergeometric Probability Distribution
Let $X$ be the number of successes in $N$ Bernoulli trials with population size = $N$ and total number of success items = $r$. $$P(X = x) = \left\{\begin{array}{}r \\ x \end{array}\right\} \frac{\left\{\begin{array}{}N - r \\ n - x \end{array}\right\}}{\left\{\begin{array}{}N \\ n \end{array}\right\}}$$

### Expected Value and Variance
$X \thicksim HG(N, r, n)$ where $N$, $r$, and $n$ are input parameters. 
* $E(X) = n (\frac{r}{n})$
* $Var(X) = n (\frac{r}{n})(1 - \frac{r}{n})(\frac{N - n}{N - 1})$

#### Shapes of $HG(N, r, n)$
![](https://i.imgur.com/UJPBa4v.png)
* Bell Shape -> $N$ larger.
* $r$ larger -> negatively skewed. 
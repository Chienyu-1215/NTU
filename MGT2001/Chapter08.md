###### tags: `MGT2001 Statistics` `Notes`
# Statistics: Chapter 8 Continuous Probability Distributions
## Agenda
* Probability Density Functions
* Normal Distribution
* Exponential Distribution


# Probability Density Functions
## Continuous Random Variable
A random variable that can assume **any value** contained in one or more intervals. Because the number of values contained in any interval is **infinite**, the possible number of values that a continuous random variable can assume is also **infinite and not countable**.
### Examples of Continuous Random Variables
* Life of a battery 
* Salaries of workers
* Prices of houses
* Learning time of a worker


## Point Probability = Zero for Continuous Random Variable 
The probability that a **continuous variable** $X$ will assume any particular value is **zero**. 
* $P(X = x) = 0$
#### Why $P(X = x) = 0$?
When the number of values approaches infinity (because $X$ is continuous) the probability of each value approaches $0$.
* Because there is an infinite number of values, the probability of each individual value is virtually $0$.
* Thus, we can determine the probability of a **range of values** only. It is meaningful to talk about $P(X \le 5)$ or $P(X \ge 5)$ but not $P(X = 5)$.


## Discrete vs. Continuous
* With a **discrete** random variable, like tossing a die, it is meaningful to talk about $P(X = 5)$.
* In a **continuous** setting (e.g. with time as a random variable), the probability the random variable of interest, say task length, takes exactly $5$ minutes is infinitesimally small, hence $P(X = 5) = 0$.


## Probability Density Function   
A function $f(x)$ is called a probability density function (over the range $a \le x \le b$)


The density function, $f(x)$, satisfies the following conditions
* $f(x) \ge 0$ for all $x$ between $a$ and $b$,
* The total area under the curve representing $f(x)$ equals $1$.


## Probability Function
The probability that $x$ falls between $c$ and $d$ is found by calculating the area under the graph of $f(x)$ between $c$ and $d$.  
![](https://i.imgur.com/z5DVl21.png)


## Mean and Variance
* Mean $\mu = \int_{all \space x}{xf(x)dx}$
* Variance $\sigma^2 = \int_{all \space x}{x^2f(x)dx} - \mu^2 = \int_{all \space x}{(x - \mu)^2f(x)dx}$
Note : Without knowing $f(x)$, there is no way to compute $\mu$ and $\sigma^2$. 


## Uniform Density Distribution
A random variable $X$ is said to be uniformly distributed if its density function is $f(x) = \frac{1}{b - a} \quad a \le x \le b$
![](https://i.imgur.com/FnIN3st.png)

### Uniform Probability Distribution
A random variable X is said to be uniformly distributed as $f(x) = \frac{1}{b - a} \quad a \le x \le b$  
The probability distribution is $$F(y) = \int_{a}^{y}{\frac{1}{b - a}dx} = \frac{y - a}{b - a} \quad where a \le y \le b$$  
![](https://i.imgur.com/rB7OrYp.png)

### Expected Value and Variance of Uniform Probability Distribution
* Mean $E(x) = \frac{b + a}{2}$  
![](https://i.imgur.com/EaupqSL.png)

* Variance $Var(x) = \frac{(b - a)^2}{12}$  
![](https://i.imgur.com/SCNW9fU.png)

### Note
(1) $f(x) \ne P(X = x)$.
(2) $P(X = x) = 0$ for all $x$ (point probability $= 0$).
(3) $F(x) = P(X \le x) = \int_a^x{f(s)ds}$ is known as **cumulative probability distribution**.


# Normal Distribution
* This is the **most important** continuous distribution considered here.
* Many **random variables** can be properly modeled as normally distributed.
* Many **distributions** can be approximated by a normal distribution.
* The normal distribution is the cornerstone distribution of **statistical inference**.

## The Normal Distribution
A random variable, $X$, with mean $\mu$ and variance $\sigma^2$ is normally distributed if its **probability density function** is given by  
![](https://i.imgur.com/IDPuKkW.png)


## Shape of Normal Distribution
A **bell shaped** distribution, **symmetrical** around $\mu$  
![](https://i.imgur.com/abcBm5X.png)
* $\mu$ will affect on the position of the center of the shape: $\mu$ is larger, the center moves right.
* $\sigma$ will affect on the shape of $f(x)$: $\sigma$ is larger, the shape is more flat. 


## Finding Normal Probabilities
* The normal distribution is **unimodal** and **symmetrical**.
* Any normal distribution can be transformed into a specific normal distribution called “**Standard Normal Distribution**”


## Standard Normal Distribution,$N(0, 1)$
![](https://i.imgur.com/DtNgtxb.png)  
A random variable, $Z$, with mean $= 0$ and variance $= 1$ is normally distributed if its **probability density function** is given by  
![](https://i.imgur.com/ZTAisu2.png)


## Standard Normal Variable
Every normal variable $X$ with $\mu$ and $\sigma$, can be transformed into $Z$. $$Z = \frac{X - \mu}{\sigma} \\ \text{where $E(Z) = \mu_z = 0$ and $Var(Z) = 1$ or $\sigma_z = 1$}$$

Therefore, once probabilities for $Z$ are calculated, probabilities of any normal variable can found.


## Table 3 (pages B-8 to B-9)
* If we know $\mu$ and $\sigma$ of a normally distributed random variable, we can always transform the probability statement about $X$ into a probability statement about $Z$. 
* This table lists cumulative  probabilities $P(Z \lt z)$ for values of $z$ ranging from $−3.09$ to $+3.09$
![](https://i.imgur.com/23QLqcE.png)

* Recall that in Tables 1 and 2 we were able to use the table to find the probability that $X$ is equal to some value of $x$, but that we **won’t do the same** with the **normal table**. 
* Remember that the normal random variable is **continuous** and the probability that it is equal to any single value is $0$.


# Exponential Distribution
## Exponential Distribution  
A random variable is exponentially distributed if its probability density function is given by $$f(x) = \lambda e^{-\lambda x}, x \ge 0$$  
where $\lambda$ is a parameter (mean arrival rate or mean occurrence rate) of the distribution ($\lambda \gt 0$)
![](https://i.imgur.com/qgGtAgQ.png)  
When **the number** of occurrences of an event follows the **Poisson distribution**, the time between occurrences follows the **exponential distribution**.
### Apply Exponential Distribution
* The length of time between two telephone calls
* The length of time between two arrivals at a service station
* The life-time of electronic components.


## Expected Value and Variance of $Exp(\lambda)$
A random variable is exponentially distributed with
* $E(X) = \frac{1}{\lambda}$  
    ![](https://i.imgur.com/eH5A5VB.png)
* $Var(X) = \frac{1}{(\lambda^2)}$  
    ![](https://i.imgur.com/ekGspzJ.png)  
* $P(X \ge a) = e^{-\lambda a}$  
    ![](https://i.imgur.com/izuklZ0.png)


## Shapes
![](https://i.imgur.com/zdi2RT0.png)


## Other Continuous Distributions
Three other important continuous distributions which will be used extensively and introduced in later sections:
* Student $t$ Distribution,
* Chi-Squared Distribution, and
* $F$ Distribution.

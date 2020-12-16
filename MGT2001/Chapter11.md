###### tags: `MGT2001 Statistics` `Notes`
# Statistics: Chapter 11 Introduction to Hypothesis Testing 
## Agenda
* Concept of Hypothesis Testing
* Conclusions and Errors
* Testing the Population Mean When s is known
* Calculating the probability of a Type II Errors


# Concept of Hypothesis Testing
## Hypothesis Testing
<a href="https://zh.wikipedia.org/wiki/%E5%81%87%E8%AA%AA%E6%AA%A2%E5%AE%9A">Wikipedia</a>
**Hypothesis Testing** is a procedure for making inferences about a population from a sample.
![](https://i.imgur.com/uI4mBvb.png)
![](https://i.imgur.com/OIpPP6z.png)


## Concepts of Hypothesis Testing 
In a criminal trial a jury must decide between two hypotheses. 
* The **null** hypothesis 虛無假設 is “The defendant is innocent”
* The **alternative** hypothesis 對立假設 or research hypothesis is “The defendant is **guilty**”

In Hypothesis Testing:
There are two hypotheses, null ($H_0$) and alternative ($H_1$). The procedure begins with the assumption that ==the null hypothesis is true==.  
* The goal is to determine whether there is ==enough evidence== to infer that the alternative hypothesis is true.

### Hypothesis Testing in Criminal Trial
The **jury** does not know which hypothesis is true. They must make a decision on the basis of **evidence** presented. 
* **Convicting** the defendant is called ==rejecting the null hypothesis in favor of the alternative hypothesis==. That is, the jury is saying that there is enough evidence to conclude that the defendant is guilty (i.e., there is enough evidence to support the alternative hypothesis).
* If the jury **acquits**, it is stating that there is ==not enough evidence to support the alternative hypothesis==. Notice that the jury **is not** saying that ==the defendant is innocent==, only that there is ==not enough evidence to support the alternative hypothesis==. That is why we never say that we accept the null hypothesis. 
***
There are two possible decisions:
1. Conclude that there is **enough evidence** to **reject** the null hypothesis.
2. Conclude that there is **not enough evidence** to reject the null hypothesis.


## Types of Errors
![](https://i.imgur.com/pTIolX2.png)

### Errors in Criminal Trial Hypothesis Testing
* A **Type I** error occurs when we reject a true null hypothesis. That is, a Type I error occurs when the jury ==convicts an innocent person==. (冤獄)
* A **Type II** error occurs when we don’t reject a false null hypothesis. That occurs when ==a guilty defendant is acquitted==. (縱放)


## Probabilities of Errors
* The probability of a Type I error is denoted as $\alpha$, $P(Type \space I \space error) = a$. 
* The probability of a Type II error is $\beta$, $P(Type \space II \space error) = \beta$.

The two probabilities are **inversely related**. Decreasing one increases the other.  
***
* In US judicial system, **Type I** errors are regarded as more serious. We try to avoid convicting innocent people. We are ==more willing to acquit guilty people==.
* We arrange to make a very small by requiring the prosecution to prove its case and instructing the jury to find the defendant guilty only if there is “evidence beyond a ==reasonable doubt.==”


## Statistical Hypothesis Testing
Statistical Hypothesis testing allows us to determine whether enough statistical evidence exists to conclude that a **belief** or an **idea** (i.e. ==hypothesis==) about ==a parameter is supported== by the data.


## What is a Hypothesis?
A hypothesis is a claim (assertion) about a population parameter:
![](https://i.imgur.com/MZSh4fo.png)


## Developing Null and Alternative Hypotheses
* The **null hypothesis**, denoted by $H_0$, is a tentative assumption about a population parameter.
* The **alternative hypothesis**, denoted by $H_1$, is the opposite of what is stated in the null hypothesis.

1. The testing procedure begins with the assumption that the null hypothesis is **true**.
2. The goal of the process is to determine ==whether there is enough evidence== to infer that the alternative hypothesis is true.


## To Determine Null vs. Alternative Hypothesis
### Equality
The null hypothesis ($H_0$) will always include the case that the **parameter equals the value** that is specified in the alternative hypothesis ($H_1$)
![](https://i.imgur.com/hamCKn1.png)

### Testing Research Hypotheses
* The **research hypothesis** should be expressed as the alternative hypothesis.
* The conclusion that the research hypothesis is true comes from sample data that **contradict the null hypothesis**.

### Testing the Validity of a Claim
* Manufacturers’ claims are usually given the benefit of **the doubt** and stated as the null hypothesis.
* The conclusion that the claim is false comes from sample data that ==contradict the null hypothesis==.

### Testing in Decision-Making Situations
A decision maker might have to choose between **two courses of action**, one associated with the null hypothesis and another associated with the alternative hypothesis.


# Conclusions and Errors
## Two Conclusions
* Conclude that there is **enough evidence** to reject the null hypothesis (also stated as: rejecting the null hypothesis in favor of the alternative)
* Conclude that there is **not enough evidence** to reject the null hypothesis (also stated as: do not reject the null hypothesis in favor of the alternative)


## Hypothesis Testing 
Once the null and alternative hypotheses are stated, the next step is to **randomly sample** the population and calculate a **testing statistic** (in this example, the sample mean).  
If the testing statistic’s value is inconsistent with the null hypothesis, ==we reject the null hypothesis and infer that the alternative hypothesis is true==.


## Two Tyoes of Errors
A Type I error occurs when we ==reject a true null hypothesis==  
$P(\text{Type I error}) = a$
* $\alpha$ is called the significance level and $1 – \alpha$ is called the confidence level  

A Type II error may occurs when we ==don’t reject== a false null hypothesis.  
$P(\text{Type II error}) = \beta$
* $1 – \beta$ is called the Power of Test (reject a false null hypothesis).

![](https://i.imgur.com/lCeGEnL.png)
***
Since hypothesis tests are based on **sample data**, we must allow for the **possibility of errors**.
* A Type I error is rejecting $H_0$ when it is true: $\alpha$
* A Type II error is not rejecting $H_0$ when it is false: $\beta$

We specify the ==maximum allowable probability== of making a Type I error, denoted by $\alpha$ and called the level of ==significance==.  

Generally, we ==cannot control for the probability of making a Type II error==, denoted by $\beta$.  

What we can do is to select a hypothesis testing approach that gives the smallest $\beta$ at a fixed level of $\alpha$. 


# Testing the Population Mean When s is known
## Summary of One- and Two-Tail Tests
![](https://i.imgur.com/wZEcatq.png)


## The Steps of Conducting a Hypothesis Testing
1. Determine the appropriate hypotheses (definitions).
2. Select the appropriate testing methods to reject or not to reject the null hypothesis.
3. Specify the level of significance for the test ($\alpha$).
4. Use $\alpha$ to develop the rule for rejecting $H_0$.
5. Collect the sampled data and compute the values of the rejection rule.
    * The Rejection Region Method
    * Testing Statistic
    * $p$-value Method
6. Compare the value(s) in the rejection rules, (critical $x, z$, or the $p$-value based on the test statistic) and determine whether or not to reject $H_0$ and draw a conclusion.


## Three Ways of Hypothesis Testing
### The Rejection Region Method
The **rejection region** is a range of values such that if the ==test statistic falls into that range==, the null hypothesis is rejected in favor of the alternative hypothesis.
Three scenarios:
![](https://i.imgur.com/QMjtFWu.png)
#### Hypothesis Testing for One-Tail
![](https://i.imgur.com/YZaMM2p.png)
![](https://i.imgur.com/vTlZvZi.png)
![](https://i.imgur.com/mN38HR4.png)
![](https://i.imgur.com/6R5fkJ4.png)
#### Hypothesis Testing for Two-Tails
The rejection region is set up so we can reject the null hypothesis when the test statistic is **large** or when it is **small**.
That is, we set up a ==two-tail== rejection region. The total area in the rejection region must sum to a, so we ==divide this probability by $2$==.
![](https://i.imgur.com/IrBGovF.png)
![](https://i.imgur.com/jIY2cil.png)

### Testing Statistic
* Instead of using the statistic 𝑥 ̅, we can use the standardized value $z = \frac{\bar{x} - \mu}{\frac{\sigma}{\sqrt{n}}}$.
* Then, for right-tail tests $(H_A: \mu \gt \mu_0)$ the rejection region becomes $z \ge z_{\alpha}$.
* Reject the null hypothesis if $z \ge z_{\alpha}$  
![](https://i.imgur.com/nWgrryq.png)

### $p$-value Method
The $p$-value of a test is the **probability** of observing a test statistic at least as extreme as the one computed (sampled), given that the null hypothesis is true.  

The $p$-value method provides information (probability) about the amount of statistical evidence that ==supports the alternative hypothesis==

![](https://i.imgur.com/q1kJzG4.png)

#### Interpreting the $p$-value 
![](https://i.imgur.com/iOYeAK8.png)
* If the $p$-value is less than $1\%$, there is **overwhelming** evidence that supports the alternative hypothesis.
* If the $p$-value is between $1\%$ and $5\%$, there is a **strong** evidence that supports the alternative hypothesis.
* If the $p$-value is between $5\%$ and $10\%$ there is a **weak** evidence that supports the alternative hypothesis.
* If the $p$-value exceeds $10\%$, there is **no evidence** that supports the alternative hypothesis.
***
* The ==smaller the $p$-value==, ==the more statistical evidence== exists to support the alternative hypothesis.
* *We observe a $p$-value of $.0069$, hence there is overwhelming evidence to support $H_1: m>170$.*

#### $p$-value vs. $\alpha$ 
Compare the p-value with the significance level a:
* If the $p-value < \alpha$, we judge the $p$-value to be small enough to reject the null hypothesis
* If the $p-value \ge \alpha$, we ==do not reject the null hypothesis==

#### Summary
![](https://i.imgur.com/VNBG7S0.png)


## Python Code
```python=
m1 = df1.Accounts.mean()
print(f"mean = {m1:.4f}")

sd1 = df1.Accounts.std()
print(f"std. dev. = {sd1:.4f}")
nobs = df1.shape[0]
print(f"Number of observation = {nobs}")
h0mean = 170
print(f"Hypothesized mean = {h0mean}")
h0sd = 65
print(f"Assumed std dev = {h0sd}")
siglevel = 0.05
print(f"Significant level = {siglevel}")

zstat = (m1-h0mean) / (h0sd/(nobs ** 0.5))
print(f"z-stat = {zstat:.4f}")
zcv_onetail = stats.norm.ppf(1-siglevel)
print(f"z critical value one tail = {zcv_onetail:.4f}")

p_onetail= 1 - stats.norm.cdf(zstat)
print(f"p-value (one-tail) = {p_onetail:.4f}")

zcv_twotail = stats.norm.ppf(1 - siglevel/2)
print(f"z critical value two tail = {zcv_twotail:.4f}")

p_twotail = (1 - stats.norm.cdf(zstat)) * 2
print(f"p-value (two-tail) = {p_twotail:.4f}")
```


# Calculating the probability of a Type II Errors
## Probability of Type II Error ($\beta$)
![](https://i.imgur.com/rkl3WGS.png)


## Calculation of the Probability of Type II Error ($\beta$)
![](https://i.imgur.com/EeK8NAb.png)
![](https://i.imgur.com/kISsN2Z.png)
![](https://i.imgur.com/SgQE3o3.png)


## Power of a Test
![](https://i.imgur.com/6s6pmpG.png)


## Python Code
![](https://i.imgur.com/6iuemmB.png)

### Multiple $H_1$ mean
![](https://i.imgur.com/RAXpiTq.png)
![](https://i.imgur.com/91v5KYY.png)


## OC and Power Curves
![](https://i.imgur.com/z2POOKK.png)


## Judging the Test
![](https://i.imgur.com/scBRZKZ.png)


## Effects on $\beta$ of Changing $\alpha$
![](https://i.imgur.com/Ocn3c9Z.png)


## Operating Characteristic Curves for Different Sample Sizes
![](https://i.imgur.com/XiMtv4Y.png)


## Note on the Power of a Test
* When more than one test can be performed in a given situation, its is preferable to use the test that is correct more often. 
* If one test has a higher power than a second test, the first test is said to be more powerful and the preferred test.
* By increasing the sample size, we reduce the probability of type II error.
* Hence, we shall not reject the null hypothesis when it is false less frequently.
* Larger n is preferred, but with a cost. 


## Relationship among $\alpha$, $\beta$, and $n$
* Once two of the three values are known, the other can be computed.
* For a given level of significance $\alpha$, increasing the sample size $n$ will reduce $\beta$.
* For a given sample size $n$, decreasing a will increase $\beta$, whereas increasing a will decrease $\beta$.


## The Road Ahead 
* **ICI** approach: Identify, Compute and Interpret
* A critical aspect in statistical analysis (in real life and on final exams) is to ==identify the correct technique==.
***
There are several factors that identify the correct technique. The first two are	
1. Type of data: interval, ordinal, nominal		
2. Problem objective:
* Describe a population
* Compare two populations
* Compare two or more populations
* Analyze the relationship between two variables 
* Analyze the relationship among two or more variables 

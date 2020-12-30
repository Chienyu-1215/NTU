###### tags: `MGT2001 Statistics` `Notes`
# Statistics: Chapter 12 Inference about a Population
## Agenda
* Inference about $\mu$ When $\sigma$ Is Unknown
* Inference About a Population Variance
* Population Total and Finite Populations
* Inference About a Population Proportion


# Inference about $\mu$ When $\sigma$ Is Unknown
## Inference About $\mu$ When $\sigma$ Is Known ($n \ge 30$)
Recall that when $\sigma$ is known we use the following statistic to estimate and test a population mean
![](https://i.imgur.com/yOzOEpx.png)

* Confidence Interval
    ![](https://i.imgur.com/YH1XEYC.png)
    * $\bar{x}$ is the sample mean
    * $1 - \alpha$ is the confidence coefficient
    * $z_{\frac{\alpha}{2}}$  is the $z$ value providing an area of $\frac{\alpha}{2}$ in the upper tail of the standard normal probability distribution
    * $\sigma$ is the population standard deviation
    * $n$ is the sample size


## What if $\sigma$ is unknown?
In most applications, the value of the population ==standard deviation ($\sigma$) is unknown==. Simply use the value of the **sample** standard deviation, $S$, as the point estimate of the population standard deviation.  
![](https://i.imgur.com/ycYJQIE.png)
When the sampled population is ==normally distributed==, the $t$ statistic is **Student t distributed**.


## Student $t$ Distribution
* Developed by W. S. Gossett in 1908 under the pseudonym “**Student**” and thus is also called **Student's t distribution**.
* ==Symmetric== about the mean (bell-shaped).
* With two ==tails== extend to infinity.
* With total area under the curve equal to $1.0$ or $100\%$.
* Flatter than the standard normal distribution 
* Approach to $N(0,1)$ as the sample size increases.
![](https://i.imgur.com/rbQFKGf.png)


## Degrees of Freedom
* A function of the sample size determines how spread the distribution is (compared to the normal distribution)
* The shape of a particular $t$ distribution curve depends on the number of degrees of freedom,
* For the case of standardize sample mean, $df = n - 1$ where $n$ is the sample size. $$E(X) = 0 \\ V(X) = \frac{df}{df - 2}$$ 


## Python Code for $t$ Distributions vs. Std. Normal Distribution
![](https://i.imgur.com/QNnlLUT.png)
![](https://i.imgur.com/hlD7rS6.png)
* 尾巴較厚實-> 厚尾分布


## Using the $t$ Table
The table provides the $t$ values ($t_A$) for which $P(t_{\nu} > t_A) = A$
![](https://i.imgur.com/QzN35PH.png)

* For a given degree of freedom, $v$, and for a predetermined right-tail probability, $\alpha$, the entry in the table is the corresponding $t_{\alpha,v}$. 
* These values are used in computing confidence interval estimates and performing hypotheses tests.
#### Python Code
![](https://i.imgur.com/Y8zl08I.png)


## Interval Estimation of $\mu$ When $\sigma$ is Unknown 
* The population is ==normally distributed== but s is unknown.
* The appropriate interval estimate is based on a probability distribution known as the t distribution.
![](https://i.imgur.com/GODvJLB.png)
where $t_{\frac{\alpha}{2}, n - 1}$ = the $t$ value providing an area of $\frac{\alpha}{2}$ in the upper tail of a $t$ distribution with $n – 1$ degrees of freedom


## Python Example
![](https://i.imgur.com/dd7Gd4C.png)


## Hypothesis Testing on $\mu$ with $\sigma$ Unknown
![](https://i.imgur.com/TQFLp4c.png)
When $\sigma$ is unknown, we use its point estimator $s$ and the $z$-statistic is replaced by the $t$-statistic, where the number of “degrees of freedom”, is $n – 1$.


## The Steps of Conducting a Hypothesis Testing
1. Determine the appropriate ==hypotheses (definitions)==.
2. Select the appropriate testing methods to test the hypotheses.
3. Specify the level of significance for the test ($\alpha$).
4. Use $\alpha$ to develop the rule for rejecting $H_0$.
5. Collect the ==sampled data== and compute the values of the rules.
6. Compare the value(s) in the **rejection rules**, (critical $x$, $t$, or the $p$-value based on the test statistic) and determine whether or not to reject $H_0$ and draw a **conclusion**.


## Three Ways of Hypothesis Testing
### The Rejection Region Method
![](https://i.imgur.com/6sz9HfV.png)
![](https://i.imgur.com/kLv0wPZ.png)
![](https://i.imgur.com/hLOtTS4.png)
![](https://i.imgur.com/gRXXjMq.png)
![](https://i.imgur.com/7ruixeD.png)
![](https://i.imgur.com/1N3fLOQ.png)

### Testing Statistic
![](https://i.imgur.com/mgKvcAw.png)

### $p$-value Method
![](https://i.imgur.com/RSMMpBv.png)
![](https://i.imgur.com/2FUA8JE.png)

### Python Code
![](https://i.imgur.com/CDVREh8.png)


## Required Normality Condition
* The Student t distribution is **robust**, which means that if the population is nonnormal, the results of the t-test and confidence interval estimate are still valid provided that the population is “==not extremely nonnormal==”.
* ==Draw a histogram== of the data and see how “==bell shaped==” the resulting figure is. If a histogram is extremely skewed (say in the case of an exponential distribution), that could be considered “extremely nonnormal” and hence t-statistics would be not be valid in this case.


# Inference About a Population Variance
* To draw inference about population variability, the parameter of interest is $\sigma^2$
* The **sample variance**, $s^2$, is an unbiased, consistent and efficient point estimator for $\sigma^2$.
* The statistic $\frac{(n - 1)s^2}{\sigma^2}$ has a distribution called Chi-squared, if the population is normally distributed.

![](https://i.imgur.com/eujc0hy.png)


## Chi-Square Distribution
### Python Code
![](https://i.imgur.com/PEQOoPj.png)
![](https://i.imgur.com/2TZyMsD.png)


## The $x^2$ Table 
![](https://i.imgur.com/0ZEwBGB.png)


## Finding Critical Value via Python
* What is $𝜒_{0.5,5}^2$?
* Right-tail probability $= 0.5$
* Degree of freedom $= 5$

![](https://i.imgur.com/zOpbPu6.png)


## Hypothesis Testing on Population Variance
![](https://i.imgur.com/V3FuUYj.png)

### Rejection Region of Right-tail Test: $S_C^2$
![](https://i.imgur.com/4xoIRCd.png)

### Rejection region of Left-tail Test: $S_C^2$
![](https://i.imgur.com/q9bh0t0.png)

### Rejection Region of Two-tail Test: $S_U^2$ and $S_L^2$
![](https://i.imgur.com/6wq3MUD.png)


## The Testing Statistic
Instead of using the statistic $S^2$,  we can use the value $\chi^2$ ![](https://i.imgur.com/kcYFg03.png)
* The rejection regions are:
![](https://i.imgur.com/na0fX9X.png)


## $p$-value
The $p$-value of a test is the probability of observing a test statistic at least as extreme as the one computed, given that the null hypothesis is true.
![](https://i.imgur.com/Cfu72UE.png)

### $p$-value in Two-tailed Tests
![](https://i.imgur.com/QwRWTcp.png)

### $p$-value vs. $\alpha$
The rejection rule: ==Reject $H_0$ if $p$-value $\lt \alpha$==


## Degree of Freedom
![](https://i.imgur.com/jTm37wr.png)


## Python Code
![](https://i.imgur.com/9px83YK.png)

### Histogram
![](https://i.imgur.com/Ta0cv6w.png)


## Confidence Interval of Population Variance
![](https://i.imgur.com/A5I4hNW.png)


## Understanding of Statistical Concepts
* The sample variance: $s^2 = \frac{\sum{(x - \bar{x})^2}}{n - 1}$.
* To determine $S^2, \bar{x}$ must be determined first. 
* We lose one degree of freedom because we had to calculate $\bar{x}$.
* The t-statistic like the z-statistic measures the **distance** between ==the sample mean and the hypothesized value== as measured by the size of **standard errors**.
* However, when the population standard deviation is unknown we estimate the standard error via $\frac{s}{\sqrt{n}}$.
* The only variable in the $z$-statistic is the sample mean, which will vary from sample to sample.
* The $t$-statistic has two variables, the sample mean and the sample standard deviation, both of which will vary from sample to sample.
* The $t$-statistic is more widely spread out than the $z$-statistic.
* Because of this feature, the t-statistic will display greater variability.



# Population Total and Finite Populations
## Estimating Totals for Large Populations
* When a population is **large** and **finite** we can estimate the total number of successes in the population by taking the product of the size of the population ($N$) and the confidence interval estimator: ![](https://i.imgur.com/o3rqtPe.png)
* When the population is small (i.e., $\frac{n}{N} \gt 0.5$), we must incorporate the finite population correction factor (FPCF) in the calculation of the standard error of estimate of the mean: ![](https://i.imgur.com/G7C4SFE.png)

The confidence interval becomes: ![](https://i.imgur.com/FLf73GT.png)


## Nielsen Ratings
* Statistical techniques play a vital role in helping ==advertisers== determine ==how many viewers== watch the shows that they sponsor. 
* Although several companies sample television viewers to determine what shows they watch, the best known is the **A. C. Nielsen firm**.
* The Nielsen ratings are based on a random sample of approximately 5,000 of the 115 million households in the United States with at least one television (in 2010). 
* A ==meter attached to the televisions== in the selected households keeps track of when the televisions are turned on and what channels they are tuned to.
* The data are sent to the Nielsen’s computer every night from which Nielsen computes the rating and sponsors can determine the number of viewers and the potential value of any commercials.

### Example
The objective is to estimate the total number of viewers from the proportion of the entire population that watched the “Big Bang Theory.”
#### Technique Identification:
* The parameter to be estimated is the population proportion, from which the total will be estimated (nominal data).
* Because the population is ==larger than 20 times== the sample size we will use the ==large and finite population formula==.

#### Python Code
![](https://i.imgur.com/1eNQAhQ.png)
![](https://i.imgur.com/iqF2wil.png)
![](https://i.imgur.com/BDa5Wqt.png)


## Selecting the Sample Size to Estimate the Proportion
Recall: The confidence interval for the proportion is
![](https://i.imgur.com/rL2rbkC.png)
Thus, to estimate the proportion to within $W$ (half-width), we can write
![](https://i.imgur.com/WAuQpXA.png)
If we fix $W$, then we can compute the required sample size:
![](https://i.imgur.com/5RYJ6Qw.png)

### Plot of $\head{p}$ versus $\head{p}(1 - \head{p})$
![](https://i.imgur.com/YN2NvMq.png)


# Inference About a Population Proportion
* When the population consists of **nominal** data, the only inference we can make is about the **proportion** of occurrence of a certain value.
* The parameter $p$ was used before to calculate these probabilities under the **binomial distribution**.

## Hypotheses about a Population Proportion
$P$ is a population proportion and $p_0$ is the hypothesized value of the population proportion
![](https://i.imgur.com/7ao7a2S.png)


## Statistic and Sampling Distribution of $p$
* The statistic used when making inference about $p$ is:$\head{p} = \frac{x}{n}$ 
    * $x$ is the number of successes 
    * $n$ the sample size
* When $np_0 \gt 5$ and $n(1 – p_0) \gt 5$, the sampling distribution of $\head{p}$ is approximately normal with
![](https://i.imgur.com/C84sElq.png)


## Three Ways of Hypothesis Testing
### The Rejection Region Method
#### Rejection Region: Left-Tail Testing
![](https://i.imgur.com/bdDGi45.png)

#### Rejection Region: Right-Tail Testing
![](https://i.imgur.com/Sub2tC6.png)

#### Rejection Region: Two-Tail Testing
![](https://i.imgur.com/z0zV945.png)

### Testing Statistic
![](https://i.imgur.com/M8wXc8x.png)

Instead of using the statistic $\hat{p}$,  we can use the standardized value $z$.
![](https://i.imgur.com/chfwd7V.png)
where
* $np_0 \gt 5$
* $n(1 - p_0) \gt 5$

### $p$-value Method
The $p$-value of a test is the probability of observing a test statistic at least as extreme as the one computed ($\hat{p}$), given that the null hypothesis is true.
![](https://i.imgur.com/xySnVKU.png)

For two-tailed test, compute the p-value from one side and multiply the value by $2$. 
* If $\hat{p} \gt p_0$, $p$-value = $2⋅𝑃(\hat{P} \gt \hat{p})$
* If  $\hat{p} \lt p_0$, $p$-value = $2⋅𝑃(\hat{P} \gt \hat{p})$


## Estimating the Proportion
Interval estimator for $p$ using $1 - \alpha$ confidence level
![](https://i.imgur.com/oJlvUs5.png)
provided $n\hat{p} \gt 5$ and $n(1 - \hat{p}) \gt 5$


## Wilson Estimator
When applying the confidence interval estimator of a proportion when success is a **relatively rare event**, it is possible to find no successes.  
* The Wilson Estimator: (Smoothing)
![](https://i.imgur.com/182Xfhf.png)



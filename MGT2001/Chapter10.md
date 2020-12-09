###### tags: `MGT2001 Statistics` `Notes`
# Statistics: Chapter 10 Introduction to Estimation
## Where We Are Going
![](https://i.imgur.com/695Sr32.png)

**Statistical inference** is the process by which we acquire information about populations ==from samples==. 
* There are two types of inference: Estimation and Hypotheses testing


## Agenda
* Concepts of Estimation
* Estimating the $\mu$ when $\sigma$ is Known
* Determining the Sample Size
* Interval Estimation of $\mu$ using the sample median


# Concepts of Estimation
* The objective of estimation is to determine the value of a ==population parameter== on the basis of a ==sample statistic==. 
* There are two types of estimators: **Point** Estimator and **Interval** estimator.
    * **Point estimator 點估計**: A point estimator draws inference about a population by estimating the value of an unknown parameter using ==a single value or point==.
    * **Interval estimator 區間估計**: Draws inferences about a population by estimating the value of an unknown parameter using an ==interval==.


## Point Estimator
![](https://i.imgur.com/2yfnn9h.png)


## Interval Estimatior
Draws inferences about a population by estimating the value of an unknown parameter using an interval.
![](https://i.imgur.com/MNm3EeM.png)


## Estimator’s Characteristics
Selecting the right **sample statistic** to estimate a **parameter** value depends on the characteristics of the statistic.

Desirable characteristics: ==Unbiasedness, Consistency, and Relative efficiency==. 
### Unbiasedness 無偏性
If the **expected value** of the sample statistic is equal to the population **parameter** being estimated, the sample statistic is said to be an **unbiased** estimator of the population parameter. 雖然==每次抽樣所抽取出的樣本不同==，可能會算出不同的統計量，但是這個統計量的==期望值應當等於我們所要估計的母體參數==。而這樣子的性質，即是無偏性 (unbiasedness) 也相當於準確度 (accuracy)。
![](https://i.imgur.com/caGryD2.png)

### Consistency 一致性
在抽出的樣本趨近無限多的情況下，估計值等於母體參數真值的機率應該要等於一，因為當樣本數趨近無限大時，可預期能夠抽出所有母體，因此估計值應當與母體參數真值相等。此性質即為一致性。
* A point estimator is consistent if the values of the point estimator tend to become ==closer to== the population parameter as the sample size becomes larger.
* An estimator is said to be **consistent** if the difference between the estimator and the parameter grows smaller as the sample size grows ==larger==.
* A biased estimator can be consistent

### Efficiency 效率性
**Efficiencies** are often defined using the ==variance or mean square error== as the measure of statistics and are used in the comparison of various statistical procedures and, in particular, it refers to a measure of the optimality of an estimator. 每次估計時，根據抽取的樣本不同，估計出來的結果會不相同，因此我們希望每次估計時所得到的估計量都不要相差太遠，才能確保不會有相差太遠的極端值產生。也就是說估計值的變異數越小越好。變異數較小的估計值，即是較具有效性 (efficiency) 的估計值。有效性也相當於精密度 (precision)。

#### Relative Efficiency
If there are ==two or more unbiased estimators== of a parameter, the one whose variance (standard deviation) is smaller is said to be relatively efficient.


## Probability Statements About the Sampling Error
Knowledge of the sampling distribution of $\bar{x}$ enables us to make probability statements about the sampling error even though the population mean $\mu$ is not known. 	


# Estimating the $\mu$ when $\sigma$ is Known
## Confidence Level and Confidence Interval
Each interval is constructed with regard to a given **confidence level** which states how much confidence we have that this interval ==covers the true population parameter==.   
The **confidence level** is denoted by $(1 – \alpha) 100\%$. In particular, $(1 – \alpha)$ is called the **confidence coefficient** and $\alpha$ is called the ==significance (or risk)== level.


## Notations
![](https://i.imgur.com/NId6Gza.png)


## Estimating the $\mu$ when $\sigma$ is Known
How is an interval estimator produced from a sampling distribution?
* A sample of size $n (\ge 30)$ is drawn from the population, and its mean, $\bar{X}$, is calculated.
* By the Central Limit Theorem, $\bar{X}$ is normally distributed (or approximately normally distributed.)  

![](https://i.imgur.com/l2ezhW2.png)

![](https://i.imgur.com/3TNqlr6.png)


## Interpreting the Confidence Interval for $\mu$
Given a sample, compute $\bar{X}$ and construct an interval
![](https://i.imgur.com/NlQRnG4.png)
There will be a $(1 − \alpha)$ chance that this interval includes (covers) the population mean, $\mu$.


## Probability Statement
There is a $1 - \alpha$ probability that the value of a sample mean will provide a sampling error of $z_{\frac{\alpha}{2}}\sigma_{\bar{x}}$ or less.
![](https://i.imgur.com/NbvXf1S.png)


## LCL and UCL
![](https://i.imgur.com/lFdQCVz.png)


## Interpreting the Interval Estimate
* It is **wrong** to state that the  interval estimator is an interval for which there is $1 – \alpha$ chance that the population mean lies between the LCL and the UCL.
* This is so because the $\mu$ is a parameter, not a random variable. 
* The correct interpretation is that there is a $1 − \alpha$ chance that the interval [LCL, UCL] covers the population mean


## Factors Affect C.I.
![](https://i.imgur.com/A8Z84ZF.png)


## Summary Mean Confidence Interval
![](https://i.imgur.com/a85hNWL.png)


# Determining the Sample Size
## From C.I. to Sample Size
* We can control ==the width of the confidence interval== by changing the sample size.
* Thus, we determine the ==interval width first==, and derive the required sample size.
* The phrase “==estimate the mean to within $w$ units==”, translates to an interval estimate of the form

![](https://i.imgur.com/etvVuba.png)

### Your Turn
To estimate the amount of lumber that can be harvested in a tract of land, the mean diameter of trees in the tract must be estimated to within one inch with a $99\%$ confidence level. 
* What sample size should be taken? (Assume diameters of trees are normally distributed with $\sigma = 6$ inches.)

```python=
w = 1
alpha = 0.01
sigma = 6
z = stats.norm.ppf(1 - alpha/2)
n = z * z * sigma * sigma / w / w
```


# Interval Estimation of $\mu$ using the sample median
## Estimation of $\mu$ Using the Sample Median
* The properties of the sampling distribution of the sample median (denoted as $m$)
* The sampling distribution of $m$ is normal when the population is normal
    * $E[m] = \mu_m = \mu$
    * $\sigma_m = \frac{1.2533 \sigma}{\sqrt{n}}$


## Estimating the \mu when \sigma is Known
How is an interval estimator of population mean produced from a sampling distribution?
* A sample of size $n$ is drawn from the population, and its median, $m$, is calculated.

![](https://i.imgur.com/1RBJVaT.png)
Using consistent notations:
* $m$ = the sample median
* $1 – \alpha$ = the confidence coefficient
* $z_{\frac{\alpha}{2}}$ = the $z$ value providing an area of $\frac{\alpha}{2}$ in the upper tail of the standard normal probability distribution
* $\sigma$ = the population standard deviation
* $n$ = the sample size


## Interpreting the Confidence Interval
$1 – \alpha$  of all the values of $m$ obtained in repeated sampling from a given distribution, construct an interval  
![](https://i.imgur.com/Icw2AMS.png)
that includes (covers) the expected value of the population.

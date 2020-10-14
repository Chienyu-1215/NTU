###### tags: `MGT2001 Statistics` `Notes`
# Statistics: Chapter 4 Numerical Descriptive Techniques
## Purpose of Using Numerical Descriptive Techniques
Usually, we focus our attention on several types of measures when describing population or sample characteristics such as **Central Location** (e.g. Average) and **Variability or Spread**.


## Numerical Descriptive Techniques
* For one variable:
    * Central Location
    * Variability
    * Relative Standing
* For two variables: Relationship between two variables 
    * Mostly for **interval data** type.


## Agenda
* Measures of Central Location
* Measures of Variability
* Measures of Relative Standing
* Measures of Linear Relationship


# Measures of Central Location
The central data point reflects the gravity center (the core, the focus, the key point) of all the actual data points.
* Arithmetic Mean 算術平均數
    * Mean(Python), Average(Excel)
* Median 中位數
* Mode (Modal Class) 高峰 眾數
* Geometric Mean 幾何平均數
## Arithmetic Mean
* Average or Expected Value
* For **interval** data type -> hard to get a direct value, usually use classes to collect data from testees. 
* This is seriously affected by **extreme values**

### Mathematical Representation
$Mean = \frac{\text{Sum of the measurements}}{\text{Number of measurements}}$
#### $\text{Sample Mean}$
$\bar{X} = \frac{\sum_{i = 1}^n {x_i}}{n\text{ (Sample Size)}}$
#### $\text{Population Mean}$
$\mu = \frac{\sum_{i = 1}^N{x_i}}{N\text{ (Population Size)}}$

### Example
#### #1
The mean of the sample of six measurements 
$7, 3, 9, -2, 4, 6$ is given by $$\bar{x} = \frac{\sum_{i = 1}^6 {x_i}}{6} = \frac{7 + 3 + 9 + (-2) + 4 + 6}{6} = 4.5$$
#### #2
Suppose the telephone bills represent population of measurements. The population mean is
![](https://i.imgur.com/KB8wP0u.png)


## Median
* The value that falls in the **middle** when the measurements are arranged in **order** of magnitude.
* Different in computing the median between **odd** and **even** numbers of observations.
* For *interval* or *ordinal* data types.

### Example
#### #1
Seven employee salaries were recorded (in 1000s): $28, 60, 26, 32, 30, 26, 29$. Find the median.
* Sort the salaries.
* Locate the value in the middle $= 29$
* $\bar{X} = 33$
#### #2
Suppose one employee’s salary of $$31,000$ was added to the group recorded before. Find the median.
* $\frac{(29 + 30)}{2} = 29.5$
* $\bar{X} = 32.75$


## Mode(Modal Class)
* The value that occurs **most frequently**.
* **Set of data** may have one mode (or modal class, unimodal), or two or more modes (bimodal or multi-modal).
* For *all data types*

### Example
#### #1
* The manager of a men’s store observes the waist size (in inches) of trousers sold yesterday: $31, 34, 36, 33, 28, 34, 30, 34, 32, 40$.
* The mode of this data set is **$34$ in**. 
#### #2
* Find the mode for the following data set: $0, 7, 12, 5, 33, 14, 8, 0, 9, 22$.
* All observation except “$0$” occur once. There are two “$0$”.  Thus, the mode is zero.
##### Question
* Is “mode” a good measure of central location? Show a bell shape histogram which is good to analysis. 
* The value “$0$” does not reside at the center of this set (compare with the mean = $11.0$ and the median = $8.5$).
![](https://i.imgur.com/asOybI7.png)
For large data sets the modal class is much more relevant than the a single-value mode.


## Relationship among Mean, Median, and Mode
If a distribution is **symmetrical and unimodal**, the mean, median and modal class **coincide**.

### Positively Skewed
$Mean \ge Median \ge Modal\space Class$

### Negatively Skewed
$Mean \le Median \le Modal\space Class$

![](https://i.imgur.com/IBF3Fnk.png)

### Example
![](https://i.imgur.com/cA1WAiN.png) ![](https://i.imgur.com/jwD9JY0.png)


## Geometric Mean
This is a measure of the average growth rate, or rate of change (such as the value of an investment), in a variable over time. 
### Example
Suppose you make a 2-year  investment of $1000, and it grows by 100% to $2000 during the first year. During the second year, however, the investment declines by 50% from $2000 back to $1000. $$\Rightarrow \frac{[100\%+(-50\%)]}{2} = 25\% $$
* 25% is arithmetic mean return and is misleading.
* There was no change in the value of the investment at the end of the two periods. The **average compounded return** over the two periods was actually 0%.

### Mathematical Representation
Let $R_i$ denote the the rate of return in period $i (i=1,2…,n)$. The geometric mean of the returns $R_1, R_2, …, R_n$ is the constant $R_g$ that produces the same terminal wealth at the end of period $n$ as do the actual returns for the $n$ periods.
![](https://i.imgur.com/fs7hAee.png)

### Example
A firm’s sales were $1000000 three years ago. Sales have grown annually by 20%, 10%, -5%. 
(1) Find the geometric mean rate of growth in sales.
(2) Find the sales at the end of last year
1. Since $R_g$ is the geometric mean 
$(1 + R_g)^3=(1+.2)(1+.1)(1-.05)= 1.2540$
![](https://i.imgur.com/SiBF4uO.png)
2. The sales at the end of last year
$1,000,000 \times (1 + R_g)^3 = 1,000,000 \times (1 + 7.84\%)3 =  1,254,000$
![](https://i.imgur.com/xAVeDGv.png)


# Measures of Variability
* Range
* Variance 
* Standard Deviation
* Coefficient of Variation

## Reason for Measures of Variability
* Look beyond the Average
* Measures of Central Location fail to tell the whole story about the distribution.

### Why Variability?
A question of interest still remains unanswered:
* How *typical* is the average value of all the measurements in the data set?
* How much *spread out* are the measurements about the average value?

![](https://i.imgur.com/4k94TE0.png)
* Sample A - Low variability data set: The average value provides a good representation of the values in the data set.
* Sample C - High variability data set: The same average value does not provide as good presentation of the values in the data set as before.


## Range 全距
* The difference between the largest and smallest measurements or observations.
* Tell us how far the data spread out.

### Example
Seven employee salaries were recorded (in 1000s): 28, 60, 26, 32, 30, 26, 29. Find the range.
* Identify the smallest and largest observations. 
* Compute range $= 60 - 26 = 34$
#### But, how do all the measurements spread out?
The range cannot assist in answering this question

### The Usage of Range
* Its major **advantage** is **the ease** with which it can be computed.
* Its major shortcoming is its failure to provide information on **the dispersion** of the values between the two end points.


## Variance
* One of the most widely accepted measures of the variability of a set of **quantitative** data.
* Observe the difference between **each value** and the mean.
* This measure of dispersion reflects the values of all the measurements.

### Large vs. Small Variations
Consider two small populations:
Population A: $8, 9, 10, 11, 12$
Population B: $4, 7, 10, 13, 16$
#### Why Not Just Sum?
The sum of deviations is zero in both cases, therefore, another measure is needed.
#### Squared Sum
The sum of squared deviations is used in calculating the variance.
#### Why Average of Squared Deviation?
Why not use the sum of squared deviations as a measure of dispersion instead?
After all, the sum of squared deviations increases in magnitude when the dispersion of a data set increases!!

### The Population Variance
The variance of a population of $N$ measurements $x_1, x_2,…,x_N$ having a mean $\mu$ is defined as $$\sigma^2 = \frac{\sum_{i = 1}^N (x_i - \mu)^2}{N}$$

### The Sample Variance
The variance of a sample of $n$ measurements $x_1, x_2, …,x_n$ having a mean $\bar{X}$ is defined as
$S^2 = \frac{\sum_{i = 1}^n {(x_i - \bar{X})^2}}{n - 1 \mbox{ (Degree of freedom)}}$


## Standart Deviation
### Why Standard Deviation
* Variance: squaring the original observations => Square the unit
    e.g., variance of minutes => minute squared, variance of dollars => dollar squared
* Goal: the measure of variability is expressed in the same unit as the original observations

### Computation of Standard Deviation
The standard deviation of a set of measurements is the square root of the variance of the measurements.
![](https://i.imgur.com/FdLAjee.png)

### Usage of Standard Deviation
* Compare the **variability** of several distributions
* Make a statement about the **general shape** of a distribution.

### The Empirical Rule
#### Bell-Shaped
If a sample of measurements has a mound-shaped (bell-shaped) distribution, the interval
* $(\bar{X} - S, \bar{X} + S)$ contains approximately 68% of the measurements
    * Approximately 68% of all observations fall within one standard deviation of the mean.
    * ![](https://i.imgur.com/WDE6czw.png)
* $(\bar{X} - 2S, \bar{X} + 2S)$ contains approximately 95% of the measurements
    * Approximately 95% of all observations fall within two standard deviations of the mean.
    * ![](https://i.imgur.com/xTFP5WS.png)
* $(\bar{X} - 3S, \bar{X} + 3S)$ contains approximately 99.7%(virtually all) of the measurements
    * Approximately 99.7% of all observations fall within three standard deviations of the mean.
    * ![](https://i.imgur.com/ka9dSJ7.png)


### The Chebyshev Theorem
Given any set of measurements and a number $k$ (not smaller than $1$), the fraction of these measurements that lie within $k$ standard deviations around the mean is at least $1 - \frac{1}{k^2}$
This theorem is valid for any set of measurements (sample, population) of any shape.
|$k$ | Interval | Chebyshev | Empirical Rule|
|----|----------|-----------| --------------|
|1|$(\bar{X} - S, \bar{X} + S)$|at least 0%|approximately 68%|
|2|$(\bar{X} - 2S, \bar{X} + 2S)$|at least 75%|approximately 95%|
|3|$(\bar{X} - 3S, \bar{X} + 3S)$|at least 89%|approximately 99.7%|


## Coefficient of Variation
* The standard deviation divided by the mean value. (**Mean** is used as the **base value**.)
* This coefficient provides a **proportionate measure** of **variation**.
#### Sample:
$cv = \frac{S}{\bar{X}}$
#### Population
$CV = \frac{\sigma}{\mu}$
### The Break Even Point
* If average returns are fixed, $$S_A = (\frac{\bar{X_A}}{\bar{X_B})S_B$$
* If standard deviations are fixed, $$\bar{X_A} = (\frac{X_A}{X_B})\bar{X_B}$$


# Measures of Relative Standing
## Measures of Relative Standing and Box Plots
Describe **another aspect** of the shape of the distribution of data, and provide information about the **relative standing** of particular observations. 
### Example: GMAT
GMAT (Graduate Management Admission Test) is one of the requirements to enter an M.B.A. program. The score range from $200$(*Base Score for attending*) to $80$ with mean = $460$.
Suppose your score is $600$. 
How well is your standing? Determine by the testee's score among all the attendents. 


## $p-\text{th}$ Percentile
* At most $p\%$ of the measurements are **less than** that value
* At most $100(1-p)\%$ of all the measurements are **greater than** that value.
*Suppose $600$ is the $78%$ percentile of a GMAT score. Then:* 
![](https://i.imgur.com/aR2qRpS.png)

### Location of Percentiles
Find the location of any percentile using the formula $$L_p = (n + 1) \frac{p}{100}$$ where $L_p$ is the location of the $p^\text{th}$ percentile and $n$ is the sample size.
#### $25^\text{th}$ Percentiles
After sorting the data, we have $0, 0, 5, 7, 8, 9, 12, 14, 22, 33$.
$L_{25} = (10 + 1) \frac{25}{10} = 2.75$
The $2.75^\text{th}$ location: Translates to the value $(.75)(5 – 0) = 3.75$ *Linear Interpolation*
#### $50^\text{th}$ Percentiles
$L_{50} = (10 + 1) \frac{50}{10} = 5.5$
The $50^\text{th}$ percentile is halfway between the fifth and sixth observations, $8$ and $9$.
In the middle between $8$ and $9$, that is $8.5$.
#### $75^\text{th}$ Percentiles
$L_{75} = (10 + 1) \frac{75}{10} = 8.25$
The $75^\text{th}$ percentile is one quarter of the distance between the eighth and ninth observation, $14$ and $22$ $\Rightarrow 14 + .25(22 – 14) = 16$. 

### Find the $p$ Percentile
Find the percentile $(p)$ of any number when the location $(L_p)$ is known $$L_p = (n + 1) \frac{p}{100} \Rightarrow p = L_p \times \frac{100}{n + 1}$$
where $L_p$ is the location of the pth percentile and $n$ is the sample size. 

### Commonly Used Percentiles
* First (lower) decile $= 10^\text{th}$ percentile
* First (lower) quartile, $Q_1 = 25^\text{th}$ percentile
* Second (middle) quartile, $Q_2 = 50^\text{th}$ percentile (median)
* Third quartile, $Q_3=75^\text{th}$ percentile
* Ninth (upper) decile $= 90^\text{th}$ percentile


## Quartiles
* Measure of Noncentral Tendency
* Split Ordered Data into 4 Quarters

### Quartiles and Variability
Quartiles can provide an idea about the shape of a histogram
![](https://i.imgur.com/xZRvTUz.png)

### Inter-Quartile Range (IQR, 間距範圍, 四分位距)
* This is a measure of the spread of the middle 50% of the observations
* Large value indicates a large spread of the observations
**Inter-Quartile Range  $= Q_3 – Q_1$**


## Box ( & Whisker) Plot
This is a **pictorial display** that provides the main descriptive measures of the data set.
### Notations
* $L$  - the largest observation
* $Q3$ - The upper quartile 
* $Q_2$ - The median
* $Q_1$ - The lower quartile
* $S$ -  The smallest observation
* $IQR$ = $Q_3 – Q_1$

![](https://i.imgur.com/HlEnUqY.png)

### Outliers 離散值
* An **unusually large** or **small** value in a sample.
* Its validity is suspected and some investigation is needed.
* Be removed from the main body of a sample.

#### Define Outliers
* Compute Inter-Quartile range: $IQR = Q_3 – Q_1$ 
* Compute lower fence: $Q_1–1.5IQR$
* Compute upper fence: $Q_3+1.5IQR$
* Any observations **drop out** of the fence is outliers.
![](https://i.imgur.com/RNBRCY6.png)


## More Measures from Quartiles
### Midrange
* Middle of Smallest & Largest Observation 
* Affected by Extreme Values

**Midrange** $= \frac{x_{smallest} + x_{largest}}{2}$

### Midhinge
* Middle of 1st & 3rd Quartiles
* Not Affected by Extreme Values

**Midhinge** $= \frac{Q_1 + Q_3}{2}$

### Comparison
* Mean $= 13.47$
* Median ($Q_2$) $= 12$
* Midrange $= 16$ 
* Midhinge $= 13$

**Long right tail distribution = Positively Skewed**


# Shape
* Describes how data are distributed
* Measures of shape
    * Skewness (Symmetry)
    * Kurtosis 峰度

## Measure of Movement 動差
* $m_1$ : 1st moment $\sum{\frac{x}{n}}$ ~ mean or $\bar{x}$
* $m_2$ : 2nd moment $\sum{\frac{(x - \bar{x})^2}{n}}$ ~ Variance(**Population only**).
* $m_3$ : 3rd moment $\sum{\frac{(x - \bar{x})^3}{n}}$ 正負會抵消
* $m_4$ : 4th moment $\sum{\frac{(x - \bar{x})^4}{n}}$


## Coefficient of Skewness 
A measure of a data set’s deviation from symmetry. $$g_1 = \frac{m_3}{\sqrt{m_2^3}} \\  \left\{\begin{array}{} g_1 \gt 0: \text{Skewed to right} \\ g_1 = 0: \text{Symmetric} \\ g_1 \lt 0: \text{Skewed to left} \end{array}\right.$$

### Excel
A measure of a data set’s deviation from symmetry $$g_2 = \frac{\sqrt{n(n - 1)}}{(n - 2)} \frac{m_3}{\sqrt{m_2^3}}\\  \left\{\begin{array}{} g_2 \gt 0: \text{Skewed to right} \\ g_2 = 0: \text{Symmetric} \\ g_2 \lt 0: \text{Skewed to left} \end{array}\right.$$

$g_1 = \frac{(n - 2)}{\sqrt{n(n - 1)}} g_2$


## Coefficient of Kurtosis 
A measure of a data set’s height. $$K = \frac{m_4}{\sqrt{m_2^4}} \\  \left\{\begin{array}{} K \gt 3: \text{Leptokurtic (Narrow-tall)} \\ K = 3: \text{Mesokurtic (Regular)} \\ K \lt 3: \text{Platykurtic (Wide-low)} \end{array}\right.$$

### Excel
A measure of a data set’s height. $$K_2 = \frac{(n - 1)}{(n - 2)(n - 3)}((n + 1)K -3(n - 1)) \\  \left\{\begin{array}{} K \gt 0: \text{Leptokurtic (Narrow-tall)} \\ K = 0: \text{Mesokurtic (Regular)} \\ K \lt 0: \text{Platykurtic (Wide-low)} \end{array}\right.$$

$K = (\frac{(n - 2)(n - 3)K_2}{(n + 1)(n - 1)} + \frac{3(n - 1)}{(n + 1)})$


## Numerical Data Properties & Measures
![](https://i.imgur.com/LZruyjW.png)


# Measures of Linear Relationship
Provide information as to the **strength & direction** of a linear  relationship between two variables (if one exists).


## Measures of Association
* Covariance: is there any pattern to the way two variables move together? 
* Coefficient of Correlation : how strong is the linear relationship between two variables


## The Covariance
Population Covariance $= \sigma_{xy} = COV(X,Y) = \frac{\sum(x_u - \mu_x)(y_i - \mu_y)}{N}$

*$\mu_x (\mu_y)$ is the population mean of the variable $X(Y)$ and $N$ is the population size.*

Sample Covariance $= S_{xy} = cov(X,Y) = \frac{\sum(x_u - \bar{x})(y_i - \bar{y})}{n - 1}$

*$n$ is the sample size.*

### Interpretation
* If the two variables **move the same direction**, (both increase or both decrease), the covariance is a **large positive** number.
* If the two variables move in **two opposite directions**, (one increases when the other one decreases), the covariance is a **large negative** number.
* If the two variables are **unrelated**, the covariance will be **close to zero**.


## The Coefficient of Correlation
* Population: $\rho = \frac{\sigma_{xy}}{\sigma_x \sigma_y}$
* Sample: $r = \frac{S_xy}{S_x S_y}$

### The Value of $\rho(r)$
![](https://i.imgur.com/6tg9ihY.png)

### Linear Relationship
* $|r| \lt 0.25$ : very weak
* $0.25 \le |r| \lt 0.5$: moderately weak
* $0.5 \le |r| \lt 0.75$: moderately strong
* $0.75 \le |r| \lt 1$: very strong
* Positive or Negative linear relation

![](https://i.imgur.com/SGYtUaf.png)


## Approximating Descriptive Measures for Grouped Data
Needed in two cases:
* when approximated values suffices the needs,
* when only secondary grouped data are available.

$\bar{x} = \frac{\sum^k_{i = 1} {f_i m_i}}{n}$
$s^2 = \frac{1}{n - 1} [\sum^k_{i = 1}{f_i m_i^2} - \frac{(\sum^k_{i = 1} {f_i m_i})^2}{n}]$

* $f_im_i$ is approx.equal to the number of measurements in class $i$ 
* $m_i$ is the midpoint of class
* $n = f_1 + f_2 + … + f_k$
* $k$ is the number of classes
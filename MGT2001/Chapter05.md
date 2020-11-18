###### tags: `MGT2001 Statistics` `Notes`
# Statistics: Chapter 5 Data Collection and Sampling
## Key Statistical Concepts
![](https://i.imgur.com/XLTX5tS.png)
Populations have **Parameters 參數**, Samples have **Statistics 統計量**.


## Descriptive Statistics 敘述統計
Methods of ==organizing, summarizing, and presenting data== in a convenient and informative way.
![](https://i.imgur.com/HPETZVz.png)


## Inferential Statistics 
A body of methods used to draw conclusions or inferences about the **characteristics** (numeric) of **populations** based on sample data.  
==Hypothesis testing in the most common cases.==
![](https://i.imgur.com/qQqmw0O.png)


## Predictive Analytics 假設檢定
* More about **prediction** instead of hypothesis testing. 
* To performance hypothesis testing, we often ==require the statistics to be **unbiased**.== (will discuss in Ch 9). 
* When repeated many times, the averaged value of the statistics is very close to the true population parameter. 
* We can use an unbiased statistics to do prediction. 
* ==However, we can do better if we allow the statistics to be biased.== 
* The main intuition is that we are learning from limited data points. 
* A biased model is often more robust to the noise in data, and can produce better predictions. 
* We will not pursue this line of reasoning in this course.


## Definition
### Variable
**Characteristics** of population or sample that is of interest for us.  
Typically denoted with a **capital** letter: $X, Y, Z…$
### Value
The **values** of the variable are the range of possible values for a variable. 
### Data
The **observed values** of a variable $(x_1, x_2, …)$


## Data Visualization
For **one** Variable, $X$ (or $Y$): Histogram, Ogive, or Stem-and-Leaf Display, and Measures of Central Location, Variability, Relative Standing, or Shape
For **two** Variables, $X$ and $Y$: Scatter Diagram


## Agenda
* Steps to Conduct a Study
* Sampling Design
* Probabilistic Sampling Method
* Sampling Errors and Non-sampling Errors


# Steps to Conduct a Study
## Conducting a Study: The Issue, Known facts, and New Knowledge
![](https://i.imgur.com/TvKmTqF.png)
從已知資料推得我們所欲知道之事。


## Typical Data Sources
Three of the most popular sources of statistical data are:
* Published data
* Observational study 觀察性研究
* Experimental study 實驗性研究
### Published Data
This is often a **preferred source** of data due to ==low cost and convenience==.  
Published data is found as printed material, tapes, disks, and on the Internet.
Data published by the organization that has collected it is called **PRIMARY DATA**.

### Secondary Data Source 二手資料
Data published by an organization **different** than the organization that has collected it is called **SECONDARY DATA**.

### Observational Study
* The measurements represent a variable of interest are observed and recorded, ==without controlling any factor that might influence their values==.
* **Passive 被動** listening devices, ==no interference== to the respondents. 對象不能被影響

### Simple Observation vs. Surveys
#### Simple Observation
* Technology greatly reduces the cost of simple observation
* Often is about **real time** status, not just about the past
#### Survey
Survey solicits information from people.  
Can be made by means of 
* personal interview
* telephone interview
* self-administered questionnaire
***
* During a **brief** interval of time and **cross-sectional** in focus
* A relative **large** number of elements are collected
* Many measurements are made on **each** sample element
* A **complicated** process (must be carefully managed)
* Usually generate **large** data bases
* Keep the questionnaire ==as short as possible==
* Ask ==short, simple, and clearly worde== questions
* Start with ==demographic questions== to help respondents get started comfortably

### A Good Questionnaire Must Be Well Designed
* Use **dichotomous** questions with only two possible responses, “yes” or “no”, and multiple choice questions
* Use open-ended questions **cautiously** 
* Avoid using **leading-questions**
    * **Leading-questions 引導式問題** - 題問時暗示價值觀或回答的方向
* It is useful to ==pretest a questionnaire==.
* Think about **the way** you intend to use the collected data when preparing the questionnaire. 

### Experimental Study 實驗性研究
The measurements representing a variable of interest are observed and recorded, while **controlling factors 控制變因** that might influence their values.
* **Active listening** devices.


## Steps of Conducting a Study
1. Determine the **purpose** and **data requirement** (time period, the method of data collection, and longitudinal context of the resulting data)
2. Determine **source of data** (published, observational, or experimental).
3. Determine the ==data analysis approaches==
    * Understanding the methods
    * Familiarity with statistical tools and methods.
4. Construct ==questionnaire, data sheet and files==, or conduct ==experiments==. 建構問卷、實驗
5. Train Personnel
    * The **mechanics** of filling out a data sheet
    * **Interviewing** a respondent
    * The importance of the **data elements**.
    * The practice with the data-collection procedure and tools.
6. Collect the data. 蒐集資料
7. **Error Control** and Audit
    * Quality Control at each step.
    * **Auditing** a long-term data collection project.
8. **Document** the work
    * Dates and Names
    * Covering memorandum
    * A full research report


# Sampling Design
## Why Sampling?
Motivations for conducting a sampling procedure:
* Costs
* Population size


## Population
* The **sample population**: the actual population from which the sample has been taken
* The **target population**: the population about which we want to draw ==inferences on==
Two should be the same or similar to one another.


## Sampling Design
* **Nonprobabilistic**: Each individual in the population has an **unequal possibility** of entering the sample, e.g., Convenience or Judgement
* 
* **Probabilistic 機率導向**: Each individual has a **equal** and **known probability** of entering the sample


## Convenience Sampling
Items are included in the sample ==without known probabilities of being selected==. The sample is identified primarily by **convenience**.
<font color = "Green">**Advantage**</font>: Sample selection and data collection are relatively easy.  
<font color = "Red">**Disadvantage**</font>: It is impossible to determine how representative of the population the sample is.  


## Judgment Sampling
The person who is ==most knowledgeable== on the subject of the study selects elements of the population that he or she feels are most representative of the population. 
<font color = "Green">**Advantage**</font>: It is a relatively easy way of selecting a sample.  
<font color = "Red">**Disadvantage**</font>: The quality of the sample results ==depends on the judgment of the person== selecting the sample.
 
 
## Considerations of Choosing a Sampling Design
* Cost
* Accuracy 準確性
* Time
* Acceptance of results
* Generality of results


# Probabilistic Sampling Method
## Simple Random Sampling
A sample taken so that each possible sample of size n of a population of size $N$ has the same chance $(\frac{n}{N})$ of being selected.
* Simple random sample without replacement (SRSWOR; 抽出不放回). <font color = "Red">This is our main focus!</font>
* Alternatively, one can do simple random sample with **replacement** (SRSWR; 抽出放回)
* 
### Sample Frame
A list of elements of the population will be sampled.
* Selecting a sample of 30 applicants, using ==a random number table 亂數表==
* Selecting a sample of 30 applicants, using ==computer-generated random numbers==

### Random Sampling via RNT
![](https://i.imgur.com/20ufHvM.jpg)
<font color = "LightSkyBlue">**Preparation**</font>: Assign a number to each element in the population. 
1. Pick **any starting point**.
2. Generate a number $m$, $1 \le m \le N$.
3. If $m$ is in the frame list and has not been selected before, then draw element from list. Else, ignore.

### Random Sampling via Python
* Python generate random numbers using the Pseudorandom number generator
* <a href = "https://zh.wikipedia.org/wiki/%E6%A2%85%E6%A3%AE%E6%97%8B%E8%BD%AC%E7%AE%97%E6%B3%95">Mersenne Twister Algorithm</a>
* The pseudo random numbers sequence depends on <font color = "Red">a seed</font> (a positive integer).
* The same seed gives you the same sequence of pseudo random numbers.
```python=
random.seed(1225): set the random number
random.random(): draw random number in [0, 1)
```
* We often set the random seed to ==something that does not repeat easily== in order to generate high quality pseudo random numbers.
* We often set the random seed to ==a fixed number for debugging purpose==. 
***
* The built-in library `<random>`provides the basic function to generate random numbers and shuffle elements in a list. 
* `random.seed()` is the function to ==set the random seed==.
* However, the random seed may **not apply** to other libraries that involves random number generation. 
* One example is the pytorch library does not honor the random seed set by `random.seed()``.
* The reason is obvious: **pytorch** use its o==wn random library==. 
* When using a new library involving random number, always check how to set the random seed. 
#### Some Useful Sampling Function
* `random.sample()`: Random sample ==without replacement==
* `random.choices()`: Random sample ==with replacement==
* `random.shuffle()`: Random Permutation

### Population vs. Simple Random Sample
An important goal of simple random sample is to estimate the population parameters.
* Population mean: $\bar Y = \frac{1}{N} \sum_{k = 1}^N{Y_i}$. ($N$ is population size; $Y_k$: the value of the target value of element $k$)
* Population variance: $\sigma_y^2 = \frac{1}{N}\sum_{k = 1}^N{(Y_k - \bar{Y})^2}$ .
* Adjusted population variance: $S_y^2 = \frac{N}{N - 1} \sigma_y^2 = \frac{1}{N - 1} \sum_{k = 1}^N{(Y_k - \bar{Y})^2}$  
Simple random sample draws 𝑛 elements from the population. Use $𝑦_1, 𝑦_2, …, 𝑦_𝑘$ to denote these sampled elements. 
* Sample mean: $\bar{y_s} = \frac{1}{n} \sum^n_{k = 1}{y_k}$.
* Sample variance: $s_y^2 = \frac{1}{n - 1} \sum_{k = 1}^n{(y_k - \bar{y_s})^2}$ . 

### Unbiasedness of SRS
![](https://i.imgur.com/Vom3Hdw.png)


## Stratified Random Sampling
This sampling procedure separates the population into ==mutually exclusive sets (strata as homogeneous groups)==, and then draw simple random samples from each stratum.
### Way of Stratifying
There are different ways to build a stratified sample. For example, keep the proportion of each stratum in the population.

### Properties of Stratification
1. A **natural strategy** in the study of groups and 
2. A helpful statistical device for **controlling variation**. 

### Procedure
1. Construct the **frame**.
2. Identify the group for stratification and sort the frame based on it.
3. Draw random samples of pre-determined size on each stratum separately. 

### Stratified Sampling in Pandas
*Note* example below sample the same number of data points from each group.   
When doing stratified sampling, the size of each stratum is **usually** proportional to its population size.
```python=
dataframe.groupby("Columns").sample(n = 3, replace = True)
```


## Cluster Sampling
The population is first ==divided into separate groups== of elements called **clusters**.
* A simple random sample of clusters is then taken.
* **All** elements within each sampled (chosen) cluster form the sample.
* Ideally, each cluster is a representative **small-scale** version of the population (i.e. heterogeneous group).
* The close **proximity** of elements can be **cost effective** (i.e. many sample observations can be obtained in a short time).


## Systematic Sampling
If a sample size of $n$ is desired from a population containing $N$ elements, sample **one** element for **every** $\frac{N}{n}$ elements in the population.  
This method has the properties of a simple random sample if the list of the population elements is in a **random order**.
<font color = "Green">**Advantage**</font>: The sample usually will be easier to identify than it would be if simple random sampling were used.

# Sampling Errors and Non-sampling Errors
## Errors Involved in Sampling
Two major types of errors can rise when a sampling procedure is performed.
* Sampling Error
* Non-sampling Error


## Sampling Error
* Refers to differences between the **sample** and the **population**, because of the specific observations that happen to be selected (**random sampling**).
* Sampling error is ==expected to== occur when making a statement about the population based on the sample taken.
* The ==absolute difference== between an unbiased point estimate and the corresponding population parameter 
* It is the result of using a subset of the population (the sample), and not the entire population to develop estimates.

### Note
* Different random numbers would have identified a different sample which would have resulted in different point estimates.
* **Increasing sample size** will **reduce** the sampling errors.
* Discussing sampling error based on one sampling results may be unreliable and misleading. 
* Better look at the ==averaged sampling errors== from multiple sampling results.


## Summarizing Sampling Errors
Assume that we repeated an sampling method for $n$ times, and have records $n$ sampling errors, $𝑒_1, 𝑒_2, …, 𝑒_𝑛, 𝑒_𝑖=𝑒𝑠𝑡_𝑖−𝑡𝑟𝑢𝑒_𝑖$ (estimated value – true value)  
Two ways to summarize these errors:
* **Mean absolute error (MAE)**
* **Root Mean Squared Error (RMSE)**
![](https://i.imgur.com/KA5LsJV.png)

### MAE vs. RMSE
* If there is only one error value, then RMSE = MAE
* RMSE is ==more sensitive to outliers== because the errors were first squared.
    * MAE, on the other hand, does not have this issue. 
* The other way to look at the problem is to think about RMSE and MAE as an optimization criterion. 

*Given n estimated values, $𝑦_1, 𝑦_2, …, 𝑦_𝑛$. What is the point that minimize RMSE (or MAE)?
* It turns out that $\bar 𝑦$ minimizes RMSE.
* The median of ${𝑦_1,𝑦_2, …, 𝑦_𝑛}$ minimizes MAE. 

```python=
for i in range(nrun):
    sample = Dataframe.sample(n = ssize, replace = False, random_state = rseed + i)
    sample_mean = sample.sat.mean()
    sample_prop = np.mean(sample.oncampus.values == "Yes")
    err_m_all.append(abs(sample_mean - pop_mean))
    err_p_all.append(abs(sample_prop - pop_prop))
```


## Non-sampling Error 
Non-sampling errors occur due to **mistakes** made along the process of **data acquisition**.  
Increasing sample size **will not** reduce this type of error.
### Types of Non-sampling Errors
* Errors in data acquisition
* Non-response errors
![](https://i.imgur.com/jXDoitt.png)
* Selection bias
* Self-selection bias 


## Self-Selection Bias
* Individuals select themselves into a group, causing a biased sample with nonprobability sampling. 
* Characteristics of the people which cause them to select themselves in the group often create abnormal or undesirable conditions in the group.
* Self-selection affects evaluation of whether or not a given program has some effect, and complicates interpretation of market research.


# Summary
* Steps of Conducting a Study
* Sampling Design: nonprobabilistic and probabilistic sampling
* Probabilistic Sampling Method: Simple Random Sampling, Stratified Random Sampling, Cluster Sampling, Systematic Sampling
* Errors: Sampling vs. Non-sampling

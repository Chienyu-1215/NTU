###### tags: `MGT2001 Statistics` `Notes`
# Statistics: Chapter 6 Probability
## Gambling and Probability
The mathematical theory of probability has its roots in attempts to analyze ==games of chance== by **Gerolamo Cardano** in the sixteenth century, and by **Pierre de Fermat** and **Blaise Pascal** in the seventeenth. Christiaan Huygens published a book on the subject in 1657.

## Agenda
* Assigning Probability to Events
* Basic Relationships of Probability
* Probability Rules 
* Probability Trees
* Bayes’ Law


# Assigning Probability to Events
## Probability Theory
* Used to measure the degree of uncertainty 
* Allows decision maker to deal with uncertainty in a consistent, rational manner
* Help decision maker to make decision under uncertainty
### Uncertainty
* Future demand of products
* Future level of interest rate
* The possibility of a labor strike
* of defective chips in the next production run.

### Random Experiment
A process or course of action, whose **outcome** is **uncertain**.
![](https://i.imgur.com/0lNDQFV.png)

### Characteristics of Probability
* Probability is a **numerical measure** of the **likelihood** that an event will occur.
* Probability values are always assigned on a scale from 0 to 1


## Determining Sample Space 
有可能發生的情形的最小單位
* Build ++an exhaustive list++ of all possible outcomes.
* Make sure the listed outcomes are ++mutually exclusive++.
A list of outcomes that meet the above two conditions is called a sample space.

### Simple Event and Event
* The individual outcome is called a simple event. A simple event cannot be further decomposed into constituent outcomes.
* An event is any collection of one or more simple events and a subset of sample space.

### Properties of Probability
Given a sample space $S ={E_1,E_2,…, E_n}$, the following characteristics for the probability, $P(E_i)$, of the Simple Event $E_i$ must hold:
1. $0 \le P(E_i) \le 1$ for eacj $i$
2. $\sum^n_{i = 1} P(E_i) = 1$

The probability of event $A$, $P(A)$, is the sum of the probabilities assigned to the simple events contained in $A$.
$P(A) = \sum_{All\space E_i\space in \space A}{P(E_i)}$


## Assigning Probability
### Classical Approach
* Deduce the probability of an outcome logically from the symmetric nature of the experiments, e.g., flipping coins, picking a porker card, …
* Assumptions: Randomness, Fairness, Equal and total information sharing
* If an experiment has $n$ possible outcomes, this method  would assign a probability of $\frac{1}{n}$ to each outcome. It is necessary to determine the number of possible outcomes.

### Relative Frequency Approach
Expresses an outcome’s probability as its long-run relative frequency of occurrence 

### Subjective Approach
* The experimental outcomes are **not equally likely**, and no history of repetition exists $\Rightarrow$ Subjective Probability Determination (reflects the personal evaluation of the uncertainties involved.)
* In the subjective approach we define probability as the degree of belief that we hold in the occurrence of an event


# Basic Relationships of Probability
## Basic Relationships of Probability
### Intersection Events 交集
* For two events,$A$ and $B$, $P(A\cap B) = P(A \text{ and } B) = P(A\text{ and } B \text{ both occur}) = P(\text{The intersection of } A \text{ and } B)$
* For $n$ events, $A_i$ where $1 \le i \le n$ $$P(\cap_{all \space i} A_i ) = P(\text{All $A_i$ are true})$$

### Union
* For two events,$A$ and $B$, $P(A\cup B) = P(A \text{ and } B) = P(A\text{ occurs or } B \text{ occurs or both})$
* For $n$ events, $A_i$ where $1 \le i \le n$ $$P(\cup_{all \space i} A_i ) = P(\text{At least one $A_i$ is true})$$

### Complement 補集
For event $A$, $P(A^C) = P(A \text{ is not true}) = P(\text{The complement event of } A)$

### Mutually Exclusive Events
When two events are mutually exclusive (that is, the two events cannot occur together or when one event occurs, the other cannot occur ), their joint probability is $0$, hence: $\Rightarrow P(A \cap C) = 0$


## Conditional Probability
The probability of an event when partial knowledge about the outcome of an experiment is known.

$P(A|B) =$The conditional probability that event $A$ occurs, given that event $B$ has occurred.
* $P(A|B) = \frac{P(A \text{ and } B)}{P(B)}$
* $P(B|A) = \frac{P(A \text{ and } B)}{P(A)}$

*The partial knowledge is contained in the “condition”*


## Joint, Marginal, Conditional Probability
The methods to determine probabilities of events from ==two different sets== of outcomes based on ==two random experiments== in various ways (conditional, joint, marginal and dependent) by using the basic relationships of events such as: complement event, intersection of events, union of events and mutually exclusive events

### The Marginal Probability
* Given a table with two random experiments
* Computed by adding **across rows and down columns**
* So named because they are calculated in the **margins** of the table

### Example (6.1)
Why are some mutual fund managers **more successful** than others? One possible factor is where the manager earned his or her **MBA**.

The following table compares mutual fund performance against the ranking of the school where the fund manager earned their MBA:

![](https://i.imgur.com/OSsnZlu.png)

The joint probability of events $A$ and $B$ is the probability of the intersection of $A$ and $B$ or $P(A \cap B)$

#### Define the Following Events
* $A_1$ = Fund manager graduated from a top-20 MBA program
* $A_2$ = Fund manager did not graduate from a top-20 MBA program
* $B_1$ = Fund outperforms the market 
* $B_2$ = Fund does not outperform the market

![](https://i.imgur.com/ofDA4KJ.png)

#### Marginal Probability
![](https://i.imgur.com/6KrUEl3.png)


## Independent and Dependent Events  
One of the objectives of calculating conditional probability is to determine ==whether two events are related==. In particular, we would like to know whether they are ==independent==, that is, if the probability of one event is not affected by the occurrence of the other event.

Note that, if the occurrence of one event ==does not change== the likelihood of occurrence of the other event, the two events are ==independent==. 

Two events $A$ and $B$ are said to be ==independent== if $P(A|B) = P(A)$ or $P(B|A) = P(B)$. Otherwise, the events are ==dependent==.

### Example 6.1
Is the factor where the manager earned his or her MBA related to the performance of a mutual fund manager ( Are Two events A1 and B1 independent?)

$P(B_1 | A_1) = .275$
The marginal probability for $B_1$, $P(B_1) = 0.17$
Since $P(B_1|A_1) \ne P(B_1)$, $B_1$ and $A_1$ are not independent events.

Stated another way, they are **dependent**. That is, the probability of one event ($B_1$) is affected by the occurrence of the other event ($A_1$).


## Contingency Table (列聯表)
* Also called a cross-classification table or cross-tabulation table.
* To describe the relationship between ==two== nominal variables.
* Lists the ==frequency== of ==each combination== of the values of the two variables.

### Example
The personnel department of an insurance company has compiled data regarding promotion, classified by **gender**. The following table describes the data
![](https://i.imgur.com/tFtyjDv.png)
![](https://i.imgur.com/wSDcEiQ.png)

#### Define the Following Events
* $M$: An employee is a male
* $M_C$: An employee is a female
* $P$: An employee is promoted
* $P_C$: An employee is not promoted

#### Conditional Probability
$P(P|M) = P(\text{The employee is promoted | The employee is male}) \\ = \frac{P(P \text{ and } M)}{P(M)} \\ = \frac{0.1704}{0.8519}$

#### Equal Opportunity
If this equality holds, there is no difference in probability of promotion between a male and a female manager.  
In other words, $P$ and $M$ are independent.  
Let us check if $P(P|M) = 0.2 ?= P(P) = 0.2$.  
**Conclusion**  
Independent events, which implies that there is no discrimination in awarding promotions.

#### Note
Independent events and mutually exclusive events are not the same!!
* Independent: $P(A|B) = P(A)$ or $P(B|A) = P(B)$. 
* Mutually Exclusive: $P(A \text{ and } B) = 0$


# Probability Rules 
## Complement rule
Each simple event must belong to either $A$ or $A^c$. Since the sum of the probabilities assigned to a sample space is one, for any event $A$$$P(A^C) = 1 - P(A)$$


## Addition rule
For any two events $A$ and $B$$$P(A \text{ or } B) = P(A) + P(B) - P(A \text{ and } B)$$  
For $n$ events, $A_i$ where $1 \le i \le n$ $$P(\cup_{\text{all }i}A_i) = \sum_{\text{all }i}{P(A_i)} -  \sum_{\text{all }i \ne j}{P(A_i \cap A_j)} +  \sum_{\text{all }i \ne j \ne k}{P(A_i \cap A_j \cap A_k)}-... \pm P(\cap_{\text{all }i A_i})$$

### Mutually Exclusive Events
* Addition Law for Mutually Exclusive Events $$P(A \cup B) = P(A) + P(B)$$	
* For $n$ events, $A_i$ where $1 \le i \le n$$$P(\cup_{\text{all }i}A_i) = \sum_{\text{all }i}P(A_i)$$


## Multiplication rule
* For any two events $A$ and $B$$$P(A \text{ and } B) = P(A)P(B|A) = P(B)P(A|B)$$
* When $A$ and $B$ are independent $$P(A \text{ and } B) = P(A)P(B)$$


## Example
A stock market analyst feels that the probability that a certain mutual fund will receive **increased contributions** from investors is $0.6$. There is a probability of $0.5$ that the stock market will **rise**.

### Past Experiences
The probability of receiving increased contributions from investors becomes $0.9$ given that the stock market **goes up**. The probability of receiving increased contributions from investors **becomes** $0.6$ given that the stock market **drops**.

### The Event of Interest
* $A$: The stock market rises 
* $W$: The company receives increased contribution.
1. The probability that sharp increase in earnings is $P(A \text{ and } W)$
2. The probability that at least moderate increase in earning is $P(A \text{ or } W)$

### Apply Rules
Given $P(A)=0.5, P(W)=0.6, P(W|A)=0.9, P(W|A^C)=0.6$
* Multiplication rule: $P(A \text{ and } W) = P(A)P(W|A) = (.5)(.9) = 0.45$
* Addition rule: $P(A \text{ or } W) = P(A) + P(W) - P(A and W) = .5 + .6 -.45 = 0.65$


# Probability Trees
## Probability Tree
An effective and simpler method of applying the ==probability rules== is the probability tree, wherein the ==events== in an experiment are represented by ==lines==. The resulting figure resembles a tree, hence the name.  
This is a useful device to build a ==sample space== and to calculate probabilities of ==simple events== and then ==events==.  

### Example
Consider the random experiment of flipping a coin twice.  
![](https://i.imgur.com/KqDwhOm.png)
![](https://i.imgur.com/e2x6cBc.png)


## Note on Probability Trees
There is no requirement that the branches splits be binary, nor that the tree only goes two levels deep, or that there be the same number of splits at each sub node…


# Bayes’ Law
## Bayesian Theorem
* Permits revising old probabilities based on new information
* Application of conditional probability  
![](https://i.imgur.com/vHedOP2.png)


## Bayesian Theorem Formula
### $P(A_i | B) = \frac{P(A_i)P(B|A_i)}{P(A_1)P(B|A_1) + ... +P(A_k)P(B|A_k)} = \frac{P(A_i \cap B)}{P(B)}$
* $P(A_i)$ is the prior probability and $P(A_i|B)$ is the post 
* Probability based on the new information of $P(B)$


## Bayesian Terminology
* The probabilities $P(G)$ and $P(G^C)$ are called prior probabilities because they are determined ==prior== to the sampling an item found defective.
* The conditional probability $P(G|D)$ is called a posterior probability (or revised probability), because the ==prior== probability is revised after the sampling an item found defective


## Tabular Approach
### Step 1
Prepare the following three columns:
* Column 1: The ==mutually exclusive events== for which posterior probabilities are desired.
* Column 2: The ==prior probabilities== for the events.
* Column 3: The ==conditional probabilities== of the new information given each event.

![](https://i.imgur.com/1d00YFL.png)

### Step 2
In column 4, compute the ==joint probabilities== for each event and the new information D by using the multiplication law. Multiply the prior probabilities in column 2 by the corresponding conditional probabilities in column 3.  That is, $P(G_i\cap D) = P(G_i) P(D|G_i)$. 

![](https://i.imgur.com/Yc8FxQN.png)

### Step 3
Sum the joint probabilities in column 4. The sum is the probability of the new information $P(D)$.  
![](https://i.imgur.com/ILzO0vJ.png)

### Step 4
In column 5: compute the posterior probabilities using the basic relationship of conditional probability. (Note that the joint probability $P(G_i \cap D)$ are in column 4 and the probability, $P(D)$, is the sum of column 4. $$P(G_i | D) = \frac{P(G_i \cap D)}{P(D)}$$
![](https://i.imgur.com/cJS8F5H.png)








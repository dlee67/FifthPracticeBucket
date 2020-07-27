# Because ML is everywhere ...
The biggest reason why I never had an infatuation with ML is because <br/>
### everyone is either going to grad school for it,
### or wants to make a career out of it.

# Turns out ...
If I want to really immerse myself in AR, it is likely that ML is unavoidable.

```
 The examples that the system uses to learn are called the training set. Each training example is called a training instance (or sample). This particular performance measure is called accuracy, and it is often used in classification tasks.
```

```
There are four major categories: supervised learning, unsupervised learning, semisupervised learning, and Reinforcement Learning.
```

### Supervised Learning
```
A typical supervised learning task is classification. The spam filter is a good example of this: it is trained with many example emails along with their class (spam or ham), and it must learn how to classify new emails.

Another typical task is to predict a target numeric value, such as the price of a car, given a set of features (mileage, age, brand, etc.) called predictors. This sort of task is called regression.1 To train the system, you need to give it many examples of cars, including both their predictors and their labels (i.e., their prices).

In Machine Learning an attribute is a data type (e.g., “mileage”), while a feature has several meanings, depending on the context, but generally means an attribute plus its value (e.g., “mileage = 15,000”). Many people use the words attribute and feature interchangeably.
```


### Unsupervised Learning 
```
In unsupervised learning, as you might guess, the training data is unlabeled (Figure 1-7). The system tries to learn without a teacher.

For example, say you have a lot of data about your blog’s visitors. You may want to run a clustering algorithm to try to detect groups of similar visitors

A related task is dimensionality reduction, in which the goal is to simplify the data without losing too much information. One way to do this is to merge several correlated features into one. For example, a car’s mileage may be strongly correlated with its age, so the dimensionality reduction algorithm will merge them into one feature that represents the car’s wear and tear. This is called feature extraction..
```

### Reinforcement Learning
```
Reinforcement Learning is a very different beast. The learning system, called an agent in this context, can observe the environment, select and perform actions, and get rewards in return (or penalties in the form of negative rewards). It must then learn by itself what is the best strategy, called a policy, to get the most reward over time. A policy defines what action the agent should choose when it is in a given situation.
```

Turns out, there are more learning models than those 3. For example,
model-based learning, instance learning, etc ...
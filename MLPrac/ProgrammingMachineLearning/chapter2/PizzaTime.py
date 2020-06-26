import numpy as np
import matplotlib.pyplot as plt
# https://seaborn.pydata.org/
import seaborn as sns

def predict(X, w, b):
    return X*w + b

def loss(X, Y, w, b):
    # So, Y is my actual value, X is my value on the x-axis, and w it the "slope," right?
    # X*w - Y is the corrected value, but this cold be negative; so, we square the expression, and average it because,
    # for example, ((-2)^2) / 2 = 4 where (2^2)/2 = 4
    loss_result = np.average((predict(X, w, b) - Y)**2)
    print("loss_result at: ", loss_result)
    return loss_result

# Ultimately, we want find w; after all, w is the "slope" of the line that predicts the values for me.
# lr is the amount of value that will be added to w to make the correction; meaning, bigger the
# lr, each changes applied as a correction will be bigger.
# lr stands for learning rate.
def train(X, Y, iterations, lr):
    # Turns out, the official name for those two in ML is "weight" and "bias.""
    w = b = 0
    for i in range(iterations):
        current_loss = loss(X, Y, w, b)
        print("Iteration %4d => Loss: %.6f" % (i, current_loss))

        # Addition of b doesn't differ too much from how training worked in the previous commit.
        # As I can notice, w += lr and w -= lr was executed (thus, creating a new "slope," the w), 
        # whenever adding the learning rate to w decreased the "loss" (margin of inaccuracy).
        # It's a same logic with b too. I am telling the application to assign a new value to b,
        # if adding/subtracting lr to b actually decreased the "loss" (margin of inaccuracy).
        if loss(X, Y, w + lr, b) < current_loss:
            w += lr
        elif loss(X, Y, w - lr, b) < current_loss:
            w -= lr
        elif loss(X, Y, w, b + lr) < current_loss:
            b += lr
        elif loss(X, Y, w, b - lr) < current_loss:
            b -= lr
        else:
            return w, b # If the loop canno decrease the error (aka loss) anymore, then, return the result.

    raise Exception("Couldn't converge within %d iterations" % iterations)

sns.set()
plt.axis([0, 50, 0, 50])
plt.xticks(fontsize=15)
plt.yticks(fontsize=15)
plt.xlabel("Reservation",fontsize=30)
plt.ylabel("Pizzas",fontsize=30)
X,Y=np.loadtxt("pizza.txt",skiprows=1,unpack=True)
w,b=train(X, Y, iterations=10000, lr=0.01)
print("\nw=%.3f"%w)
plt.plot(X,Y,"bo")
plt.plot([w*1 + b, w*2 + b, w*3 + b, w*4 + b, w*5 + b, w*6 + b, w*7 + b, w*8 + b, w*9 + b, w*10 + b, 
            w*11 + b, w*12 + b, w*13 + b, w*14 + b, w*15 + b, w*16 + b, w*17 + b, w*18 + b, w*19 + b, w*20 + b])
plt.show()
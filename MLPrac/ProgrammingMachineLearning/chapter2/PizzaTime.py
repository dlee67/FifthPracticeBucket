import numpy as np
import matplotlib.pyplot as plt
# https://seaborn.pydata.org/
import seaborn as sns

def predict(X, w):
    return X*w

def loss(X, Y, w):
    # So, Y is my actual value, X is my value on the x-axis, and w it the "slope," right?
    # X*w - Y is the corrected value, but this cold be negative; so, we square the expression, and average it because,
    # for example, ((-2)^2) / 2 = 4 where (2^2)/2 = 4
    loss_result = np.average((predict(X, w) - Y)**2)
    print("loss_result at: ", loss_result)
    return loss_result

# Ultimately, we want find w; after all, w is the "slope" of the line that predicts the values for me.
# lr is the amount of value that will be added to w to make the correction; meaning, bigger the
# lr, each changes applied as a correction will be bigger.
# lr stands for learning rate.
def train(X, Y, iterations, lr):
    w = 0
    for i in range(iterations):
        current_loss = loss(X, Y, w)
        print("Iteration %4d => Loss: %.6f" % (i, current_loss))

        # Does this new line result in a lower loss than our current line? 
        # If so, then w + lr becomes the new current w, and the loop continues. 
        # Otherwise, the algorithm tries another line: w - lr.
        # Ultimately, we need to decrease the loss as much as possible.
        if loss(X, Y, w + lr) < current_loss:
            w += lr
        elif loss(X, Y, w - lr) < current_loss:
            w -= lr
        else:
            return w # If the loop canno decrease the error (aka loss) anymore, then, return the result.

    raise Exception("Couldn't converge within %d iterations" % iterations)

sns.set()
plt.axis([0, 50, 0, 50])
plt.xticks(fontsize=15)
plt.yticks(fontsize=15)
plt.xlabel("Reservation",fontsize=30)
plt.ylabel("Pizzas",fontsize=30)
X,Y=np.loadtxt("pizza.txt",skiprows=1,unpack=True)
w=train(X, Y, iterations=10000, lr=0.01)
print("\nw=%.3f"%w)
plt.plot(X,Y,"bo")
plt.plot([w*1, w*2, w*3, w*4, w*5, w*6, w*7, w*8, w*9, w*10, w*11, w*12, w*13, w*14, w*15, w*16, w*17, w*18, w*19, w*20])
plt.show()
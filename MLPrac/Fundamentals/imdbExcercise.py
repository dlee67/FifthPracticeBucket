from tensorflow import keras
from tensorflow.keras import layers
from tensorflow.keras.datasets import imdb
import tensorflow as tf
import numpy as np

def vectorize_sequences(sequences, dimension=10000):
    results = np.zeros((len(sequences), dimension))
    for i, sequence in enumerate(sequences):
        for j in sequence:
            results[i, j] = 1.
    return results

(x_train, y_train), (x_test, y_test) = imdb.load_data(num_words=10000)

print(len(x_train[0])) # 218
print(len(x_train[1])) # 189
print(len(y_train)) # 25000

# Regularize
x_train = vectorize_sequences(x_train)
x_test = vectorize_sequences(x_test)

print(len(x_train[0])) # 10000
print(len(x_train[1])) # 10000
print(len(y_train)) # 25000

model = keras.Sequential([
      layers.Dense(16, activation="relu"),
      layers.Dense(16, activation="relu"),
      layers.Dense(1, activation="sigmoid")
    ])
model.compile(optimizer="rmsprop",
                  loss="binary_crossentropy",
                  metrics=["accuracy"])

# Have them be of equal lengths so that they can be processed.
model.fit(x_train[:10000], y_train[:10000], epochs=3)
results = model.evaluate(x_test, y_test)
print(results)
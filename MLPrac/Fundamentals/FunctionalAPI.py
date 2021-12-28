from tensorflow import keras
from tensorflow.keras import layers
from tensorflow.keras.datasets import mnist

# This inputs object holds information about the shape and dtype of the data that the model will process:
inputs = keras.Input(shape=(28, 28, 1))
# You don't have to use Dense to train a NN with 
# x = layers.Dense(64, activation="relu")(inputs)
# filters=32 means "I am going to create 32 covolution passes."
# https://stats.stackexchange.com/questions/296679/what-does-kernel-size-mean/339265
# And the kernel_size is the size of the convolutional filter.
x = layers.Conv2D(filters=32, kernel_size=3, activation="relu")(inputs)
# https://www.quora.com/What-is-max-pooling-in-convolutional-neural-networks
# This is something that even some PhD students are having hard time completely understanding it.
x = layers.MaxPooling2D(pool_size=2)(x)
# The app will not work is Flatten is not called on the layers.
x = layers.Flatten()(x)
# For some strange reasons, this app will not work if the units is less than 10 (the first argument).
outputs = layers.Dense(10, activation="softmax")(x)
model = keras.Model(inputs=inputs, outputs=outputs)

model.summary()

(train_images, train_labels), (test_images, test_labels) = mnist.load_data()
print(train_images.shape) # (60000, 28, 28)
print(train_labels.shape) # (60000,)

train_images = train_images.reshape((60000, 28, 28, 1))
train_images = train_images.astype("float32") / 255 
test_images = test_images.reshape((10000, 28, 28, 1))
test_images = test_images.astype("float32") / 255 

model.compile(optimizer="rmsprop",
              loss="sparse_categorical_crossentropy",
              metrics=["accuracy"])
print(train_images.shape) # (60000, 28, 28, 1)
print(train_labels.shape) # (60000,)
model.fit(train_images, train_labels, epochs=1, batch_size=64)

test_loss, test_acc = model.evaluate(test_images, test_labels)
print(f"Test accuracy: {test_acc:.3f}")
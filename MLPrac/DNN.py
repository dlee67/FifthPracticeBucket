import numpy as np
import time
import matplotlib.pyplot

def convert(imgf, labelf, outf, n):
    f = open(imgf, "rb")
    o = open(outf, "w")
    l = open(labelf, "rb")

    f.read(16)
    l.read(8)
    images = []

    for i in range(n):
        image = [ord(l.read(1))]
        for j in range(28*28):
            image.append(ord(f.read(1)))
        images.append(image)

    for image in images:
        o.write(",".join(str(pix) for pix in image)+"\n")
    f.close()
    o.close()
    l.close()

# Convert the MNIST dataset to CSV format
convert("C:\\Users\\talla\\DL_Projects\\archive\\train-images.idx3-ubyte",
        "C:\\Users\\talla\\DL_Projects\\archive\\train-labels.idx1-ubyte",
        "C:\\Users\\talla\\DL_Projects\\archive\\mnist_train.csv", 60000)
convert("C:\\Users\\talla\\DL_Projects\\archive\\t10k-images.idx3-ubyte",
        "C:\\Users\\talla\\DL_Projects\\archive\\t10k-labels.idx1-ubyte",
        "C:\\Users\\talla\\DL_Projects\\archive\\mnist_test.csv", 10000)

# Load the training and test data
train_file = open("C:\\Users\\talla\\DL_Projects\\archive\\mnist_train.csv", 'r')
train_list = train_file.readlines()
train_file.close()

test_file = open("C:\\Users\\talla\\DL_Projects\\archive\\mnist_test.csv", 'r')
test_list = test_file.readlines()
test_file.close()

class DNN:
    # Neural network with 784 input nodes, two hidden layers (128 and 64 nodes), and 10 output nodes
    def __init__(self, sizes=[784, 128, 64, 10], epochs=10, lr=0.001):
        self.sizes = sizes
        self.epochs = epochs
        self.lr = lr
        input_layer = sizes[0]
        hidden_1 = sizes[1]
        hidden_2 = sizes[2]
        output_layer = sizes[3]
        # Initialize weights and biases
        self.params = {
            'W1': np.random.randn(hidden_1, input_layer) * np.sqrt(1. / hidden_1),
            'b1': np.zeros((hidden_1)),
            'W2': np.random.randn(hidden_2, hidden_1) * np.sqrt(1. / hidden_2),
            'b2': np.zeros((hidden_2)),
            'W3': np.random.randn(output_layer, hidden_2) * np.sqrt(1. / output_layer),
            'b3': np.zeros((output_layer))
        }

    def sigmoid(self, x, derivative=False):
        sig = 1 / (1 + np.exp(-x))
        if derivative:
            return sig * (1 - sig)
        return sig

    def softmax(self, x, derivative=False):
        exps = np.exp(x - np.max(x))
        softmax = exps / np.sum(exps)
        if derivative:
            return softmax * (1 - softmax)
        return softmax

    def forward_pass(self, x_train):
        params = self.params
        # Input layer activations become the sample
        params['A0'] = x_train
        # Input layer to first hidden layer
        params['Z1'] = np.dot(params['W1'], params['A0']) + params['b1']
        params['A1'] = self.sigmoid(params['Z1'])
        # First hidden layer to second hidden layer
        params['Z2'] = np.dot(params['W2'], params['A1']) + params['b2']
        params['A2'] = self.sigmoid(params['Z2'])
        # Second hidden layer to output layer
        params['Z3'] = np.dot(params['W3'], params['A2']) + params['b3']
        params['A3'] = self.softmax(params['Z3'])
        return params['A3']

    def backward_pass(self, y_train, output):
        params = self.params
        change_w = {}
        m = 1  # Processing one sample at a time

        # Calculate the gradient for W3 and b3
        dZ3 = output - y_train  # Shape: (10,)
        change_w['W3'] = np.dot(dZ3[:, None], params['A2'][None, :])  # Shape: (10, 64)
        change_w['b3'] = dZ3  # Shape: (10,)

        # Calculate the gradient for W2 and b2
        dA2 = np.dot(params['W3'].T, dZ3)
        dZ2 = dA2 * self.sigmoid(params['Z2'], derivative=True)  # Sigmoid derivative
        change_w['W2'] = np.dot(dZ2[:, None], params['A1'][None, :])  # Shape: (64, 128)
        change_w['b2'] = dZ2  # Shape: (64,)

        # Calculate the gradient for W1 and b1
        dA1 = np.dot(params['W2'].T, dZ2)
        dZ1 = dA1 * self.sigmoid(params['Z1'], derivative=True)  # Sigmoid derivative
        change_w['W1'] = np.dot(dZ1[:, None], params['A0'][None, :])  # Shape: (128, 784)
        change_w['b1'] = dZ1  # Shape: (128,)

        return change_w

    def update_network_parameters(self, changes_to_w):
        # Update network parameters using gradient descent
        for key in self.params.keys():
            self.params[key] -= self.lr * changes_to_w[key]

    def compute_accuracy(self, test_data, output_nodes):
        # Compute accuracy on the test data
        predictions = []

        for x in test_data:
            all_values = x.strip().split(',')
            inputs = (np.asfarray(all_values[1:]) / 255.0 * 0.99) + 0.01
            correct_label = int(all_values[0])
            output = self.forward_pass(inputs)
            pred = np.argmax(output)
            predictions.append(pred == correct_label)

        return np.mean(predictions)

    def train(self, train_list, test_list, output_nodes):
        # Training the neural network
        start_time = time.time()
        for iteration in range(self.epochs):
            for anImage in train_list:
                all_values = anImage.strip().split(',')
                inputs = (np.asfarray(all_values[1:]) / 255.0 * 0.99) + 0.01
                targets = np.zeros(output_nodes) + 0.01
                targets[int(all_values[0])] = 0.99
                output = self.forward_pass(inputs)
                changes_to_w = self.backward_pass(targets, output)
                self.update_network_parameters(changes_to_w)

            accuracy = self.compute_accuracy(test_list, output_nodes)
            print('Epoch: {0}, Time Spent: {1:.2f}s, Accuracy: {2:.2f}%'.format(
                iteration + 1, time.time() - start_time, accuracy * 100
            ))

# Initialize and train the neural network
dnn = DNN(sizes=[784, 128, 64, 10], epochs=50, lr=0.001)
dnn.train(train_list, test_list, 10)

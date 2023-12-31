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

convert("C:\\Users\\talla\\DL_Projects\\archive\\train-images.idx3-ubyte", "C:\\Users\\talla\\DL_Projects\\archive\\train-labels.idx1-ubyte",
        "C:\\Users\\talla\\DL_Projects\\archive\\mnist_train.csv", 60000)
convert("C:\\Users\\talla\\DL_Projects\\archive\\t10k-images.idx3-ubyte", "C:\\Users\\talla\\DL_Projects\\archive\\t10k-labels.idx1-ubyte",
        "C:\\Users\\talla\\DL_Projects\\archive\\mnist_test.csv", 10000)

train_file = open("C:\\Users\\talla\\DL_Projects\\archive\\mnist_train.csv", 'r')
train_list = train_file.readlines()
train_file.close()
test_file = open("C:\\Users\\talla\\DL_Projects\\archive\\mnist_test.csv", 'r')
test_list = test_file.readlines()
test_file.close()

all_values = train_list[100].split(',')
# image_array = np.asfarray(all_values[1:]).reshape((28,28)) # take the data from a record, rearrange it into a 28*28 array and plot it as an image
# matplotlib.pyplot.imshow(image_array, cmap='Greys', interpolation='None')
# scaled_input_train = (np.asfarray(all_values[1:]) / 255.0 * 0.99) + 0.01

class DNN:
    # 784 nodes (28 x 28) as the input layer.
    # 128 nodes for the 1st hidden layer and ... 
    # 64 nodes for the 2nd hidden layer.
    # 10 nodes for the output layer.
    def __init__(self, sizes=[784, 128, 64, 10], epochs=10, lr=0.001):
        self.sizes = sizes
        self.epochs=epochs
        self.lr=lr
        input_layer=sizes[0]
        hidden_1=sizes[1]
        hidden_2=sizes[2]
        output_layer=sizes[3]
        # The below values don't really matter what they are set to as long as they match the number of paths
        # required for each layers to be interconnected. 
        self.params = {
            'W1': np.random.randn(hidden_1, input_layer) * np.sqrt(1. / hidden_1),
            'b1': np.zeros((hidden_1)),  # Initialize bias for the first hidden layer
            'W2': np.random.randn(hidden_2, hidden_1) * np.sqrt(1. / hidden_2),
            'b2': np.zeros((hidden_2)),  # Initialize bias for the second hidden layer
            'W3': np.random.randn(output_layer, hidden_2) * np.sqrt(1. / output_layer),
            'b3': np.zeros((output_layer))  # Initialize bias for the output layer
        }

    def sigmoid(self, x, derivative=False):
        if derivative:
            return (np.exp(-x))/((np.exp(-x)+1)**2)
        return 1/(1 + np.exp(-x))
    
    def softmax(self, x, derivative=False):
        # Numerically stable with large exponentials
        exps = np.exp(x - x.max())
        if derivative:
            return exps / np.sum(exps, axis=0) * (1 - exps / np.sum(exps, axis=0))
        return exps / np.sum(exps, axis=0)
        
    def forward_pass(self, x_train):
        params = self.params
        # The identifiers 'A0', 'Z1', 'A1', 'A2', 'Z2', 'Z3', and 'A3' are arbitrary.
        # 'A' is for activation, and 'Z' is for the weighted sum.    
        # input layer activations becomes sample
        params['A0'] = x_train
        # input layer to hidden layer 1
        params['Z1'] = np.dot(params["W1"], params['A0']) + params['b1']
        # print("Shape of Z1:", params['Z1'].shape)
        params['A1'] = self.sigmoid(params['Z1'])
        # print("Shape of A1:", params['A1'].shape)
        # hidden layer 1 to hidden layer 2
        params['Z2'] = np.dot(params["W2"], params['A1']) + params['b2']
        # print("Shape of Z2:", params['Z2'].shape)
        params['A2'] = self.sigmoid(params['Z2'])
        # print("Shape of A2:", params['A2'].shape)
        # hidden layer 2 to output layer
        params['Z3'] = np.dot(params["W3"], params['A2']) + params['b3']
        # print("Shape of Z3:", params['Z3'].shape)
        params['A3'] = self.softmax(params['Z3'])
        # print("Shape of A3:", params['A3'].shape)
        return params['A3']
        
    def backward_pass(self, y_train, output):
        params = self.params
        change_w = {}
        m = output.shape[0]

        # Calculate W3 update
        dZ3 = output - y_train
        change_w['W3'] = np.dot(dZ3[:, None], params['A2'].T[None, :]) / m
        change_w['b3'] = np.sum(dZ3, keepdims=True) / m

        # Calculate gradients for second hidden layer
        dZ2 = np.dot(params['W3'].T, dZ3) * (1 - np.power(params['A2'], 2))
        change_w['W2'] = np.dot(dZ2[:, None], params['A1'].T[None, :]) / m
        change_w['b2'] = np.sum(dZ2, keepdims=True) / m
        
        # Calculate gradients for the second hidden layer
        dZ1 = np.dot(params['W2'].T, dZ2) * (1 - np.power(params['A1'], 2))
        change_w['W1'] = np.dot(dZ1[:, None], params['A0'].T[None, :]) / m
        change_w['b1'] = np.sum(dZ1, keepdims=True) / m

        return change_w

    def train(self, train_list, test_list, output_nodes):
        # For MNIST training, no matter what, output_nodes will always be 10.
        # After all, if there are 10 digits that can be classifed, then, that's 10 output nodes (still one layer).
        start_time = time.time()
        for iteration in range(self.epochs):
            for anImage in train_list:
                all_values = anImage.split(',')
                inputs = (np.asfarray(all_values[1:]) / 255.0 * 0.99) + 0.01
                targets = np.zeros(output_nodes) + 0.01
                targets[int(all_values[0])] = 0.99
                output = self.forward_pass(inputs)
                changes_to_w = self.backward_pass(targets, output)
                self.update_network_parameters(changes_to_w)
          
            accuracy = self.compute_accuracy(test_list, output_nodes)
            print('Epoch: {0}, Time Spent: {1:.2f}s, Accuracy: {2:.2f}%'.format(
                iteration+1, time.time() - start_time, accuracy * 100
            ))

    def update_network_parameters(self, changes_to_w):
        '''
          Update network parameters according to update rule from
          Stochastic Gradient Descent.

          θ = θ - η * ∇J(x, y), 
              theta θ:            a network parameter (e.g. a weight w)
              eta η:              the learning rate
              gradient ∇J(x, y):  the gradient of the objective function,
                                  i.e. the change for a specific theta θ
        '''
        for key, value in changes_to_w.items():
            self.params[key] -= self.lr * value
    
    
    def compute_accuracy(self, test_data, output_nodes):
        '''
            This function does a forward pass of x, then checks if the indices
            of the maximum value in the output equals the indices in the label y. 
            Then it sums over each prediction and calculates the accuracy.
        '''
        predictions = []

        for x in train_list:
            all_values = x.split(',')
            # scale and shift the inputs
            inputs = (np.asfarray(all_values[1:]) / 255.0 * 0.99) + 0.01
            # create the target output values (all 0.01, except the desired label which is 0.99)
            targets = np.zeros(output_nodes) + 0.01
            # all_values[0] is the target label for this record
            targets[int(all_values[0])] = 0.99
            output = self.forward_pass(inputs)
            pred = np.argmax(output)
            predictions.append(pred == np.argmax(targets))
      
        return np.mean(predictions)
            
dnn = DNN(sizes=[784, 128, 64, 10], epochs=50, lr=0.001)
dnn.train(train_list, test_list, 10)
import numpy as np
import torch
import torchvision
import matplotlib.pyplot as plt
from time import time
from torchvision import datasets, transforms
from torch import nn, optim

class NeuralNetwork:
    
    def __init__(self):
        self.transform = transforms.Compose([transforms.ToTensor(),
                              transforms.Normalize((0.5,), (0.5,)),
                              ])

        self.trainset = datasets.MNIST('.', download=True, train=True, transform=self.transform)
        self.valset = datasets.MNIST('.', download=True, train=False, transform=self.transform)
        self.trainloader = torch.utils.data.DataLoader(self.trainset, batch_size=64, shuffle=True)
        self.valloader = torch.utils.data.DataLoader(self.valset, batch_size=64, shuffle=True)

        input_size = 784
        hidden_sizes = [128, 64]
        output_size = 10

        self.model = nn.Sequential(nn.Linear(input_size, hidden_sizes[0]), # Hidden layer
                      nn.ReLU(),
                      nn.Linear(hidden_sizes[0], hidden_sizes[1]), # Hidden layer
                      nn.ReLU(),
                      nn.Linear(hidden_sizes[1], output_size), # Output layer
                      nn.LogSoftmax(dim=1)) # This allows us to make class prediction.

    def train(self):        
        criterion = nn.NLLLoss() # The cost function.
        optimizer = optim.SGD(self.model.parameters(), lr=0.003, momentum=0.9)
        time0 = time()
        epochs = 15
        for e in range(epochs):
            running_loss = 0
            for images, labels in self.trainloader:
                # Flatten MNIST images into a 784 long vector
                images = images.view(images.shape[0], -1)

                optimizer.zero_grad()
                
                #Forward propagation
                output = self.model(images)
                loss = criterion(output, labels)
                #Backward propagation
                loss.backward()
                optimizer.step()
                
                running_loss += loss.item()
            else:
                print("Epoch {} - Training loss: {}".format(e, running_loss/len(self.trainloader)))

    def predict(self):        
        correct_count, all_count = 0, 0
        for images,labels in self.valloader:
          for i in range(len(labels)):
            img = images[i].view(1, 784)
            with torch.no_grad():
                logps = self.model(img)
            ps = torch.exp(logps)
            probab = list(ps.numpy()[0])
            pred_label = probab.index(max(probab))
            print("pred_label: ", pred_label)
            true_label = labels.numpy()[i]
            if(true_label == pred_label):
              correct_count += 1
            all_count += 1
        print("Number Of Images Tested =", all_count)
        print("\nModel Accuracy =", (correct_count/all_count))

net = NeuralNetwork()
net.train()
net.predict()

torch.save(self.model, './my_mnist_model.pt') # This saves the model.
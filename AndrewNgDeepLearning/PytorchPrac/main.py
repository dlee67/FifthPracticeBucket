import torch
import numpy as np
np.set_printoptions(precision=3)
a = [1, 2, 3]
b = np.array([4, 5, 6], dtype=np.int32)
t_a = torch.tensor(a)
t_b = torch.from_numpy(b)
print(t_a)
print(t_b)

t_ones = torch.ones(2, 3)
t_ones.shape

t_a_new = t_a.to(torch.int64)

t = torch.rand(3, 5)
t_tr = torch.transpose(t, 0, 1)

t = torch.zeros(30)
t_reshape = t.reshape(5, 6)

t = torch.zeros(1, 2, 1, 4, 1)
t_sqz = torch.squeeze(t, 2) # Squeeze removes the unncessary dimensions.
print(t.shape, ' --> ', t_sqz.shape)

torch.manual_seed(1)
t = torch.rand(6)
print(t)
t_splits = torch.chunk(t, 3)
[item.numpy() for item in t_splits]

A = torch.ones(3)
B = torch.zeros(2)
C = torch.cat([A, B], axis=0)
print(C)

from torch.utils.data import Dataset
class JointDataset(Dataset):
    def __init__(self, x, y):
        self.x = x
        self.y = y
       
    def __len__(self):
        return len(self.x)
    def __getitem__(self, idx):
        return self.x[idx], self.y[idx]

from torch.utils.data import TensorDataset
joint_dataset = TensorDataset(t_x, t_y)

for example in joint_dataset:
    print('  x: ', example[0], '  y: ', example[1])
joint_dataset = TensorDataset(t_x, t_y)

torch.manual_seed(1) 
data_loader = DataLoader(dataset=joint_dataset, batch_size=2, shuffle=True)

for i, batch in enumerate(data_loader, 1):
    print(f'batch {i}:', 'x:', batch[0],
          '\n         y:', batch[1])

for epoch in range(2): 
    print(f'epoch {epoch+1}')
    for i, batch in enumerate(data_loader, 1):
        print(f'batch {i}:', 'x:', batch[0], 
              '\n         y:', batch[1])
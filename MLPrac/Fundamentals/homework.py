import pandas as pd
import numpy as np

csv_df = pd.read_csv('Iris.csv')
pedal_width = csv_df['SepalWidthCm'].to_numpy()

print(np.percentile(pedal_width, 10))
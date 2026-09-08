import os
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
import torch

csv_content = """StudyHours,Attendance,PreviousMarks,Assignments,FinalMarks
2,65,55,3,58
3,70,60,4,62
4,75,65,5,68
5,80,70,6,75
6,85,75,7,80
7,90,80,8,86
8,92,85,9,91
1,60,50,2,52
3,72,62,4,64
5,82,72,6,77
6,88,78,7,83
7,95,88,8,94"""

# Saving data locally
with open('students.csv', 'w') as f:
    f.write(csv_content.strip())

# Load and Inspect Dataset
print("Data Inspection")
df = pd.read_csv('students.csv')

print("\nFirst 5 Records:")
print(df.head())

print("\nLast 5 Records:")
print(df.tail())

print("\nData Summary:")
df.info()

print("\nStatistical Descriptive Summary:")
print(df.describe())
print("\n")


# Numerical Operations
print("Specific Metrics")
avg_study_hours = df['StudyHours'].mean()
max_final_marks = df['FinalMarks'].max()
min_attendance = df['Attendance'].min()
std_final_marks = df['FinalMarks'].std()

print(f"Average Study Hours: {avg_study_hours:.2f}")
print(f"Maximum Final Marks: {max_final_marks}")
print(f"Minimum Attendance:  {min_attendance}%")
print(f"Standard Deviation of Final Marks: {std_final_marks:.2f}")
print("\n")

print("Generating Plots")
plt.figure(figsize=(11, 4))

#subplot 1
plt.subplot(1, 2, 1)
plt.scatter(df['StudyHours'], df['FinalMarks'], color='darkorange', edgecolor='black', s=50)
plt.title('Study Hours vs Final Marks')
plt.xlabel('Study Hours')
plt.ylabel('Final Marks')
plt.grid(True, alpha=0.3)

#subplot 2
plt.subplot(1, 2, 2)
plt.scatter(df['Attendance'], df['FinalMarks'], color='teal', edgecolor='black', s=50)
plt.title('Attendance vs Final Marks')
plt.xlabel('Attendance %')
plt.ylabel('Final Marks')
plt.grid(True, alpha=0.3)

plt.tight_layout()
plt.show()
print("Plots rendered successfully.\n")

print("ML Preprocessing")

X = df[['StudyHours', 'Attendance', 'PreviousMarks', 'Assignments']]
y = df['FinalMarks']

# Splitting data 
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.25, random_state=7)
print(f"Train features shape: {X_train.shape}")
print(f"Test features shape:  {X_test.shape}")

# Scaling features to have zero mean and unit variance
scaler = StandardScaler()
X_train_scaled = scaler.fit_transform(X_train)
X_test_scaled = scaler.transform(X_test)

print("\nSample of Scaled Training Data (First 2 rows):")
print(X_train_scaled[:2])
print("\n")


#PyTorch Tensor Operations
print("PyTorch Tensor Experiments")

#2D tensors
tensor_a = torch.tensor([[1.0, 3.0], [5.0, 7.0]])
tensor_b = torch.tensor([[2.0, 4.0], [6.0, 8.0]])
print("Tensor A:\n", tensor_a)
print("Tensor B:\n", tensor_b)

#Addition
print("\nAddition (A + B):\n", tensor_a + tensor_b)

#Multiplication
print("\nElement-wise Multiplication (A * B):\n", tensor_a * tensor_b)

# Matrix Multiplication
print("\nMatrix Multiplication (torch.matmul):\n", torch.matmul(tensor_a, tensor_b))

#Reshaping a Tensor
flat_tensor = torch.tensor([10, 20, 30, 40, 50, 60])
reshaped_tensor = flat_tensor.view(3, 2)
print("\nReshaped Tensor (from 1D to 3x2):\n", reshaped_tensor)

# NumPy and Tensors
numpy_array = np.array([1.5, 2.5, 3.5])
t_from_np = torch.from_numpy(numpy_array)
np_from_t = t_from_np.numpy()
print(f"\nConverted NumPy to Tensor: {t_from_np}")
print(f"Converted Tensor back to NumPy: {np_from_t}")

#matrix to show slicing features
grid_tensor = torch.arange(10, 26).view(4, 4)
print("\nBase Grid Tensor for Indexing/Slicing:")
print(grid_tensor)

#Indexing
print("\nSingle Item at Row 2, Col 3:", grid_tensor[2, 3].item())
print("Entire Row index 1:         ", grid_tensor[1, :])
print("Entire Column index 2:      ", grid_tensor[:, 2])

#Slicing with submatrices and steps
sub_matrix = grid_tensor[1:3, 1:4]
print("\nExtracted Submatrix:\n", sub_matrix)

stepped_slice = grid_tensor[::2, ::2]
print("Sliced with Step size of 2:\n", stepped_slice)

#Indexing and Boolean Masks
rows_to_pick = [0, 1, 3]
print("\nFancy Indexing (Selecting rows 0, 1, and 3):\n", grid_tensor[rows_to_pick])

boolean_mask = grid_tensor > 18
print("\nBoolean Mask (Elements > 18):\n", boolean_mask)
print("Filtered Matrix Data using Mask:\n", grid_tensor[boolean_mask])
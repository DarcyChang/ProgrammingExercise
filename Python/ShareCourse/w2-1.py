import numpy as np
import pandas as pd

np_data = np.array([1,2,3,4])

print(np_data+np_data)
print(np_data[0])
print(np_data[:2])

matrix1 = np.array([[1,2,3,4], [5,6,7,8]])
matrix2 = np.array([[1,2,3,4], [5,6,7,8]])

print(matrix1)
print(matrix2)
print(matrix1 * matrix2)

print(matrix2.transpose())

print(np.dot(matrix1, matrix2.transpose()))

print("")

df = pd.DataFrame({'cid':['c01','c02','c03','c04','c05'], 'time_spent':[2,34,91,203,763]})

print(df)
print("")

df2 = pd.DataFrame([{'cid':'c01', 'num_spent':2}, {'cid':'c02', 'num_spent':34}])

print(df2)
print("")

print(df['time_spent'])
print(df2.num_spent)
print(df[['cid','time_spent']])
print(df[0:2])
print(df[df['time_spent'] > 50])

df['num_products'] = [2, 3, 4, 1, 6]
print(df)
print("")

df = df.append(pd.DataFrame([{'cid':'c06', 'time_spent':3, 'num_products':4}]))  # index will be 0
print(df)
print("")

df = df.reset_index(drop=True)  # index reset
print(df)
print("")

df = df.rename(columns={'cid':'pid', 'num_products':'num_purchase'})  # Modify column
print(df)
print("")

df[0:1] = pd.DataFrame([{'pid':'c07', 'num_purchase':93, 'time_spent':23}])  # Modify row 0
print(df)
print("")

del df['pid']
print(df)
print("")

df = df.drop('time_spent', axis=1)
print(df)
print("")

df = df.drop([0, 2, 3])
print(df)
print("")

df = df.reset_index(drop=True)  # index reset
print(df)
print("")

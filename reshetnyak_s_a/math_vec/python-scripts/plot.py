import matplotlib.pyplot as plt
import numpy as np
import csv


def millions(x):
    return '$%1.1fM' % (x * 1e-5)


# Fixing random state for reproducibility
np.random.seed(19680801)

arr_x = []
arr_y = []

with open("data_out.csv", "r") as csvfile:
    plots = csv.reader(csvfile, delimiter = ',')

    for row in plots:
        if row[2] != "x" and row[3] != "y":
            arr_x.append(float(row[2]))
            arr_y.append(float(row[3]))

# print(arr_x)

fig, ax = plt.subplots()
ax.fmt_ydata = millions
plt.plot([0], [0], 'ro')
plt.axhline(0, color="black", linestyle="--")
plt.axvline(0, color="black", linestyle="--")
plt.plot(arr_x, arr_y, 'o')
ax.set(xlabel='x', ylabel='y')

plt.show()
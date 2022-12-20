import matplotlib.pyplot as plt
import numpy as np
import csv


def millions(x):
    return '$%1.1fM' % (x * 1e-5)


# Fixing random state for reproducibility
np.random.seed(19680801)

arr_x = []
arr_y = []

v_x, v_y, r_x, r_y = 0, 0, 0, 0

with open("data_out.csv", "r") as csvfile:
    plots = csv.reader(csvfile, delimiter = ',')

    i = 1
    for row in plots:
        if row[2] != "x" and row[3] != "y":
            if i == 1: 
                v_x, v_y, r_x, r_y = float(row[4]), float(row[5]), float(row[6]), float(row[7])
                i += 1
            arr_x.append(float(row[2]))
            arr_y.append(float(row[3]))

# print(arr_x)

fig, ax = plt.subplots()
ax.fmt_ydata = millions

plt.plot([0], [0], 'ro')
plt.plot([arr_x[0]], [arr_y[0]], 'ro')
plt.axhline(0, color="black", linestyle="--")
plt.axvline(0, color="black", linestyle="--")
x = np.linspace(-1, 1, len(arr_x))
c = np.tan(x)
plt.scatter(arr_x, arr_y, c=c)
ax.set(xlabel='x', ylabel='y')
plt.show()

# vectors
# V = np.array([[v_x, v_y], [r_x, r_y]])
# origin = np.array([arr_x[0], arr_y[0]]) # origin point
# print(origin)

# plt.quiver(*origin, *V, color=['r','b','g'], scale=21)
# plt.show()
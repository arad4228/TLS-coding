import matplotlib.pyplot as plt

X = []
Y = []

for x in range(17):
    for y in range(17):
        if(x ** 3 + 2 * x + 2 - y**2) % 17 == 0:
            X.append(x)
            Y.append(y)

plt.grid()
plt.scatter(X, Y)
import numpy as np
import matplotlib.pyplot as plt

datos=np.loadtxt('data2.txt')
plt.plot(datos[:,0],datos[:,1])
plt.savefig('grafica2.png')


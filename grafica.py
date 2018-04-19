import numpy as np
import matplotlib.pyplot as plt

datos=np.loadtxt('data.txt')
plt.plot(datos[:,0],datos[:,1])
plt.savefig('grafica.png')


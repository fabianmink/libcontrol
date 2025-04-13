# -*- coding: utf-8 -*-
"""
Created on Sun Mar 30 07:53:02 2025

@author: Fabian Mink
"""

import numpy as np
import matplotlib.pyplot as plt

    
#fem_data = np.genfromtxt('output_Ia_z.csv', delimiter=',')
data = np.genfromtxt('out.csv', delimiter=',')


pos = data[:,0]
val = data[:,1]

plt.plot(pos,val,'kx-')


plt.show()

  
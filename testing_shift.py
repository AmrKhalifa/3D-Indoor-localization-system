from scipy import signal
from scipy.io.wavfile import read
from scipy.io.wavfile import write
import matplotlib.pyplot as plt
import pandas as pd 
import numpy as np
from numpy import array, empty, zeros, roll, exp, pi, arange


def zcsequence(u, seq_length):

    zcseq = exp((-1j * pi * u * arange(seq_length) * (arange(seq_length)+1)) / seq_length)

    return zcseq


z = zcsequence(5,1023)

new_z= np.insert(z,[0]*1000,0)
new_z= np.insert(new_z,[1023+1000]*1000,0)

#plt.plot(new_z)
#plt.show()

correlation = signal.correlate(new_z.real,z.real,'full','direct')
plt.plot(correlation)
plt.show()
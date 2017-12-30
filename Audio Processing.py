import scipy
from scipy import signal
from scipy.io.wavfile import read
from scipy.io.wavfile import write
import matplotlib.pyplot as plt
import pandas as pd 
import numpy as np
from numpy import array, empty, zeros, roll, exp, pi, arange
from scipy.fftpack import fft, ifft

def zcsequence(u, seq_length):

    zcseq = exp((-1j * pi * u * arange(seq_length) * (arange(seq_length)+1)) / seq_length)

    return zcseq


def cos (signal_frequency,sampling_rate,no_of_samples):
	signal_frequency= signal_frequency
	sampling_rate = sampling_rate
	samples= no_of_samples
	x = np.arange(samples)
	y = np.cos(2 * np.pi * signal_frequency * x / sampling_rate)

	return y
	pass


def sin (signal_frequency,sampling_rate,no_of_samples):
	signal_frequency= signal_frequency
	sampling_rate = sampling_rate
	samples= no_of_samples
	x = np.arange(samples)
	y = np.sin(2 * np.pi * signal_frequency * x / sampling_rate)

	return y
	pass


def interpolate():
	pass



baseBand = zcsequence(5,1023)

#real_modulated_zadoffChu = np.real(baseBand)*cos(signal_frequency =0, sampling_rate =44100,no_of_samples =1023)
#imag_modulated_zadoffChu= np.imag(baseBand)*sin(signal_frequency =0, sampling_rate =44100,no_of_samples =1023*100 )
#modulated_zadoffChu = real_modulated_zadoffChu+imag_modulated_zadoffChu
#write("modulated_zadoffChu.wav",44100,np.real(modulated_zadoffChu))
#print("done")

#plt.subplot(2,1,1)
# plt.plot(baseBand)
# plt.plot(modulated_zadoffChu)
# plt.subplot(2,1,2)
# modulated_zadoffChu = np.real(baseBand)*cos(signal_frequency =199, sampling_rate =200,no_of_samples =93 )
# plt.plot(baseBand)
# plt.plot(modulated_zadoffChu)
# baseBandFrequency = scipy.fftpack.fft(baseBand)
# modulated_zadoffChu_Frequency = scipy.fftpack.fft(modulated_zadoffChu)
#plt.plot(baseBandFrequency)
#plt.plot(modulated_zadoffChu_Frequency)
#plt.plot()
#plt.show()

fs = 44100
#am = cos_1*cos_2
#plt.plot(am)

#f, Pxx_den = signal.periodogram(baseBand, fs)
f_1= fft(baseBand)
#plt.plot(f_1)

f_2 = fft(baseBand*cos(signal_frequency =1000, sampling_rate =44100,no_of_samples =1023))
#plt.plot(f_2)
correlation = signal.correlate(f_1,f_1,'full','direct')
plt.plot(correlation)

correlation = signal.correlate(f_1,f_2,'full','direct')
plt.plot(correlation)
#f, Pxx_den = signal.periodogram(am, fs)
#plt.plot(Pxx_den)

plt.show()

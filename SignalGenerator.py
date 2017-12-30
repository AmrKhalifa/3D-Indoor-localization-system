from scipy import signal
from scipy.io.wavfile import read
from scipy.io.wavfile import write
import matplotlib.pyplot as plt
import pandas as pd 
import numpy as np
from numpy import array, empty, zeros, roll, exp, pi, arange
import math

# read audio samples
input_data = read("10kHz_44100Hz_16bit_1sec.wav")
audio = input_data[1]
sampling_rate = input_data[0]
# plot the first 1024 samples
#plt.plot(audio[0:1024])
# label the axes
#plt.ylabel("Amplitude")
#plt.xlabel("Time (samples)")
# set the title
#plt.title("sine wave samples")
# display the plot
print(sampling_rate)
#plt.show()

#df = pd.DataFrame(audio)
#df.to_csv("samples.csv")

correlated_signal = signal.correlate(audio,audio,'full','auto')
#plt.plot(correlated_signal[0:1024])
#plt.show()

def getSinWave():

	sinWave = []
	for i in range (1,1024*100):
		sinWave.append(math.sin(i))

	return sinWave




newSignal = getSinWave();
#print(newSignal)

#plt.plot(newSignal)
#plt.show();


write("GeneratedSinWave.wav",100000,np.array(newSignal))



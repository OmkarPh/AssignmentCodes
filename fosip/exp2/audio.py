import numpy as np
import soundfile as sf
from exp1 import custom_convolve


def Pearson_correlation(X, Y):
    corr = 0
    if len(X) == len(Y):
        Sum_xy = sum((X - X.mean()) * (Y - Y.mean()))
        Sum_x_squared = sum((X - X.mean()) ** 2)
        Sum_y_squared = sum((Y - Y.mean()) ** 2)
        corr = Sum_xy / np.sqrt(Sum_x_squared * Sum_y_squared)
    return corr


input_audio1, sample_rate1 = sf.read("pass1.wav")
input_audio2, sample_rate2 = sf.read("pass2.wav")
input_audio1 = custom_convolve(input_audio1)
input_audio2 = custom_convolve(input_audio2)
print("Correlation: ", Pearson_correlation(input_audio1, input_audio2))

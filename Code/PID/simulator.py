import numpy as np
import matplotlib.pyplot as plt
import time
import random

from pid import PID
from ringbuff import Ringbuffer

# simulation variables
running: bool = True
plotting_values = 100
nature_values: list = [0 for i in range(0, plotting_values)]
x_vals = np.linspace(0, plotting_values, plotting_values)

setpoint: float = 20.0
output_var: int = 0  # -10 - 10
max_disturbance_val: float = 1.0

# PID
pid = PID(KP=0.5, KI=0.1, KD=0.3, setpoint=setpoint,
          maxOutputVal=3, minOutputVal=-3)

# Last Measured Value
meas_sensor_val: float = 30

# Ringbuffer for Error Values
error_rb = Ringbuffer(5)

for i in range(plotting_values):
    # update input variables
    meas_sensor_val += output_var + \
        round(random.uniform(0.0, max_disturbance_val), 4)
    # calculate pid function
    output_var = pid.update(meas_sensor_val, error_rb)

    nature_values[i] = meas_sensor_val
    # time.sleep(1)

    if i == 50:
        pid.updateSetPoint(24.0)

plt.plot(x_vals, nature_values)
plt.xlabel('Time (s)')
plt.ylabel('Temperature (°C)')
plt.title('PID Controlled Temperature')
plt.show()

import numpy as np

from ringbuff import Ringbuffer

set_point: float
process_var: float


class PID:

    def __init__(self, KP: float, KI: float, KD: float, setpoint: float, maxOutputVal: float, minOutputVal: float) -> None:
        self.Kp = KP
        self.Ki = KI
        self.Kd = KD

        self.setpoint = setpoint
        self.maxOutputVal = maxOutputVal
        self.minOutputVal = minOutputVal

    def updateSetPoint(self, new_sp: float):
        self.setpoint = new_sp

    def update(self, process_var: float, error_rb: Ringbuffer) -> float:

        error_rb.add(self.setpoint - process_var)
        newestIndex = error_rb.getNewestValueIndex()
        lastIndex = newestIndex - 1
        if lastIndex < 0:
            lastIndex = error_rb.MAXMEMBERS - 1

        proportional = self.Kp * error_rb[newestIndex]
        integral = self.Ki * sum(error_rb[i]
                                 for i in range(0, error_rb.MAXMEMBERS))
        derivate = self.Kd * (error_rb[newestIndex] - error_rb[lastIndex])

        output_var = proportional + integral + derivate

        # max values possible for output
        if output_var > self.maxOutputVal:
            output_var = self.maxOutputVal
        elif output_var < self.minOutputVal:
            output_var = self.minOutputVal

        return output_var

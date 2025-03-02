import numpy as np
import matplotlib.pyplot as plt

# signal 1
a1 = 3
f1 = 5
# signal 2
a2 = 1
f2 = 5
# signal 3
a3 = 0.2
f3 = 30

# time to plot signal eg. x values
t: float = 1.0
num_samples: int = 1000
x_vals = np.linspace(0, t, num_samples)


def get_cosine_signal(frequency, amplitude, phase, time_interval, num_samples) -> list:
    import numpy as np

    # phase in degrees
    # time_interval in seconds (float)

    phase_rads = (phase/360)*2*np.pi

    s: list = np.linspace(0, 2*np.pi * frequency, num_samples)
    s = [amplitude * np.cos(s[i] + phase_rads) for i in range(num_samples)]

    return s


def get_delta_signal(amplitude: float, time_shift: float, time_in_s, num_samples):
    d: list = [0.0 for i in range(num_samples)]

    shift_index = int((-time_shift/time_in_s)*num_samples)

    d[shift_index] = amplitude

    return d


def filter_low_pass(signal_in: list, R_val, C_val,  time_in_s, num_samples):
    T = time_in_s/num_samples
    RC = R_val * C_val

    filtered: list = [0.0 for i in range(num_samples)]

    filtered[0] = signal_in[0]

    for i in range(1, num_samples):
        filtered[i] = signal_in[i] * (T/(T+RC)) + filtered[i-1] * (RC/(T+RC))

    return filtered


if __name__ == "__main__":
    d = get_delta_signal(4, -0.3, t, num_samples)

    # signal definitions
    s1: list = get_cosine_signal(f1, a1, 0, t, num_samples)
    s2: list = get_cosine_signal(f2, a2, 0, t, num_samples)
    s3: list = get_cosine_signal(f3, a3, 0, t, num_samples)

    s: list = [0.0 for i in range(num_samples)]
    # s = [s1[i]+s2[i]+s3[i] for i in range(num_samples)]
    s = [s2[i]+s3[i] for i in range(num_samples)]

    filtered = filter_low_pass(s, 1000, 15.9e-6, t, num_samples)

    # plotting signal
    fig, axs = plt.subplots(3, 2, figsize=(10, 8))
    axs[0, 0].stem(x_vals, s)
    axs[0, 0].plot(x_vals, s)
    axs[0, 0].set_title('s')

    axs[0, 1].stem(x_vals, filtered)
    axs[0, 1].plot(x_vals, filtered)
    axs[0, 1].set_title('filtered')

    axs[1, 0].stem(x_vals, s2)
    axs[1, 0].plot(x_vals, s2)
    axs[1, 0].set_title('s2')

    axs[1, 1].stem(x_vals, s3)
    axs[1, 1].plot(x_vals, s3)
    axs[1, 1].set_title('s3')

    # axs[1, 1].stem(x_vals, s)
    # axs[1, 1].plot(x_vals, s)
    # axs[1, 1].set_title('s')

    plt.tight_layout()
    plt.show()

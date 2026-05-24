import serial
import matplotlib.pyplot as plt
import numpy as np

# Update COM port if needed
ser = serial.Serial("COM13",9600)

plt.ion()

fig = plt.figure()
ax = fig.add_subplot(111, projection='polar')
#Setting only for 0 to 180 instead of full circle
ax.set_thetamin(0)
ax.set_thetamax(180)

ax.set_theta_zero_location("W")
ax.set_theta_direction(-1)

angles=[]
distances=[]

while True:

    try:
        line = ser.readline().decode().strip()

        print(line)   # Debug

        angle, distance = line.split(",")

        angle=float(angle)
        distance=float(distance)

        angles.append(np.radians(angle))
        distances.append(distance)

        if len(angles)>180:
            angles=angles[-180:]
            distances=distances[-180:]

        ax.clear()

        ax.set_theta_zero_location("W")
        ax.set_theta_direction(-1)

        ax.set_ylim(0,50)

        ax.scatter(
            angles,
            distances
        )

        fig.canvas.draw()
        fig.canvas.flush_events()

    except Exception as e:
        print(e)
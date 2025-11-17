import subprocess
import pandas as pd
import matplotlib.pyplot as plt

# user input
num_walkers = int(input("Enter the number of walkers: "))
num_steps = int(input("Enter the number of steps: "))

# run the C++ simulation
subprocess.run(["./multiwalk.exe", str(num_walkers), str(num_steps)])

# read in the random walk csv
df = pd.read_csv("randomwalk.csv")

# plot the squared displacement
plt.figure()
plt.plot(df['step', df['exp_squared_disp']])
plt.xlabel("Step")
plt.ylabel("Expected Squared Displacement")
plt.title("Random Walk Ensemble Average")
plt.grid(True)
plt.show()
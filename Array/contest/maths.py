#importing mathematics library 
import math
import random
#importing the matplotlin library for ploting graphs/ histogram  
import matplotlib.pyplot as plt


def box_muller(mu, sigma):
  # generate two independent random numbers from a uniform distribution
  u1 = random.random()  
  u2 = random.random()
  # applying the Box-Muller transformation to get two independent
  # standard normally distributed random variables
  z1 = math.sqrt(-2 * math.log(u1)) * math.cos(2 * math.pi * u2)
  z2 = math.sqrt(-2 * math.log(u1)) * math.sin(2 * math.pi * u2)

  # transform z1 into a normal variable with mean mu and standard deviation sigma
  x = mu + sigma * z1
  
  return x

# taking input value of mu and sigma
mu = int(input("Enter mu: "))
sigma = int(input("Enter sigma: "))

# Generate 1000 random numbers from a normal distribution with mean mu and standard deviation sigma

random_numbers = []
for i in range(100000):
  x = box_muller(mu, sigma)
  random_numbers.append(box_muller(mu, sigma))

# Ploting a histogram of the random numbers
plt.hist(random_numbers, bins=75)
plt.xlabel('Value')
plt.ylabel('Frequency')
plt.title('Histogram of Random Numbers')
plt.show()
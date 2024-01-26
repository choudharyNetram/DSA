import numpy as np
import math

def common_area_circle_ellipse(circle_eq, ellipse_eq):
    
    x_c, y_c, r = circle_eq
    a, b, x_e, y_e = ellipse_eq

    # Construct a grid of points covering the potential overlap region
    x, y = np.linspace(x_c - r - a, x_c + r + a, 4000), np.linspace(y_c - r - b, y_c + r + b, 4000)
    X, Y = np.meshgrid(x, y)

    # Determine points inside the circle and ellipse
    inside_circle = (X - x_c)**2 + (Y - y_c)**2 <= r**2
    inside_ellipse = ((X - x_e) / a)**2 + ((Y - y_e) / b)**2 <= 1

    # Find overlapping points
    common_area = np.count_nonzero(inside_circle & inside_ellipse)

    # Calculate area using grid spacing
    grid_area = (x[1] - x[0]) * (y[1] - y[0])
    return common_area * grid_area



# Read input values

# Read input values from separate lines
R = float(input())
r = float(input())
Q = float(input())
# Convert Q to radians
Q_rad = math.radians(Q)

# Set parameters for the circle and ellipse
x1 = R * math.sin(Q_rad)
y1 =  math.cos(Q_rad) / 2.0

# Define the circle and ellipse
circle_eq = (x1, y1, r)  
ellipse_eq = (R, (1/2), 0, 0)  
common_area = common_area_circle_ellipse(circle_eq, ellipse_eq)
print(common_area)




Sean Niez  
dependencies: matplotlib  
  
Summary: This program seeks to provide a visual and numerical simulation of a "random walk." A "walker" is an entity  
whose only attributes are x and y coordinates on a plane. At every step, the walker will travel in a random  
direction by 1 unit of distance, where the walker starts at the origin (0, 0) at step 0. In this program, the user is   
afforded the ability to choose how many steps each walker takes in its random walk, as well as how many walkers there   
will be. Another feature of this program is that it computes the expected displacement an arbitrary walker should take.  
In random walks, displacement is not the same as distance traveled. Here, displacement is the magnitude of the  
position vector drawn from the origin (0, 0) to the walker at some step.  
  
The program begins in C++. Here, the user inputs the parameters for the simulation, and the computations then take place.  
The other language used here is python for visualization.  
  
C++ is the best choice for the computation side of this due to the fact that there could potentially be a very large  
quantity of both walkers and steps, meaning that a computationally efficient language is a must. Python was employed  
here since it is very well suited in producing visuals for the random walk, using matplotlib.  
  
The languages are connected in the sense that python acts as a frontend, where the user inputs the parameters for the  
simulation and views the output, and C++ handles the computations. The user inputs the parameters, which are treated as  
command line arguments for the executable, and then running the C++ executable as a subprocess. At this point, the C++   
program runs the full simulation, and outputs everything to a CSV. Then, python reads the CSV and produces visualizations  
of the simulation.
  
  
  
  
  
Future work: With more time, this program could be adapted to simulate a wider range of scenarios. At this point, the  
expected squared displacement as a function of time is what is known as "normal diffusion," meaning that the motion is  
completely random with no bias or instigating factors. But this leaves out two other forms of diffusion that could  
simulate different environments. These being "subdiffusion," where the walker(s) is in a constrained, crowded, sticky  
environment. As well as "superdiffusion," meaning that the walker(s) have some sort of boost or momentum.

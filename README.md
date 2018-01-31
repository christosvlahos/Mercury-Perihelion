# Precession of Mercury's Perihelion

## Introduction
We examine the precession of Mercury's perihelion under the effects of General Relativity. From early years the observed value of the angle could not agree with the predictions given by Newtonian theory. However Einstein's theory of General Relativity managed to explain the remaining part of the precession angle.

## Program Compilation
To use the program for the simulation of the planet orbit, download the files using:
```
git clone https://github.com/christosvlahos/Precession-of-Mercury-s-Perihelion
```
To compile it, run ```make``` in your terminal and it'll create an executable named ```mercury```.
Finally run ```./mercury``` to run the simulation. The ```main.cpp``` file uses the data structures containing position and velocity in x and y direction and the functions defined in ```functions.cpp``` and ```fun.h```.
<br />
To get the results 5 input parameters are needed:
1. Eccentricity value
2. Total simulation time in years
3. GR correction parameter value
4. Name of file to store coordinates of the orbit and times
5. Name of file to store precession angles and their times

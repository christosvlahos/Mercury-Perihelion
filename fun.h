#ifndef fun_h
#define fun_h

#include<fstream>
#include<iostream>
#include<cmath>
#include<vector>


using namespace std;


typedef struct position{
  double x;
  double y;
  double vx;
  double vy;
} state;


state Eom(double a, state pos);

state addit(state a, state b);

state multit(state a, double b);

void rk4(double a, double dt, state init, state x[]);

#endif

#include"fun.h"

state Eom(double a, state pos){
  const double pi = 3.1415926535897;
  double Gm = 4* pow(pi,2); //Product of G and solar mass 
  double r = sqrt(pow(pos.x,2) + pow(pos.y,2));

  state res;
     
  res.x = pos.vx;
  res.y = pos.vy;
  res.vx =  (Gm * pos.x) * (-1 + a/pow(r,2)) / pow(r,3);
  res.vy =  (Gm * pos.y) * (-1 + a/pow(r,2)) / pow(r,3);

  return res;
}

state addit(state a, state b){
  
  state c;
  
  c.x = a.x + b.x;
  c.y = a.y + b.y;
  c.vx = a.vx + b.vx;
  c.vy = a.vy + b.vy;
  
  return c;
}
  
state multit(state a, double b){
  
  state c;
  
  c.x = b * a.x;
  c.y = b * a.y;
  c.vx = b * a.vx;
  c.vy = b * a.vy;
  
  return c;
}


void  rk4(double a, double dt, state init, state x[]){

  
  state k1, k2, k3, k4;

  k1 = Eom(a, init);  
  k2 = Eom(a, addit(init, multit(k1, 0.5*dt)));
  k3 = Eom(a, addit(init, multit(k2, 0.5*dt))); 
  k4 = Eom(a, addit(init, multit(k3, dt))); 

  x[0] = k1;
  x[1] = k2;
  x[2] = k3;
  x[3] = k4;
}


  

    	
   
  

#include"fun.h"


int main(){

   const double pi = 3.1415926535897;
   double GM = 4 * pow(pi, 2);
   double e;
   cout << "Eccentricity value is: ";
   cin >> e;
   double perih = 0.30966; //value of perihelion for Mercury
   double a = perih/(1 - e); // elliptic orbit major semi-axis
  
  state init; // initial state of (position, velocity)
  
   init.x = a * (1 + e); // initial x position in AU, depending on eccentricity
  //init.x = 0.47;
  init.y = 0; //initial y position in AU
  init.vx = 0; // initial velocity in x direction in AU/yr
  //init.vy = 8.2;
   init.vy = sqrt((GM * (1 - e)) / (a * (1 + e))); // initial velocity in y direction in AU/yr
  
  double t0 = 0;  // initial time
  double dt = 0.0001;  // time step in years
  double T;   // time endpoint in years
  cout << "Total run time is: ";
  cin >> T			

  int n;         // number of steps
  n = T / dt + 1;
  
  int i;      // variable for the loop
  
  double alpha;
  cout << "Correction term value is: ";
  cin >> alpha;
  
  double ts[n]; // stores time
  double xs[n]; // stores x-values
  double ys[n]; // stores y-values
  double vxs[n]; // stores velocities at x direction
  double vys[n]; // stores velocities at y direction

  std::vector<double> theta;
  std::vector<double> time;

  ts[0] = t0;
  xs[0] = init.x;
  ys[0] = init.y;
  vxs[0] = init.vx;
  vys[0] = init.vy;

  
  for (i = 0; i < n-1; i++){

    state mid;
    mid.x = xs[i];
    mid.y = ys[i];
    mid.vx = vxs[i];
    mid.vy = vys[i];
    
    state arr[4];
    
    rk4(alpha,dt,mid, arr);
    
    
    state m1,m2,m3;

    m1 = addit(arr[0], multit(arr[1], 2));
    m2 = addit(arr[3], multit(arr[2], 2));
    m3 = addit(m1, m2);

    xs[i+1] = xs[i] + (m3.x * dt/6);
    ys[i+1] = ys[i] + (m3.y * dt/6);
    vxs[i+1] = vxs[i] + (m3.vx * dt/6);
    vys[i+1] = vys[i] + (m3.vy * dt/6);
    ts[i+1] = ts[i] + dt;


    if((xs[i]*vxs[i]+ys[i]*vys[i])<0 && (xs[i+1]*vxs[i+1]+ys[i+1]*vys[i+1])>0){

      double angle = acos(xs[i] / sqrt(pow(xs[i],2) + pow(ys[i],2))) * 180 / pi;
      if (ys[i] < 0){
	angle = 360 - angle;
      }
      angle = fabs(angle - 180);
      theta.push_back(angle);
      time.push_back(ts[i]);
    }
  }

  ofstream myfile;
  myfile.open ("coords.csv");

  for( i=0; i<n; i++){
    myfile << ts[i] << "," << xs[i] << "," << ys[i] << "," << vxs[i] << "," << vys[i] << "\n";
  }
  myfile.close();

  ofstream file1;
   file1.open ("precession.csv");
  
   for(i = 0; i< theta.size(); i++){
     file1 << time[i] << "," << theta[i] << "\n";
   }
   file1.close();
  return(0);
}
    

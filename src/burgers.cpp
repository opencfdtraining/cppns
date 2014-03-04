#include "burgers.h"

using namespace std;

double ufunc(double t, double x, double nu)
{
  
  /* This is the equation -2*nu*(phiprime/phi)+4, C++ doesn't seem to have a nice and easy CAS system unless you want to dive into Maxima (I don't want to) so we calculate this before hand %/ */
  /* I'll be screwed if we need to calculate this stuff on the fly in future steps */
  return -2*nu*(-(-8*t + 2*x)*exp(-pow((-4*t + x),2)/(4*nu*(t + 1)))/(4*nu*(t + 1)) - (-8*t + 2*x - 12.5663706143592)*exp(-pow((-4*t + x - 6.28318530717959),2)/(4*nu*(t + 1)))/(4*nu*(t + 1)))/(exp(-pow((-4*t + x - 6.28318530717959),2)/(4*nu*(t + 1))) + exp(-pow((-4*t + x),2)/(4*nu*(t + 1)))) + 4;

}

void burgers()
{
  const double PI = 3.141592653589793238463; // Precalculate this too...
  double nx = 101;
  double nt = 100;
  double dx = 2*PI/(nx-1);
  double nu = .07;
  double dt = dx/nu;
  double t = 0;
  
  // Make an output folder
  string dir = "step4/";
  mkdir(dir.c_str(),0755); //Make a folder to store results in
  
  Eigen::ArrayXd x; // Array containing our x values
  x.setLinSpaced(nx,0,2*PI);
  
  Eigen::ArrayXd y; // Array containing our y values
  Eigen::ArrayXd yn; // Temporary storage for y values
  
  y.setZero(nx,1);
  yn.setZero(nx,1);
  
  for(int i; i<nx;i++)
  {
    y(i,1) = ufunc(t,x(i,1),nu); // Uses our function we defined
  }
  
    ofstream writexdata((dir + "output.dat").c_str(), ios::out | ios::trunc);
    for (int i=0;i<nx;i++){
        writexdata << x(i) << "\t" << y(i) << endl;
    }

    writexdata.close();
  
}
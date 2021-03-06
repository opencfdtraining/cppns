#include "arrayops.h"

void arrayops() {
  double nx = 10;
  double ny = 10;
  double nt = 100;
  double c = 1;
  double dx = 2/(nx-1);
  double dy = 2/(ny-1);
  double sigma = .2;
  double dt = sigma*dx;
  
  Eigen::ArrayXd x; // Array containing our x values
  x.setLinSpaced(nx,0,2);
  
  Eigen::ArrayXd y; // Array containing our x values
  y.setLinSpaced(ny,0,2);

  Eigen::ArrayXXd u;
  u.setOnes(ny,nx);
  
  Eigen::ArrayXXd un;
  un.setOnes(ny,nx);
  
  u.block(.5/dy,.5/dx,(1/dy+1)-.5/dy,(1/dx+1)-.5/dx) = Eigen::ArrayXXd::Constant((1/dy+1)-.5/dy,(1/dx+1)-.5/dx,2);
  
  int count;
  for(int i=0;i<nt;i++) {
    un << u;
    u.block(1,1,ny-1,nx-1) = un.block(1,1,ny-1,nx-1)-(c*dt/dx*(un.block(1,1,ny-1,nx-1)-un.block(0,1,ny-1,nx-1)))-(c*dt/dy*(un.block(1,1,ny-1,nx-1)-un.block(1,0,ny-1,nx-1)));
    
  }
  
  std::cout << u << std::endl;
 
}  
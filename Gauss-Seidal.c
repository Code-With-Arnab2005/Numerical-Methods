#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/* Defining the system of equations:
   20x + y  - 2z = 17   =>  x = (17 - y + 2z)/20
   3x  + 20y - z = -18  =>  y = (-18 - 3x + z)/20
   2x  - 3y + 20z = 25  =>  z = (25 - 2x + 3y)/20
*/

#define f1(x, y, z)  ((17 - y + 2*z) / 20)
#define f2(x, y, z)  ((-18 - 3*x + z) / 20)
#define f3(x, y, z)  ((25 - 2*x + 3*y) / 20)


int main(){
    float x0=0, y0=0, z0=0;
    float x1, y1, z1, e1, e2, e3, e;
    printf("Enter the tolerable error: ");
    scanf("%f", &e);
    int step=0;

    do{
        x1=f1(x0,y0,z0);
        y1=f2(x1,y0,z0);
        z1=f3(x1,y1,z0);

        e1=fabs(x1-x0);
        e2=fabs(y1-y0);
        e3=fabs(z1-z0);

        x0=x1, y0=y1, z0=z1;

        step++;
    } while(e1>e || e2>e || e3>e);
    printf("Solution: x=%.3f y=%.3f z=%.3f", x1, y1, z1);
    return 0;
}
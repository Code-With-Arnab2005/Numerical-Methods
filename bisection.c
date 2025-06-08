#include<stdio.h>
#include<math.h>

#define f(x) cos(x)-x*exp(x)

int main(){
    float x0, x1, x2, f0, f1, f2, e;
    int step = 1;
    
    printf("Enter the initial gausses: ");
    scanf("%f%f", &x0, &x1);
    
    printf("Enter the tolarabel error: ");
    scanf("%f", &e);
    
    f0 = f(x0);
    f1 = f(x1);

    while(f0*f1 > 0.0){
        printf("Incorrect Initial gauss\nplease Enter gausses again: ");
        scanf("%f%f", &x0, &x1);
        f0 = f(x0);
        f1 = f(x1);
    }

    printf("Step\t\tx0\t\tx1\t\tx2\t\tf2\n");

    do {
        x2 = (x0+x1)/2;
        f2 = f(x2);

        printf("%d\t\t%f\t\t%f\t\t%f\t\t%f\n", step, x0, x1, x2, f2);
        
        if(f0*f2 < 0.0){
            x1=x2;
            f1=f2;
        } else {
            x0=x2;
            f0=f2;
        }
        step++;
    } while(fabs(f2)>e);

    printf("Root is: %f", x2);
    return 0;
}
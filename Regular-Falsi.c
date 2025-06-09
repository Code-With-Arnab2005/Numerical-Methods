#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define f(x) x*log10(x) - 1.2
int main(){
    float x0,x1,x2,f0,f1,f2,e;
    int step=1;
    printf("Enter initial Gausses: ");
    scanf("%f%f", &x0, &x1);
    printf("Enter tolerable Error: ");
    scanf("%f", &e);
    while(f0*f1 > 0.0){
        printf("Wrong Info, please give again\n");
        scanf("%f%f", &x0, &x1);
    }
    do{
        f0=f(x0), f1=f(x1);
        x2 = x0-(x0-x1) * f0/(f0-f1);
        f2 = f(x2);
        printf("%d\t\t%f\t\t%f\t\t%f\t\t%f\n", step, x0, x1, x2, f2);
        if(f0*f2<0.0){
            x1=x2;
            f1=f2;
        } else {
            x0=x2;
            f0=f2;
        }
        step++;
    } while(fabs(f2)>e);
    printf("The Root is: %f", x2);
    return 0;
}
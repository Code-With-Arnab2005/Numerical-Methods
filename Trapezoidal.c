#include<stdio.h>
#include<math.h>
#define f(x) (1.0 / (1.0 + (x)*(x)))

int main(){
    float x0, x1;
    int n;

    printf("Enter the upper and lower limit: ");
    scanf("%f%f", &x0, &x1);
    printf("Enter the number of steps: ");
    scanf("%d", &n);

    float f0 = f(x0);
    float f1 = f(x1);

    float ans = 0;

    float h = (float)(x1-x0)/(float)n;
    printf("%f\n", (float)(x1-x0));
    
    //formula => y = h/2[(y0+yn) + 2(y1+y2+y3+...+yn-1)]
    float ft = f0+f1;
    float st = 0;
    for(float i=x0+h; i<x1; i=i+h){
        st += f(i);
        // printf("%f\n", i);
    }
    printf("Ans is: %f\n", (float)(h*(ft+2*st))/2);
    return 0;
}
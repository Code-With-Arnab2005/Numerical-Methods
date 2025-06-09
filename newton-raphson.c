// #include<stdio.h>
// #include<math.h>
// #include<stdlib.h>

// #define f(x) 3*x-cos(x)-1
// #define g(x) 3+sin(x)

// int main(){
//     float x0, x1, f0, f1, g0, e;
//     int step=1, N;

//     printf("Enter the initial Gauss: ");
//     scanf("%f", &x0);

//     printf("Enter tolerable error: ");
//     scanf("%f", &e);

//     printf("Enter maximum iteration: ");
//     scanf("%d", &N);

//     printf("\nStep\t\t\tx0\t\t\tf(x0)\t\t\tx1\t\t\tf(x1)\n");

//     do {

//         g0 = g(x0);
//         f0 = f(x0);

//         if(g0==0.0){
//             printf("Mathematical Error\n");
//             exit(0);
//         }

//         x1 = x0 - f0/g0;
//         printf("%d\t\t%f\t\t%f\t\t%f\t\t%f\n", step, x0, f0, x1, f1);
//         x0=x1;
//         step++;
        
//         if(step>N){
//             printf("Not Convergent\n");
//             exit(0);
//         }

//         f1=f(x1);

//     } while(fabs(f1)>e);

//     printf("Root is: %f", x1);
//     return 0;
// }

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define f(x) 3*x-cos(x)-1 
#define g(x) 3+sin(x)

int main(){
    float x0, x1, f0, f1, g0, e;
    printf("Enter the initial gauss: ");
    scanf("%f", &x0);

    printf("Enter the tolerable error: ");
    scanf("%f", &e);

    int step=1, N;
    printf("Enter the max number of interation: ");
    scanf("%d", &N);

    printf("Step\t\tx0\t\tx1\t\tf0\t\tf1\n");

    do {
        f0=f(x0);
        g0=g(x0);
        if(g0==0.0){
            printf("Mathematical Error\n");
            exit(0);
        }
        x1 = x0 - f0/g0;
        f1=f(x1);
        printf("%d\t\t%f\t\t%f\t\t%f\t\t%f\n", step, x0, x1, f0, f1);
        step++;
        if(step==N){
            printf("Not Convergent\n");
            exit(0);
        }
        x0=x1;
        f1=f(x1);
    } while(fabs(f1)>e);

    printf("The Root is %f", x1);
    return 0;
}
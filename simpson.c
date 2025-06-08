#include<stdio.h>
#include<math.h>

#define f(x) (1.0 / (1.0 + (x) * (x)))

int main(){
    float lower, upper;
    printf("Enter the lower and upper value: ");
    scanf("%f%f", &lower, &upper);

    int n;
    printf("Enter the number of intervals: ");
    scanf("%d", &n);

    float h = (upper-lower)/n;

    float ft = f(lower)+f(upper);

    float evenSum=0, oddSum=0;
    for(float i=lower+h; i<upper; i+=2*h){
        oddSum += f(i);
    }
    for(float i=lower+2*h; i<upper; i+=2*h){
        evenSum += f(i);
    }

    float ans = (h*(ft + 4*oddSum + 2*evenSum))/3;
    printf("ans: %f", ans);

    return 0;
}
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main(){
    int n;
    printf("Enter the number of variables: ");
    scanf("%d", &n);

    float a[n][n+1], ans[n];
    printf("Enter the values of matrix\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n+1; j++){
            scanf("%f", &a[i][j]);
        }
    }

    //constructing upper triangular matrix
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            float ratio = a[j][i]/a[i][i];
            for(int k=0; k<n+1; k++){
                a[j][k] = a[j][k] - ratio*a[i][k];
            }
        }
    }

    //backsubstitution method
    ans[n-1]=a[n-1][n]/a[n-1][n-1];
    for(int i=n-2; i>=0; i--){
        float curr=a[i][n];
        for(int j=n-1; j>=i+1; j--){
            curr -= a[i][j]*ans[j];
        }
        ans[i] = curr/a[i][i];
    }

    //printing output
    printf("So the variables are: ");
    for(int i=0; i<n; i++){
        printf("%f ", ans[i]);
    }

    return 0;
}
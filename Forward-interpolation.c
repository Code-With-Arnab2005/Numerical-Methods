#include<stdio.h>
#include<math.h>
int size = 100;
int main(){

    int n;
    printf("Enter number of entries: ");
    scanf("%d", &n);
    float ax[n], ay[n], diff[n-1][n-1], x;

    printf("Enter the values of x and y for each iteration\n");
    for(int i=0; i<n; i++){
        scanf("%f%f", &ax[i], &ay[i]);
    }

    printf("Enter the value of x: ");
    scanf("%f", &x);

    //first order difference
    for(int i=0; i<n-1; i++){
        diff[i][0] = ay[i+1] - ay[i];
        // printf("%f %f %f\n", ay[i+1], ay[i], diff[i][0]);
    }

    // for(int i=0; i<n-1; i++){
    //     for(int j=0; j<n-1; j++){
    //         printf("%f ", diff[i][j]);
    //     }
    //     printf("\n");
    // }

    //higher order differnece
    int cnt = 1;
    while(cnt<n-1){
        // printf("col: %d\n", cnt);
        for(int i=0; i<n-1-cnt; i++){
            diff[i][cnt] = diff[i+1][cnt-1] - diff[i][cnt-1];
            // printf("%f %f %f\n", ay[i+1], ay[i], diff[i][0]);
        }
        for(int i=n-1-cnt; i<n-1; i++) diff[i][cnt]=0;

        // printf("col: %d\n", cnt);
        // for(int i=0; i<n-1; i++){
        //     for(int j=0; j<n-1; j++){
        //         printf("%f ", diff[i][j]);
        //     }
        //     printf("\n");
        // }
        cnt++;
    }

    // for(int i=0; i<n-1; i++){
    //     for(int j=0; j<n-1; j++){
    //         printf("%f ", diff[i][j]);
    //     }
    //     printf("\n");
    // }

    //calculate h
    float h = ax[1]-ax[0];

    //calculate u
    float u = (x-ax[0])/h;

    //calculate y using formula
    float upper=1, lower=1, ans=ay[0];

    for(int i=0; i<n-1; i++){
        upper *= (u-i);
        lower *= (i+1);
        // printf("%d %f %f\n", i, upper, lower);
        ans += (float)(upper*diff[0][i])/lower;
    }

    printf("So the value for x=%f is %f", x, ans);

    return 0;
}
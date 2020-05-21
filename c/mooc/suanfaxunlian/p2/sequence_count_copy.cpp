#include <cstdio>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>

const int N = 300005;

int n, d, a[N];
int maxa[N], f1, r1;
int mina[N], f2, r2;

void update_max_index(int *array,int * low,int *high,int *max,int*min,int d);
void update_min_index(int *array,int * low,int *high,int *max,int*min,int d);


int main() {

    srand(time(NULL));
    
    int n=0;
    long d=0;
    scanf("%d",&n);
    scanf("%ld",&d);
    for(int i=0;i<n;i++){
        a[i]=rand();
        printf("%d ",a[i]);
    }
    printf("\n ");


   /* scanf("%d%d", &n, &d);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i)
        printf("%d \n ", a[i]);
    */
    long long ans = 0;
    for (int i = 0, j = 0; i < n; ++i) {
        while (f1 < r1 && a[maxa[r1 - 1]] < a[i]) --r1;
        while (f2 < r2 && a[mina[r2 - 1]] > a[i]) --r2;
        maxa[r1++] = i;
        mina[r2++] = i;
        while (a[maxa[f1]] - a[mina[f2]] > d) {
            if (j == maxa[f1])
                f1++;
            if (j == mina[f2])
                f2++;
            ++j;
        }
        ans += i - j;
    }

    printf("%lld\n", ans);

    int low=0;
    int high=0;
    int max=0;
    int min=0;
    long long total=0;
    for(int i=0;i<n;i++){
        high=i;
        if(a[i]>a[max]){
            max=i;
            update_min_index(a,&low,&high,&max,&min,d);
        }
        else if(a[i]<a[min]){
            min=i;
            update_max_index(a,&low,&high,&max,&min,d);
        }
        total+=(high-low);
        //print_seq(array,low,high);
    }
    printf("%lld",total);


    return 0;
}


void update_max_index(int *array,int * low,int *high,int *max,int*min,int d){
//    printf("Update max: Max: %d, min: %d,High: %d, low: %d\n",*max,*min,*high,*low);
    while(*max!=*min){
        if(array[*max]-array[*min]>d){
            (*max)++;
            *low=*max;
            continue;
        }
        else{   
            break;
        }
    }

}
void update_min_index(int *array,int * low,int *high,int *max,int*min,int d){
//    printf("Update min: Max: %d, min: %d,High: %d, low: %d\n",*max,*min,*high,*low);
    while(*max!=*min){
        if(array[*max]-array[*min]>d){
            (*min)++;
            *low=*min;
            continue;
        }
        else{
            break;
        }
    }
//    printf("updated\n");
}
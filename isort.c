#include <stdio.h>
#define SIZE 50

void shift_element(int *arr,int i){
    int temp=*(arr+i);
    for (int j = i; j >=0 ; j--) {
        *(arr+j)=*(arr+j-1);
    }
    *arr=temp;
}

void insertionSort(int *arr, int len)
{
    int key, j;
    for (int i = 1; i < len; i++) {
        j = i - 1;
        key = *(arr+i);

        int count = 0;
        while (j >= 0 && *(arr+j) > key) {
            j--;
            count++;
        }
        shift_element(arr+j+1,count);
    }
}

int main(){
    int arr[SIZE];
    int j=0;
    int x;
    while(j<SIZE){
        scanf("%d",&x);
        *(arr+j)=x;
        j++;
    }
    insertionSort(arr,SIZE);
    for (int i = 0; i < SIZE-1; ++i) {
        printf("%d,",*(arr+i));
    }
    printf("%d\n",*(arr+SIZE-1));
}
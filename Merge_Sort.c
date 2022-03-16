#include<stdio.h>
#define SIZE 100

void merge(int arr[],int beg,int mid, int end)
{
    int i=beg,j = mid+1,index=beg,temp[SIZE],k;
    while((i<=mid) && (j<=end)) {
        if(arr[i] < arr[j]) {
            temp[index] = arr[i];
            i++;
        }
        else {
            temp[index] = arr[j];
            j++;
        }
        index++;
    }
    if(i>mid) {
        while(j<=end) {
            temp[index] = arr[j];
            j++;
            index++;
        }
    }
    else {
        while(i<=mid) {
            temp[index] = arr[i];
            i++;
            index++;
        }
    }
    for(k=beg; k<index; k++)
        arr[k] = temp[k];
}

void mergeSort(int arr[],int beg, int end) {
    int mid;
    if(beg<end) {
        mid = (beg+end)/2;
        mergeSort(arr,beg,mid);
        mergeSort(arr,mid+1,end);
        merge(arr,beg,mid,end);
    }
}
int main()
{
    int arr[SIZE],i,n;
    printf("\n Enter the number of elements in the array : ");
    scanf("%d",&n);
    printf("\n Enter the elements of the array : ");
    for(int i=0; i<n; i++)
        scanf("%d",&arr[i]);
    mergeSort(arr,0,n-1);
    printf("\n The sorted array is : ");
    for(int i=0; i<n; i++)
        printf("%d ",arr[i]);
    return 0;
}

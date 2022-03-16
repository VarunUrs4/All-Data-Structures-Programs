#include<stdio.h>
#define SIZE 100

int partition(int a[],int beg,int end)
{
    int left,right,temp,loc,flag;
    loc = left = beg;
    right = end;
    flag =0;

    while(flag != 1) {
        while((a[loc] <= a[right]) && (loc != right))
            right--;

        if(loc == right)
            flag = 1;

        else if(a[loc] > a[right]) {
            temp = a[loc];
            a[loc] = a[right];
            a[right] = temp;
            loc = right;
        }

        if(flag != 1) {
            while((a[loc] >= a[left]) && (loc != left))
                left++;

            if(loc == left)
                flag = 1;

            else if(a[loc] < a[left]) {
                temp = a[loc];
                a[loc] = a[left];
                a[left] = temp;
                loc = left;
            }
        }
    }
    return loc;
}

void quickSort(int a[],int beg, int end) {
    int loc;
    if(beg<end) {
        loc = partition(a,beg,end);
        quickSort(a,beg,loc-1);
        quickSort(a,loc+1,end);
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
    quickSort(arr,0,n-1);
    printf("\n The sorted array is : ");
    for(int i=0; i<n; i++)
        printf("%d ",arr[i]);
    return 0;
}

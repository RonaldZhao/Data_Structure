#include <stdio.h>
//二分查找，建立在已排好序的基础上
int maxId(int a[], int len){
    int maxid = 0;
    for(int i = 0; i<len; i++){
        if(a[i]>a[maxid])
            maxid = i;
    }
    return maxid;
}

int search(int a[],int len, int key){
    int left=0, mid, right=len-1;

    mid = (left+right)/2;
    while(right>left){
        if(a[mid]==key){
            break;
        }else if(a[mid]>key){
            right = mid-1;
        }else{
            left = mid+1;
        }
        mid = (left+right)/2;
    }
    return mid;
}

int main()
{
    int a[] = {1,3,5,6,4,12,59,33,22,90,8,36,67,42};
    int len = sizeof(a)/sizeof(a[0]),i,temp;

    for(i=len-1;i>0;i--){   //排序
        int maxid = maxId(a, i+1);
        temp = a[maxid];
        a[maxid] = a[i];
        a[i] = temp;
    }

    for(i=0; i<len; i++){   //排好序后输出
        printf("%d ",a[i]);
    }

    printf("\nid = %d\n", search(a,len,3));

    return 0;
}

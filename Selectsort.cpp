#include <iostream>

using namespace std;

/*
 * 选择排序（Selection sort）是一种简单直观的排序算法。
    它的工作原理是：第一次从待排序的数据元素中选出最小（或最大）的一个元素，
    存放在序列的起始位置，然后再从剩余的未排序元素中寻找到最小（大）元素，
    然后放到已排序的序列的末尾。以此类推，直到全部待排序的数据元素的个数为零。

选择排序是不稳定的排序方法。
 *
 * */

void select_sort(int a[], int n)
{
    int tmp;
    int i = 0, j = 0, k = 0;

    for (i=0; i < n-1; i++)
    {
        k = i;

        for (j=i+1; j < n; j++)
        {
            if (a[k] > a[j])
            {
                k = j;
            }
        }

        if (k != i)
        {
            tmp=a[k];
            a[k]=a[i];
            a[i]=tmp;
        }
    }
}



int main(){
    int a[] {9,8,7,6,5,4,3,2,1,0};
    for(int i = 0;i < sizeof(a)/ sizeof(int);i++){
        cout<<a[i];
    }
    cout<<endl;
    select_sort(a, sizeof(a)/ sizeof(int));
    for(int i = 0;i < sizeof(a)/ sizeof(int);i++){
        cout<<a[i];
    }
    return 0;
}




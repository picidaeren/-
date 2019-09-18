#include <iostream>

using namespace std;

/*
 * 快速排序的时间复杂度在最坏情况下是O(N2)，平均的时间复杂度是O(N*lgN)。
 *
 * 快速排序算法通过多次比较和交换来实现排序，其排序流程如下：
(1)首先设定一个分界值，通过该分界值将数组分成左右两部分。
(2)将大于或等于分界值的数据集中到数组右边，小于分界值的数据集中到数组的左边。
 此时，左边部分中各元素都小于或等于分界值，而右边部分中各元素都大于或等于分界值。
(3)然后，左边和右边的数据可以独立排序。对于左侧的数组数据，又可以取一个分界值，
 将该部分数据分成左右两部分，同样在左边放置较小值，右边放置较大值。右侧的数组
 数据也可以做类似处理。
(4)重复上述过程，可以看出，这是一个递归定义。通过递归将左侧部分排好序后，
 再递归排好右侧部分的顺序。当左、右两个部分各数据排序完成后，整个数组的排序也就完成了。

一趟快速排序的算法是： [1]
1）设置两个变量i、j，排序开始的时候：i=0，j=N-1；
2）以第一个数组元素作为关键数据，赋值给key，即key=A[0]；
3）从j开始向前搜索，即由后开始向前搜索(j--)，找到第一个小于key的值A[j]，
 将A[j]和A[i]的值交换； [1]
4）从i开始向后搜索，即由前开始向后搜索(i++)，找到第一个大于key的A[i]，
 将A[i]和A[j]的值交换； [1]
5）重复第3、4步，直到i=j； (3,4步中，没找到符合条件的值，
 即3中A[j]不小于key,4中A[i]不大于key的时候改变j、i的值，使得j=j-1，
 i=i+1，直至找到为止。找到符合条件的值，进行交换的时候i， j指针位置不变。
 另外，i==j这一过程一定正好是i+或j-完成的时候，此时令循环结束）。
 *
 *
 * */



void Qsort(int arr[], int low, int high){
    if (high <= low) return;
    int i = low;
    int j = high + 1;
    int key = arr[low];
    while (true)
    {
        /*从左向右找比key大的值*/
        while (arr[++i] < key)
        {
            if (i == high){
                break;
            }
        }
        /*从右向左找比key小的值*/
        while (arr[--j] > key)
        {
            if (j == low){
                break;
            }
        }
        if (i >= j) break;
        /*交换i,j对应的值*/
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    /*中枢值与j对应值交换*/
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    Qsort(arr, low, j - 1);
    Qsort(arr, j + 1, high);
}

int main()
{
    int a[] = {9,8,7,6,5,4,3,2,1,0};
    for(int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    {
        cout << a[i] << " ";
    }
    cout<<endl;
    Qsort(a, 0, sizeof(a) / sizeof(a[0]) - 1);/*这里原文第三个参数要减1否则内存越界*/

    for(int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}
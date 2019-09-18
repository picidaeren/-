#include <iostream>

using namespace std;

/*
 * 冒泡排序算法
原理如下：
比较相邻的元素。如果第一个比第二个大，就交换他们两个。
对每一对相邻元素做同样的工作，从开始第一对到结尾的最后一对。
 在这一点，最后的元素应该会是最大的数。
针对所有的元素重复以上的步骤，除了最后一个。
持续每次对越来越少的元素重复上面的步骤，直到没有任何一对数字需要比较。
 *
 *
 * */

void bubblesort(int a[],int size){
    int i,j,temp;
    for(i = 0; i < size;i++){
        for(j = 0;j < size-i-1;j++){
            if(a[j] >  a[j + 1]){
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

}

int main(){
    int a[] {9,8,7,6,5,4,3,2,1,0};
    for(int i = 0;i < sizeof(a)/ sizeof(int);i++){
        cout<<a[i];
    }
    cout<<endl;
    bubblesort(a, sizeof(a)/ sizeof(int));
    for(int i = 0;i < sizeof(a)/ sizeof(int);i++){
        cout<<a[i];
    }
    return 0;
}




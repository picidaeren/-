#include <iostream>
using namespace std;

/*
 * 插入排序
   时间复杂度平均O(n2)，最好O(n)，最差O(n2)，空间复杂度O(1)，就地、稳定的排序；
   思路为：从第一与第二个元素开始，不断考虑后缀的元素，将其插入到前缀中合适其的位置，
   随着插入，其后的所有位置都需要改变。类似于打扑克时的抽牌，不过这里的牌是全部知道的。
 *
 * */
template<typename T>
void insertionsort(T data[], int n)
{
    for(int i = 0; i < n;i++){
        cout<<data[i]<<" ";
    }
    cout<<endl;
    for (int i = 1, j; i < n; i++)
    {
        T tmp = data[i];
        for (j = i; j > 0 && tmp < data[j - 1]; j--)
            //注意只有<才会移动，=不动的

            data[j] = data[j - 1];   //插入的数（也就是每次后缀的第一个数）
            // 不断与其前面的数字比较，比其大就向前交换，直至比它小或到数组头
        data[j] = tmp;  //最后退出的那个位置被tmp赋值进去补充即可
    }
    for(int i = 0; i < n;i++){
        cout<<data[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int a[] = {9,8,7,6,5,4,3,2,1,0};
    insertionsort(a, sizeof(a)/ sizeof(int));

    return 0;
}
#include <iostream>

using namespace std;

//冒泡排序
void swap(int* num1, int* num2)
//交换两个指针所指向的元素的值
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void BubbleSort(int arr[], int len)
{
    for(int i = 0;i < len - 1 ; i++ )
    {
        bool sorted = true;
        for(int j = 0; j < len - 1 - i; j++)
        {
            if(arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                sorted = false;
            }
            if(sorted)
                break;
        }
    }
}
int main() {
    int stttest[] = {11, 16, 18, 17, 1, 8, 9, 10, 12};
    int lenteststt = sizeof(stttest) / sizeof(stttest[0]);
    BubbleSort(stttest, lenteststt);
    printf("排序后的结果是：\n");
    for(int i = 0; i< lenteststt;  i++)
    {
        printf("%d ", stttest[i]);
    }
    cout << "Hello, World!" << endl;
    return 0;
}
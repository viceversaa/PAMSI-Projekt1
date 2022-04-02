#include <iostream>
// SORTOWANIE PRZEZ KOPCOWANIE
using namespace std;

void heapify(int arr[], int size, int start)
{
    int max = start;
    int ls = 2 * start + 1;
    int rs = 2 * start + 2;
    if (ls < size && arr[ls] > arr[max])
    {
        max = ls;
    }
    if (rs < size && arr[rs] > arr[max])
    {
        max = rs;
    }
    if (max != start)
    {
        swap(arr[max], arr[start]);
        heapify(arr, size, max);
    }
}

void heapsort(int arr[], int size)
{
    for (int i = size - 1; i >= 0; i--)
    {
        heapify(arr, size, i);
    }
    for (int i = size - 1; i > 0; i--)
    {
        swap(arr[i], arr[0]);
        heapify(arr, i, 0);
    }
}

/*int main()
{
    int arr[] = {6, 9, 7, 2, 8, 4, 9, 5, 3, 6};
    heapsort(arr, 10);
    for (int i = 0; i < 10; ++i)
        cout << arr[i] << ' ';
}*/


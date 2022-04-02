#include <iostream>
// QUICKSORT
using namespace std;

int partition(int arr[], int start, int end) 
{
    int pivot = arr[start]; //pivot jako wartość początkowa
    int count = 0; //ilość mniejszych elementów od pivota w tablicy
    for (int i = start; i < end; i++)
    {
        if (arr[i] < pivot) 
        {
            count++; //gdy wartość mniejsza od pivot to nalicza o 1
        }
    }
    int pivotIdx = start + count; //indeks pivota
    swap(arr[start], arr[pivotIdx]); //zamienia wartość pierwszego elementu i "wrzuca" go na odpowiednie miejsce
    int r = end - 1;
    int l = start;
    while (l < pivotIdx)
    {
        while (arr[l] < pivot)
        {
            l++;
        }
        while (r > pivotIdx && arr[r] >= pivot)
        {
            r--;
        }
        swap(arr[l], arr[r]); 
    }
    return pivotIdx;
}

void quicksort(int arr[], int start, int end)
{
    if (start + 1 >= end)
    {
        return;
    }
    int mid = partition(arr, start, end);//zwraca indeks pivota
    quicksort(arr, start, mid);
    quicksort(arr, mid + 1, end);
}

/*int main()
{
    int arr[] = {3, 2, 5, 4, 1, 9, 8, 7, 5, 4, 3, 8, 7, 0};
    quicksort(arr, 0, 14);

    for (int i = 0; i < 14; ++i)
    {
        cout << arr[i] << ' ';
    }
}*/

#include <iostream>
// SORTOWANIE PRZEZ SCALANIE
using namespace std;

template <typename T>
void merge(T arr[], int from, int mid, int to)
{
    T *arr1 = new T[to - from]; //dynamicznie zaalokowana tablica
    int i = from, j = mid, k = 0;
    while (i < mid || j < to)
    {
        if (j == to || (i != mid && arr[i] < arr[j]))
        {
            arr1[k] = arr[i];
            i++;
        }
        else
        {
            arr1[k] = arr[j];
            j++;
        }
        k++;
    }

    for (k = 0; k < to - from; k++)
    {
        arr[from + k] = arr1[k];
    }

    delete[] arr1; 
}

template <typename T>
void mergesort(T arr[], int from, int to)
{
    if (from + 1 == to)
    {
        return;
    }
    int mid = (from + to) / 2; //dzieli tablice na dwie części
    mergesort(arr, from, mid); //wywołanie rekurencyjne - sortuje od początku sortowanego fragmentu "mid"
    mergesort(arr, mid, to); //wywołanie rekurencyjne - sortuje od fragmentu "mid" do końca sortowanego fragmentu
    merge(arr, from, mid, to); 
}

/*int main()
{
    int arr[] = {3, 2, 5, 4, 1};
    mergesort(arr, 0, 5);

    for (int i = 0; i < 5; ++i)
        ;
    {
        cout << arr[i] << ' ';
    }
}*/
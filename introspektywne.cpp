#include <iostream>
#include <cmath>
#include "kopcowanie.cpp"
#include "quicksort.cpp"
// INTROSPEKTYWNE
using namespace std;

void IntroSortAux(int arr[], int start, int end, int M)
{
    if (start + 1 >= end) //kończy gdy skończy się tablica

    {
        return;
    }

    if (M <= 0) //działa no momentu wyczerpania możliwej głębokości rekurencji
    {
        heapsort(arr + start, end - start); //sortowanie przez kopcowanie
    }
    else
    {
        int mid = partition(arr, start, end); //zwraca indeks pivota
        IntroSortAux(arr, start, mid, M - 1); //rekurencyjne wywołanie - sortuje lewą strone tablicy
        IntroSortAux(arr, mid + 1, end, M - 1); //rekurencyjne wywołanie - sortuje prawą strone tablicy
    }
}

void IntroSort(int arr[], int size)
{
    int M = 2 * log(size) / M_LN2; //obliczenie maksymalnej głębokości rekurencji
    IntroSortAux(arr, 0, size, M);
}

/*int main()
{
    int arr[] = {6, 9, 7, 2, 8, 4, 9, 5, 3, 6};
    IntroSort(arr, 10);
    for (int i = 0; i < 10; ++i)
        cout << arr[i] << ' ';
}*/

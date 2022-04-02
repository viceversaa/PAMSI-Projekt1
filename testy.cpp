#include <iostream>
#include <cstdlib>
#include <time.h>
#include "introspektywne.cpp"
#include "scalanie.cpp"

using namespace std;

int *randomArr(int size) //tablica losowych elemntów
{
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand();
    }
    return arr;
}

int *reverseArr(int size) //tablica posortowana w odwrotnej kolejności
{
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = size - i;
    }
    return arr;
}

int *kopiuj(int *from, int size) //kopia tablicy - pomoc do maina
{
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = from[i];
    }
    return arr;
}

int *partiallySortedArr(int size, double p) //tablica z częściowo posortowanymi elementami
{
    int *arr = randomArr(size);
    quicksort(arr, 0, size * p);
    return arr;
}

bool check(int *arr, int size) //sprawdzenie czy tablica jest dobrze posortowana
{
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            cerr << "Błąd przy sortowaniu!!!" << endl;
            return false;
        }
    }
    return true;
}

int main()
{
    int sizes[] = {10000, 50000, 100000, 500000, 1000000}; //rozmiary tablic
    int n = 1; //ilość tablic
     //cout << "Wybrany przypadek tablicy: " << "wszystkie wartości losowe.\n" << endl;
     //cout << "Wybrany przypadek tablicy: " << 0.25 * 100 << "\% początkowych elementów tablicy jest już posortowanych.\n"<< endl;
     cout << "Wybrany przypadek tablicy: " << "wszystkie elementy tablicy już posortowane ale w odwrotnej kolejności. \n" << endl;

    for (int size : sizes)
    {
        double quicksortTime = 0, mergesortTime = 0, introSortTime = 0;

        for (int i = 0; i < n; i++)
        {
            int *arr = reverseArr(size); //tablica i wybór rodzaju elementów
            int *arr2 = kopiuj(arr, size); //kopia tablicy dla mergesorta
            int *arr3 = kopiuj(arr, size); //kopia tablica dla introsorta

            clock_t start = clock();
            quicksort(arr, 0, size);
            clock_t end = clock();
            quicksortTime += ((double)(end - start)) / CLOCKS_PER_SEC;
            check(arr, size);
            delete[] arr;

            start = clock();
            mergesort(arr2, 0, size);
            end = clock();
            mergesortTime += ((double)(end - start)) / CLOCKS_PER_SEC;
            check(arr2, size);
            delete[] arr2;

            start = clock();
            IntroSort(arr3, size);
            end = clock();
            introSortTime += ((double)(end - start)) / CLOCKS_PER_SEC;
            check(arr3, size);
            delete[] arr3;
        }

        cout << "Tablice o rozmiarze: " << size << endl;
        cout << "quicksort: " << quicksortTime / n << endl;
        cout << "mergesort: " << mergesortTime / n << endl;
        cout << "introSort: " << introSortTime / n << "\n" << endl;
    }
}
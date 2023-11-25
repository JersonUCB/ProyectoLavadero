#pragma once
#include <vector>

using namespace std;

template <class T>
class QuickSort
{
private:
    static int partitionLomuto(vector<T*>& array, int low, int high)
    {
        T* pivot = array[high];

        int i = low;
        for (int j = low; j < high; j++)
        {
            if (*array[j] <= *pivot)
            {
                T* aux = array[i];
                array[i] = array[j];
                array[j] = aux;
                i++;
            }
        }

        T* aux = array[i];
        array[i] = array[high];
        array[high] = aux;

        return i;
    }

    static void sort(vector<T*>& array, int low, int high)
    {
        if (low < high)
        {
            int pivot = partitionLomuto(array, low, high);
            sort(array, low, pivot - 1);
            sort(array, pivot + 1, high);
        }
    }

public:
    static void sort(vector<T*>& array)
    {
        sort(array, 0, array.size() - 1);
    }


    static void sort(vector<T*>& array, bool (*customComparator) (T*, T*))
    {
        sort(array, 0, array.size() - 1, customComparator);
    }

    static void sort(vector<T*>& array, int low, int high, bool (*customComparator)(T*, T*))
    {
        if (low < high)
        {
            int pivot = partitionLomuto(array, low, high, customComparator);
            sort(array, low, pivot - 1, customComparator);
            sort(array, pivot + 1, high, customComparator);
        }
    }

    static int partitionLomuto(vector<T*>& array, int low, int high, bool (*customComparator)(T*, T*))
    {
        T* pivot = array[high];

        int i = low;
        for (int j = low; j < high; j++)
        {
            if (customComparator(array[j], pivot)) //Compara que array[j] < array[high] para ordenar ascendetemente
            {
                T* aux = array[i];
                array[i] = array[j];
                array[j] = aux;
                i++;
            }
        }

        T* aux = array[i];
        array[i] = array[high];
        array[high] = aux;

        return i;
    }
};

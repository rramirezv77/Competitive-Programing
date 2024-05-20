#include<iostream>
//antes de compilar cualquier cosa, acuerdate de guardar lo que cambiaste

//ordena una lista de elementos uno a la vez a travez de comparaciones

//eficiente para numeros pequeños
//eficiente en la practica
//Complejidad O(n2)--cuadratica

int insertionSort(int arr[], int n)
{
    //----insertion sort----
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 and arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    //----------------------   
}
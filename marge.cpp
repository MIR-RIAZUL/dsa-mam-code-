#include <iostream>

using namespace std;

int main()
{
    int low = 0;

    int n;
    cout << "entrt the arry size :" << endl;
    cin >> n;
    int array[n];
    int high = n - 1;

    cout << "enetr the array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    cout << endl;
    cout << "the array before sort:" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    return 0;
}

void margeSort(int array[], int n, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        margeSort(array, low, mid);
        margeSort(array, mid + 1, high);
        merge(array, low, mid, high);
    }
}

void merge(int array[], int low, int mid, int high)
{
    int length_1, length_r;
    length_1 = mid - low + 1;
    length_r = high - mid;

    int a;

    int arrayLeft(length_1), arrayRight(length_r);
    for (a = 0; a < length_1; a++)
    {
        arrayLeft[a] = array[low + a];
    }

    for (a = 0; a < length_r; a++)
    {
        arrayRight[a] = array[mid + 1 + a];
    }
    int l = 0, r = 0, k = low;

    while (1 < length_1 && r < length_r)
    {
        if ()
    }
}
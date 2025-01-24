#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int target)
{
    int start = 0;
    int end = size - 1;

    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        int element = arr[mid];

        if (element == target)
        {
            return mid;
        }
        if (element < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return -1;
}

int main()
{
    int arr[] = {2, 4, 5, 6, 7, 8};
    int size = 6;
    int target = 7;

    int indexOftarget = binarySearch(arr, size, target);

    if (indexOftarget == -1)
    {
        cout << " element not found" << endl;
    }
    else
    {
        cout << "Element found at index: " << indexOftarget << endl;
    }
    return 0;
}


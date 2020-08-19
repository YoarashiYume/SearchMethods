#include "Interpolation.h"

int interpolationSearch(std::vector<double> arr, double key)
{
    int middle = 0;
    int leftBorder = 0;
    int rightBorder = arr.size() - 1;

    while (arr[leftBorder] < key && arr[rightBorder] > key)
    {
        if (arr[rightBorder] == arr[leftBorder])
            break;
        middle = leftBorder + ((key - arr[leftBorder]) * (rightBorder - leftBorder)) / (arr[rightBorder] - arr[leftBorder]);
        if (arr[middle] < key)
            leftBorder = middle + 1;
        else if (arr[middle] > key)
            rightBorder = middle - 1;
        else
            return middle;
    }

    if (arr[leftBorder] == key)
        return leftBorder;
    if (arr[rightBorder] == key)
        return rightBorder;

    return -1;
}

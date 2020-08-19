#include "Interpolation.h"

int interpolationSearch(std::vector<double> arr, double key)
{
    int middle = 0;
    int leftBorder = 0;
    int rightBorder = arr.size() - 1;
    std::vector<double> arrIn = arr;
    std::sort(arrIn.begin(), arr.end());
    while (arr[leftBorder] < key && arr[rightBorder] > key)
    {
        if (arrIn[rightBorder] == arrIn[leftBorder])
            break;
        middle = leftBorder + ((key - arrIn[leftBorder]) * (rightBorder - leftBorder)) / (arrIn[rightBorder] - arrIn[leftBorder]);
        if (arrIn[middle] < key)
            leftBorder = middle + 1;
        else if (arrIn[middle] > key)
            rightBorder = middle - 1;
        else
            return middle;
    }

    if (arrIn[leftBorder] == key)
        return leftBorder;
    if (arrIn[rightBorder] == key)
        return rightBorder;

    return -1;
}

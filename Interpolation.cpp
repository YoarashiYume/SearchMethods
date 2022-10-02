#include "Interpolation.h"

int interpolationSearch(std::vector<double> arr, const double key)
{
	std::sort(arr.begin(), arr.end());//only sorted arrays
    int middle = 0;
    int leftBorder = 0;
    int rightBorder = arr.size() - 1;

    while (arr[leftBorder] < key && arr[rightBorder] > key)//comparing elements on borders with key
    {
        if (arr[rightBorder] == arr[leftBorder])
            break;//if the elements on the borders are equal, then the required element is not in the array
		//middle is calculated and checked against the key element
        middle = leftBorder + ((key - arr[leftBorder]) * (rightBorder - leftBorder)) / (arr[rightBorder] - arr[leftBorder]);
		//changing boundaries based on comparison
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

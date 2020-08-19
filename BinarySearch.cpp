#include "BinarySearch.h"

int binarySearch(std::vector<double> arr, double key)
{
	std::vector<double> arrIn = arr;
	std::sort(arrIn.begin(), arrIn.end());
	int index = 0;
	bool isFind = false;
	int middle = arrIn.size() / 2;
	while (arrIn.size() != 0 && !isFind)
	{
		if (key == arrIn.at(middle))
			isFind = true;
		else if (arrIn.size() == 1 && arr.at(0) != key)
			break;
		else if (arrIn.at(middle) > key)
		{
			arrIn.erase(arrIn.begin() + arrIn.size() / 2, arrIn.end());
			continue;
		}
		else 
			arrIn.erase(arrIn.begin(),arrIn.begin() + arrIn.size() / 2);
		index += middle;
		middle = arrIn.size() / 2;
	}
	return isFind ? index : -1;
}

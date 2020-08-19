#include "BinarySearch.h"

int binarySearch(std::vector<double> arr, double key)
{
	int index = 0;
	bool isFind = false;
	int middle = arr.size() / 2;
	while (arr.size() != 0 && !isFind)
	{
		if (key == arr.at(middle))
			isFind = true;
		else if (arr.size() == 1 && arr.at(0) != key)
			break;
		else if (arr.at(middle) > key)
		{
			arr.erase(arr.begin() + arr.size() / 2, arr.end());
			continue;
		}
		else 
			arr.erase(arr.begin(),arr.begin() + arr.size() / 2);
		index += middle;
		middle = arr.size() / 2;
	}
	return isFind ? index : -1;
}

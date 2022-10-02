#include "BinarySearch.h"

int binarySearch(std::vector<double> arr,const double key)
{
	std::sort(arr.begin(), arr.end());//only sorted arrays
	int index = 0;
	bool isFind = false;//exit flag
	while (arr.size() != 0 && !isFind)
	{
		int middle = arr.size() / 2;
		if (key == arr.at(middle))
			isFind = true;
		else if (arr.size() == 1 && arr.at(0) != key)
			break;
		else if (arr.at(middle) > key)
		{
			//if the element is to the right of the middle, then the element is to the left
			arr.erase(arr.begin() + arr.size() / 2, arr.end());
			continue;
		}
		else 
			//otherwise - right
			arr.erase(arr.begin(),arr.begin() + arr.size() / 2);
		index += middle;
		
	}
	return isFind ? index : -1;
}

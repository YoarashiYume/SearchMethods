#include "Fibonacciev.h"


int fibonachiValue(int n)
{
	return ((pow((1 + sqrt(5)) / 2, n) - pow((1 - sqrt(5)) / 2, n)) / sqrt(5));
}
int fibonaccievSearch(std::vector<double> arr, 	double key)
{
	std::sort(arr.begin(), arr.end());//only sorted arrays
	int  currentNumberOfFibonachi = 0;
	int  indexOffset = 0;
	int index = 0;
	bool isFind = false;//exit flag
	while (!isFind&& indexOffset < arr.size())
	{
		//get the index based on the current fibonacci numbers and offset from the beginning of the array
		int currentFibonachiValue = fibonachiValue(currentNumberOfFibonachi) + indexOffset;
		if (currentFibonachiValue >= arr.size())
		{
			if (fibonachiValue(currentNumberOfFibonachi - 1) == 0)//no key element
				break;
			//reassign offset and reset fibonacci number index
			indexOffset += fibonachiValue(currentNumberOfFibonachi - 1);
			currentNumberOfFibonachi = 0;
		}
		else
		{
			if (arr.at(currentFibonachiValue) > key)
			{
				//reassign offset and reset fibonacci number index
				indexOffset += fibonachiValue(currentNumberOfFibonachi - 1);
				currentNumberOfFibonachi = 0;
			}
			else if (arr.at(currentFibonachiValue) == key)
			{
				index = currentFibonachiValue;
				isFind = true;
			}
			else
				currentNumberOfFibonachi++;
		}
	}
	return  isFind ? index : -1;

}
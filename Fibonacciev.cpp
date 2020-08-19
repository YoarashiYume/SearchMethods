#include "Fibonacciev.h"


int fibonachiValue(int n)
{
	return ((pow((1 + sqrt(5)) / 2, n) - pow((1 - sqrt(5)) / 2, n)) / sqrt(5));
}
int fibonaccievSearch(std::vector<double> arr, 	double key)
{
	std::vector<double> arrIn = arr;
	std::sort(arrIn.begin(), arrIn.end());
	int  currentNumberOfFibonachi = 0;
	int  indexOffset = 0;
	int index = 0;
	bool isFind = false;
	while (!isFind&& indexOffset < arrIn.size())
	{
		int currentFibonachiValue = fibonachiValue(currentNumberOfFibonachi) + indexOffset;
		if (currentFibonachiValue >= arrIn.size())
		{
			if (fibonachiValue(currentNumberOfFibonachi - 1) == 0)
				break;
			indexOffset += fibonachiValue(currentNumberOfFibonachi - 1);
			currentNumberOfFibonachi = 0;
		}
		else
		{
			if (arrIn.at(currentFibonachiValue) > key)
			{
				indexOffset += fibonachiValue(currentNumberOfFibonachi - 1);
				currentNumberOfFibonachi = 0;
			}
			else if (arrIn.at(currentFibonachiValue) == key)
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
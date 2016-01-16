#include <stdlib.h>
#include <stdio.h>

typedef int bool;
#define true 1
#define false 0

struct Stocks {
   float value;
} stock;  
 
int main(int argc, char *argv[])
{
	struct Stocks allStocks[argc-1];
	int index;
   	++argv;
	for (index = 0; index < argc - 1; index++)
	{
		double temp = strtod(*argv, NULL);
  		float ftemp = atof(*argv);
		allStocks[index].value = ftemp;
   		++argv;
	}

	int currMin = 0;
	int bestMin = 0;
	int currMax = 0;
	int bestMax = 0;
	float currentTotal = 0;
	float bestTotal = 0;

	for(int i = 1; i < sizeof(allStocks) / sizeof(struct Stocks); i++)
        {
		if (allStocks[i].value > allStocks[i-1].value && currentTotal == 0){
			//first increase
			//currentTotal = allStocks[i ].value -  allStocks[i - 1].value;
			currMin = i - 1;
			currMax = i;
		}
		else if (allStocks[i].value > allStocks[i-1].value){
			//continuing increase
			currMax = i;
		}
		else if (allStocks[i].value < allStocks[i-1].value){
			//prices going down, should sell
			currMax = i - 1;
			currentTotal = allStocks[currMax].value - allStocks[currMin].value;
			if (currentTotal > bestTotal && currMax > currMin + 1)
			{
				bestTotal = currentTotal;
				bestMin = currMin;
				bestMax = currMax;
			}
		}
        }

	printf("\nBuy at %f", allStocks[bestMin].value);
	printf("\nSell at %f \n", allStocks[bestMax].value);
	return 0;
}

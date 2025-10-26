#include<stdio.h>
int main()
{
	int arr[3][3][3]={
	   { {1,3,5},{2,4,6},{7,9,11} },
	   { {8,10,12},{13,15,17},{14,16,18} },
	   { {19,21,23},{20,22,24},{25,27,29} }
	   };
	
	int layerSum[3]={0};
	int layerMin[3], layerMax[3];
	float layerAvg[3];
	
	int arrSum=0;
	int arrMin=arr[0][0][0], arrMax=arr[0][0][0];
	float arrAvg;
	
	printf("\t Layer wise Analysis \n");
	printf("=========================================== \n");
	
	for(int i=0;i<3;i++) // i is layer no
	{
		int sum=0;
		int min=arr[i][0][0];
		int max=arr[i][0][0];
		
		printf("\t Layer %d: \n",i+1);
		
		for(int j=0;j<3;j++) // j is row no
		{
			for(int k=0;k<3;k++) // k is column no
			{
				int val=arr[i][j][k];
				printf("%8d",val);  // printing all layers
				
				sum+=val;
				if(val<min)  min=val;
				if(val>max)  max=val;
				
				arrSum+=val;
				if(val<arrMin)  arrMin=val;
				if(val>arrMax)  arrMax=val;
			}
			printf("\n");	
		}
		
		layerSum[i]=sum;
		layerMin[i]=min, layerMax[i]=max;
		layerAvg[i]= (float)sum / 9.0;
		
		printf("\n \t Sum = %d \n",sum);
		printf("\t Minimum = %d \n",min);
		printf("\t Maximum = %d \n",max);
		printf("\t Average = %.2f \n\n",layerAvg[i]);
	}
	
	arrAvg= (float)arrSum / 27.0;

	printf("=========================================== \n\n");
	printf("\t Overall 3D Array Analysis \n");
	printf("=========================================== \n");
	
	printf("\n \t Total Sum = %d \n",arrSum);
	printf("\t Total Minimum = %d \n",arrMin);
	printf("\t Total Maximum = %d \n",arrMax);
	printf("\t Total Average = %.2f \n",arrAvg);
	
	return 0;
}


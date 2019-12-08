int counts = 0;
int Prob = 0;
class WaveSort
{
public:
	static long int W_compareCount;
	static long int W_setCount;
	static long int W_memoryCount;
	static long int W_recursionCount;
public:
	template<class T>
	static void SortFaser(T *arr, int left, int right)
	{
		W_recursionCount++;
		W_memoryCount += 3;
		if (left < right)
		{
			if (counts++ >= Prob)
				return;
			W_compareCount++;
			int tmp = Tmp(&*arr, left, right);
			SortFaser(&*arr, left, tmp - 1);
			SortFaser(&*arr, tmp + 1, right);
		}
	}
	template<class T>
	static int Tmp(T * arr, int left, int right)
	{
		W_memoryCount += 3;
		W_recursionCount++;
		T tmp = arr[left];
		while (left < right)
		{
			W_compareCount++;
			while (left < right && tmp <= arr[right])
			{
				right--;
				W_compareCount++;
			}
			W_compareCount++;
			arr[left] = arr[right];

			while (left < right && tmp >= arr[left])
			{
				left++;
				W_compareCount++;
			}
			W_compareCount++;
			W_setCount++;
			arr[right--] = arr[left];

		}
		W_compareCount++;
		W_setCount++;
		arr[left] = tmp;
		return left;
	}
	template<class T>
	static void Sort(T * arr,const int nLen,int FaserCount)
	{
		Prob = FaserCount;

		SortFaser(arr, 0, nLen - 1);
		W_recursionCount++;
		W_memoryCount += 5;
		if(nLen <= 1) 
		{
			W_compareCount++;
			return;
		}

		T oCompareItem;

		int nEnd = -1;
		int eIndex = -1;
		int bIndex = -1;
		bool isOne = true;
		while(true)
		{
			/*
			for(int i = 0; i < 16; i++)
			{
				cout<<arr[i]<<" ";
			}
			cout<<endl;*/
			//找到第一个小于自己前一个元素的元素
			for(eIndex = eIndex + 1; eIndex < nLen - 1; eIndex++)
			{
				W_compareCount++;
				if(arr[eIndex] > arr[eIndex + 1])
				{
					W_setCount++;
					oCompareItem = arr[eIndex + 1];
					nEnd = eIndex;
					break;
				}	
			}

			//不需要排序或已经到结尾了
			if(nEnd == -1 || eIndex == nLen - 1)
			{
				W_compareCount++;
				return;
			}
			W_setCount++;	
			arr[nEnd + 1] = arr[nEnd--];

			isOne = true;
			//把前面大于自己的元素往后移动一位
			for(bIndex = nEnd; bIndex >= 0; bIndex--)
			{
				W_compareCount++;
				W_setCount++;
				if(arr[bIndex] > oCompareItem)
				{
					arr[bIndex + 1] = arr[bIndex];
				}
				else
				{
					arr[bIndex + 1] = oCompareItem;
					isOne = false;
					break;
				}	
			}
			if(isOne)
			{
				W_setCount++;
				W_compareCount++;
				arr[0] = oCompareItem;
			}
		}	
	}
};
long int WaveSort::W_compareCount = 0;
long int WaveSort::W_setCount = 0;
long int WaveSort::W_memoryCount = 0;
long int WaveSort::W_recursionCount = 0;
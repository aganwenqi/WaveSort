
class BucketSort
{
public:
	static long int B_compareCount;
	static long int B_setCount;
	static long int B_memoryCount;
	static long int B_recursionCount;
public:
	static void Sort(int *arr,const int nLen)//¼ÆÊýÍ°ÅÅ
	{
		B_recursionCount++;
		B_memoryCount++;
		if (arr == nullptr || nLen < 2) {
			B_compareCount++;
			return ;
		}
		int i,j;
		int max = 0;
		max = arr[0];
		B_memoryCount++;
		B_setCount += 4;
		for (i = 1; i < nLen; i++) 
		{
			B_compareCount++;
			if(arr[i] > max)
			{
				B_setCount++;
				max = arr[i];
			}
		}
    
		int * bucket = new int[max + 1];
		B_memoryCount += (max + 1);
		for(i = 0 ; i < max + 1; i++)
		{
			B_compareCount++;
			B_setCount++;
			bucket[i] = 0;
		}
    
		for (i = 0; i < nLen; i++) {
			B_compareCount++;
			B_setCount++;
			bucket[arr[i]]++;
		}
		i = 0;
		B_setCount++;
		for (j = 0; j < max + 1; j++) {
			while (bucket[j]-- > 0) {
				B_compareCount++;
				B_setCount++;
				arr[i++] = j;
			}
		}
		return ;
	}
};
long int BucketSort::B_compareCount = 0;
long int BucketSort::B_setCount = 0;
long int BucketSort::B_memoryCount = 0;
long int BucketSort::B_recursionCount = 0;
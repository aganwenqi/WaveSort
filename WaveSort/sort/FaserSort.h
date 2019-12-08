
class FaerSort
{
public:
	static long int F_compareCount;
	static long int F_setCount;
	static long int F_memoryCount;
	static long int F_recursionCount;
private:
	static void SortFaser(int *arr,int left,int right)
	{
		F_recursionCount++;
		F_memoryCount += 3;
		if(left < right)
		{
			F_compareCount++;
			int tmp = Tmp(&*arr,left,right);
			SortFaser(&*arr,left,tmp-1);
			SortFaser(&*arr,tmp+1,right);
		}
	}
	static int Tmp(int * arr,int left,int right)
	{
		F_memoryCount +=3;
		F_recursionCount++;
		int tmp = arr[left];
		while(left < right)
		{
			F_compareCount++;
			while(left < right && tmp <= arr[right])
			{
				right--;
				F_compareCount++;
			}
			F_compareCount++;
			arr[left] = arr[right];

			while(left < right && tmp >= arr[left])
			{
				left++;
				F_compareCount++;
			}
			F_compareCount++;
			F_setCount++;
			arr[right--] = arr[left] ;

		}
		F_compareCount++;
		F_setCount++;
		arr[left] = tmp;
		return left;
	}
public:
	static void Sort(int *arr,int nLen)
	{
		F_memoryCount++;
		F_recursionCount++;
		SortFaser(arr,0,nLen - 1);
	}
};
bool EquinoctialSearch(int * arr,int & cp,int b ,int e)//¶þ·Ö²éÕÒ
{
	int i = (b+e) / 2;
	bool quit = false;
	if(b > e)
		quit = false;
	else if(arr[i] > cp){
		quit = EquinoctialSearch(arr,cp,b,i - 1);
	}
	else if(arr[i] < cp){
		quit = EquinoctialSearch(arr,cp,i+1,e);
	}
	else if(arr[i] == cp){
		quit = true;
	}
	return quit;
}
long int FaerSort::F_compareCount = 0;
long int FaerSort::F_setCount = 0;
long int FaerSort::F_memoryCount = 0;
long int FaerSort::F_recursionCount = 0;

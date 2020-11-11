template<typename TYPE>
int binarySearch(const TYPE* array, TYPE target, int min, int max)
{
	if (min > max)
		return -1;

	int midpoint{ min + ((max - min) / 2) };

	if (array[midpoint] > target)
	{
		return binarySearch(array, target, min, midpoint - 1);
	}
	else if (array[midpoint] < target)
	{
		return binarySearch(array, target, midpoint + 1, max);
	}
	else
	{
		return midpoint;
	}
}
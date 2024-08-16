int count_symbols(int arg)
{
	int ans = 1, i = 10;
	while (abs(arg) >= i)
	{
		ans += 1;
		i *= 10;
	}
	return ans; 
}

int count_symbols(int* arr, int n)
{
	int ans = 0;
	for(int i=0; i < n; i++) ans += count_symbols(arr[i]);
	return ans;
}

int count_symbols(int* ptr)
{
	return count_symbols(*ptr);
}

int count_symbols(const char* str)
{
	const char* tmp = str;
	int ans = 0;
	while (*tmp != 0)
	{
		ans += 1;
		tmp += 1;
	}
	return ans;
}

int count_symbols(double f, int n)
{
	int x = f;
	return count_symbols(x) + n;
}

int count_symbols(double f)
{
	int x = f;
	return count_symbols(x);
}
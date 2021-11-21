#include<iostream>

int main() {
	int n;

	std::cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		std::cin >> arr[i];
	int x;
	std::cin >> x;

	int compare = 0;
	bool found = false;
	for(int i = 0 ; i < n && !found; i++)
		for (int j = 1; j <n; j *= 2)
		{
			found += 1;
			if (arr[j] == x)
			{
				compare ++;
				found = true;
				break;
			}
		}
	if (found)
		std::cout << "Present " << compare;
	else
		std::cout << "Not Present " << compare;
	return 0;
}
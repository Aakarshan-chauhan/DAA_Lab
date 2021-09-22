#include<iostream>
int main() {
	int t;
	std::cin >> t;
	while (t--) {
		int n, x;
		std::cin >> n;
		
		int arr[n];
		for (int i = 0; i < n; i++)
		{
			std::cin >> arr[i];
		}
		std::cin >> x;
		int compare = 0;
		bool found = false;

		for (int i = 0; i < n; i++)
		{
			if (x == arr[i])
			{
				found = true;
				compare = i + 1;
				break;
			}

		}
		if (found)
			std::cout << "Present \n" << compare;
		else
			std::cout << "Not Present \n" << n;
	}
	return 0;
}
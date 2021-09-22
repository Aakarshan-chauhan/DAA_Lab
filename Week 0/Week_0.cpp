#include<iostream>

int main() {
	int n;
	std::cout << "Enter the size of the array: ";
	std::cin >> n;
	int arr[n];
	std::cout << "Enter the Array: ";
	for (int i = 0; i < n; i++)
		std::cin >> arr[i];

	std::cout << "Enter the element to be found: ";
	int x;
	std::cin >> x;

	for (int i = 0; i < n; i++) {
		if (x == arr[i])
		{
			std::cout << "Found at position: " << i;
			return 0;
		}
	}
	std::cout << "Not found";
	return 0;
}
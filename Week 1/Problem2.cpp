#include <iostream>
#include<vector>

using namespace std;

int main()
{

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> arr(n);
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		int key;
		cin >> key;
		int compare = 0, flag = 0;
		for (int x : arr)
		{
			compare++;
			if (x == key)
			{
				flag = 1;
				break;
			}
		}
		cout << (flag ? "Present " : "Not Present ") << compare << endl;
	}
	return 0;
}
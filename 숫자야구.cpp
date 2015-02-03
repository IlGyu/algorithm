#include<iostream>
using namespace std;

int main()
{
	int q, w;
	int t, arr[101], strike[101], ball[101];
	int a[101];
	int b[101];
	int c[101];

	int result;

	cin >> q;

	for (w = 1; w <= q; w++) {

		cin >> t;

		result = 0;

		for (int i = 0; i < t; i++)
		{
			cin >> arr[i] >> strike[i] >> ball[i];
			a[i] = arr[i] / 100;
			b[i] = (arr[i] % 100) / 10;
			c[i] = arr[i] % 10;
		}

		for (int x = 1; x < 10; x++)
		{
			for (int y = 1; y < 10; y++)
			{
				if (x == y) continue;
				for (int z = 1; z < 10; z++)
				{
					if (x == z) continue;
					else if (y == z) continue;

					int target_strike[101] = { 0, };
					int target_ball[101] = { 0, };

					for (int i = 0; i < t; i++)
					{
						if (a[i] == x)
							target_strike[i]++;
						if (b[i] == y)
							target_strike[i]++;
						if (c[i] == z)
							target_strike[i]++;

						if (a[i] == y)
							target_ball[i]++;
						if (a[i] == z)
							target_ball[i]++;

						if (b[i] == x)
							target_ball[i]++;
						if (b[i] == z)
							target_ball[i]++;

						if (c[i] == x)
							target_ball[i]++;
						if (c[i] == y)
							target_ball[i]++;
					}

					int state = 0;
					for (int i = 0; i < t; i++)
					{
						if (strike[i] != target_strike[i])
						{
							state = 1;
							break;
						}
						if (ball[i] != target_ball[i])
						{
							state = 1;
							break;
						}
					}
					if (state == 0)
					{
						result++;
					}
				}
			}
		}

		cout << "#testcase" << w << endl << result << endl;
	}

	return 0;
}
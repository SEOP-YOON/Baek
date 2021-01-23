#include <iostream>
#include <queue>
using namespace std;

int main()
{
	long long S, K;
	long long num1,num2;
	long long sum=1;
	long long temp1, temp2 = 0;

	queue<long long> q;

	cin >> S >> K;
	
	num1 = S / K;
	num2 = S % K;



	for (int i = 0; i < K; i++)
	{
		q.push(num1);
	}
	for (int j = 0; j < num2; j++)
	{
		temp1 = q.front() + 1;
		q.push(temp1);
		q.pop();
	}
	int t_size = q.size();
	for (int z = 0; z < t_size; z++)
	{
		temp2 = q.front();
		sum = sum * temp2;
		q.pop();
	}

	cout << sum << endl;
}
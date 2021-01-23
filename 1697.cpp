#include <iostream>
#include <queue>

using namespace std;

//BFS ����

int main()
{
	queue<int> q;
	int visited[100001] = { 0 };

	int N, K;

	cin >> N >> K;

	q.push(N);
	visited[N] = 1;
	while (!q.empty())
	{
		int p = q.front();
		q.pop();
		if (p == K)
		{
			visited[K] = visited[K] - 1;
			break;
		}
		// ���� ��ġ���� -1 ������쿡 �湮���� �ʾ����� p-1�� �̵����� index����
		if (p - 1 >= 0 && visited[p-1] == 0)
		{
			visited[p-1] = visited[p] +1;
			q.push(p - 1);
		}
		// ���� ��ġ���� +1 ������쿡 �湮���� �ʾ����� p+1�� �̵����� index����
		if (p + 1 <= 100000 && visited[p+1] == 0)
		{
			visited[p + 1] = visited[p] + 1;
			q.push(p + 1);
		}
		// ���� ��ġ���� *2 ������쿡 �湮���� �ʾ����� p*2�� �̵����� index����
		if(p*2 <=100000 && visited[p*2] == 0)
		{
			visited[p * 2] = visited[p] + 1;
			q.push(p * 2);
		}
		//�湮 �ߴ� ���� ���ʿ� ���ع߻�
	}
	cout << visited[K] << endl;

}
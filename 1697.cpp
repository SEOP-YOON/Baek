#include <iostream>
#include <queue>

using namespace std;

//BFS 문제

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
		// 현재 위치에서 -1 했을경우에 방문하지 않았으면 p-1로 이동한후 index증가
		if (p - 1 >= 0 && visited[p-1] == 0)
		{
			visited[p-1] = visited[p] +1;
			q.push(p - 1);
		}
		// 현재 위치에서 +1 했을경우에 방문하지 않았으면 p+1로 이동한후 index증가
		if (p + 1 <= 100000 && visited[p+1] == 0)
		{
			visited[p + 1] = visited[p] + 1;
			q.push(p + 1);
		}
		// 현재 위치에서 *2 했을경우에 방문하지 않았으면 p*2로 이동한후 index증가
		if(p*2 <=100000 && visited[p*2] == 0)
		{
			visited[p * 2] = visited[p] + 1;
			q.push(p * 2);
		}
		//방문 했던 곳을 애초에 손해발생
	}
	cout << visited[K] << endl;

}
﻿#include <iostream>
#include <queue>
#include <climits>

using namespace std;


queue <int> Q;

int** createG(int size)
{
	int** G;
	G = (int**)malloc(size * sizeof(int*));
	for (int i = 0; i < size; i++)
	{
		G[i] = (int*)malloc(size * sizeof(int));
	}
	for (int i = 0; i < size; i++)
	{
		G[i][i] = 0;
		for (int j = i + 1; j < size; j++)
		{
			G[i][j] = rand() % 2;
			G[j][i] = G[i][j];
		}
	}
	return G;
}

void printG(int** G, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << G[i][j] << " ";
		}
		cout << endl;
	}
}

void bFS(int** G, int size, int start, int* dist) {
	Q.push(start);
	dist[start] = 0;


	while (!Q.empty()) {
		start = Q.front();
		Q.pop();
		for (int i = 0; i < size; i++) {
			if (G[start][i] == 1 && dist[i] == INT_MAX) {
				Q.push(i);
				dist[i] = dist[start] + G[start][i];
			}
		}
	}
}

int main() {
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	int** G = NULL;
	int nG, s;


	cout << "Введите размер графа: ";
	cin >> nG;

	G = createG(nG);

	printG(G, nG);
	cout << endl;

	cout << "Введите стартовую вершину: ";
	cin >> s;
	cout << endl;

	int* dist = NULL;
	dist = (int*)malloc(nG * sizeof(int));


	for (int i = 0; i < nG; i++) {
		dist[i] = INT_MAX;
	}


	bFS(G, nG, s - 1, dist);
	for (int i = 0; i < nG; i++) {
		if (dist[i] == INT_MAX) dist[i] = -1;
		cout << dist[i] << " ";
	}

	cout << endl;

	return 0;
}
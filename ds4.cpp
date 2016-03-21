#include <iostream>
#include <list>
#include <limits.h>
#include <fstream>
#include <queue>
using namespace std;

int i, j;
int n, m;

ifstream input;

class Graf
{

	int A;
	int  **graf;
	list<int> *adj;
	bool dfs(int c, bool used[], bool *stack, int *cycle, int count);
public:
	Graf(int A);
	void in(int a, int b);
	void DFS(int q);
	void BFS(int s);
};

Graf::Graf(int A)
{
	this->A = A;
	adj = new list<int>[A];
	graf = new int *[A];
	for (int i = 0; i < A; i++)
		graf[i] = new int[A];
	for (int i = 0; i <  A; i++)
	for (int j = 0; j < A; j++)
		graf[i][j] = 0;
}

void output_queue(queue <int> Q) {
	int quantity = Q.size(), temp;
	for (int i = 0; i < quantity; i++) {
		temp = Q.front();
		Q.push(temp);
		printf("%d ", temp+1);
		Q.pop();
	}

}

void output(queue <int> Q) {
	int quantity = Q.size(), temp;
	if (!quantity) {
		cout << "Null"<<endl;
		return;
	}
	for (int i = 0; i < quantity; i++) {
		temp = Q.front();
		Q.push(temp);
		printf("%d ", temp + 1);
		Q.pop();
	}
}

void Graf::BFS(int w) 
{
	queue <int> turn;
	turn.push(w);
	int k = 1;
	bool * vis= new bool[A];
	for (int i = 0; i <A; i++)
		vis[i] = false;
	while (!turn.empty()) 
	{
		int ind = turn.front();
		turn.pop();
		k++;
		printf("\n   %d      %d        %d ",k,ind+1,ind+1);
		for (int i = 0; i<A; i++)
		{
			if (graf[ind][i] == 1&&!vis[i])
			{
				turn.push(i);
				vis[i] = true;

			}
		}
		output_queue(turn);
		printf("\n");
		k++;
		printf("   %d               ", k);
		output(turn);
	}
}

void Graf::in(int a, int b)
{
	adj[a].push_back(b);
	graf[a][b] = 1;
}

bool Graf::dfs(int c, bool used[], bool *stack, int *cycle, int count)
{
	if (used[c] == false)
	{
		for (i = 0; i < count; i++){
			printf("\t%d ", cycle[i] + 1);
		}
		cout << endl;
		used[c] = true;
		stack[c] = true;
		cycle[count] = c;
		count++;
		printf("    %d          %d", count, c + 1);
		list<int>::iterator i;
		for (i = adj[c].begin(); i != adj[c].end(); ++i)
		{
			if (!used[*i] && dfs(*i, used, stack, cycle, count))
				return true;
			else if (stack[*i])
				return true;
		}
		for (int u = 0; u < count; u++){
			printf("\t%d ", cycle[u] + 1);
		}
		cout << endl;
		count--;
		printf("    %d             ", count);

		stack[c] = false;
		return false;
	}
}

void Graf::DFS(int q)
{
	int *cycle=new int [100];
	bool *used = new bool[A];
	bool *stack= new bool[A];
	int count = 0;
	for (i = 0; i < A; i++)
	{
		used[i] = false;
		stack[i] = false;
	}
	if (dfs(q, used, stack, cycle, count)){
		return;
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	input.open("matr.txt");
	input >> n >> m;
	Graf e(n);
	int **g = new int *[m];
	for (i = 0; i < m; i++)
	{
		g[i] = new int[2];
		input >> g[i][0] >> g[i][1];
	}
	for (i = 0; i < m; i++)
	{
		e.in(g[i][0] - 1, g[i][1] - 1);
	}
	int s;
	cout << "Введите вершину для поиска вширь: ";
	cin >> s;
	cout << "BFS-номер Вершина Стек" << endl;
	printf("   1      %d        %d", s, s);
	e.BFS(s -1);
	cout << "Введите вершину для поиска в глубину: ";
	cin >> s;
	cout << "DFS-номер Вершина      Стек" << endl;
	e.DFS(s-1);
	printf("        Null\n");
	input.close();
	system("pause");
}
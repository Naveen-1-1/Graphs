#include <bits/stdc++.h>
using namespace std;

struct graph{
	int v;
	int w;
	graph(int x, int y){
		v = x, w = y;
	}
};

map <int, int> vertex;
int vsz = 0;

int add_vertex(vector <graph *> v[], int a){
	int vert;
	(!vertex.count(a)) ? vertex[a] = vsz, vert = vsz++ : vert = vertex[a]; 
	return vert;
}

int vertex_in_graph(vector <graph *> v[], int in, int a, int w){
	int f = 0;
	for(auto i:v[in]){
		if(i->v == a && i->w){
			f = 1;
			break;
		}
	}
	return f;
}

void add_edge(vector <graph *> v[], int a1, int a2, int w){
	int in = add_vertex(v, a1);
	int f = vertex_in_graph(v, in, a2, w);
	if(f == 0){
		graph *g = new graph(a2, w);
		v[in].push_back(g);
	}
}

void dfs(int a, vector <graph *> v[], set <int> &visit, int x){
	for(int i = 0; i < x; i++)
		cout<<"\t";
	cout<<":"<<a<<"\n";
	visit.insert(a);
	if(!vertex.count(a))
		return;
	for(auto &i:v[vertex[a]]){
		if(visit.find(i->v) == visit.end())
			dfs(i->v, v, visit, x+1);
	}
}

int main(){
	vector <graph *> v[100];
	int cnt;
	fstream fin("Edge List.txt");
	fin>>cnt;
	int a1, a2, w;
	for(int i = 0; i < cnt; i++){
		fin>>a1>>a2>>w;
		add_edge(v, a1, a2, w);
	}
	set <int> visit;
	fin>>a1;
	cout<<"DFS:\n";
	dfs(a1, v, visit, 0);
	return 0;
}

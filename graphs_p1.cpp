#include<bits/stdc++.h>
using namespace std;


class graph1 {
	int N;
	unordered_map<int, list<int>>list1;
	vector<int>*list2;
	list<int>*list3;
public:

	graph1(int n) {
		this->N = n;
		list2 = new vector<int>[n];
		list3 = new list<int>[n];
	}

	void addEdge(int u , int v) {
		list1[u].push_back(v);
		list1[v].push_back(u);

		list2[u].push_back(v);
		list2[v].push_back(u);

		list3[u].push_back(v);
		list3[u].push_back(v);
	}
	void print1() {
		for (auto el : list1) {
			int node = el.first;
			list<int> neighs = el.second;
			cout << "NODE -> " << node << " - > ";
			for (auto negih : neighs) {
				cout << negih << " ";
			} cout << endl;
		}
	}
	void print2() {
		for
	}


};


int main(int argc, char const *argv[]) {
	graph1 g1(5) ;
	g1.addEdge(1, 2);
	g1.addEdge(3, 2);
	g1.addEdge(4, 2);
	g1.addEdge(0, 3);
	g1.print1();


	return 0;
}
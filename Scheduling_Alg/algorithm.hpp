#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>


class alg {
public:
	//funcs to run alg
	void FCFS(int size);
	void SJF(int size);
	void STR(int size);
	void RR(int size);

	//func to print results
	void totalWait(int size);
	void avgWait(int size);
	void minWait(int size);
	void maxWait(int size);

private:
	//stored data queues
	std::vector<int> ready;
	std::vector<int> waiting;
	//results queue
	std::vector<int> wait;
	std::vector<int> avg;
};

class num_gen {
public:
	void initialize();
	int generate(int y);
};
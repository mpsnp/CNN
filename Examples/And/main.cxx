#include "CNN.hxx"
#define _USE_MATH_DEFINES
#include <cmath>
#include <random>
#include <iostream>
#include <vector>


using namespace CNN;
using namespace std;

int main(int argc, char const *argv[])
{
	CPerceptron percepron(2);

	vector<int> layers = {2,4,4,1};
	percepron.FillLayers(layers);

	float speed = 0;
	int iterations = 0;

	cout << "Enter speed and iterations" << endl;
	cin >> speed >> iterations;

	CBackpropagationTeacher teacher;
	teacher.SetTrainedNetwork(&percepron);
	teacher.SetTrainingSpeed(speed);
	teacher.SetIterationsCount(iterations);
	
	TLearningData data;
	TInputVector input;
	TOutputVector output;
	TLearningPair pair;
	
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			input.clear();
			output.clear();
			
			input.push_back(i);
			input.push_back(j);
			if ((i == j) && (1 == i))
				output.push_back(1);
			else
				output.push_back(0);
			
			pair.first = input;
			pair.second = output;
			
			data.push_back(pair);
		};
	};
	
	for (int i = 0; i < 1; i++)
	{
		teacher.Teach(data);
		
		cout << percepron.Calculate({0,0})[0] << endl;
		cout << percepron.Calculate({0,1})[0] << endl;
		cout << percepron.Calculate({1,0})[0] << endl;
		cout << percepron.Calculate({1,1})[0] << endl;
	};
	
	return 0;
}
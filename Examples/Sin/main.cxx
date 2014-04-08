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
	CPerceptron percepron(1);
	// percepron.AddNeuronToLayer(percepron.GenerateNewNeuron(), 0);
	vector<int> layers = {2,5,1};
	percepron.FillLayers(layers);
	

	cout << percepron.Calculate({1, M_PI / 6})[0] << endl;

	percepron.PrintNetwork();

	CBackpropagationTeacher teacher;
	teacher.SetTrainedNetwork(&percepron);
	teacher.SetTrainingSpeed(0.1);
	teacher.SetIterationsCount(100);
	
	TLearningData data;
	TInputVector input;
	TOutputVector output;
	TLearningPair pair;
	
	for (int i = 0; i < 100; i++)
	{
		input.clear();
		output.clear();
		
		input.push_back(1);
		input.push_back((M_PI / 200 * float(rand() % 100)));
		output.push_back(sin(input[0]));
		
		pair.first = input;
		pair.second = output;
		
		data.push_back(pair);
	};
	
	teacher.Teach(data);

	percepron.PrintNetwork();
	
	cout << percepron.Calculate({1, M_PI / 6})[0] << endl;
	
	return 0;
}
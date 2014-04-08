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
	vector<int> layers = {2,50,1};
	percepron.FillLayers(layers);
	

	cout << percepron.Calculate({1, M_PI / 6})[0] << endl;

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
	
	for (int i = 0; i < 50; i++)
	{
		input.clear();
		output.clear();
		
		input.push_back(1);
		input.push_back((M_PI / 100 * i));
		output.push_back(sin(input[1]));
		
		pair.first = input;
		pair.second = output;
		
		data.push_back(pair);
	};
	
	for (int i = 0; i < 50; i++)
	{
		teacher.Teach(data);
		
		cout << percepron.Calculate({1, M_PI / 6})[0] << endl;
	};
	
	return 0;
}
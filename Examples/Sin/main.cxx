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
	// percepron.AddNeuronToLayer(percepron.GenerateNewNeuron(), 0);
	vector<int> layers = {1,5,3,1};
	percepron.FillLayers(layers);

	float speed = 0;
	int iterations = 0;
	int si = 0;

	cout << "Enter speed, iterations and output times" << endl;
	cin >> speed >> iterations >> si;

	CBackpropagationTeacher teacher;
	teacher.SetTrainedNetwork(&percepron);
	teacher.SetTrainingSpeed(speed);
	teacher.SetIterationsCount(iterations);
	
	TLearningData data;
	TInputVector input;
	TOutputVector output;
	TLearningPair pair;
	
	for (int i = 0; i < 5; i++)
	{
		input.clear();
		output.clear();
		
		input.push_back((M_PI / 10 * i));
		output.push_back(sin(input[0]));
		
		pair.first = input;
		pair.second = output;
		
		data.push_back(pair);
	};
	
	for (int i = 0; i < si; i++)
	{
		teacher.Teach(data);
		
		cout << percepron.Calculate({M_PI / 6})[0] << endl;
	};
	
	return 0;
}
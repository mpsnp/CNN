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
	vector<int> layers = {1,5,1};
	percepron.FillLayers(layers);
	
	CBackpropagationTeacher teacher;
	teacher.SetTrainedNetwork(&percepron);
	teacher.SetTrainingSpeed(0.05);
	teacher.SetIterationsCount(100);
	
	TLearningData data;
	TInputVector input;
	TOutputVector output;
	TLearningPair pair;
	
	for (int i = 0; i < 10; i++)
	{
		input.clear();
		output.clear();
		
		input.push_back(M_PI / 10 * (rand() % 10));
		output.push_back(sin(input[0]));
		
		pair.first = input;
		pair.second = output;
		
		data.push_back(pair);
	};
	
	teacher.Teach(data);
	
	vector<float> out = percepron.Calculate({M_PI / 6});
	
	cout << sin(M_PI / 6) - out[0];
	
	return 0;
}
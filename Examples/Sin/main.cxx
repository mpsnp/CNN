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
	vector<int> layers = {1,20,20,1};
	percepron.FillLayers(layers);

	CLevMaqTeacher teacher;
	teacher.SetTrainedNetwork(&percepron);
//	teacher.SetTrainingSpeed(speed);
//	teacher.SetIterationsCount(iterations);
	
	TLearningData data;
	TInputVector input;
	TOutputVector output;
	TLearningPair pair;
	
	for (int i = 0; i < 40; i++)
	{
		input.clear();
		output.clear();
		
		input.push_back((M_PI * i / 80));
		output.push_back(sin(input[0]));
		
		pair.first = input;
		pair.second = output;
		
		data.push_back(pair);
	};
	
	for (int i = 0; i < 1; i++)
	{
		teacher.Teach(data);
        
        cout << percepron.Calculate({M_PI / 2})[0] << endl;
        cout << percepron.Calculate({M_PI / 3})[0] << endl;
        cout << percepron.Calculate({M_PI / 4})[0] << endl;
        cout << percepron.Calculate({M_PI / 6})[0] << endl;
        cout << percepron.Calculate({0})[0] << endl;
	};
	
	return 0;
}
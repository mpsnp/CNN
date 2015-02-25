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

	vector<int> layers = {1,10,1};
	percepron.FillLayers(layers);

	float speed = 0;
	int iterations = 0;

//	cout << "Enter speed and iterations" << endl;
//	cin >> speed >> iterations;

	CLevMaqTeacher teacher;
    teacher.SetTrainedNetwork(&percepron);
	// teacher.SetTrainingSpeed(speed);
	// teacher.SetIterationsCount(iterations);
	
	TLearningData data;
	TInputVector input;
	TOutputVector output;
	TLearningPair pair;
	
	for (int i = 0; i < 5; i++)
	{
        input.clear();
        output.clear();
        
        input.push_back(i);
        output.push_back(i*i);
        
        pair.first = input;
        pair.second = output;
        
        data.push_back(pair);
	};
	
	for (int i = 0; i < 1; i++)
	{
		teacher.Teach(data);
		
		cout << percepron.Calculate({0})[0] << endl;
		cout << percepron.Calculate({1})[0] << endl;
		cout << percepron.Calculate({2})[0] << endl;
		cout << percepron.Calculate({3})[0] << endl;
	};
	
	return 0;
}
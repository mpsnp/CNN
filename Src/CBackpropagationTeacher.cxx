#include "CBackpropagationTeacher.hxx"
#include "CPerceptron.hxx"
#include <cassert>
#include <map>
#include <iostream>

CNN::CBackpropagationTeacher::CBackpropagationTeacher()
:CTeacher()
{
	_TrainingSpeed = DEFAULT_TRAINING_SPEED;
	_TrainingInnertion = DEFAULT_TRAINING_INNERTION;
	_IterationsCount = DEFAULT_ITERATIONS_COUNT;
};

CNN::CBackpropagationTeacher::~CBackpropagationTeacher()
{
	
};

void CNN::CBackpropagationTeacher::Teach(TLearningData LearningData)
{
	CPerceptron* network = dynamic_cast<CPerceptron*>(_TrainedNetwork);
	assert(network);
	std::map <CNeuron*, float> deltas;
	
	for (int iteration = 0; iteration < _IterationsCount; iteration++)
	{
		for (TLearningPair learningPair : LearningData)
		{
			network->Calculate(learningPair.first);
			TNeuronLayer analysingLayer = network->GetRecieversLayer();
			
			// Outputs deltas.
			for (int i = 0; i < analysingLayer.size(); i++)
			{
				float output = analysingLayer[i]->GetOutput();
				float aim = learningPair.second[i];
				float delta = -analysingLayer[i]->GetDifferentialOutput() * (aim - output);
				deltas[analysingLayer[i]] = delta;
			};
			
			// Hidden layers deltas.
			for (int i = network->GetLayerCount() - 2; i >= 0; i--)
			{
				analysingLayer = network->GetLayer(i);
				
				for (int i = 0; i < analysingLayer.size(); i++)
				{
					CNeuron* neuron = analysingLayer[i];
					float output = neuron->GetOutput();
					float sum = 0;
					
					std::vector<CNeuron*> axons = neuron->GetAxons();
					
					for (CNeuron* axon : axons)
						sum += axon->GetDendritWeight(neuron) * deltas[axon];
					
					float delta = neuron->GetDifferentialOutput() * sum;
					deltas[analysingLayer[i]] = delta;
				};
			};
			
			// Setting weights
			for (int i = 0; i < network->GetLayerCount(); i++)
			{
				analysingLayer = network->GetLayer(i);
				for (CNeuron* sender : analysingLayer)
					for (CNeuron* reciever : sender->GetAxons())
						reciever->SetDendritWeight(sender, reciever->GetDendritWeight(sender) - (_TrainingSpeed / _IterationsCount * (_IterationsCount - iteration)) * deltas[reciever] * sender->GetOutput());
			};
		};
	};
};

void CNN::CBackpropagationTeacher::SetIterationsCount(int Count)
{
	_IterationsCount = Count;
};

void CNN::CBackpropagationTeacher::SetTrainingInnertion(float Innertion)
{
	_TrainingInnertion = Innertion;
};

void CNN::CBackpropagationTeacher::SetTrainingSpeed(float Speed)
{
	_TrainingSpeed = Speed;
};
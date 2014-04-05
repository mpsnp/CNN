#include "CBackpropagationTeacher.hxx"
#include "CPerceptron.hxx"
#include <cassert>
#include <map>

CNN::CBackpropagationTeacher::CBackpropagationTeacher()
:CTeacher(){};

void CNN::CBackpropagationTeacher::Teach(TLearningData LearningData)
{
	CPerceptron* network = dynamic_cast<CPerceptron*>(_TrainedNetwork);
	assert(network);
	std::map <CNeuron*, float> deltas;
	
	for (int i = 0; i < _IterationsCount; i++)
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
				float delta = output * (1 - output) * (aim - output);
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
						sum += axon->GetDendritWeight(neuron) * deltas[neuron];
					
					float delta = output * (1 - output) * sum;
					deltas[analysingLayer[i]] = delta;
				};
			};
			
			// Setting weights
			for (int i = 0; i < network->GetLayerCount(); i++)
			{
				analysingLayer = network->GetLayer(i);
				for (CNeuron* sender : analysingLayer)
					for (CNeuron* reciever : sender->GetAxons())
						reciever->SetDendritWeight(sender, reciever->GetDendritWeight(sender) + _TrainingSpeed * deltas[reciever] * sender->GetOutput());
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
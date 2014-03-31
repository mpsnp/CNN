#include "CBackpropagationTeacher.hxx"
#include "CPerceptron.hxx"
#include <cassert>

CNN::CBackpropagationTeacher::CBackpropagationTeacher()
:CTeacher(){};

void CNN::CBackpropagationTeacher::Teach(TLearningData LearningData)
{
	CPerceptron* network = dynamic_cast<CPerceptron*>(_TrainedNetwork);
	assert(network);
	
	for (int i = 0; i < _IterationsCount; i++)
	{
		for (TLearningPair learningPair : LearningData)
		{
			network->Calculate(learningPair.first);
			TNeuronLayer analysingLayer = network->GetRecieversLayer();
			for (int i = 0; i < analysingLayer.size(); i++)
			{
				float output = analysingLayer[i]->GetOutput();
				float aim = learningPair.second[i];
				float delta = output * (1 - output) * (aim - output);
				// TODO: TO BE CONTINUED))
			}
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
#ifndef _BACKPROPAGATION_TEACHER_H
#define _BACKPROPAGATION_TEACHER_H

#include "CTeacher.hxx"

#define DEFAULT_TRAINING_SPEED 0.5
#define DEFAULT_TRAINING_INNERTION 0.5
#define DEFAULT_ITERATIONS_COUNT 1

namespace CNN
{
	class CBackpropagationTeacher : public CTeacher
	{
	private:
		float _TrainingSpeed = DEFAULT_TRAINING_SPEED;
		float _TrainingInnertion = DEFAULT_TRAINING_INNERTION;
		int _IterationsCount = DEFAULT_ITERATIONS_COUNT;
	public:
		CBackpropagationTeacher();
		~CBackpropagationTeacher();
		void Teach(TLearningData LearningData);
		void SetTrainingSpeed(float Speed);
		void SetTrainingInnertion(float Innertion);
		void SetIterationsCount(int Count);
	};
};

#endif
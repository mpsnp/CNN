#ifndef _BACKPROPAGATION_TEACHER_H
#define _BACKPROPAGATION_TEACHER_H

#include "CTeacher.hxx"

#define DEFAULT_TRAINING_SPEED 0.5
#define DEFAULT_TRAINING_INNERTION 0.5
#define DEFAULT_ITERATIONS_COUNT 1

namespace CNN
{
	/**
	 * @brief Teacher that use back propagation algorithm.
	 */
	class CBackpropagationTeacher : public CTeacher
	{
	private:
		float _TrainingSpeed;
		float _TrainingInnertion;
		int _IterationsCount;
	public:
		/**
		 * @brief Default constructor.
		 * @details Sets default values to all it's private members.
		 */
		CBackpropagationTeacher();

		/**
		 * @brief Default destructor.
		 */
		~CBackpropagationTeacher();

		/**
		 * @brief Trains specified network.
		 * @note Currently it supports only CPerceptron.
		 * @param LearningData Learning data.
		 */
		void Teach(TLearningData LearningData);

		/**
		 * @brief Training speed setter.
		 */
		void SetTrainingSpeed(float Speed);

		/**
		 * @brief Training innertion setter.
		 */
		void SetTrainingInnertion(float Innertion);

		/**
		 * @brief Iterations count setter.
		 */
		void SetIterationsCount(int Count);
	};
};

#endif
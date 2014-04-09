#ifndef _TEACHER_H
#define _TEACHER_H

#include "CGenericNetwork.hxx"

namespace CNN
{
	/**
	 * @brief Pair of input vector and output vector.
	 * @details Just for compact and clear code.
	 */
	typedef std::pair<TInputVector, TOutputVector> TLearningPair;

	/**
	 * @brief Vector of learning pairs.
	 * @details Just for compact and clear code.
	 */
	typedef std::vector<TLearningPair> TLearningData;
	
	/**
	 * @brief Generic teacher.
	 */
	class CTeacher
	{
	protected:
		CGenericNetwork* _TrainedNetwork;
	public:
		/**
		 * @brief Constructs empty teacher.
		 */
		CTeacher();

		/**
		 * @brief Virtual destructor for inheritance purposes.
		 */
		virtual ~CTeacher();

		/**
		 * @brief Sets network for training.
		 * @warning Successor class must check network type.
		 * @param TrainedNetwork Generic network.
		 */
		void SetTrainedNetwork(CGenericNetwork* TrainedNetwork);

		/**
		 * @brief Trains recieved network.
		 * 
		 * @param LearningData Learning data for trainig.
		 */
		virtual void Teach(TLearningData LearningData) = 0;
	};
};

#endif
#ifndef _TEACHER_H
#define _TEACHER_H

#include "CGenericNetwork.hxx"

namespace CNN
{
	typedef std::pair<TInputVector, TOutputVector> TLearningPair;
	typedef std::vector<TLearningPair> TLearningData;
	
	class CTeacher
	{
	protected:
		CGenericNetwork* _TrainedNetwork;
	public:
		CTeacher();
		virtual ~CTeacher();
		void SetTrainedNetwork(CGenericNetwork* TrainedNetwork);
		virtual void Teach(TLearningData) = 0;
	};
};

#endif
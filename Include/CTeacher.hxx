#ifndef _TEACHER_H
#define _TEACHER_H

#include "CGenericNetwork.hxx"

namespace CNN
{
	class CTeacher
	{
		CGenericNetwork* _TrainedNetwork;
	public:
		CTeacher();
		virtual ~CTeacher();
		void SetTrainedNetwork(CGenericNetwork* TrainedNetwork);
	};
};

#endif
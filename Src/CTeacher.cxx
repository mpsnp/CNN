#include "CTeacher.hxx"
#include "cstdlib"

CNN::CTeacher::CTeacher()
{
	_TrainedNetwork = NULL;
};

void CNN::CTeacher::SetTrainedNetwork(CNN::CGenericNetwork *TrainedNetwork)
{
	_TrainedNetwork = TrainedNetwork;
};

CNN::CTeacher::~CTeacher()
{
};
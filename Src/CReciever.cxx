#include "CReciever.hxx"

CNN::CReciever::CReciever()
{
	_ScailingFactor = 1;
};

CNN::CReciever::CReciever(float AScailingFactor)
{
	_ScailingFactor = AScailingFactor;
};

float CNN::CReciever::GetOutput()
{
	return _ScailingFactor * CNeuron::GetOutput();
};

void CNN::CReciever::SetScailingFactor(float AScailingFactor)
{
	_ScailingFactor = AScailingFactor;
};

float CNN::CReciever::GetScailingFactor()
{
	return _ScailingFactor;
};

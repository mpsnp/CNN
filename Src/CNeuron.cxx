#include "CNeuron.hxx"
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <random>
#include <iostream>

CNN::TDendrit::TDendrit()
{
	Weight = 0;
	Signal = 0;
};

CNN::TDendrit::TDendrit(float AWeight, float ASignal)
{
	Weight = AWeight;
	Signal = ASignal;
};

void CNN::CNeuron::AddAxonTo(CNeuron* AimNeuron)
{
	if ((_Axons.size() == 0) || (AimNeuron != *std::find(_Axons.begin(), _Axons.end(), AimNeuron)))
	{
		_Axons.push_back(AimNeuron);
		AimNeuron->AddDendrit(this);
	};
};

std::vector<CNN::CNeuron*> CNN::CNeuron::GetAxons()
{
	return _Axons;
};

CNN::CNeuron::CNeuron()
{
	_SignalsResieved = 0;
	_ActivationShifter = 0.5;
	_Dendrits.clear();
	_Axons.clear();
};

void CNN::CNeuron::Print()
{
	std::cout << "Neuron " << this << std::endl;
	for (auto dendrit : _Dendrits)
		std::cout << "    Weight: " << dendrit.second.Weight << std::endl;
};

CNN::CNeuron::~CNeuron()
{
	// TODO: Remove dependances.
	_Dendrits.clear();
	_Axons.clear();
};

void CNN::CNeuron::AddDendrit(CNeuron* SenderNeuron)
{
	if (_Dendrits.find(SenderNeuron) == _Dendrits.end())
	{
		_Dendrits.insert(std::pair<CNeuron*, TDendrit>(SenderNeuron, TDendrit(rand() * 1.0 / RAND_MAX, 0)));
		SenderNeuron->AddAxonTo(this);
	};
};

float CNN::CNeuron::GetOutput()
{
	return ActivationFunction(GetLinearCombination());
};

int CNN::CNeuron::DendritsQuantity()
{
	return _Dendrits.size();
};

void CNN::CNeuron::SetDendritWeight(CNeuron* Sender, float Weight)
{
	assert(_Dendrits.find(Sender) != _Dendrits.end());
	_Dendrits[Sender].Weight = Weight;
};

float CNN::CNeuron::GetDendritWeight(CNeuron* Sender)
{
	auto Dendrit = _Dendrits.find(Sender);
	assert(Dendrit != _Dendrits.end());
	return (*Dendrit).second.Weight;
};

void CNN::CNeuron::RecieveSignal(CNeuron* Sender, float Signal)
{
	auto Dendrit = _Dendrits.find(Sender);
	assert(Dendrit != _Dendrits.end());
	_SignalsResieved++;
	(*Dendrit).second.Signal = Signal;
	if (_SignalsResieved == _Dendrits.size())
	{
		SendImpulse(GetOutput());
		_SignalsResieved = 0;
	};
};

float CNN::CNeuron::GetSignalState(CNeuron* Sender)
{
	auto Dendrit = _Dendrits.find(Sender);
	assert(Dendrit != _Dendrits.end());
	return (*Dendrit).second.Signal;
};

float CNN::CNeuron::GetLinearCombination()
{
	float result = 0;
	for (auto dendrit : _Dendrits)
		result += dendrit.second.Signal * dendrit.second.Weight;
	return result;
};

float CNN::CNeuron::ActivationFunction(float x)
{
	return 1.0 / (1 + exp(-x));
	//return x / (fabsf(x) + _ActivationShifter);
};

void CNN::CNeuron::SendImpulse(float Intencity)
{
	for (auto axon : _Axons)
		axon->RecieveSignal(this, Intencity);
};
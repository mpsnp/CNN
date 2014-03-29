#include "CPerceptron.hxx"
#include <cassert>

CNN::CPerceptron::CPerceptron(int HiddenLayers)
{
	_vLayers.resize(HiddenLayers + 2);
};

CNN::CPerceptron::~CPerceptron()
{
	for (auto layer : _vLayers)
		for (auto neuron : layer)
			if (neuron)
			{
				delete neuron;
				neuron = NULL;
			};
};

void CNN::CPerceptron::AddNeuronToLayer(CNeuron* Neuron, int Layer)
{
	// Range check
	assert((Layer < _vLayers.size()) && (Layer >= 0));

	_vLayers[Layer].push_back(Neuron);

	// Add connections
	if (Layer > 0)
		for (auto upperNeuron : _vLayers[Layer - 1])
			upperNeuron->AddAxonTo(Neuron);
	if (Layer < _vLayers.size() - 1)
		for (auto overNeuron : _vLayers[Layer])
			Neuron->AddAxonTo(overNeuron);
};

void CNN::CPerceptron::FillLayers(std::vector<int> NeuronsQuantity)
{
	assert(_vLayers.size() == NeuronsQuantity.size());
	// TODO: add sensors and reaction neurons

	for (int i = 1; i < NeuronsQuantity.size() - 1; i++)
		for (int ii = 0; ii < NeuronsQuantity[i]; ii++)
			AddNeuronToLayer(GenerateNewNeuron(), i);
};

CNN::CNeuron* CNN::CPerceptron::GenerateNewNeuron()
{
	return new CNeuron();
};
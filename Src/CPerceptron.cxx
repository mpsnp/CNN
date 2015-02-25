#include "CPerceptron.hxx"
#include <cassert>
#include <random>
#include <iostream>
#include <queue>

CNN::CPerceptron::CPerceptron(int HiddenLayers)
{
	_vLayers.resize(HiddenLayers + 2);
	srand(time(NULL));
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

void CNN::CPerceptron::PrintNetwork()
{
	for (int i = 0; i < _vLayers.size(); i++)
		PrintLayer(i);
};

void CNN::CPerceptron::PrintLayer(int ALayer)
{
	std::cout << "Layer " << ALayer << std::endl;
	for (auto neuron : _vLayers[ALayer])
		neuron->Print();
};

int CNN::CPerceptron::GetLayerCount()
{
	return _vLayers.size();
};

CNN::TNeuronLayer CNN::CPerceptron::GetLayer(int Layer)
{
	assert (Layer < _vLayers.size());
	return _vLayers[Layer];
};

CNN::TNeuronLayer CNN::CPerceptron::GetSensorsLayer()
{
	assert(_vLayers.size() > 0);
	return _vLayers[0];
};

CNN::TNeuronLayer CNN::CPerceptron::GetRecieversLayer()
{
	assert(_vLayers.size() > 0);
	return _vLayers.back();
};

CNN::TOutputVector CNN::CPerceptron::Calculate(TInputVector Input)
{
	assert(_vLayers[0].size() == Input.size());
	
	for (int i = 0; i < _vLayers[0].size(); i++)
		_vLayers[0][i]->SendImpulse(Input[i]);
	
	TOutputVector result;
	for (auto neuron : _vLayers.back())
		result.push_back(neuron->GetOutput());
	return result;
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
		for (auto overNeuron : _vLayers[Layer + 1])
			Neuron->AddAxonTo(overNeuron);
};

void CNN::CPerceptron::FillLayers(std::vector<int> NeuronsQuantity)
{
	assert(_vLayers.size() == NeuronsQuantity.size());

	for (int i = 0; i < NeuronsQuantity.size(); i++)
		for (int ii = 0; ii < NeuronsQuantity[i]; ii++)
			AddNeuronToLayer(GenerateNewNeuron(), i);
};

void CNN::CPerceptron::MapToArray(double *&map, int &length)
{
    length = 0;
    for (int i = 0; i < this->GetLayerCount(); i++)
    {
        TNeuronLayer layer = this->GetLayer(i);
        for (int i = 0; i < layer.size(); i++)
            length += layer[i]->DendritsQuantity();
    }
    
    if (!map)
        map = new double[length];
    int k = 0;
    
    TNeuronLayer layer = this->GetLayer(0);
    
    for (int i = 1; i < this->GetLayerCount(); i++)
    {
        TNeuronLayer nextLayer = this->GetLayer(i);
        for (int i = 0; i < nextLayer.size(); i++)
        {
            for (int j = 0; j < layer.size(); j++)
            {
                map[k++] = nextLayer[i]->GetDendritWeight(layer[j]);
            }
        }
        layer = nextLayer;
    }
}

void CNN::CPerceptron::MapFromArray(double *map, int length)
{
    int k = 0;
    TNeuronLayer layer = this->GetLayer(0);
    
    for (int i = 1; i < this->GetLayerCount(); i++)
    {
        TNeuronLayer nextLayer = this->GetLayer(i);
        for (int i = 0; i < nextLayer.size(); i++)
        {
            for (int j = 0; j < layer.size(); j++)
            {
                nextLayer[i]->SetDendritWeight(layer[j], map[k++]);
            }
        }
        layer = nextLayer;
    }
}

CNN::CNeuron* CNN::CPerceptron::GenerateNewNeuron()
{
	return new CNeuron();
};
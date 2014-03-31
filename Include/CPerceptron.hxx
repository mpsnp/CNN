#ifndef _PERCEPTRON_H
#define _PERCEPTRON_H

#include "CGenericNetwork.hxx"
#include "CNeuron.hxx"

namespace CNN
{
	typedef std::vector<CNeuron*> TNeuronLayer;
	
	class CPerceptron : public CGenericNetwork
	{
	private:
		std::vector< std::vector<CNeuron*> > _vLayers;
	public:
		CPerceptron(int HiddenLayers);
		~CPerceptron();

		TOutputVector Calculate(TInputVector Input);
		void AddNeuronToLayer(CNeuron* Neuron, int Layer);
		void FillLayers(std::vector<int> NeuronsQuantity);
		
		TNeuronLayer GetLayer(int Layer);
		TNeuronLayer GetRecieversLayer();
		TNeuronLayer GetSensorsLayer();
		
		int GetLayerCount();
		
		virtual CNeuron* GenerateNewNeuron();
	};
};

#endif
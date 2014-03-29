#ifndef _PERCEPTRON_H
#define _PERCEPTRON_H

#include "CGenericNetwork.hxx"
#include "CNeuron.hxx"

namespace CNN
{
	class CPerceptron : public CGenericNetwork
	{
	private:
		std::vector< std::vector<CNeuron*> > _vLayers;
	public:
		CPerceptron(int HiddenLayers);
		~CPerceptron();

		std::vector<float> Calculate(std::vector<float> Input);
		void AddNeuronToLayer(CNeuron* Neuron, int Layer);
		
		// void AddTeacher();
	};
};

#endif
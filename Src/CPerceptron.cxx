#include "CPerceptron.hxx"

CNN::CPerceptron::CPerceptron(int HiddenLayers)
{
	_vLayers.resize(HiddenLayers + 2);
};

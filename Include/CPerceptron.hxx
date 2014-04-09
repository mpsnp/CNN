#ifndef _PERCEPTRON_H
#define _PERCEPTRON_H

#include "CGenericNetwork.hxx"
#include "CNeuron.hxx"

namespace CNN
{
	/**
	 * @brief Vector contains neurons.
	 * @details Symply typedef just for good looking and code understanding.
	 */
	typedef std::vector<CNeuron*> TNeuronLayer;
	
	/**
	 * @brief Perceptron implementation.
	 * @details Implements multi layer perceptron.
	 */
	class CPerceptron : public CGenericNetwork
	{
	private:
		std::vector<TNeuronLayer> _vLayers;
	public:
		/**
		 * @brief Constructs new perceptron.
		 * @details It only prepares perceptron structure for neurons adding. All layers are blank after construction.
		 * For neurons adding use AddNeuronToLayer() and FillLayers() methods. 
		 * @note Don't forget to train it.
		 * 
		 * @param HiddenLayers Hidden layers quantity. 
		 */
		CPerceptron(int HiddenLayers);

		/**
		 * @brief Deletes all neurons in it.
		 */
		~CPerceptron();

		TOutputVector Calculate(TInputVector Input);

		/**
		 * @brief Adds specified neuron to specified layer.
		 * @warning First layer index is 0.
		 * 
		 * @param Neuron Neuron instance.
		 * @param Layer Layer index.
		 */
		void AddNeuronToLayer(CNeuron* Neuron, int Layer);

		/**
		 * @brief Automatically fills layers.
		 * @details Automatically adds new neurons by calling AddNeuronToLayer(). 
		 * New neurons are generated with GenerateNewNeuron() method.
		 * 
		 * @param NeuronsQuantity Vector contains neurons quantity for each layer. 
		 * Vector must be the same size as GetLayerCount().
		 */
		void FillLayers(std::vector<int> NeuronsQuantity);
		
		/**
		 * @brief Returns layer with specified index.
		 * 
		 * @param Layer Layer index.
		 */
		TNeuronLayer GetLayer(int Layer);

		/**
		 * @brief Returns the last layer.
		 * @details It is simply for convenience purposes.
		 */
		TNeuronLayer GetRecieversLayer();

		/**
		 * @brief Returns first layer.
		 */
		TNeuronLayer GetSensorsLayer();
		
		/**
		 * @brief Returns layers count.
		 */
		int GetLayerCount();

		/**
		 * @brief Prints every neuron in layer.
		 * @todo Add new param --- output stream.
		 * 
		 * @param ALayer Layer index.
		 */
		void PrintLayer(int ALayer);

		/**
		 * @brief Prints every layer in network.
		 */
		void PrintNetwork();
		
		/**
		 * @brief Generates new neuron.
		 * @details If you want to use custom neurons, you need override this method.
		 * @return Pointer to base class CNeuron.
		 */
		virtual CNeuron* GenerateNewNeuron();
	};
};

#endif
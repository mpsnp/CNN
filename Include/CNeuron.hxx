#ifndef _NEURON_H
#define _NEURON_H

#include <map>
#include <vector>

/**
 * @brief Main and the one namespace.
 * @details All classes are defined in this namespace.
 */
namespace CNN
{
	/**
	 * @brief Dendrit structure.
	 * @details It is used in neuron for handling input signals and weights in summator.
	 */
	struct TDendrit
	{
		/**
		 * @brief Weight of link (dendrit).
		 */
		float Weight;

		/**
		 * @brief Input signal recieved from sender neuron.
		 */
		float Signal;

		/**
		 * @brief Constructs dendrit with null values.
		 */
		TDendrit();

		/**
		 * @brief Constructs dendrit with start values.
		 * 
		 * @param AWeight Weight of link.
		 * @param ASignal Start signal state.
		 */
		TDendrit(float AWeight, float ASignal);
	};

	/**
	 * @brief Generic neuron.
	 * @details Key functions are virtual such as ActivationFunction().
	 */
	class CNeuron
	{
	private:
		int _SignalsResieved;
		float _ActivationShifter;
		std::map<CNeuron*, TDendrit> _Dendrits;
		std::vector<CNeuron*> _Axons;
	public:
		/**
		 * @brief Default constructor.
		 * @details Constructs neuron with no links to others.
		 */
		CNeuron();

		/**
		 * @brief Virtual destructor.
		 * @details Removes links to other neurons.
		 */
		virtual ~CNeuron();

		/**
		 * @brief Adds axon to AimNeuron.
		 * @details It also adds dendrit from AimNeuron to self.
		 * 
		 * @param AimNeuron Neuron which to link with.
		 */
		void AddAxonTo(CNeuron* AimNeuron);

		/**
		 * @brief Get all axons recievers.
		 */
		std::vector<CNeuron*> GetAxons();

		/**
		 * @brief Adds dendrit.
		 * @details It also adds axon from sender to self.
		 * 
		 * @param SenderNeuron Neuron from which recieve signals.
		 */
		void AddDendrit(CNeuron* SenderNeuron);

		/**
		 * @brief Returns dendrits quantity.
		 */
		int DendritsQuantity();

		/**
		 * @brief Sets dendrit weight.
		 * @details This method searces dendrit which conforms to Sender and sets it new weight.
		 * 
		 * @param Sender neuron.
		 * @param Weight New dendrit weight.
		 */
		void SetDendritWeight(CNeuron* Sender, float Weight);

		/**
		 * @brief Gets dendrit weight.
		 * @details If link exists it returns it weight.
		 * 
		 * @param Sender neuron.
		 * @return Weight.
		 */
		float GetDendritWeight(CNeuron* Sender);
		
		/**
		 * @brief Recieves signal.
		 * @details If dendrit exists, neuron recieves signal on it. 
		 * If neuron recieves DendritsQuantity() signals it sends impulse to all it's axons.
		 * 
		 * @param Sender neuron.
		 * @param Signal value.
		 */
		void RecieveSignal(CNeuron* Sender, float Signal);

		/**
		 * @brief Gets signal on dendrit.
		 * 
		 * @param Sender neuron.
		 * @return Signal value.
		 */
		float GetSignalState(CNeuron* Sender);

		/**
		 * @brief Returns linear combination of weights and signals.
		 */
		float GetLinearCombination();

		/**
		 * @brief Prints neuron to Out.
		 * @param Out Output stream.
		 */
		void Export(std::ostream Out);

		/**
		 * @brief Sends impulse to all axons.
		 * 
		 * @param Intencity Signal value.
		 */
		void SendImpulse(float Intencity);

		/**
		 * @brief Neuron activation function.
		 */
		virtual float ActivationFunction(float x);
		
		/**
		 * @brief Returns output signal of neuron.
		 */
		float GetOutput();
	};	
};

#endif
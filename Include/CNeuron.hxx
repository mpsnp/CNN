#ifndef _NEURON_H
#define _NEURON_H

namespace CNN
{
	class CNeuron
	{
	public:
		CNeuron();
		virtual ~CNeuron();

		void AddAxonTo(CNeuron* AimNeuron);
		void AddDendrit(CNeuron* SenderNeuron);
		int DendritsQuantity();
		void SetDendritWeight(CNeuron* Sender, float Weight);
		
		void RecieveSignal(CNeuron* Sender, float Signal);
		float GetSignalState(CNeuron* Sender);

		virtual float ActivationFunction(); 
	};	
};

#endif
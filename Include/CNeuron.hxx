#ifndef _NEURON_H
#define _NEURON_H

#include <map>
#include <vector>

namespace CNN
{
	struct TDendrit
	{
		float Weight;
		float Signal;
		TDendrit();
		TDendrit(float AWeight, float ASignal);
	};

	class CNeuron
	{
	private:
		int _SignalsResieved = 0;
		float _ActivationShifter = 0.5;
		std::map<CNeuron*, TDendrit> _Dendrits;
		std::vector<CNeuron*> _Axons;
	public:
		CNeuron();
		virtual ~CNeuron();

		void AddAxonTo(CNeuron* AimNeuron);
		std::vector<CNeuron*> GetAxons();
		void AddDendrit(CNeuron* SenderNeuron);
		int DendritsQuantity();

		void SetDendritWeight(CNeuron* Sender, float Weight);
		float GetDendritWeight(CNeuron* Sender);
		
		void RecieveSignal(CNeuron* Sender, float Signal);
		float GetSignalState(CNeuron* Sender);

		float GetLinearCombination();

		void SendImpulse(float Intencity);

		virtual float ActivationFunction(float x);
		
		float GetOutput();
	};	
};

#endif
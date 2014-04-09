#ifndef _RECIEVER_H
#define _RECIEVER_H

#include "CNeuron.hxx"

namespace CNN
{
	/**
	 * @brief Reciever (output neuron).
	 * @details It can be used not only as output, because the main difference is that it's output signal is scalable.
	 */
	class CReciever : public CNeuron
	{
		float _ScailingFactor;
	public:
		/**
		 * @brief Default constructor.
		 * @details Default scailing factor equals 1.
		 */
		CReciever();

		/**
		 * @brief Constructor with scailing factor.
		 */
		CReciever(float AScailingFactor);

		/**
		 * @brief Default destructor.
		 */
		~CReciever();

		/**
		 * @brief Scailing factor setter.
		 */
		void SetScailingFactor(float AScilingFactor);

		/**
		 * @brief Scailing factor getter.
		 */
		float GetScailingFactor();

		float GetOutput();
	};
};

#endif
#ifndef _GENERIC_NETWORK_H
#define _GENERIC_NETWORK_H

#include <vector>

namespace CNN
{
	/**
	 * @brief Input vector.
	 * @details Symply typedef just for good looking and code understanding.
	 */
	typedef std::vector<float> TInputVector;

	/**
	 * @brief Output vector.
	 * @details Symply typedef just for good looking and code understanding.
	 */
	typedef std::vector<float> TOutputVector;
	
	/**
	 * @brief Base class for all networks.
	 */
	class CGenericNetwork
	{
	public:
		/**
		 * @brief Default empty constructor.
		 */
		CGenericNetwork(){};

		/**
		 * @brief Default virtual destructor.
		 */
		virtual ~CGenericNetwork(){};

		/**
		 * @brief Processes input vector to output vector.
		 * @warning Correct processing requires network training.
		 * 
		 * @param Input Input vector.
		 * @return Output vector.
		 */
		virtual TOutputVector Calculate(TInputVector Input) = 0;
	};
};

#endif
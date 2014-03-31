#ifndef _GENERIC_NETWORK_H
#define _GENERIC_NETWORK_H

#include <vector>

namespace CNN
{
	typedef std::vector<float> TInputVector;
	typedef std::vector<float> TOutputVector;
	
	class CGenericNetwork
	{
	public:
		CGenericNetwork(){};
		virtual ~CGenericNetwork(){};
		virtual TOutputVector Calculate(TInputVector Input) = 0;
	};
};

#endif
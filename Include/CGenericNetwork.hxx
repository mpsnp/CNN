#ifndef _GENERIC_NETWORK_H
#define _GENERIC_NETWORK_H

#include <vector>

namespace CNN
{
	class CGenericNetwork
	{
	public:
		CGenericNetwork(){};
		virtual ~CGenericNetwork(){};
		virtual std::vector<float> Calculate(std::vector<float> Input) = 0;
	};
};

#endif
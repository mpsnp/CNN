#include "CNN.hxx"

using namespace CNN;
using namespace std;

int main(int argc, char const *argv[])
{
	CPerceptron percepron(1);
	percepron.FillLayers({1,5,1});
	vector<float> out = percepron.Calculate({10});
	return 0;
}
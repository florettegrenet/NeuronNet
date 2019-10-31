#include "random.h"


RandomNumbers::RandomNumbers(unsigned long int s) : seed(s)
{
	 if (s == 0) {
        std::random_device rd;
        seed = rd();
    }
    rng = std::mt19937(seed);
}


void RandomNumbers::uniform_double(std::vector<double>& res, double lower, double upper)
{
	std::uniform_real_distribution<double> unif(lower, upper);
    for (auto I = res.begin(); I != res.end(); I++) *I = unif(rng); //ou reutiliser la fonction ci dessous
}


double RandomNumbers::uniform_double(double lower, double upper)
{
	std::uniform_real_distribution<double> unif(lower, upper);
	return unif(rng);
}



void RandomNumbers::normal(std::vector<double>& res, double mean, double sd)
{
	std::normal_distribution<double> norm(mean, sd);
    for (auto I = res.begin(); I != res.end(); I++) *I = norm(rng); //ou reutiliser la fonction ci dessous
}



double RandomNumbers::normal(double mean, double sd)
{
	std::normal_distribution<double> norm(mean, sd);
	return norm(rng);
}



void RandomNumbers::poisson(std::vector<int>& res, double mean)
{
	std::poisson_distribution<int> poi(mean);
    for (auto I = res.begin(); I != res.end(); I++) *I = poi(rng); //ou reutiliser la fonction ci dessous
}



int RandomNumbers::poisson(double mean)
{
	std::poisson_distribution<int> poi(mean);
	return poi(rng);
}

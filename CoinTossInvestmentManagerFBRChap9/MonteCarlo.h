#ifndef MONTECARLO_H
#define MONTECARLO_H

#include <iostream>
#include <vector>
#include <random>
#include <chrono>

template <typename T>
class MonteCarlo
{
public:
	MonteCarlo(int size);
	void flipCoin();
private:
	std::vector<T> m_data;
	int m_year;
};



template <typename T>
MonteCarlo<T>::MonteCarlo(int size) : m_year(0)
{
	m_data.resize(size);
}


template<typename T>
inline void MonteCarlo<T>::flipCoin()
{
	int headsSum{};

	//we use the system clock as the seed for our random number generator
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator{seed};
	std::uniform_int_distribution<int> distribution(0, 1);
	
	
	for (auto i : m_data)
	{
		i = distribution(generator);
		if (i == 1)
			headsSum++;
	}

	m_data.resize(headsSum);
	m_year++;

	std::cout << "After year " << m_year << " " << headsSum << " managers are up this year" << std::endl;
	
	
}

#endif // !MONTECARLO_H
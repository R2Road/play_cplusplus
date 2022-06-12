#include <iostream>
#include <stdio.h>
#include <vector>

#define A( a ) #a

template<typename T>
class DummyTemplateClass
{
public: using ValueT = T;
private: ValueT mValue;
};

int main()
{
	std::vector<DummyTemplateClass<int>> dummy_vector;
	for( const auto v : dummy_vector ) { std::cout << v; }

	return 0;
}
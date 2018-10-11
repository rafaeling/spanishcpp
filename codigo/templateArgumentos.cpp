/*

	Tutorial que tiene como objetivo fortalecer conocimientos
	sobre templates con argumentos.

	Aclaraciones 
	************
	Cuando aparece templates con algo como template<class ...Args>
	A veces  parece algo realmente feo a simple vista, pero cuando leemos una clase 
	o funcion template en la que un argumento es algo como: template<typename T, class ...Args>

*/

#include <iostream>
#include <tuple>
#include <iostream>
#include <array>
#include <utility>

template <std::size_t N, class T>
struct miembro_base
{
	T value;
	std::size_t size;
	miembro_base()
	{
		size = N;
	}
};

template <class I, class ...Argumentos>
struct double_base; // Predefinicion necesaria de double_base abajo utilizada


template <std::size_t... I, class ...Tail>
struct double_base <std::index_sequence<I...>, Tail... >
	: miembro_base<I, Tail>... // esta parte actua como un iterador sobre la secuencia de elementos ...Tail
{

};

int main(int argc, char *argv[])
{
	auto test_miembro_base = miembro_base<8,int>();
	std::cout << test_miembro_base.size << std::endl;
	return 0;
}
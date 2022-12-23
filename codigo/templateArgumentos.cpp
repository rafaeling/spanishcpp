/*

	Tutorial que tiene como objetivo fortalecer conocimientos
	sobre templates con argumentos.

	Aclaraciones
	************
	Cuando aparece templates con algo como template<class ...Args>
	significa algo asi como un vector de elementos (de diferentes clases)

	Ejemplo:
	template<class ...Args>
	class Base {};

	Uso:
	auto baseTest = Base<int, string, double, ObjetoA, ObjectoB>();

*/

#include <iostream>
#include <tuple>
#include <iostream>
#include <array>
#include <utility>

template <std::size_t index, class T>
struct miembro_base
{
	T value;
	miembro_base()
	{
		std::cout << index << std::endl;
	}
};

template <class I, class ...Argumentos>
struct doble_base; // Predefinicion necesaria de double_base abajo utilizada


template <std::size_t... I, class ...Clases>
struct doble_base <std::index_sequence<I...>, Clases... >
	: miembro_base<I, Clases>... // esta parte actua como un iterador sobre la secuencia de elementos ...Tail
{

};

template <class ...Valores>
struct doble : doble_base<std::make_index_sequence<sizeof...(Valores)>, Valores...>
{

};

int main(int argc, char *argv[])
{
	auto test_double_base = doble<int, double, int, int>();
	return 0;
}

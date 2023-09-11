#pragma
#include <string>
extern "C" 
{
	_declspec(dllimport) const char* GetCodeName();
	_declspec(dllimport) double Sumar(double a, double b);
	_declspec(dllimport) std::string Concatenar(const std::string frase1, const std::string frase2);
}
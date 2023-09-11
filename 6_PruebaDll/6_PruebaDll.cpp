#include <iostream>
#include  <windows.h>
#include <fstream>


int main()
{
    puts("hola, Cargando DLL");
    HINSTANCE mydll = LoadLibrary(L"6_DLL.dll");

    if (mydll != NULL) 
    {
        puts("Se cargo la DLL ;)");
        typedef const char* (*GetCodenameFunc)();
        GetCodenameFunc getCodename = reinterpret_cast<GetCodenameFunc>(GetProcAddress(mydll, "GetCodeName"));

        if (getCodename != NULL) 
        {
            const char* mensaje = getCodename();
            std::cout << "desde la DLL " << mensaje << "\n";
        }
        else 
        {
            puts("No se encontro funcion :(");
        }
        typedef double (*SumarFunc)(double a, double b);
        SumarFunc sumar = reinterpret_cast<SumarFunc>(GetProcAddress(mydll, "Sumar"));

        if (sumar != NULL) 
        {
            std::cout << "prueba de suma " << sumar(3.1416, 1.414) << "\n";
        }
        else 
        {
            puts("You Globed Up");
        }
        typedef std::string(*ConcatenarFunc)(const std::string& frase1, const std::string& frase2);
        ConcatenarFunc concatenar = reinterpret_cast<ConcatenarFunc>(GetProcAddress(mydll, "Concatenar"));

        if (concatenar != NULL)
        {
            std::cout << "Resultado de concatenacion: " << concatenar("Hola, ", "mundo!") << "\n";
        }
        else
        {
            puts("No se encontró la función de concatenación :(");
        }
        FreeLibrary(mydll);
    }
    else 
    {
        puts("Ya te cargo el payaso");
    }

    return 0;
}
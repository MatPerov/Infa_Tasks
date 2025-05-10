#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef void (*function_type)();

int main() {
    HMODULE hLib = LoadLibrary("external/lib/house.dll");

    function_type cat = (function_type)GetProcAddress(hLib, "cat");
    function_type mouse = (function_type)GetProcAddress(hLib, "mouse");
    function_type elephant = (function_type)GetProcAddress(hLib, "elephant");
    function_type dog = (function_type)GetProcAddress(hLib, "dog");
    function_type tiger = (function_type)GetProcAddress(hLib, "tiger");
    function_type axolotl = (function_type)GetProcAddress(hLib, "axolotl");

    cat();
    mouse();
    elephant();

    dog();
    tiger();
    axolotl();

    FreeLibrary(hLib);

    return 0;
}
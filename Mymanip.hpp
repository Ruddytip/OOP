#pragma once
#include <ios>

// Task 2. Создать собственный манипулятор endll для стандартного потока вывода, который выводит два перевода строки и сбрасывает буфер.
template<typename T, typename S>
std::basic_ostream<T, S>& endll(std::basic_ostream<T, S>& _os){
    _os.put(_os.widen('\n'));
    _os.put(_os.widen('\n'));
    return flush(_os);
}
#include <iostream>
#include "hello.h"

void hello(){
    #ifdef NDEBUG
    std::cout << "hello/1.0: Hello World Release!" <<std::endl;
    #else
    std::cout << "hello/1.0: Hello World Debug!" <<std::endl;
    #endif
}

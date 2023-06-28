#include "compiler.h"

int main() {
    Compiler compiler;
    ByteCodeStream bcs;
    compiler.Compile(std::cin, bcs);

    return 0;
}
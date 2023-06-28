#include "compiler.h"
#include "scanner.h"
#include "program_node_builder.h"
#include "parser.h"
#include "code_generate.h"

Compiler::Compiler() {
}

void Compiler::Compile(std::istream &input, ByteCodeStream &output) {
    Scanner scanner(input);
    ProgramNodeBuilder builder;
    Parser parser;

    parser.Parse(scanner, builder);

    RISCCodeGenerator generator(output);
    ProgramNode *parseTree = builder.GetRootNode();
    parseTree->Traverse(generator);
}
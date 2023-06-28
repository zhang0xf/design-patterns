#ifndef PARSER_H
#define PARSER_H

#include "scanner.h"
#include "program_node_builder.h"

// (Parser)类由(Scanner)类生成的标识符构件一颗语法分析树.

class Parser {
public:
    Parser();
    virtual ~Parser();

    virtual void Parse(Scanner &, ProgramNodeBuilder &);
};

#endif
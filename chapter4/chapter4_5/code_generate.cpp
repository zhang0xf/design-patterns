#include "code_generate.h"

// CodeGenerator ============================================
CodeGenerator::CodeGenerator(ByteCodeStream &) {
}

void CodeGenerator::Visit(StatementNode *) {
}

void CodeGenerator::Visit(ExpressionNode *) {
}

// RISCCodeGenerator ========================================
RISCCodeGenerator::RISCCodeGenerator(ByteCodeStream &bcs) :
    CodeGenerator(bcs) {
}
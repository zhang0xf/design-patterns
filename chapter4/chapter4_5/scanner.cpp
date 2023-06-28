#include "scanner.h"

Scanner::Scanner(std::istream &input) :
    _inputStream(input) {
    UNUSED(_inputStream);
}

Scanner::~Scanner() {
}

Token &Scanner::Scan() {
    Token *token = new Token;
    return *token;
}

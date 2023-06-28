#include "glyph.h"
#include "def.h"

// Glyph ========================================

Glyph::Glyph() {
}

Glyph::~Glyph() {
}

void Glyph::Draw(Window *, GlyphContext &) {
}

void Glyph::SetFont(Font *, GlyphContext &) {
}

Font *Glyph::GetFont(GlyphContext &) {
    return new Font;
}

void Glyph::First(GlyphContext &) {
}

void Glyph::Next(GlyphContext &) {
}

bool Glyph::IsDone(GlyphContext &) {
    return false;
}

Glyph *Glyph::Current(GlyphContext &) {
    return new Glyph; // 简化
}

void Glyph::Insert(Glyph *, GlyphContext &) {
}

void Glyph::Remove(GlyphContext &) {
}

// Character =====================================

Character::Character(char) {
    UNUSED(_charcode);
}

void Character::Draw(Window *, GlyphContext &) {
}

// GlyphFactory ==================================

GlyphFactory::GlyphFactory() {
    for (int i = 0; i < NCHARCODES; i++) {
        _character[i] = 0;
    }
}

GlyphFactory::~GlyphFactory() {
}

Character *GlyphFactory::CreateCharacter(char ch) {
    if (!_character[int(ch)]) {
        _character[int(ch)] = new Character(ch);
    }
    return _character[int(ch)];
}

Row *GlyphFactory::CreateRow() {
    return new Row;
}

Column *GlyphFactory::CreateColumn() {
    return new Column;
}

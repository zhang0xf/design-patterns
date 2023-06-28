#ifndef GLYPH_H
#define GLYPH_H

#include "window.h"
#include "btree.h"
#include "font.h"

// 为了避免给每一个(Glyph)的字体属性都分配空间, 我们可以将该属性外部存储于(GlyphContext)对象中.
// (GlyphContext)是一个外部状态的存储库, 它维持(Glyph)与字体(以及其他一些可能的图形属性)之间的一种简单映射关系.
// 对于任何操作,如果它需要知道在给定场景下的(Glyph)字体, 都会有一个(GlyphContext)实例作为参数传递给它, 然后该操作就可以查询(GlyphContext)以获取场景中的字体信息了.
class GlyphContext {
public:
    GlyphContext();
    virtual ~GlyphContext();

    virtual void Next(int step = 1);
    virtual void Insert(int quantity = 1);

    virtual Font *GetFont();
    virtual void SetFont(Font *, int span = 1);

private:
    int _index;    // 字体索引作为(BTree)结构的关键字(详见:p152)
    BTree *_fonts; // 存储(Glyph)到字体的映射(详见:p152)
};

// (Glyph)类是一些(Composite)类, 有图形化属性, 并且可以绘制自己.

class Glyph {
public:
    virtual ~Glyph();

    virtual void Draw(Window *, GlyphContext &);

    virtual void SetFont(Font *, GlyphContext &);
    virtual Font *GetFont(GlyphContext &);

    virtual void First(GlyphContext &);
    virtual void Next(GlyphContext &); // 随着遍历的进行, (GlyphContext::Next)将增加(_index)的值
    virtual bool IsDone(GlyphContext &);
    virtual Glyph *Current(GlyphContext &);

    virtual void Insert(Glyph *, GlyphContext &);
    virtual void Remove(GlyphContext &);

protected:
    Glyph();
};

// (Glyph)的子类(如: (Row)和(Column))对Next操作的实现必须使得它在遍历的每一点调用(GlyphContext::Next)
class Row : public Glyph {
};

class Column : public Glyph {
};

// (Character)的子类存储一个字符代码
class Character : public Glyph {
public:
    Character(char);

    virtual void Draw(Window *, GlyphContext &);

private:
    char _charcode;
};

// (GlyphFactory)负责创建(Glyph)并确保它们进行合理共享

const int NCHARCODES = 128; // ASCII码

class GlyphFactory {
public:
    GlyphFactory();
    virtual ~GlyphFactory();
    virtual Character *CreateCharacter(char); // 在字母符号数组中查找一个字符
    virtual Row *CreateRow();
    virtual Column *CreateColumn();
    // ...

private:
    Character *_character[NCHARCODES]; // 包含指向以字母代码为索引的的(Character Glyph)的指针
};

#endif
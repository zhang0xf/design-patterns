#ifndef DOCUMENT_H
#define DOCUMENT_H

class Document {
public:
    Document();
    Document(const char *);

    bool Open();
    bool Paste();

private:
    const char *_name;
};

#endif
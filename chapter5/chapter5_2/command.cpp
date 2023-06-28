#include "command.h"
#include "iterator.h"

Command::Command() {
}

Command::~Command() {
}

OpenCommand::OpenCommand(Application *app) {
    _application = app;
}

void OpenCommand::Execute() {
    const char *name = AskUser();

    if (name != 0) {
        Document *document = new Document(name);
        _application->Add(document);
        document->Open();
    }
}

const char *OpenCommand::AskUser() {
    return _response;
}

PasteCommand::PasteCommand(Document *doc) {
    _document = doc;
}

void PasteCommand::Execute() {
    _document->Paste();
}

void MacroCommand::Execute() {
    cps::ListIterator<Command *> i(_cmds);

    for (i.First(); !i.IsDone(); i.Next()) {
        Command *c = i.CurrentItem();
        c->Execute();
    }
}

void MacroCommand::Add(Command *c) {
    _cmds->Append(c);
}

void MacroCommand::Remove(Command *c) {
    _cmds->Remove(c);
}
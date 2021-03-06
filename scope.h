#ifndef SCOPE_H
#define SCOPE_H

#include "symbol.h"
#include "function.h"
#include "variable.h"

namespace Demo {

class GLWidget;
class CodeEditor;

namespace GL {
class Compiler;
}

class Scope: public QObject
{
    Q_OBJECT

public:

    typedef QList<CodeEditor*> EditorList;
    typedef QMap<QString, int> IndexMap;

    // code offsets: smaller than 0xfff = 4095 (see Compiler::pushBack)
    static const int FunctionOffset = 1000;
    static const int VariableOffset = 2000;

    Scope(GLWidget* glContext, QObject *parent = 0);
    Scope* clone(QObject* parent = 0) const;
    const SymbolMap& symbols() const;
    const FunctionList& functions() const;
    bool subscriptRelation(const QString& top, const QString& sub);
    void dispatch(const QString& other) const;
    const EditorList& editors() const;
    void appendEditor(CodeEditor* ed, const QString& script, const QString& file);
    void removeEditor(int index);
    CodeEditor* editor(const QString& name) const;
    CodeEditor* editor(int index) const;
    GL::Compiler* compiler(const QString& name) const;
    void rename(CodeEditor* ed, const QString& name);
    const VariableMap& exports() const;
    void addFunction(Function* f);
    void recompileAll();
    QStringList itemSample(const QString& except = QString()) const;

    ~Scope();


signals:

public slots:

private:

    Scope(const Scope&);

    SymbolMap mSymbols;
    FunctionList mFunctions;
    VariableMap mExports;
    EditorList mEditors;
    IndexMap mEditorIndices;
};

}

#endif // SCOPE_H

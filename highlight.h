#ifndef HIGHLIGHT_H
#define HIGHLIGHT_H

#include <QSyntaxHighlighter>
#include <QTextCharFormat>
#include <QRegExp>
#include <QMap>

#ifndef YY_TYPEDEF_YY_SCANNER_T
#define YY_TYPEDEF_YY_SCANNER_T
typedef void* yyscan_t;
#endif


class QTextDocument;

namespace Demo {
namespace GL {
class Compiler;
}
}

class Highlight : public QSyntaxHighlighter
{
    Q_OBJECT

public:

    Highlight(Demo::GL::Compiler* compiler, QTextDocument* parent);
    ~Highlight();

protected:

    void highlightBlock(const QString &text);

private:
    typedef QMap<int, QTextCharFormat> FormatMap;

    Demo::GL::Compiler* mCompiler;
    QRegExp mCommentExp;
    QTextCharFormat mComment;
    QTextCharFormat mReserved;
    QTextCharFormat mNumeric;
    QTextCharFormat mFunction;
    QTextCharFormat mConstant;
    QTextCharFormat mText;
    FormatMap mFormats;
    yyscan_t mScanner;
};


#endif // HIGHLIGHT_H

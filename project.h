#ifndef PROJECT_H
#define PROJECT_H

#include <QAbstractItemModel>
#include <QDir>

#include "codeeditor.h"

namespace GL {

class ImageStore;

}

namespace Demo {

class GLWidget;

class BadProject {

public:
    BadProject(const QString& msg): mMsg(msg) {}
    QString msg() {return mMsg;}

private:
    QString mMsg;
};




class Project : public QAbstractItemModel
{
    Q_OBJECT

public:

    enum ProjectRoles {
        FileRole = Qt::UserRole,
        ScriptRole,
        EditorRole,
        FileNameRole
    };


public:
    // create new project
    Project(const QDir& pdir, GLWidget* target, bool autoCompileOn);
    // parse existing project
    Project(const QString& fullpath, GLWidget* target, bool autoCompileOn);

    const QDir& directory() const {return mProjectDir;}
    const QString& projectFile() const {return mProjectIni;}
    void setProjectFile(const QString& fname);
    bool autoCompileEnabled() const {return mAutoCompileOn;}
    void toggleAutoCompile(bool on);

    void saveProject();

    QString initScript() const;
    QString drawScript() const;

    QModelIndex scriptParent() const;
    QModelIndex modelParent() const;
    QModelIndex textureParent() const;

    //! Reimplemented from QAbstractItemModel
    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;

    QModelIndex index(int row, const QModelIndex &parent) const;

    //! Reimplemented from QAbstractItemModel
    QModelIndex parent(const QModelIndex &index) const;

    //! Reimplemented from QAbstractItemModel
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

    //! Reimplemented from QAbstractItemModel
    QVariant headerData(int section, Qt::Orientation, int role = Qt::DisplayRole) const;

    //! Reimplemented from QAbstractItemModel
    int rowCount(const QModelIndex &parent) const;

    //! Reimplemented from QAbstractItemModel
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    //! Reimplemented from QAbstractItemModel
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);

    //! Reimplemented from QAbstractItemModel
    Qt::ItemFlags flags(const QModelIndex &index) const;

    //! Reimplemented from QAbstractItemModel
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex());

    bool appendRow(const QString& name, const QString& file, const QModelIndex& parent);

    virtual ~Project();

public slots:

    void runnerReady();

    void scriptModification_changed(bool edited);
    void scriptStatus_changed();

    void setInitScript(const QString&);
    void setDrawScript(const QString&);

    void dispatcher(const QString& curr, const QString& other);

signals:

    void initChanged();
    void drawChanged();
    void scriptModificationChanged(bool edited);

private:


    typedef QMap<QString, QString> NameMap;
    typedef QMapIterator<QString, QString> NameIterator;
    typedef QList<CodeEditor*> EditorList;

    enum RowNames {
        ScriptRow = 0,
        ModelRow,
        TextureRow,
        NumRows
    };


private:

    CodeEditor* appendEditor(const QString& name, const QString& script, const QString& file);
    void init_and_connect();
    QString uniqueScriptName(const QString& orig) const;
    QString uniqueModelName(const QString& orig) const;
    QString uniqueImageName(const QString& orig) const;


private:

    QDir mProjectDir;
    QString mProjectIni;
    EditorList mEditors;
    NameMap mScripts;
    CodeEditor* mInit;
    CodeEditor* mDraw;
    GLWidget* mTarget;
    bool mAutoCompileOn;
};

}
#endif // PROJECT_H

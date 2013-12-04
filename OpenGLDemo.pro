#-------------------------------------------------
#
# Project created by QtCreator 2013-10-09T18:26:49
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OpenGLDemo
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    parser.cpp \
    gl_widget.cpp \
    runner.cpp \
    teapot.cpp \
    camera.cpp \
    project.cpp \
    codeeditor.cpp \
    highlight.cpp \
    newdialog.cpp \
    imagestore.cpp \
    patch.cpp \
    modelstore.cpp

HEADERS  += mainwindow.h \
    math3d.h \
    gl_functions.h \
    constant.h \
    function.h \
    parser.h \
    symbol.h \
    variable.h \
    gl_widget.h \
    runner.h \
    blob.h \
    teapot.h \
    camera.h \
    project.h \
    codeeditor.h \
    highlight.h \
    newdialog.h \
    texblob.h \
    imagestore.h \
    patch.h \
    modelstore.h \
    s_o_types.h \
    s_p_types.h

FORMS    += mainwindow.ui \
    newdialog.ui

OTHER_FILES += \
    TODO.txt \
    g_p.y \
    g_o.y \
    s_o.l \
    s_p.l


DEFINES += YYERROR_VERBOSE QT_STATICPLUGIN

MY_YACC_SOURCES = g_o.y g_p.y

my_yacc_source.commands = yacc -t ${QMAKE_FILE_IN} -p ${QMAKE_FILE_BASE} && mv y.tab.c ${QMAKE_FILE_BASE}.cpp
my_yacc_source.input = MY_YACC_SOURCES
my_yacc_source.output = ${QMAKE_FILE_BASE}.cpp
my_yacc_source.variable_out = SOURCES
my_yacc_source.CONFIG += target_predeps

my_yacc_header.commands = yacc -t -d ${QMAKE_FILE_IN}  -p ${QMAKE_FILE_BASE} && rm y.tab.c && mv y.tab.h ${QMAKE_FILE_BASE}.h
my_yacc_header.input = MY_YACC_SOURCES
my_yacc_header.output = ${QMAKE_FILE_BASE}.h
my_yacc_header.variable_out = HEADERS
my_yacc_header.CONFIG += target_predeps

QMAKE_EXTRA_COMPILERS += my_yacc_source
QMAKE_EXTRA_COMPILERS += my_yacc_header

MY_LEX_SOURCES = s_o.l s_p.l

my_lex_source.commands = flex -P${QMAKE_FILE_BASE} -t ${QMAKE_FILE_IN} > ${QMAKE_FILE_BASE}.c
my_lex_source.input = MY_LEX_SOURCES
my_lex_source.output = ${QMAKE_FILE_BASE}.c
my_lex_source.variable_out = SOURCES
my_lex_source.CONFIG += target_predeps

my_lex_header.commands = flex -P${QMAKE_FILE_BASE} --header-file=${QMAKE_FILE_BASE}.h -t ${QMAKE_FILE_IN} > /dev/null
my_lex_header.input = MY_LEX_SOURCES
my_lex_header.output = ${QMAKE_FILE_BASE}.h
my_lex_header.variable_out = HEADERS
my_lex_header.CONFIG += target_predeps

QMAKE_EXTRA_COMPILERS += my_lex_source
QMAKE_EXTRA_COMPILERS += my_lex_header


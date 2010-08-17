#############################################################################
# Makefile for building: dist/Debug/GNU-Linux-x86/3Dscanner_mk2
# Generated by qmake (2.01a) (Qt 4.6.2) on: Tue Aug 17 10:42:09 2010
# Project:  nbproject/qt-Debug.pro
# Template: app
# Command: /usr/bin/qmake -unix VPATH=. -o qttmp-Debug.mk nbproject/qt-Debug.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -Inbproject -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I. -Inbproject -I.
LINK          = g++
LFLAGS        = 
LIBS          = $(SUBLIBS)  -L/usr/lib -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = build/Debug/GNU-Linux-x86/

####### Files

SOURCES       = SplineDisplay.cpp \
		GUI.cpp \
		main.cpp \
		ModelGenerator.cpp \
		TextureDisplay.cpp \
		ImageManager.cpp \
		SplineGenerator.cpp \
		ModelManager.cpp \
		ImageDisplay.cpp moc_GUI.cpp \
		moc_SplineGenerator.cpp \
		moc_ImageManager.cpp \
		moc_ImageDisplay.cpp \
		moc_ModelGenerator.cpp \
		moc_SplineDisplay.cpp \
		moc_TextureDisplay.cpp \
		moc_ModelManager.cpp
OBJECTS       = build/Debug/GNU-Linux-x86/SplineDisplay.o \
		build/Debug/GNU-Linux-x86/GUI.o \
		build/Debug/GNU-Linux-x86/main.o \
		build/Debug/GNU-Linux-x86/ModelGenerator.o \
		build/Debug/GNU-Linux-x86/TextureDisplay.o \
		build/Debug/GNU-Linux-x86/ImageManager.o \
		build/Debug/GNU-Linux-x86/SplineGenerator.o \
		build/Debug/GNU-Linux-x86/ModelManager.o \
		build/Debug/GNU-Linux-x86/ImageDisplay.o \
		build/Debug/GNU-Linux-x86/moc_GUI.o \
		build/Debug/GNU-Linux-x86/moc_SplineGenerator.o \
		build/Debug/GNU-Linux-x86/moc_ImageManager.o \
		build/Debug/GNU-Linux-x86/moc_ImageDisplay.o \
		build/Debug/GNU-Linux-x86/moc_ModelGenerator.o \
		build/Debug/GNU-Linux-x86/moc_SplineDisplay.o \
		build/Debug/GNU-Linux-x86/moc_TextureDisplay.o \
		build/Debug/GNU-Linux-x86/moc_ModelManager.o
DIST          = /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		nbproject/qt-Debug.pro
QMAKE_TARGET  = 3Dscanner_mk2
DESTDIR       = dist/Debug/GNU-Linux-x86/
TARGET        = dist/Debug/GNU-Linux-x86/3Dscanner_mk2

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: qttmp-Debug.mk $(TARGET)

$(TARGET):  $(OBJECTS)  
	@$(CHK_DIR_EXISTS) dist/Debug/GNU-Linux-x86/ || $(MKDIR) dist/Debug/GNU-Linux-x86/ 
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

qttmp-Debug.mk: nbproject/qt-Debug.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/libQtGui.prl \
		/usr/lib/libQtCore.prl
	$(QMAKE) -unix VPATH=. -o qttmp-Debug.mk nbproject/qt-Debug.pro
/usr/share/qt4/mkspecs/common/g++.conf:
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/debug.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/libQtGui.prl:
/usr/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -unix VPATH=. -o qttmp-Debug.mk nbproject/qt-Debug.pro

dist: 
	@$(CHK_DIR_EXISTS) nbproject/build/Debug/GNU-Linux-x86/3Dscanner_mk21.0.0 || $(MKDIR) nbproject/build/Debug/GNU-Linux-x86/3Dscanner_mk21.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) nbproject/build/Debug/GNU-Linux-x86/3Dscanner_mk21.0.0/ && $(COPY_FILE) --parents GUI.h SplineGenerator.h ImageManager.h ImageDisplay.h ModelGenerator.h common.h SplineDisplay.h TextureDisplay.h ModelManager.h nbproject/build/Debug/GNU-Linux-x86/3Dscanner_mk21.0.0/ && $(COPY_FILE) --parents SplineDisplay.cpp GUI.cpp main.cpp ModelGenerator.cpp TextureDisplay.cpp ImageManager.cpp SplineGenerator.cpp ModelManager.cpp ImageDisplay.cpp nbproject/build/Debug/GNU-Linux-x86/3Dscanner_mk21.0.0/ && (cd `dirname nbproject/build/Debug/GNU-Linux-x86/3Dscanner_mk21.0.0` && $(TAR) 3Dscanner_mk21.0.0.tar 3Dscanner_mk21.0.0 && $(COMPRESS) 3Dscanner_mk21.0.0.tar) && $(MOVE) `dirname nbproject/build/Debug/GNU-Linux-x86/3Dscanner_mk21.0.0`/3Dscanner_mk21.0.0.tar.gz . && $(DEL_FILE) -r nbproject/build/Debug/GNU-Linux-x86/3Dscanner_mk21.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) qttmp-Debug.mk


mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_GUI.cpp moc_SplineGenerator.cpp moc_ImageManager.cpp moc_ImageDisplay.cpp moc_ModelGenerator.cpp moc_SplineDisplay.cpp moc_TextureDisplay.cpp moc_ModelManager.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_GUI.cpp moc_SplineGenerator.cpp moc_ImageManager.cpp moc_ImageDisplay.cpp moc_ModelGenerator.cpp moc_SplineDisplay.cpp moc_TextureDisplay.cpp moc_ModelManager.cpp
moc_GUI.cpp: common.h \
		ModelGenerator.h \
		SplineGenerator.h \
		ImageManager.h \
		ImageDisplay.h \
		TextureDisplay.h \
		SplineDisplay.h \
		ModelManager.h \
		GUI.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) GUI.h -o moc_GUI.cpp

moc_SplineGenerator.cpp: common.h \
		SplineGenerator.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) SplineGenerator.h -o moc_SplineGenerator.cpp

moc_ImageManager.cpp: common.h \
		ImageDisplay.h \
		TextureDisplay.h \
		ImageManager.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) ImageManager.h -o moc_ImageManager.cpp

moc_ImageDisplay.cpp: common.h \
		ImageDisplay.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) ImageDisplay.h -o moc_ImageDisplay.cpp

moc_ModelGenerator.cpp: common.h \
		ModelGenerator.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) ModelGenerator.h -o moc_ModelGenerator.cpp

moc_SplineDisplay.cpp: common.h \
		SplineDisplay.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) SplineDisplay.h -o moc_SplineDisplay.cpp

moc_TextureDisplay.cpp: common.h \
		TextureDisplay.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) TextureDisplay.h -o moc_TextureDisplay.cpp

moc_ModelManager.cpp: common.h \
		ImageManager.h \
		ImageDisplay.h \
		TextureDisplay.h \
		SplineGenerator.h \
		SplineDisplay.h \
		ModelManager.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) ModelManager.h -o moc_ModelManager.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean 

####### Compile

build/Debug/GNU-Linux-x86/SplineDisplay.o: SplineDisplay.cpp SplineDisplay.h \
		common.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/SplineDisplay.o SplineDisplay.cpp

build/Debug/GNU-Linux-x86/GUI.o: GUI.cpp GUI.h \
		common.h \
		ModelGenerator.h \
		SplineGenerator.h \
		ImageManager.h \
		ImageDisplay.h \
		TextureDisplay.h \
		SplineDisplay.h \
		ModelManager.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/GUI.o GUI.cpp

build/Debug/GNU-Linux-x86/main.o: main.cpp GUI.h \
		common.h \
		ModelGenerator.h \
		SplineGenerator.h \
		ImageManager.h \
		ImageDisplay.h \
		TextureDisplay.h \
		SplineDisplay.h \
		ModelManager.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/main.o main.cpp

build/Debug/GNU-Linux-x86/ModelGenerator.o: ModelGenerator.cpp ModelGenerator.h \
		common.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/ModelGenerator.o ModelGenerator.cpp

build/Debug/GNU-Linux-x86/TextureDisplay.o: TextureDisplay.cpp TextureDisplay.h \
		common.h \
		ImageDisplay.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/TextureDisplay.o TextureDisplay.cpp

build/Debug/GNU-Linux-x86/ImageManager.o: ImageManager.cpp ImageManager.h \
		common.h \
		ImageDisplay.h \
		TextureDisplay.h \
		SplineGenerator.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/ImageManager.o ImageManager.cpp

build/Debug/GNU-Linux-x86/SplineGenerator.o: SplineGenerator.cpp SplineGenerator.h \
		common.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/SplineGenerator.o SplineGenerator.cpp

build/Debug/GNU-Linux-x86/ModelManager.o: ModelManager.cpp ModelManager.h \
		common.h \
		ImageManager.h \
		ImageDisplay.h \
		TextureDisplay.h \
		SplineGenerator.h \
		SplineDisplay.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/ModelManager.o ModelManager.cpp

build/Debug/GNU-Linux-x86/ImageDisplay.o: ImageDisplay.cpp ImageDisplay.h \
		common.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/ImageDisplay.o ImageDisplay.cpp

build/Debug/GNU-Linux-x86/moc_GUI.o: moc_GUI.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/moc_GUI.o moc_GUI.cpp

build/Debug/GNU-Linux-x86/moc_SplineGenerator.o: moc_SplineGenerator.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/moc_SplineGenerator.o moc_SplineGenerator.cpp

build/Debug/GNU-Linux-x86/moc_ImageManager.o: moc_ImageManager.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/moc_ImageManager.o moc_ImageManager.cpp

build/Debug/GNU-Linux-x86/moc_ImageDisplay.o: moc_ImageDisplay.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/moc_ImageDisplay.o moc_ImageDisplay.cpp

build/Debug/GNU-Linux-x86/moc_ModelGenerator.o: moc_ModelGenerator.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/moc_ModelGenerator.o moc_ModelGenerator.cpp

build/Debug/GNU-Linux-x86/moc_SplineDisplay.o: moc_SplineDisplay.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/moc_SplineDisplay.o moc_SplineDisplay.cpp

build/Debug/GNU-Linux-x86/moc_TextureDisplay.o: moc_TextureDisplay.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/moc_TextureDisplay.o moc_TextureDisplay.cpp

build/Debug/GNU-Linux-x86/moc_ModelManager.o: moc_ModelManager.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/moc_ModelManager.o moc_ModelManager.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:


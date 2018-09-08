
BIN  = ./build/unit_test
BUILDDIR = ./tmp/
LIBDIR = ./lib/

CXX  = g++

CXXFLAGS += -c -w 

OBJS =  $(BUILDDIR)/mu_main.o \
	$(BUILDDIR)/mu_tree.o \
	$(BUILDDIR)/mu_list.o \
	$(BUILDDIR)/mu_string.o \
	$(BUILDDIR)/mu_algorithm.o

LIB_OBJ = utl_tree.cpp \
	  utl_list.cpp \
	  utl_string.cpp \
	  utl_algorithm.cpp

#LIBS  = $(LIBDIR)/libutltree.so
#	$(LIBDIR)/libutllist.so

LIBS  = $(LIBDIR)/libutl.so

DEPS = 
MKDIR_P = mkdir -p

.PHONY: directories

all : dir directories $(LIBS) $(BIN)
directories: ${BUILDDIR} ${LIBDIR}

${BUILDDIR}:
	${MKDIR_P} ${BUILDDIR}

${LIBDIR}:
	${MKDIR_P} ${LIBDIR}

dir :
	${MKDIR_P} ./build/


$(BIN) : $(OBJS)
	$(CXX) $(OBJS) -o $@ -Llib  -lutl

$(BUILDDIR)/%.o : %.c
	$(CXX)  $(CXXFLAGS) -o $@ $<

$(BUILDDIR)/%.o : %.cpp
	$(CXX)  $(CXXFLAGS) -o $@ $< 

$(LIBDIR)/%.o : %.cpp
	$(CXX)  $(CXXFLAGS) -o $@ $<


$(LIBS): $(LIB_OBJ)
	$(CXX) -std=c++11 -shared -fPIC -o $@ $(LIB_OBJ)

clean :
	rm -rf $(BIN) $(OBJS) $(LIBS)
	rm -rf *~

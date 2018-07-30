
BIN  = ./build/unit_test
BUILDDIR = ./tmp/

CXX  = gcc

CXXFLAGS += -c -w

OBJS =  $(BUILDDIR)/mu_main.o \
	$(BUILDDIR)/mu_tree.o 

DEPS = 
MKDIR_P = mkdir -p

.PHONY: directories

all : dir directories $(BIN)
directories: ${BUILDDIR}

${BUILDDIR}:
	${MKDIR_P} ${BUILDDIR}

dir :
	${MKDIR_P} ./build/


$(BIN) : $(OBJS)
	$(CXX) $(OBJS) -o $@ 

$(BUILDDIR)/%.o : %.c $(DEPS)
	$(CXX)  $(CXXFLAGS) -o $@ $<

clean :
	rm -rf $(BIN) $(OBJS)
	rm -rf *~

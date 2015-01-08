BUILDDIR    = ./bin/
SOURCEDIR   = ./src/

DEFINES     =

PREFIX      = /usr/local
INSTDIR     = $(PREFIX)
INSTBIN     = $(INSTDIR)/bin

SDIRS       = $(wildcard $(SOURCEDIR)*/)
VPATH       = $(SOURCEDIR):$(SDIRS):$(foreach dir, $(SDIRS), $(wildcard $(dir)*/))

IFILES      = $(shell find $(SOURCEDIR) -name '*.cpp')

OFILES      = $(subst $(SOURCEDIR),  $(BUILDDIR), $(addsuffix .o, $(notdir $(shell find $(SOURCEDIR)  -name '*.cpp'))))

CC          = clang++
LINKER      = $(CC)
ARCH        = 64

CCFLAGS     = -c -g -w -O3 -m$(ARCH) -std=c++0x
LINKFLAGS   = -m$(ARCH)


TARGET = bee

.PHONY: all install remove clean

all: $(BUILDDIR) $(TARGET)

$(BUILDDIR):
	test -d $@ || mkdir -p $@

$(TARGET): $(foreach file, $(OFILES), $(BUILDDIR)$(file))
	$(LINKER) $^ $(LINKFLAGS) -o $(BUILDDIR)$@

$(BUILDDIR)%.cpp.o: %.cpp
	$(CC) $(foreach def, $(DEFINES), -D $(def)) $(CCFLAGS) $< -o $@

install:
	test -d $(INSTDIR) || mkdir -p $(INSTDIR)
	test -d $(INSTBIN) || mkdir -p $(INSTBIN)

	install -m 0755 $(BUILDDIR)$(TARGET) $(INSTBIN)

remove:
	rm $(INSTBIN)/$(TARGET)

clean:
	rm $(BUILDDIR)*

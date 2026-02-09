CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I./include
LDFLAGS  =

TARGET = breadfetch
SRCDIR = src
INCDIR = include
BUILDDIR = build

# Find all .cc files recursively under src/
SOURCES := $(shell find $(SRCDIR) -name '*.cc')

# Map src/foo/bar.cc -> build/foo/bar.o
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SOURCES))

.PHONY: all clean install

all: $(BUILDDIR) $(TARGET)

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -rf $(BUILDDIR) $(TARGET)

install: $(TARGET)
	install -D -m 755 $(TARGET) /usr/local/bin/$(TARGET)

uninstall:
	rm -f /usr/local/bin/$(TARGET)

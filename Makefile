CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I./include
LDFLAGS  =

TARGET   = breadfetch
SRCDIR   = src
BUILDDIR = build

# Find all .cc files recursively under src/
SOURCES := $(shell find $(SRCDIR) -name '*.cc')

# Map src/foo/bar.cc -> build/foo/bar.o
OBJECTS := $(patsubst $(SRCDIR)/%.cc,$(BUILDDIR)/%.o,$(SOURCES))

.PHONY: all clean install uninstall

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Ensure build directories exist before compiling
$(BUILDDIR)/%.o: $(SRCDIR)/%.cc
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILDDIR) $(TARGET)

install: $(TARGET)
	install -D -m 755 $(TARGET) /usr/local/bin/$(TARGET)

uninstall:
	rm -f /usr/local/bin/$(TARGET)

CC := clang
CFLAGS := -g -Wall -Werror -pedantic -std=c99

CXX := clang++
CXXFLAGS := -g -Wall -Werror -pedantic -std=c++14

LDFLAGS :=

SRCDIR = src
BUILDDIR = build


% : $(SRCDIR)/%.c
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) $< -o $(BUILDDIR)/$@ $(LDFLAGS)
	./$(BUILDDIR)/$@

% : $(SRCDIR)/%.cpp
	@mkdir -p $(BUILDDIR)
	$(CXX) $(CXXFLAGS) $< -o $(BUILDDIR)/$@ $(LDFLAGS)
	./$(BUILDDIR)/$@

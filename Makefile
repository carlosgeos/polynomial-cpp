CXXFLAGS = -std=c++14 -ggdb3 -Wpedantic -Wall -Wextra -Wconversion	\
-Weffc++ -Wstrict-null-sentinel -Wold-style-cast -Wnoexcept		\
-Wctor-dtor-privacy -Woverloaded-virtual -Wsign-promo			\
-Wzero-as-null-pointer-constant -Wsuggest-final-types			\
-Wsuggest-final-methods -Wsuggest-override

SOURCES = main.cpp
HEADERS = $(wildcard *.hpp)
OBJECTS = $(SOURCES:.cpp=.o)

LISTING = listing.tex
UML_FILE = class.uml

.PHONY: listing clean execute

run: $(OBJECTS)
	$(CXX) $< -o $@

%o.: %.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

execute: run
	./$< | tee execution.txt

uml: $(UML_FILE)
	plantuml $<

listing: $(HEADERS) $(SOURCES)
	latexmk -xelatex -output-directory=tex_files $(LISTING)

clean:
	rm run $(OBJECTS)

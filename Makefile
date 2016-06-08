if [ -z ${CXX+x} ]; then CXX=g++5;fi

CXXFLAGS = -std=c++14 -ggdb3 -Wpedantic -Wall -Wextra -Wconversion	\
-Weffc++ -Wstrict-null-sentinel -Wold-style-cast -Wnoexcept		\
-Wctor-dtor-privacy -Woverloaded-virtual -Wsign-promo			\
-Wzero-as-null-pointer-constant -Wsuggest-final-types			\
-Wsuggest-final-methods -Wsuggest-override

SOURCES = main.cpp
OBJECTS = $(SOURCES:.cpp=.o)

run: $(OBJECTS)
	$(CXX) $< -o $@

%o.: %.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

execute: run
	./$< | tee execution.txt

listing: listing.tex
	latexmk -xelatex -output-directory=tex_files $<

uml: class.uml
	plantuml $< && gthumb class.png&

clean:
	rm run $(OBJECTS)

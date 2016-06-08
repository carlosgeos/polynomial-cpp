CC = g++-5			#Version: g++ (GCC) 5.3.0
CFLAGS = -std=c++14 -ggdb3 -Wpedantic -Wall -Wextra -Wconversion	\
-Weffc++ -Wstrict-null-sentinel -Wold-style-cast -Wnoexcept		\
-Wctor-dtor-privacy -Woverloaded-virtual -Wsign-promo			\
-Wzero-as-null-pointer-constant -Wsuggest-final-types			\
-Wsuggest-final-methods -Wsuggest-override
SOURCE = main.cpp
DEPS = *.hpp

all: polynomial.o execute

polynomial.o: $(SOURCE) $(DEPS)
	$(CC) $(CFLAGS) $< -o $@

execute: polynomial.o
	./$< | tee execution.txt

listing: listing.tex
	latexmk -xelatex -output-directory=tex_files $<

uml: class.uml
	plantuml $< && gthumb class.png&

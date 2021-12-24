HEADER	=	$(wildcard *.hh)
SOURCE	=	$(wildcard *.cc)
OBJECT	=	$(addprefix obj/,$(addsuffix .o,$(SOURCE)))

build: obj/ $(OBJECT)
	@g++ -o ProTyper $(OBJECT) -lSDL2 -lSDL2_image -lSDL2_ttf

obj/%.cc.o:	%.cc $(HEADER)
	@echo "Building $<"
	@g++ -c -o $@ $< -std=c++17 -pedantic -Wall -Wextra -g

obj/:
	@mkdir -p obj

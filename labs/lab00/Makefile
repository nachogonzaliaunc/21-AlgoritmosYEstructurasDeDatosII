.PHONY: all clean run_bounds run_tictactoe run_tictactoe_gen

CFLAGS = -Wall -Werror -Wextra -pedantic -std=c99 
OUT = .out

all: bounds tictactoe tictactoe_gen
	@echo "Todos los archivos se compilaron de forma correcta"

bounds: bounds.c
	gcc $(CFLAGS) -o bounds$(OUT) bounds.c
	@echo "bounds.c se compiló de forma correcta"

tictactoe: tictactoe.c
	gcc $(CFLAGS) -o tictactoe$(OUT) tictactoe.c
	@echo "tictactoe.c se compiló de forma correcta"

tictactoe_gen: tictactoe_gen.c
	gcc $(CFLAGS) -o tictactoe_gen$(OUT) tictactoe_gen.c
	@echo "tictactoe_gen.c se compiló de forma correcta"

run_bounds: bounds
	./bounds$(OUT)

run_tictactoe: tictactoe
	./tictactoe$(OUT)

run_tictactoe_gen: tictactoe_gen
	./tictactoe_gen$(OUT)

clean:
	rm -f bounds$(OUT) tictactoe$(OUT) tictactoe_gen$(OUT)
	@echo "Los archivos se limpiaron de forma correcta"
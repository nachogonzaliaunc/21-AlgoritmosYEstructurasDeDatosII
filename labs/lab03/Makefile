CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c99
OBJS_EJ1 = ./ej1/main.o ./ej1/array_helpers.o
OBJS_EJ2 = ./ej2/main.o ./ej2/array_helpers.o ./ej2/weather.o ./ej2/weather_utils.o
OBJS_EJ3 = ./ej3/main.o ./ej3/helpers.o ./ej3/sort.o

objs_ej1:
	$(CC) $(CFLAGS) -c ./ej1/main.c -o ./ej1/main.o
	$(CC) $(CFLAGS) -c ./ej1/array_helpers.c -o ./ej1/array_helpers.o

# $^: includes all prerequisites regardless of being updated or not.
comp_ej1: $(OBJS_EJ1)
	$(CC) $(CFLAGS) $^ -o ./ej1/readphrase

clean_ej1:
	rm -f $(OBJS_EJ1) ./ej1/readphrase

objs_ej2:
	$(CC) $(CFLAGS) -c ./ej2/array_helpers.c \
			-o ./ej2/array_helpers.o
	$(CC) $(CFLAGS) -c ./ej2/weather.c \
			-o ./ej2/sort.o
	$(CC) $(CFLAGS) -c ./ej2/main.c \
			-o ./ej2/main.o
	$(CC) $(CFLAGS) -c ./ej2/weather_utils.c \
			-o ./ej2/weather_utils.o

comp_ej2: $(OBJS_EJ2)
	$(CC) $(CFLAGS) $^ -o ./ej2/weather

clean_ej2:
	rm -f $(OBJS_EJ2) ./ej2/weather ./ej2/weather_cordoba.out

objs_ej3:
	$(CC) $(CFLAGS) -c -g ./ej3/helpers.c \
			-o ./ej3/helpers.o
	$(CC) $(CFLAGS) -c -g ./ej3/sort.c \
			-o ./ej5/sort.o
	$(CC) $(CFLAGS) -c -g ./ej3/main.c \
			-o ./ej3/main.o

comp_ej3: $(OBJS_EJ3)
	$(CC) $(CFLAGS) $^ -g -o ./ej3/mysort

clean_ej3:
	rm -f $(OBJS_EJ3) ./ej3/mysort ./ej3/atp-players2022.out


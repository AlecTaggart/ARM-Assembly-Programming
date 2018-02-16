# Add new .o files to OBJS list here
OBJS=driver.o sum_a.o sum_c.o sum_array.o find_max.o fib_rec.o fib_iter_C.o fib_rec_C.o sum_array_C.o find_max_C.o fib_iter.o find_str.o find_str_C.o 


all: driver

driver.o: driver.c
	gcc -c -o driver.o driver.c

driver: $(OBJS)
	gcc -o driver $(OBJS)

sum_a.o: sum_a.s
	as -o sum_a.o sum_a.s

sum_c.o: sum_c.c
	gcc -c -o sum_c.o sum_c.c

# Add more .s and .c files here
sum_arrays.o: sum_arrays.s
	as -o sum_array.o sum_arrays.s

find_max.o: find_max.s
	as -o find_max.o find_max.s

fib_rec.o: fib_rec.s
	as -o fib_rec.o fib_rec.s

fib_iter_C.o: fib_iter_C.c
	gcc -c -o fib_iter_C.o fib_iter_C.c

fib_iter.o: fib_iter.s
	gcc -c -o fib_iter.o fib_iter.s


fib_rec_C.o: fib_rec_C.c
	gcc -c -o fib_rec_C.o fib_rec_C.c 

sum_array_C.o: sum_array_C.c
	gcc -c -o sum_array_C.o sum_array_C.c

find_max_C.o: find_max_C.c
	gcc -c -o find_max_C.o find_max_C.c

find_str_C.o: find_str_C.c
	gcc -c -o find_str_C.o find_str_C.c

find_str.o: find_str.s
	as -o find_str.o find_str.s



clean:
	rm -rf $(OBJS) driver
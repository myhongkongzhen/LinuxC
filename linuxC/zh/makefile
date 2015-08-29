OBJ=input.o primer.o

input.o:input.c
	#gcc -c -fpic input.c
	#不顯示執行的命令@
	@gcc -c -fpic input.c
primer.o:primer.c
	gcc -c -fpic primer.c
libdemo.so:$(OBJ)
	gcc -shared -olibdemo.so $(OBJ) 
demo:main.c libdemo.so
	gcc main.c -omain -ldemo -L.

.PHONY:clean
clean:
	rm -f *.o *.so *.a tags main tags cscope.*
	#echo ${PATH}


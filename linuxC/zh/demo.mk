demo:
	#gcc -c -fpic input.c
	#不顯示執行的命令@
	@gcc -c -fpic input.c
	gcc -c -fpic primer.c
	gcc -shared -olibdemo.so input.o primer.o
	gcc main.c -omain -ldemo -L.

clean:
	rm -f *.o *.so *.a tags main tags cscope.*


all:
	gcc test.c -o test
	gcc fstat.c -o fstat

run: all
	echo Run without fcntl
	./test > nofcntl
	echo Run after fcntl
	./test fcntl > withfcntl
	diff -u nofcntl withfcntl

clean:
	rm -f test fstat fcntl nofcntl withfcntl

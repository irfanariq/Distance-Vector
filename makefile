make:
	g++ done.cpp -o output

test1:
	./output < data/test1.in > data/hasil1.out

test2:	
	./output < data/test2.in > data/hasil2.out

clean:
	rm output
	rm data/*.out
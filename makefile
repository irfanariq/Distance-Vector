make:
	g++ src/done.cpp -o output

test1:
	./output < data/test1.in > data/hasil1.out
	if [$(md5sum data/hasil1.out) == $(md5sum data/solusi1.out)]; then echo 'sama'; else echo 'beda'; fi

test2:	
	./output < data/test2.in > data/hasil2.out
	if [$(md5sum data/hasil2.out) == $(md5sum data/solusi2.out)]; then echo 'sama'; else echo 'beda'; fi

clean:
	rm output
	rm data/hasil*.out
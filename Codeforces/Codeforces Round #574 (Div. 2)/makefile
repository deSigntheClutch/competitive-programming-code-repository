obj = a b c d e f

a: a.cpp
	g++ -std=c++11 $@.cpp -o $@
	./$@
b: b.cpp
	g++ -std=c++11 $@.cpp -o $@
	./$@
c: c.cpp
	g++ -std=c++14 $@.cpp -o $@
	./$@
d: d.cpp
	g++ -std=c++11 $@.cpp -o $@
	./$@
e: e.cpp
	g++ -std=c++11 $@.cpp -o $@
	./$@
f: f.cpp
	g++ -std=c++11 $@.cpp -o $@
	./$@

.phony:
	clean

clean:
	rm $(obj)


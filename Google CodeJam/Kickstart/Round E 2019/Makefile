OBJ = A B C D E F

tmp: tmp.cpp
	@g++ -std=c++17 $@.cpp -o $@
	@date
	@./$@

A: A.cpp
	@g++ -std=c++17 $@.cpp -o $@
	@date
	@./$@

B: B.cpp
	@g++ -std=c++11 $@.cpp -o $@
	@date
	@./$@

C: C.cpp
	@g++ -std=c++11 $@.cpp -o $@
	@date
	@./$@

D: D.cpp
	@g++ -std=c++11 $@.cpp -o $@
	@date
	@./$@

E: E.cpp
	@g++ -std=c++11 $@.cpp -o $@
	@date
	@./$@

F: F.cpp
	@g++ -std=c++11 $@.cpp -o $@
	@date
	@./$@

.phony:
	clean
	
clean:
	rm $(OBJ)

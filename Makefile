all: csgraph b2 extracred
csgraph:csgraph.cpp
b2:b2.cpp
extracred:extracred.cpp

%: %.cc
	g++ -std=c++11 $< -o $@

%: %.c
	gcc $< -o $@

clean:
	rm csgraph b2 extracred
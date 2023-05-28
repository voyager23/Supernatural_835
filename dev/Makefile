UNAME := $(shell uname)
SOURCE = a_dev.c
CC = clang++

cira:	c_aira.cxx
	$(CC) c_aira.cxx -std=c++17 -lgmpxx -lgmp -o cira

bira:	b_aira.cxx
	g++ b_aira.cxx -std=c++17 -lgmpxx -lgmp -o bira
	
	
clang:	clangtest.c
	clang clangtest.c -g -lgmp -o clang
	
superplus:
	g++ a_dev.c -std=c++17 -lgmpxx -lgmp -o superplus
	
	
super:
ifeq ($(UNAME),Darwin)
	@echo "Macbook"
	gcc $(SOURCE) -I/opt/homebrew/include  -L/opt/homebrew/lib  -lgmp -o super
else
	@echo "Assuming Linux"
	gcc $(SOURCE) -g -lgmp -o super
endif

gcd:
	g++ gcd.cxx -g -lgmpxx -lgmp -o gcdxx
	


UNAME := $(shell uname)
SOURCE = a_dev.c

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
	gcc gcd.c -g -lgmp -o gcd
	


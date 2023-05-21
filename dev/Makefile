UNAME := $(shell uname)
SOURCE = a_dev.c

super:
ifeq ($(UNAME),Darwin)
	@echo "Macbook"
	gcc $(SOURCE) -I/opt/homebrew/include  -L/opt/homebrew/lib  -lgmp -o super
else
	@echo "Assuming Linux"
	gcc $(SOURCE) -g -lgmp -o super
endif

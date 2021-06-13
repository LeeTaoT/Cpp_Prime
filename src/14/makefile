ROOT := ../..
include  $(ROOT)/GNU_makefile_template

OBJECTS := $(patsubst %.cc, %.bin, $(wildcard *.cc))

all : $(OBJECTS)

add.o Sales_data.o : Sales_data.h

%.o : %.cc
	$(CC) $(CCFLAGS) $(LOCFLAGS) -c $< -o $@

%.bin : %.o
	$(CC) $(CCFLAGS) $(LOCFLAGS) $< -o $@
	cp $@ $(BINPATH)/

clean :
	rm *.bin *.o
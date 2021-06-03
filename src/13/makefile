ROOT := ../..
include  $(ROOT)/GNU_makefile_template

OBJECTS := $(patsubst %.cc, %.bin, $(wildcard *.cc))

all : $(OBJECTS)

%.o : %.cc
	$(CC) $(CCFLAGS) $(LOCFLAGS) -c $< -o $@

%.bin : %.o
	$(CC) $(CCFLAGS) $(LOCFLAGS) $< -o $@
	cp $@ $(BINPATH)/

clean :
	rm *.bin *.o
ROOT := ../..
include  $(ROOT)/GNU_makefile_template

OBJECTS := $(patsubst %.cc, %.bin, $(wildcard *.cc))

all : $(OBJECTS)

%.o : %.cc
	$(CC) $(CCFLAGS) $(LOCFLAGS) -c $< -o $@

%.bin : %.o
	$(CC) $(CCFLAGS) $(LOCFLAGS) $< -o $(BINPATH)/$@

clean:
	rm *.o 
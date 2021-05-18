ROOT=..
# executable files for this directory
OBJECTS = add_item.bin avg_price.bin \
		  useAccount.bin useScreen.bin  buf.bin clearIO.bin fileIO.bin sstream.bin\
		  capacity.bin erase1.bin  erase2.bin find_ops.bin find-str.bin refreshlter.bin stack.bin\
		  str_assignOps.bin substr.bin  absint.bin\
#		  useDebug.bin 

# OBJECTS := $(patsubst %.cc , %.bin, $(wildcard *.cc))


# tells make to use the file "../GNU_makefile_template", which
# defines general rules for making .o and .exe files
include ../GNU_makefile_template

LOCFLAGS = -I$(ROOT)/include
useScreen: $(ROOT)/include/Screen.h

# Account.o useAccount.o: $(ROOT)/include/Account.h
# Debug.o useDebug.o: $(ROOT)/include/Debug.h

useAccount.bin: Account.o useAccount.o
#	$(CC) $(CCFLAGS) $(LOCFLAGS) $(addprefix $(LINKPATH)/, $^)  -o $(BINPATH)/$@
 
# useDebug.bin: Debug.o useDebug.o
#	$(CC) $(CCFLAGS) $(LOCFLAGS) $(addprefix $(LINKPATH)/, $^)  -o $(BINPATH)/$@
 
add_item.bin: add_item.o  Sales_data.o
#	$(CC) $(CCFLAGS) $(LOCFLAGS) $(addprefix $(LINKPATH)/, $^)  -o $(BINPATH)/$@
 
avg_price.bin: avg_price.o  Sales_data.o
#	$(CC) $(CCFLAGS) $(LOCFLAGS) $(addprefix $(LINKPATH)/, $^)  -o $(BINPATH)/$@
 
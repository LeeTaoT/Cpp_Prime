ROOT=..
# executable files for this directory
OBJECTS = add_item.bin avg_price.bin \
		  useAccount.bin useScreen.bin \
#		  useDebug.bin 

# tells make to use the file "../GNU_makefile_template", which
# defines general rules for making .o and .exe files
include ../GNU_makefile_template

LOCFLAGS = -I$(ROOT)/include
TARGET = add_item.o Sales_data.o
useScreen: $(ROOT)/include/Screen.h

Account.o useAccount.o: $(ROOT)/include/Account.h
# Debug.o useDebug.o: $(ROOT)/include/Debug.h

useAccount.bin: Account.o useAccount.o
	$(CC) $(CCFLAGS) $(LOCFLAGS) $(addprefix $(LINKPATH)/, $^)  -o $(BINPATH)/$@
 
# useDebug.bin: Debug.o useDebug.o
#	$(CC) $(CCFLAGS) $(LOCFLAGS) $(addprefix $(LINKPATH)/, $^)  -o $(BINPATH)/$@
 
add_item.bin: add_item.o  Sales_data.o
	$(CC) $(CCFLAGS) $(LOCFLAGS) $(addprefix $(LINKPATH)/, $^)  -o $(BINPATH)/$@
 
avg_price.bin: avg_price.o  Sales_data.o
	$(CC) $(CCFLAGS) $(LOCFLAGS) $(addprefix $(LINKPATH)/, $^)  -o $(BINPATH)/$@
 
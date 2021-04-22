ROOT=..
PLATFORM=$(shell $(ROOT)/systype.sh)
include $(ROOT)/Make.defines.$(PLATFORM)

ifeq "$(PLATFORM)" "linux"
  MEMSTR = memstr
else
  MEMSTR =
endif

PROGS =	buf fgetsfputs getcharbug getcputc mkstemp tempfiles

# $@  目标名 / $^ 所有依赖  / $< 第一个依赖  / $? 比目标还要新的依赖文件列表 
# %: 匹配符

all:	

%:	%.c $(LIBCPP)
	$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(PROGS) $(TEMPFILES) *.o $(MEMSTR)

include $(ROOT)/Make.libcpp.inc

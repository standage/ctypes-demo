CC=gcc
CFLAGS=-Wall -Werror -O3 -m64 -g -fPIC
INCS=-Iinc
prefix=/usr/local

PLATFORM=$(shell uname -s)
LIBEXT=so
SHAREDFLAG=-shared
ifeq ($(PLATFORM),Darwin)
  LIBEXT=dylib
  SHAREDFLAG=-dynamiclib -undefined dynamic_lookup
endif
mylib=libmy.$(LIBEXT)
MY_OBJS=obj/gizmo.o obj/data.o

all:		$(mylib) mytest

test:		mytest all
		@ ./mytest

mytest:		src/test.c $(MY_OBJS)
		@ echo "[compile test]"
		@ $(CC) $(CFLAGS) $(INCS) -o $@ $^

$(mylib):	$(MY_OBJS)
		@ echo "[compile MyLib]"
		@ $(CC) $(CFLAGS) $(SHAREDFLAG) -o $@ $^

$(MY_OBJS):	obj/%.o : src/%.c inc/%.h
		@ mkdir -p obj
		@ echo "[compile $*]"
		@ $(CC) $(CFLAGS) $(INCS) -c -o $@ $<

install:	$(mylib)
		cp $(mylib) $(prefix)/lib/.
		mkdir -p /usr/local/include/mylib
		cp inc/*.h $(prefix)/include/mylib/.

clean:		
		@ echo "[cleanup]"
		@ rm -rf $(MY_OBJS) $(mylib) obj/ mytest mytest.dSYM

SRC := $(wildcard *.c)

OBJS := $(patsubst %.c, %.o, $(SRC))

LIB := libQuectel_bc95.a

all : $(OBJS)
	ar -cr $(LIB) $(OBJS)

%.o : %.c
	$(CC) -g -c $< -o $@

sinclude $(OBJS:.o=.d)

.PHONY : clean

clean :
	rm -rf $(LIB) $(OBJS) $(OBJS:.o=.d)


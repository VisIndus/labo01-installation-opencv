#
# Makefile
#

# set the executable name
EXEC=app

CC=g++
CFLAGS+= -Wall -g
CFLAGS+= `pkg-config --cflags opencv`
LDLIBS:= `pkg-config  --libs opencv`

ODIR:=obj

SRC := $(wildcard *.cpp)
OBJS = $(patsubst %,$(ODIR)/%,$(SRC:.cpp=.o))

all: $(EXEC)

-include $(ODIR)/*.d

$(EXEC): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS) $(LDLIBS)

$(ODIR)/%.o: %.cpp | $(ODIR)
	$(CC) $(CFLAGS) -c $< -o $@ -MMD -MF $(@:.o=.d)

$(ODIR):
	mkdir $@

clean:
	$(RM) $(EXEC)
	$(RM) -rf $(ODIR)

.PHONY:	clean all
.DEFAULT: all



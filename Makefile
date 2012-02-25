INC_DIR= ./lib/ARToolKit/include
LIB_DIR= ./lib/ARToolKit/lib
BIN_DIR= ./bin
SRC_DIR= ./src

LDFLAG=-pthread -lgstreamer-0.10 -lgobject-2.0 -lgmodule-2.0 -lxml2 -lgthread-2.0 -lrt -lglib-2.0 -L/usr/X11R6/lib -L/usr/local/lib -L$(LIB_DIR)
LIBS= -lARgsub -lARvideo -lAR -lpthread -lglut -lGLU -lGL -lXi -lX11 -lm
CFLAG= -O -pthread -I/usr/include/gstreamer-0.10 -I/usr/include/glib-2.0 -I/usr/lib/glib-2.0/include -I/usr/include/libxml2 -I/usr/X11R6/include -g -I$(INC_DIR)

OBJS = util.o roller.o
HEADDERS = $(SRC_DIR)/util.h

all: $(BIN_DIR)/roller

$(BIN_DIR)/roller: $(OBJS)
	cc -o $(BIN_DIR)/roller  $(OBJS) $(LDFLAG) $(LIBS)

util.o: $(SRC_DIR)/util.c $(HEADDERS)
	cc -c $(CFLAG) $(SRC_DIR)/util.c

roller.o: $(SRC_DIR)/roller.c $(HEADDERS)
	cc -c $(CFLAG) $(SRC_DIR)/roller.c

clean:
	rm -f *.o
	rm -f $(BIN_DIR)/roller

allclean:
	rm -f *.o
	rm -f $(BIN_DIR)/roller
	rm -f Makefile


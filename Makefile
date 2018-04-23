
EXECUTABLE = $(shell basename $(CURDIR))
HEADERS    = $(wildcard *.h)
SOURCES    = $(wildcard *.cpp)
OBJS       = $(patsubst %.cpp,%.o,$(SOURCES))
DEPS       = $(patsubst %.cpp,%.d,$(SOURCES))

# -Ofast does -O3 (max std optimization) plus nonstandard speedups
OFLAGS     = -Ofast
STDFLAGS   = -std=c++11

# uncomment extra flags to enable symbols & override OFLAGS (-Og doesn't work)
DEBUGFLAGS = -Wall
#DEBUGFLAGS += -g -O0

# add .h files to implicit .o deps (really ought to be the default)
DEPFLAGS   = -MMD

# CPPFLAGS & CXXFLAGS (not CFLAGS) are used by cpp.o implicit rule
CPPFLAGS = $(STDFLAGS) $(OFLAGS) $(DEBUGFLAGS) $(DEPFLAGS)

INCDIRS = -I/usr/local/include
LIBDIRS = -I/usr/local/lib
# Compiles and runs without -lm even though glfw docs say to use it
# but the rest of this mess is strictly necessary to get anywhere
#LIBS    = -lglfw3 -lGL -lXrandr -lXi -lX11 -lXxf86vm -lpthread
# at some point in 2015-16, the glfw lib name dropped the 3
LIBS    = -lglfw -lGL -lXrandr -lXi -lX11 -lXxf86vm -lpthread

LFLAGS = $(OFLAGS) $(DEBUGFLAGS) $(LIBDIRS) $(LIBS)

$(EXECUTABLE): $(OBJS) $(HEADERS)
	g++ $(OBJS) $(LFLAGS) -o $@

clean:
	rm -f *.d *.o $(EXECUTABLE)

include $(wildcard *.d)


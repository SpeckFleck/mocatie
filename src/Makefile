CC = gcc
CXX = g++

MOCASINNS_ROOT = ../../mocasinns
MOCASINNS_INCLUDE =  -I$(MOCASINNS_ROOT)/libmocasinns/include
MOCASINNS_RANDOM_INCLUDE = -I$(MOCASINNS_ROOT)/librandom/include
MOCASINNS_RANDOM_LIB = -L$(MOCASINNS_ROOT)/librandom/lib

CFLAGS_DEBUG = #-ggdb3 -pg
CFLAGS_PREFERENCES = -std=gnu++0x -mfpmath=sse
CFLAGS_OPTIMIZATION = -O3 -march=native
CFLAGS_WARNINGS = -Wall -Wextra -pedantic
CFLAGS_INCLUDE = -I../include $(MOCASINNS_RANDOM_INCLUDE) $(MOCASINNS_INCLUDE)
CFLAGS = $(CFLAGS_DEBUG) $(CFLAGS_PREFERENCES) $(CFLAGS_OPTIMIZATION) $(CFLAGS_WARNINGS) $(CFLAGS_INCLUDE)


LDFLAGS_BOOST = -static
LDFLAGS = $(LDFLAGS_BOOST)

TIE_WL_OPTIONS = 
TIE_WL_LIBS = -lrandom -lboost_serialization -lboost_signals -lboost_program_options -lboost_system -lboost_filesystem -lboost_log_setup -lboost_log -lboost_thread -lpthread -lrt
TIE_WL_LIBS_PATH = $(MOCASINNS_RANDOM_LIB)
TIE_WL_SOURCES = take_it_easy_wl.cpp

all: take_it_easy_wl

take_it_easy_wl: $(TIE_WL_SOURCES)
	$(CXX) $(CFLAGS) $(TIE_WL_SOURCES) $(LDFLAGS) $(INCLUDE) $(TIE_WL_OPTIONS) $(TIE_WL_LIBS_PATH) $(TIE_WL_LIBS) -o $@

clean:
	rm -f *.o *.d take_it_easy_wl

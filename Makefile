# Executable names:
EXE = AirTravel
TEST = test

# Add all object files needed for compiling:
EXE_OBJ = main.o
OBJS = AirTravel.o Node.o Airport.o dijkstras.o 

#Add all the traversals
CPP_FILES += $(wildcard traversal/*.cpp)
OBJS += $(CPP_FILES:.cpp=.o)

# Generated files
CLEAN_RM = out-*.png 

# Use the cs225 makefile template:
include cs225/make/cs225.mk

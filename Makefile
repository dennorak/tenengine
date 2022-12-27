# okay, we're going to build this right this time

### define universal vars ###

# build target
TARGET = tenengine
# compiler
CC = g++
# compiler flags
CFLAGS = -Wall -g -fno-stack-protector
# linker flags
LDFLAGS = -lSDL2 -lGL -lGLEW -lSDL2_image -lSDL2_ttf -lpugixml
# linker libs (-l)
LIBS = SDL2 GL GLEW SDL2_image SDL2_ttf pugixml

### define pattern vars ###
OBJ_OF = $(patsubst src/%.cpp, build/%.o, $1 $2 $3)
SRC_OF = $(patsubst build/%.o, src/%.cpp, $1 $2 $3)

### Define file locations ###

LAUNCHER = src/main.cpp
ENGINE = $(wildcard src/tenengine/*.cpp)
TILED = $(wildcard src/tenengine/tiled/*.cpp)
GRAPHICS = $(wildcard src/tenengine/graphics/*.cpp)
INPUT = $(wildcard src/tenengine/input/*.cpp)
ENTITY = $(wildcard src/tenengine/entity/*.cpp)
ALL = $(LAUNCHER) $(ENGINE) $(TILED) $(GRAPHICS) $(INPUT) $(ENTITY)

### Define routines ####

# qol routines
.PHONY: run
run: $(TARGET)
	./bin/$(TARGET)

.PHONY: clean
clean:
	rm -rf bin/* build/*

# link routines
launcher: $(call OBJ_OF, $(LAUNCHER))
	$(CC) $(CFLAGS) -o bin/$(TARGET) $(call OBJ_OF, $(LAUNCHER)) $(LDFLAGS)

tenengine: $(call OBJ_OF, $(ALL))
	$(CC) $(CFLAGS) -o bin/$(TARGET) $(call OBJ_OF, $(ALL)) $(LDFLAGS)


# compile routines

$(call OBJ_OF, $(LAUNCHER)): $(LAUNCHER)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ -c $(call SRC_OF, $@)

$(call OBJ_OF, $(ENGINE)): $(ENGINE)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ -c $(call SRC_OF, $@)

$(call OBJ_OF, $(TILED)): $(TILED)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ -c $(call SRC_OF, $@)

$(call OBJ_OF, $(GRAPHICS)): $(GRAPHICS)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ -c $(call SRC_OF, $@)

$(call OBJ_OF, $(INPUT)): $(INPUT)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ -c $(call SRC_OF, $@)

$(call OBJ_OF, $(ENTITY)): $(ENTITY)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ -c $(call SRC_OF, $@)
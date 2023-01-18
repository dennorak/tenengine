###########################
##### VARIABLE CONFIG #####
###########################

### universal vars ###

# build target
TARGET = tenengine
# compiler
CC = g++
# compiler flags
CFLAGS = -Wall -g -fno-stack-protector
# linker flags
LDFLAGS = -lSDL2 -lGL -lGLEW -lSDL2_image -lSDL2_ttf -lpugixml

### pattern vars ###
OBJ_OF = $(patsubst src/%.cpp, build/%.o, $1 $2 $3)
SRC_OF = $(patsubst build/%.o, src/%.cpp, $1 $2 $3)

##########################
##### FILE LOCATIONS #####
##########################

LAUNCHER = src/main.cpp
ENGINE = $(wildcard src/tenengine/*.cpp)
TILED = $(wildcard src/tenengine/tiled/*.cpp)
GRAPHICS = $(wildcard src/tenengine/graphics/*.cpp)
INPUT = $(wildcard src/tenengine/input/*.cpp)
ENTITY = $(wildcard src/tenengine/entity/*.cpp)
STATE = $(wildcard src/tenengine/state/*.cpp)
ALL = $(LAUNCHER) $(ENGINE) $(GRAPHICS) $(ENTITY) $(TILED) $(STATE) $(INPUT)

####################
##### ROUTINES #####
####################

### qol routines ###

.PHONY: run
run: $(TARGET)
	./bin/$(TARGET)

.PHONY: clean
clean:
	rm -rf bin/* build/*

### link routines ###

# global
LINK = mkdir -p bin && $(CC) $(CFLAGS) -o bin/$(TARGET) $(call OBJ_OF, $1) $(LDFLAGS)

# targets
launcher: $(call OBJ_OF, $(LAUNCHER))
	$(call LINK, $(LAUNCHER))

tenengine: $(call OBJ_OF, $(ALL))
	$(call LINK, $(ALL))

### compile routines ###

# global
COMPILE = mkdir -p $1 && $(CC) $(CFLAGS) -o $2 -c $(call SRC_OF, $2)

# targets
$(call OBJ_OF, $(LAUNCHER)): $(LAUNCHER)
	$(call COMPILE, $(@D), $@)

$(call OBJ_OF, $(ENGINE)): $(ENGINE)
	$(call COMPILE, $(@D), $@)

$(call OBJ_OF, $(TILED)): $(TILED)
	$(call COMPILE, $(@D), $@)

$(call OBJ_OF, $(GRAPHICS)): $(GRAPHICS)
	$(call COMPILE, $(@D), $@)

$(call OBJ_OF, $(INPUT)): $(INPUT)
	$(call COMPILE, $(@D), $@)

$(call OBJ_OF, $(ENTITY)): $(ENTITY)
	$(call COMPILE, $(@D), $@)

$(call OBJ_OF, $(STATE)): $(STATE)
	$(call COMPILE, $(@D), $@)
BUILD_PATH = build
DEBUG_PATH = $(BUILD_PATH)/debug
RELEASE_PATH = $(BUILD_PATH)/release

LIB_PATH = lib


ifdef DEBUG
	CPP_OPTIMIZATION = -Og -g3 -fno-omit-frame-pointer
	OUT_PATH = $(DEBUG_PATH)
else
	CPP_WARNING = -w
	OUT_PATH = $(RELEASE_PATH)
endif


APP_NAME = spectrium
APP_PATH = $(OUT_PATH)/$(APP_NAME)


CC = g++
CPP_VERSION = --std=c++20
CPP_INCLUDE_PATH = -I include
CPP_LIB_PATH = #-Lsome_path
CPP_LIB_NAME = #-lmy_lib
CPP_COMPILER_FLAGS = $(CPP_VERSION) $(CPP_OPTIMIZATION) $(CPP_WARNING) $(CPP_INCLUDE_PATH)
CPP_LINKER_FLAGS = $(CPP_LIB_PATH) $(CPP_LIB_NAME)


SOURCES = $(shell find src -name "*.cpp")
OBJECTS = $(SOURCES:.cpp=.o)
FINAL_OBJECTS = $(addprefix $(OUT_PATH)/, $(notdir $(OBJECTS)))



.PHONY: all
.PHONY: run
.PHONY: build



all: build


run:
	@ echo Running...
	@ $(APP_PATH)




build: $(OUT_PATH) $(CPP_DEPENDENCIES) $(OBJECTS)
	@ echo Linking objects...
	@ ar rcs $(APP_PATH) $(FINAL_OBJECTS)
	@ echo Application created at \"$(OUT_PATH)\" as \"$(APP_NAME)\".


$(OUT_PATH):
	@ echo Creating output path \"$(OUT_PATH)\".
	@ mkdir $(OUT_PATH) -p


$(OBJECTS): %.o: %.cpp
	@ echo Compiling source file \"$<\"...
	@ $(CC) -c $< -o $(addprefix $(OUT_PATH)/, $(notdir $@)) $(CPP_COMPILER_FLAGS)




clean:
	@ echo Removing build path \"$(BUILD_PATH)\"...
	@ rm $(BUILD_PATH) -r -f
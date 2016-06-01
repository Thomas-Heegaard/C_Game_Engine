######## Build options ########

verbose = 0

######## Build setup ########

# SRCROOT should always be the current directory
SRCROOT         = $(CURDIR)

# .o directory
ODIR            = obj

# Source VPATHS
VPATH       += $(SRCROOT)/engine/collision
VPATH	    += $(SRCROOT)/engine/debug
VPATH	    += $(SRCROOT)/engine/entity
VPATH       += $(SRCROOT)/engine/graphics
VPATH       += $(SRCROOT)/engine/physics
VPATH       += $(SRCROOT)/engine/sdl_wrapper
VPATH       += $(SRCROOT)/engine/utils
VPATH       += $(SRCROOT)/game

# Engine Objects
C_FILES		+= collision.c
C_FILES		+= collision_object.c
C_FILES		+= debug.c
C_FILES		+= entity.c
C_FILES		+= draw.c
C_FILES		+= fps_manager.c
C_FILES		+= graphics.c
C_FILES		+= sprite.c
C_FILES		+= physics.c
C_FILES		+= sdl_wrapper.c
C_FILES		+= config_loader.c
C_FILES		+= extra_math.c
C_FILES		+= list.c

# Game Objects
C_FILES		+= live_define.c
C_FILES		+= test_controller.c
C_FILES		+= main.c

# Include Paths
INCLUDES        += -I$(SRCROOT)/engine/collision
INCLUDES	    += -I$(SRCROOT)/engine/debug
INCLUDES	    += -I$(SRCROOT)/engine/entity
INCLUDES        += -I$(SRCROOT)/engine/graphics
INCLUDES        += -I$(SRCROOT)/engine/physics
INCLUDES        += -I$(SRCROOT)/engine/sdl_wrapper
INCLUDES        += -I$(SRCROOT)/engine/utils
INCLUDES        += -I$(SRCROOT)/game

# Generate OBJS names
OBJS = $(patsubst %.c,%.o,$(C_FILES))

######## C Flags ########

# Libraries

LDFLAGS		+= -lm
LDFLAGS		+= -lSDL2

# Warnings
CWARNS += -W
CWARNS += -Wall
#CWARNS += -Werror
CWARNS += -Wextra
CWARNS += -Wformat
CWARNS += -Wmissing-braces
CWARNS += -Wno-cast-align
CWARNS += -Wparentheses
CWARNS += -Wshadow
CWARNS += -Wno-sign-compare
CWARNS += -Wswitch
CWARNS += -Wuninitialized
CWARNS += -Wunknown-pragmas
CWARNS += -Wunused-function
CWARNS += -Wunused-label
CWARNS += -Wunused-parameter
CWARNS += -Wunused-value
CWARNS += -Wunused-variable
#CWARNS += -Wmissing-prototypes

CFLAGS += -m32
CFLAGS += -DDEBUG=1
CFLAGS += -pthread -DUSE_STDIO=1 -D__GCC_POSIX__=1

# MAX_NUMBER_OF_TASKS = max pthreads used in the POSIX port. 
# Default value is 64 (_POSIX_THREAD_THREADS_MAX), the minimum number required by POSIX.
CFLAGS += -DMAX_NUMBER_OF_TASKS=300

CFLAGS += $(INCLUDES) $(CWARNS)

######## Makefile targets ########

# Rules
.PHONY : all
all: setup app

.PHONY : setup
setup:
# Make obj directory
	@mkdir -p $(ODIR)

# Fix to place .o files in ODIR
_OBJS = $(patsubst %,$(ODIR)/%,$(OBJS))

$(ODIR)/%.o: %.c
# If verbose, print gcc execution, else hide
ifeq ($(verbose),1)
	@echo ">> Compiling $<"
	$(CC) $(CFLAGS) -c -o $@ $<
else
	@echo ">> Compiling $(notdir $<)"
	@$(CC) $(CFLAGS) -c -o $@ $<
endif

app: $(_OBJS)
	@echo ">> Linking $@..."
ifeq ($(verbose),1)
	$(CC) $(CFLAGS) $^ $(LINKFLAGS) $(LDFLAGS) -o $@
else
	@$(CC) $(CFLAGS) $^ $(LINKFLAGS) $(LDFLAGS) -o $@
endif

	@echo "-------------------------"
	@echo "BUILD COMPLETE: $@"
	@echo "-------------------------"

.PHONY : clean
clean:
	@-rm -rf $(ODIR) app
	@echo "--------------"
	@echo "CLEAN COMPLETE"
	@echo "--------------"

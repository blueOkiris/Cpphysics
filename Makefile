# Changeable build settings
LIBNAME :=  cpphysics
INCFLDRS := include
SRCFLDRS := src
CPPC :=     g++
CPPFLAGS := -std=c++17 -O2 -Wall -Werror

# Auto generated settings
SRCS :=     $(foreach folder,$(SRCFLDRS),$(wildcard $(folder)/*.cpp))
HFILES :=   $(foreach folder,$(INCFLDRS),$(wildcard $(folder)/*.hpp))
OBJS :=     $(foreach file,$(SRCS),objs/$(basename $(notdir $(file))).o)
INC :=      $(addprefix -I,$(INCFLDRS))

.PHONY : all
all : lib$(LIBNAME).so
	

# Auto generated build settings
define make-objectfile-target
objs/$(basename $(notdir $1)).o : $1 $(HFILES)
	mkdir -p objs
	$(CPPC) $(CPPFLAGS) $(INC) -o objs/$(basename $(notdir $1)).o -c $1
endef

$(foreach objfile,$(SRCS), $(eval $(call make-objectfile-target,$(objfile))))

# Primary build targets
lib$(LIBNAME).so : $(OBJS)
	$(CPPC) -shared -o lib$(LIBNAME).so $(OBJS)

.PHONY : clean
clean :
	rm -rf objs
	rm -rf lib$(LIBNAME).so

####################################################
# Generic makefile - ����Makefile
# for compiling and linking C++ projects on Linux 
# Author: George Foot  Modified:Jackie Lee
####################################################
### Customising
#
# Adjust the following if necessary; EXECUTABLE is the target
# executable's filename, and LIBS is a list of libraries to link in
# (e.g. alleg, stdcx, iostr, etc). You can override these on make's
# command line of course, if you prefer to do it that way.
#
#
EXECUTABLE := SocketServer  # ��ִ���ļ���
LIBDIR:=  /usr/local/lib           # ��Ŀ¼
LIBS :=  protobuf           # ���ļ��� ȥ��lib��so
INCLUDES:=.   /home/protobuf-3.2.0/src/google           # ͷ�ļ�Ŀ¼
SRCDIR:=              # ���˵�ǰĿ¼�⣬������Դ�����ļ�Ŀ¼
#
# # Now alter any implicit rules' variables if you like, e.g.:

CC:=g++
CFLAGS := -g -Wall -O3
CPPFLAGS := $(CFLAGS)
CPPFLAGS += $(addprefix -I,$(INCLUDES))
CPPFLAGS += -MMD
#
# # The next bit checks to see whether rm is in your djgpp bin
# # directory; if not it uses del instead, but this can cause (harmless)
# # `File not found' error messages. If you are not using DOS at all,
# # set the variable to something which will unquestioningly remove
# # files.
#

RM-F := rm -f


# # You shouldn't need to change anything below this point.
#
SRCS := $(wildcard *.cpp) $(wildcard $(addsuffix /*.cpp, $(SRCDIR)))
OBJS := $(patsubst %.cpp,%.o,$(SRCS))
DEPS := $(patsubst %.o,%.d,$(OBJS))
MISSING_DEPS := $(filter-out $(wildcard $(DEPS)),$(DEPS))
MISSING_DEPS_SOURCES := $(wildcard $(patsubst %.d,%.cpp,$(MISSING_DEPS)))


.PHONY : all 

all: $(EXECUTABLE)


ifneq ($(MISSING_DEPS),)
$(MISSING_DEPS) :
	@$(RM-F) $(patsubst %.d,%.o,$@)
endif
$(EXECUTABLE) : $(OBJS)
	$(CC) -o $(EXECUTABLE) $(OBJS) $(addprefix -L,$(LIBDIR)) $(addprefix -l,$(LIBS))

info:
	@echo $(SRCS)
	@echo $(OBJS)
	@echo $(DEPS)
	@echo $(MISSING_DEPS)
	@echo $(MISSING_DEPS_SOURCES)


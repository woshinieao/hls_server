TARGET = HlsServer.out
TOP_DIR =.
OBJ_DIR = $(TOP_DIR)/obj

CC=g++
AR=ar
LD=g++
CC_OPTS=-Wall -fPIC
DEFINE=-DDEBUG

MAIN_SOURCE_PATH	:=$(TOP_DIR)

MAIN_SRCS	:=$(wildcard $(MAIN_SOURCE_PATH)/*.cpp)

MAIN_OBJS	:=$(patsubst $(MAIN_SOURCE_PATH)/%.cpp,$(OBJ_DIR)/%.o,$(MAIN_SRCS))

INC_DIR = -I$(TOP_DIR)

LIB_DIR = -Wl,-rpath,-L. -L/usr/lib/mysql -L./lib
LIBS += -lpthread -lmysqlclient_r -lserver -lnetsdk $(LIB_DIR) 


CC_OPTS+=-g
DEFINE += -D_GNU_SOURCE -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64

target:$(TARGET)
	@echo "|-------------------------------------------|"
	@echo "|        building hls server program        |"
	@echo "|-------------------------------------------|"
	@date
	@echo ""
$(TARGET):$(MAIN_OBJS)
	$(CC) -o $@ $(MAIN_OBJS) $(LIBS)

$(OBJ_DIR)/%.o:$(MAIN_SOURCE_PATH)/%.cpp	
	$(CC) $(DEFINE) $(INC_DIR) -c $(CC_OPTS) $< -o $@


clean:
	rm -rf $(OBJ_DIR)/*.o 

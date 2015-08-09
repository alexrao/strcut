#################################################
# AUTHOR：rxp
# DATE  :2015.08.08
#################################################
CFLAGS += -g 
CFLAGS += -std=c99

LDFLAGS := -lpthread
LDFLAGS += -Wl,--no-warn-mismatch
LDFLAGS += -lm -lrt

SOURCE := main.c color_print.c list.c tcp_server.c thread.c 

OBJS = $(patsubst %.c,%.o,$(SOURCE))


APPLICATION := main

.PHONY: $(APPLICATION)

$(APPLICATION): $(OBJS) 
	@echo [Link $@]
	$(Q_) $(CC) -o $@ $(OBJS) $(LDFLAGS)
	md5sum $@
	@echo [Done]
	sync
	
%.o: %.c
	@echo [Compile $^ ...]
	$(Q_)$(CC) $(CFLAGS) -c $^ -o $@
	
clean:
	rm *.o -f
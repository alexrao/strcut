#################################################
# AUTHOR：rxp
# DATE  :2015.08.08
#################################################
CFLAGS += -g 
CFLAGS += -std=c99

SOURCE := main.c color_print.c link.c

OBJS = $(patsubst %.c,%.o,$(SOURCE))


APPLICATION := main

.PHONY: $(APPLICATION)

$(APPLICATION): $(OBJS) 
	@echo [Link $@]
	$(Q_) $(CC) -o $@ $(OBJS) 
	md5sum $@
	@echo [Done]
	sync
clean:
	rm *.o -f
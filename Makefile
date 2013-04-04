CFLAGS = -Wall -W -g
all ::
.PHONY : all clean

client_xaw : client_xaw.c
client_xaw : LDLIBS = -lXaw
clean :: ; $(RM) client_xaw
all :: client_xaw

client_forms : client_forms.c
client_forms : LDLIBS = -lforms
clean :: ; $(RM) client_forms
all :: client_forms

client_w : client_w.c
client_w : LDLIBS = -lWINGs -lwraster -lX11 -lfontconfig -lXft
clean :: ; $(RM) client_w
all :: client_w

client_xv : client_xv.c
client_xv : LDLIBS = -lxview
clean :: ; $(RM) client_xv
all :: client_xv

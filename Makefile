CFLAGS = /Spsm /O+
OBJS = hpled.obj io.obj 
LFLAGS = /NOE /PMTYPE:VIO /NOLOGO
LIBS = ./os2.lib
all : $(OBJS)
    ilink.exe $(LFLAGS) $(OBJS) $(LIBS) hpled.def 
    lxlite hpled.exe
    mv hpled.exe ../
clean:
    rm hpled.obj io.obj ../hpled.exe 
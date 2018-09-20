
# export PATH="$PATH:/usr/local/gcc_arm/gcc-arm-none-eabi-7-2018-q2-update/bin/"
# A mettre en début d'exercice pour exporter le bon compilateur
# Attention ceci est pour mon mac personnel, à tester sur linux

#Compilateur utilisé
CC = arm-none-eabi-gcc

#Drapeaux de l'exercice
CFLAGS = -Wall -Werror -g -Og -mthumb
LDLIBS = -lm -o
LDFLAGS = -L/opt/mylibs -mthumb

#Repertoire additionnel à aller chercher
VPATH = libs

#Variables de fichiers
OBJS = main.o t1.o t2.o stubs.o
EXE = hello
SOURCES = t1.c t2.c stubs.c

stubs.o: CFLAGS = -g -O2

#Règles
$(EXE): $(OBJS)
	$(LINK.o) $(LDFLAGS) $^ $(LDLIBS) $@

#Gestion des dependances en .d
-include $(subst .o,.d,$(OBJS))

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -M -MF $@\
-MP $<

clean:
	rm -f $(OBJS)

#En cas de présence d'un fichier au nom de "clean"
.PHONY: clean

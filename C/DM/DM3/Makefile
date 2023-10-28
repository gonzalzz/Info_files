# https://sites.uclouvain.be/SyllabusC/notes/Outils/make.html
CC = gcc
CFLAGS = -Wall

im: im.o mainim.o
	$(CC) $(CFLAG) -o $@ $^	-lm  	

pm: pm.o mainpm.o 
	$(CC) $(CFLAG) -o $@ $^  

#pour compiler tous les fichiers sources $^, possédant l’extension .c, en
#fichiers objets correspondant $@ (nom de la règle):
# $< première dépendance
%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<


#indiquer que la règle ne crée rien. Pour faire cela il existe une
#cible spéciale .PHONY permettant de définir quelles règles doivent
#toujours être exécutées à nouveau.
.PHONY: clean

clean:
	rm -f *.o

mrproper: clean
	rm -f pm

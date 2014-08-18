CC			= gcc
SRC			= main.c tgdesf.c
OBJS		= ${SRC:.c=.o}
LIBS		=  
CFLAGS 		= -g -c -Wall  	

TARGET 		= ./Apps

${TARGET} : ${OBJS}
	@${CC} -o ${TARGET} ${OBJS} ${LIBS}
.c.o:
	@${CC} ${CFLAGS} $<
	
clean :
	@ rm -rf *.o ${TARGET} *.c~ *.h~ Makefile~

all:	test

test:	main.c ./cd/cd.o ./linkedlist/linkedList.o ./linkedlist/listUtils.o ./structs/command.o ./pipes/pipe.o ./process/process.o ./token/makeArgs.o ./utils/fileUtils.o ./utils/myUtils.o 
	gcc -g main.c ./cd/cd.o ./linkedlist/listUtils.o ./structs/command.o ./structs/command.o ./pipes/pipe.o ./process/process.o ./token/makeArgs.o ./utils/fileUtils.o ./utils/myUtils.o -o test

cd.o:	./cd/cd.c ./cd/cd.h
	gcc -g -c ./cd/cd.c

pipe.o:		./pipes/pipe/c ./pipes/pipe.h
	gcc -g -c ./pipes/pipe.c

process.o:	./process/process.c ./process/process.h
	gcc -g -c ./process/process.c

makeArgs.o:	./token/makeArgs.c ./token/makeArgs.h
	gcc -g -c ./token/makeArgs.c

fileUtils.o:	./utils/fileUtils.c ./utils/fileUtils.h
	gcc -g -c ./utils/fileUtils.c

myUtils.o:	./utils/myUtils.c ./utils/myUtils.h
	gcc -g -c ./utils/myUtils.c

command.o:	./structs/command.c ./structs/command.h
	gcc -g -c ./structs/command.c

linkedList.o: ./linkedlist/linkedList.c ./linkedlist/linkedList.h
	gcc -g -c ./linkedlist/linkedList.c

listUtils.o:	./linkedlist/listUtils.c ./linkedlist/listUtils.h


clean:
	rm ./pipes/pipe.o
	rm ./process/process.o
	rm ./token/makeArgs.o
	rm ./utils/fileUtils.o
	rm ./utils/myUtils.o
	rm ./structs/command.o
	rm ./linkedlist/linkedList.o
	rm ./linkedlist/listUtils.o

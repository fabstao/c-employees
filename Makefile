CC=/usr/bin/gcc
DATA=employees.fabdb

all: employee.c
	touch ${DATA}
	${CC} -o employee employee.c
	
clean:
	echo "Cleaning..."
	rm -f employee ${DATA}

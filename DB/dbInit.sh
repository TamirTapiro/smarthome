#/bin/bash

if [ -e "smarthome.db" ]; then
	rm "smarthome.db"
fi
gcc -o dbInit dbInit.c -l sqlite3	
./dbInit


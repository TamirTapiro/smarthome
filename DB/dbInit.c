#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h> 

static int callback(void *NotUsed, int argc, char **argv, char **azColName){
   int i;
   //Prints the db's values on execution of queries
   for(i=0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}



int main(int argc, char* argv[])
{
   sqlite3 *db;
   char *zErrMsg = 0;
   int  rc;
   char *sql;

   /* Open database */
   rc = sqlite3_open("smarthome.db", &db);
   if( rc ){
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return(0);
   }else{
      fprintf(stdout, "Opened database successfully\n");
   }

   /* Create SQL statement */
   sql = "CREATE TABLE socket("  \
        "SID 			TEXT 	PRIMARY KEY     NOT NULL," \
        "NAME           TEXT     NOT NULL," \
        "CRITICAL       TEXT      NOT NULL," \
        "STATUS         TEXT		NOT NULL," \
        "TIMER        	TEXT	," \
	"HOUSE			TEXT		NOT NULL," \
	"USER			TEXT);" \
        "CREATE TABLE user(" \
        "UID            TEXT    PRIMARY KEY     NOT NULL," \
        "NAME           TEXT    NOT NULL," \
	"PASSWORD         TEXT    NOT NULL," \
        "HOMEID      TEXT    NOT NULL);"
        "CREATE TABLE home(" \
        "HID            TEXT     PRIMARY KEY     NOT NULL," \
        "ADMIN          TEXT     NOT NULL);"
        "INSERT INTO user(UID,NAME,PASSWORD,HOMEID)" \
        "VALUES " \
        "('1','tamir','tamir123','1')," \
        "('2','ran','ran123','1')," \
        "('3','nadav','nadav123','2')," \
        "('4','haim','haim123','2');" \
        "INSERT INTO home(HID,ADMIN)" \
        "VALUES " \
        "('1','1')," \
        "('2','2');" \
        "INSERT INTO socket(SID,NAME,CRITICAL,STATUS,TIMER,HOUSE,USER)" \
        "VALUES " \
        "('1','oven','1','0','0','1','-1')," \
        "('2','boiler','1','0','0','2','-1')," \
        "('3','badroom-lamp','0','0','0','4','-1')," \
        "('4','living-room-lamp','0','0','0','3','-1');";

   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
   if( rc != SQLITE_OK ){
   fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   }else{
      fprintf(stdout, "Tables created successfully\n");
   }
   sqlite3_close(db);
   return 0;
}

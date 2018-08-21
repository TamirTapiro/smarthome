#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h> 


static int callback(void *NotUsed, int argc, char **argv, char **azColName){

   return 0;
}



int main(int argc, char* argv[])
{
   sqlite3 *db;
   char *zErrMsg = 0;
   int  rc;
   char *sql;
	int i =0;
   /* Open database */
   rc = sqlite3_open("smarthome.db", &db);
   if( rc ){
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return(0);
   }

   /* Create SQL statement */
   sql = "UPDATE socket SET TIMER = CAST(TIMER as int) - 1 WHERE TIMER > '0';";
   rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
   if( rc != SQLITE_OK )
	{
   fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   }
   sqlite3_close(db);
   return 0;
}

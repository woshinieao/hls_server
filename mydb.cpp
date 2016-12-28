#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <pthread.h>
#include <unistd.h>
#include <mysql/mysql.h>
#include "mydb.h"


//static db_ops *gndb_ops = NULL;
static  db_ops mysql_ops;
static MYSQL  *mysql_conn  = NULL;
static MYSQL_ROW   *mysql_row   = NULL;
static MYSQL_RES   *mysql_res   = NULL;
static tMySQLConf dbconf;

//pthread_mutex sql_mutex;
//pthread_mutex sql_type;


static void *mysql_open_conn(tMySQLConf *conf )
{
	char value = 1;

	/* sanity check */
	if (conf == NULL)
		return NULL;
	mysql_conn = (MYSQL*)malloc(sizeof(MYSQL));
	if (mysql_conn == NULL)
		return NULL;
	if (!mysql_init(mysql_conn))
	{
		printf("MYSQL: init failed! %s\n", mysql_error(mysql_conn));
		goto failed;
	}

	if (!mysql_real_connect(mysql_conn, conf->host, conf->username, conf->password,
		conf->database, 0, NULL, 0))
	{
		printf("MYSQL: can not connect to database! %s\n", mysql_error(mysql_conn));
		goto failed;
	}
	mysql_options(mysql_conn, MYSQL_OPT_RECONNECT, (char *)&value);

	printf("MYSQL: Succeeded connected to server at %s.\n", conf->host);
	printf("MYSQL: server version %s, client version %s.\n",
	mysql_get_server_info(mysql_conn), mysql_get_client_info());
	return mysql_conn;
failed:
    if (mysql_conn != NULL)
        free(mysql_conn);
    return NULL;


}


static void mysql_close_conn()
{
	printf("mysql db close connection......\n");
	if (mysql_conn == NULL)
		return;

	mysql_close((MYSQL*) mysql_conn);
	free(mysql_conn);
	mysql_conn = NULL;


}

static int mysql_check_conn()
{
	if (mysql_conn == NULL)
        return DB_FAILURE;
    if (mysql_ping((MYSQL*)mysql_conn))
    {
        printf("MYSQL: database check failed! %s\n", mysql_error(mysql_conn));
        return DB_FAILURE;
    }
    return DB_SUCCESS;
}
	

static void mysql_conf_destroy(tMySQLConf *db_conf)
{
	printf("mysql db destroy......\n");
    if (db_conf == NULL)
        return;
    free(db_conf);
}


static int mysql_db_excute(const char *sqlstr)
{
    if (!mysql_query((MYSQL *)mysql_conn, sqlstr))
        return DB_SUCCESS;
    return DB_FAILURE;
}



static void* mysql_db_firstrow(const char *sqlstr)
{
    if (sqlstr == NULL)
        return NULL;

    if (mysql_db_excute(sqlstr) == DB_FAILURE)
        return NULL;

    // we must check this.
    if (mysql_res)
        mysql_free_result(mysql_res);

    mysql_res = mysql_store_result(mysql_conn);
    if (mysql_res == NULL)
        return NULL;
    if (mysql_num_rows(mysql_res) < 1)
    {
        printf("Could not get count of table. sql: %s\n", sqlstr);
        mysql_free_result(mysql_res);
        mysql_res = NULL;
        return NULL;
    }
    mysql_row = (MYSQL_ROW *)mysql_fetch_row(mysql_res);
    if (mysql_row == NULL)
    {
       printf("rows found but could not load them. sql: %s\n", sqlstr);
        mysql_free_result(mysql_res);
        mysql_res = NULL;
        return NULL;
    }

    return (void *)mysql_row;
}



static void* mysql_db_nextrow()
{
    if (mysql_res == NULL)
        return NULL;
    mysql_row = (MYSQL_ROW *)mysql_fetch_row(mysql_res);
    if (mysql_row == NULL)
    {
        //WriteLog(LOG_SYS_ERR, "\ndb.mysql, rows found but could not load them");
        mysql_free_result(mysql_res);
        mysql_res = NULL;
        return NULL;
    }
    if (mysql_row == NULL)
    {
        mysql_free_result(mysql_res);
        mysql_res = NULL;
        return NULL;
    }

    return (void *)mysql_row;
}



static int mysql_db_flush(const char *table)
{
    char sqlstr[128];
    if (table == NULL)
        return DB_FAILURE;    
    sprintf(sqlstr, "truncate %s;", table);
    //sprintf(sqlstr, "DELETE FROM %s;", table);

    return mysql_db_excute(sqlstr);
}



static int mysql_db_errno()
{
  if (mysql_conn == NULL)
      return DB_FAILURE;
  int err = mysql_errno(mysql_conn);
  if(err == 1043 || err == 1081 || err == 1129)
  	return DB_FAILURE;
  
  return DB_SUCCESS;
}


char* GetWorkingPath()
{
    int iResult = 0;
	static char pPath[128];
	static int bInit = bFALSE;
	if(bInit)
		return pPath;
	
    iResult = readlink( "/proc/self/exe",pPath,128); 
    if ( iResult < 0 || iResult >= 128 ) 
        return NULL;
    if(pPath[iResult] == '/')
		iResult--;
    while(pPath[iResult] != '/' && iResult>= 0)
    {
        iResult--;
    }
    pPath[iResult] = 0; 

    bInit = bTRUE;
    return pPath;
}
  




db_ops * db_init_mysql()
{
	strcpy(dbconf.host,"localhost");
	strcpy(dbconf.username,"admin");
	strcpy(dbconf.password,"admin");
	strcpy(dbconf.database,"db_ir");
	mysql_ops.db_conf	=	&dbconf;
	mysql_ops.open         = mysql_open_conn;
    mysql_ops.close        = mysql_close_conn;
    mysql_ops.check        = mysql_check_conn;
    mysql_ops.conf_destroy = mysql_conf_destroy;
    mysql_ops.excute       = mysql_db_excute;
    mysql_ops.getfirst     = mysql_db_firstrow;
    mysql_ops.getnext      = mysql_db_nextrow;
    mysql_ops.flush        = mysql_db_flush;
	mysql_ops.geterrno     = mysql_db_errno;

printf("11111111111111111111\n");
	mysql_ops.conn_ptr = mysql_ops.open(&dbconf);
	return &mysql_ops;

}



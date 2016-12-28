#ifndef _MYDB_H_
#define _MYDB_H_



enum db_result {
    DB_FAILURE=-1, DB_SUCCESS=0
};

#define bFALSE				-1
#define bTRUE				0


typedef struct {
    char host[32];
    char username[32];
    char password[32];
    char database[32];
}tMySQLConf;


typedef struct _db_ops {

	char cb_sys[15];
	
	void *conn_ptr;
	tMySQLConf *db_conf;

	
	void *(*open)(tMySQLConf *conf);
	void (*close)();

	int (*check)();
	void (*conf_destroy)(tMySQLConf *conf);
	
	int (*excute)(const char *sqlstr);
	void *(*getfirst)(const char *sqlstr);
	void *(*getnext)();
	int (*flush)(const char *table);
	int (*geterrno)();
}db_ops;


extern db_ops	*db_init_mysql();


#endif







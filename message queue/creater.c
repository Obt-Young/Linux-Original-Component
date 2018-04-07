#include "1.h"

int main(int argc,char ** argv)
{
	int msgid;
	int ret;

	msgid=msgget(MSG_KEY,IPC_CREAT|IPC_EXCL|0666);

	if(msgid==-1)
		{
			printf("create message queue fail!\n");
			exit(-1);
		}

	printf("create mq success\n");
	return 0;
}



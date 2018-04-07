#include "1.h"

int main(int argc,char ** argv)
{
	int msgid;
	char msg[1024];
	long size;
	char cmd[3];

	memset(&msg,0,sizeof(1024));	

	msgid=msgget(MSG_KEY,0006);
	
	recv:
	size=msgrcv(msgid,msg,1024,0,IPC_NOWAIT);
	if(size == -1)
		{
			perror("receive fail:");
			exit(-1);
		}

	printf("read a message from queue's head -> %s\n",msg);

	scanf("%s",cmd);
	if(cmd[0]=='n')
		goto recv;
	else 
		return 0;
}

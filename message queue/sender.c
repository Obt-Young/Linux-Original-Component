#include "1.h"

struct my_msg{
	long mtype;
	char mtext[1024];
};

int main(int argc,char ** argv)
{
	int msgid;
	struct my_msg msg;
	char mtext[1024];
	int ret;

	msgid=msgget(MSG_KEY,0006);
	if(msgid==-1)
		{
			perror("get mq fail:");
			exit(-1);
		}
	send:	
	memset(&msg,0,sizeof(msg));
	scanf("%s",mtext);
	printf("this -> '%s' will be sent into mq\n",mtext);
	
	msg.mtype=getpid();
	memcpy(msg.mtext,mtext,strlen(mtext));

	ret=msgsnd(msgid,msg.mtext,strlen(mtext),IPC_NOWAIT);
	if(ret == -1)
		{
			perror("send fail:");
			exit(-1);
		}
	goto send;

}

# common
*some common method for both windows and linux.
*1. common class TabFile, read txt file that every column use delimiter '\t'.
*2. common thread operation for windows and linux.
*thread example:
*// inherrite Engine::IRunable
*class NetWork : public Engine::IRunable
*{
*public:
*	void run()
*	{
*		int loop = 0;
*
*		while(true) {
*			if(loop++ == 10)
*				break;
*
*			printf("network run....\n");
*			Engine::Thread::thread_sleep(1000);
*		}
*	}
*};
*
*Engine::Thread* pthread = new Engine::Thread(new NetWork());
*pthread->start();
*pthread->join(); // wait thread task over
*
*delete pthread;
*pthread = NULL; 

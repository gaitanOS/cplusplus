#include <iostream>
#include <cstdlib>
#include <pthread.h>

using namespace std;

#define thread_num 15

int mutex = 0;

void *printmsg(void *t_id){
  while(1){
    if(mutex){
      cout << "thread " << long(t_id) << " locked...waiting for mutex unlock...\n" << endl;
    }
    else{
      mutex = 1; //lock
      cout << "Current thread running printmsg: " << (long)t_id << endl;
      //stop the thread here
      mutex = 0; //unlock
      pthread_exit(NULL); //function to stop thread
      break;
    }
  }
}




int main() {
  int i, tv;
  pthread_t threads[thread_num]; // makes thread_num threads

  for(i = 0; i < thread_num; i++){
    cout << "creating thread: " << i << endl;
    tv = pthread_create(&threads[i], NULL, printmsg, (void *)i);

    if(tv){
      cout << "thread: " << i << " failed to create. \n" << endl;
    }
  }
  pthread_exit(NULL); //terminate any remaining threads
}
#include <iostream>
#include <unistd.h>
#include <fcntl.h>


int __attribute__ ((noinline))  top()
{
   for(int i=0; i<100000; i++) {
      int fd = open("/", O_DIRECTORY);
      close(fd);

   }
   return 1;
}


int __attribute__ ((noinline)) c1()
{
   return top();
}

int __attribute__ ((noinline))  b1()
{
   return c1();
}


int __attribute__ ((noinline))  a1()
{
   return b1();
}

int __attribute__ ((noinline)) c2()
{
   return top();
}

int __attribute__ ((noinline))  b2()
{
   return c2();
}


int __attribute__ ((noinline))  a2()
{
   return b2();
}

int __attribute__ ((noinline)) c3()
{
  sleep(1);
   return 1;
}

int __attribute__ ((noinline))  b3()
{
   return c3();
}


int __attribute__ ((noinline))  a3()
{
   return b3();
}


int main()
{
    while(true) {
        std::cout << "Calling a" << std::endl;
        a1();
        a2();
	a3();
    }
    return 0;
}

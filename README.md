# libconf
A conf file management library.

This is a workable conf file management. It supposes that all the conf items are without
sublevel, only one level, say, key and value. It supports set, get, del operations.
It relies on json-c library.

How to use:
* On desktop Linux, install libjson-c Download from https://github.com/json-c/json-c  
  cmake .  
  ./configure --prefix=/usr  
  make  
  sudo make install  
* Download libconf code and build it.  
  make  
  sudo make install  
  make example  
* Run the examples  
  ./example/x86_64-linux-gnu-release/main  
  You will see conf pairs get, set, del operations like below.
Content: { "test1": 20, "test2": 40, "test3": true, "test4": "hello world" }  
test1: 20  
test2: 40  
test3: 1  
test4: hello world  
Operation on test2 failed.  

Note: the test2 operation failure is because key test2 was del and then  
we get it. Please refer to main.c for better understanding.  

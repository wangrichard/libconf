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
  You will see conf pairs get, set, del operations.

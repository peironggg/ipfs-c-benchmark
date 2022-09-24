# ipfs-c-client
Simple examples to access IPFS HTTP endpoints using libcurl in C

## Setup
After cloning the project, do the following:

```console
user:~$ chmod +x setup.sh
user:~$ ./setup.sh
```

This installs kubo (go implementation of IPFS) and sets up a private IPFS network in your machine.

You can then run

```console
user:~$ make
```

to compile the examples.

## Other endpoints
The examples include query the MFS endpoints.
They can be easily modified to access other IPFS HTTP endpoints by changing the path and updating the query parameters accordingly.

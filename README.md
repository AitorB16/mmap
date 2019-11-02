# mmap

Some files to compare performance of reading and writing to a file using standar ```fread``` and ```fwrite``` library functions
and ```mmap```.

## How to test

1. To create a big file execute ```createBigFile.sh```. This will create a file called ```tmpfile2G``` with random characters with a size 
of 2.1GB (2GiB). 

2. Compile readLib.c and readMmap.c

3. Execute each file: ``` \usr\bin\time -v ./<program name> tmpfile2G``` 
This will show in the terminal some information about the execution. We are looking for ```Elapsed (wall lock) time```,
```Minor (reclaiming a frame) page faults``` and ```Major (requiring I/O) page faults```.

Note: To ensure fair conditions, you should run ```createBigFile.sh``` before each execution as the programs will overwrite 
each character with a 0. 

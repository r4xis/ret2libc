# BYPASS SSP & RET2LIBC
```
$ file vuln
vuln: ELF 32-bit LSB shared object, Intel 80386, version 1 (SYSV), dynamically linked, interpreter /lib/ld-linux.so.2, for GNU/Linux 2.6.32, BuildID[sha1]=289b8b82021fef23b1785c858c7d929cdd74bd96, not stripped
```
## CHECKSEC
```
gdb-peda$ checksec
CANARY    : ENABLED
FORTIFY   : disabled
NX        : ENABLED
PIE       : ENABLED
RELRO     : FULL
```
## ASLR
```
# cat /proc/sys/kernel/randomize_va_space
2
```

## CANARY
[https://www.elttam.com.au/blog/playing-with-canaries/](https://www.elttam.com.au/blog/playing-with-canaries/)
## LIBCBASE
[http://uaf.io/exploitation/misc/2016/04/02/Finding-Functions.html](http://uaf.io/exploitation/misc/2016/04/02/Finding-Functions.html)
## RESULT
![exp-gets](https://user-images.githubusercontent.com/16120472/33175101-94a83590-d06b-11e7-950a-926f9a31f3fd.png)

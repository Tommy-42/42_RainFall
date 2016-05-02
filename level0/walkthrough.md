# level0 walkthrough
## First let's see the main
```bash
gdb -batch -ex 'file level0' -ex 'disassemble main'
```
output
```
Dump of assembler code for function main:
   0x08048ec0 <+0>:	push   %ebp
   ...
   0x08048ed4 <+20>:	call   0x8049710 <atoi>
   0x08048ed9 <+25>:	cmp    $0x1a7,%eax
   0x08048ede <+30>:	jne    0x8048f58 <main+152>
   ...
   0x08048f85 <+197>:	leave
   0x08048f86 <+198>:	ret
End of assembler dump.
```
we can see that there is a call to `atoi` se we can think of transformation from args to an integer
```
0x08048ed4 <+20>:	call   0x8049710 <atoi>
```
because right after there is a compare with `$eax` and `0x1a7` value
where we can print it as a decimal to see what is the value of `0x1a7`
```bash
python -c 'print "%d" % 0x1a7'
```
the result of the commande is : `423`
so let's try to pass it as a parameter of the programm
```bash
./level0 423
```
the programm give us a new shell so a basic `whoami` to let us know who we are gives
```
$ whoami
level1
```
then we just need to go to the user home `cd /home/user/level1` and cat the `.pass` to get the flag
```
$ cat /home/user/level1/.pass
1fe8a524fa4bec01ca4ea2a869af2a02260d4a7d5fe7e7c24d8617e6dca12d3a
```
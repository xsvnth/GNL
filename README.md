# GNL


### References

- [read(2) — Linux manual](https://man7.org/linux/man-pages/man2/read.2.html): Understanding the `read()` system call, its arguments and return values.
- [C Storage Duration](https://en.cppreference.com/w/c/language/storage_duration): Understanding `static` variables and how they retain their values between function calls.
- [C Preprocessor — Macro Definitions](https://en.cppreference.com/w/c/preprocessor/replace): Understanding `#define` and how `BUFFER_SIZE` is defined and replaced during preprocessing.
=======
# Get Next Line (GNL)

A 42 project focused on reading a file descriptor one line at a time, while preserving the unread data between successive calls.

## Research & Resources

Resources I used to understand the concepts behind the project, from file descriptors and static variables to Linux internals and the x86-64 ABI.

### 1. Static Variables

- [Wikipedia – Static Variables](https://en.wikipedia.org/wiki/Static_variable)
- [42 Subject – Static Variables](https://en.wikipedia.org/wiki/Static_variable)

### 2. Linux Manual Pages

Useful references for understanding system calls, file descriptors, processes, memory mappings, and file systems.

- [read(2)](https://man7.org/linux/man-pages/man2/read.2.html)
- [open(2)](https://man7.org/linux/man-pages/man2/open.2.html)
- [close(2)](https://man7.org/linux/man-pages/man2/close.2.html)
- [dup(2)](https://man7.org/linux/man-pages/man2/dup.2.html)
- [fcntl(2)](https://man7.org/linux/man-pages/man2/fcntl.2.html)
- [inode(7)](https://man7.org/linux/man-pages/man7/inode.7.html)
- [path_resolution(7)](https://man7.org/linux/man-pages/man7/path_resolution.7.html)
- [proc(5)](https://man7.org/linux/man-pages/man5/proc.5.html)
- [proc_pid_fdinfo(5)](https://man7.org/linux/man-pages/man5/proc_pid_fdinfo.5.html)
- [proc_pid_maps(5)](https://man7.org/linux/man-pages/man5/proc_pid_maps.5.html)
- [C Storage Classes](https://en.cppreference.com/w/c/language/storage_duration.html)

Full manual collection: [Linux man-pages](https://man7.org/linux/man-pages/)

### 3. File Descriptors

- [Handling a File by Its Descriptor in C](https://www.codequoi.com/en/handling-a-file-in-c/)

### 4. Linux Kernel Source Code

Exploring the Linux kernel source to understand how file descriptors, open files, and processes are represented internally.

- [fs.h – File System Structures](https://github.com/torvalds/linux/blob/master/include/linux/fs.h)
- [sched.h – Process and Task Structures](https://github.com/torvalds/linux/blob/master/include/linux/sched.h)
- [entry_64.S – x86-64 Entry Code](https://github.com/torvalds/linux/blob/master/arch/x86/entry/entry_64.S)

### 5. x86-64 ABI

- [System V Application Binary Interface – AMD64](https://gitlab.com/x86-psABIs/x86-64-ABI)

### 6. Videos

- [Reading Files](https://www.youtube.com/watch?v=aiJj4mLS9oI)

---

## Exploring Linux Internals

Some useful commands for locating and inspecting the structures discussed during my research.

**`struct file`**

```bash
grep -n -A100 'struct file {' \
/usr/src/linux-headers-$(uname -r)/include/linux/fs.h
```

**`struct task_struct`**

```bash
grep -n -A150 'struct task_struct {' \
/usr/src/linux-headers-$(uname -r)/include/linux/sched.h
```

**`struct files_struct` – File Descriptor Table**

```bash
grep -R -n -A80 'struct files_struct {' \
/usr/src/linux-headers-$(uname -r)/include/linux/
```

**`struct fdtable`**

```bash
grep -R -n -A40 'struct fdtable {' \
/usr/src/linux-headers-$(uname -r)/include/linux/
```

*Note: These commands assume the matching Linux kernel headers are installed.*

---

*This README also serves as a collection of references and notes gathered while exploring the concepts behind Get Next Line.*
>>>>>>> f0bbc23970980fb3d3dc0627389e36a3d398bcd7

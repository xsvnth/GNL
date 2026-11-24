# GNL


## Resources
wikipedia:
the one from the subject about Static_variable: https://en.wikipedia.org/wiki/Static_variable
manuals(read, open , close, dup, fcntl, inode, path_resolution, proc, proc_pid_finfo, proc_pid_maps, storage class):
https://man7.org/index.html
random by chance:
handling-a-file-by-its-descriptor-in-c: https://www.codequoi.com/en/handling-a-file-by-its-descriptor-in-c/#what-is-a-file-descriptor
github:
https://github.com/torvalds/linux/blob/master/include/linux/fs.h
https://github.com/torvalds/linux/blob/master/include/linux/sched.h
https://github.com/torvalds/linux/blob/master/arch/x86/entry/entry_64.S
gitlab:
https://gitlab.com/x86-psABIs/x86-64-ABI
youtube:
Reading files: https://www.youtube.com/watch?v=aiJj4mLS9oI
structs:
=file struct : grep -n -A100 'struct file {' \
/usr/src/linux-headers-$(uname -r)/include/linux/fs.h
=task struct : grep -n -A150 'struct task_struct {' \
/usr/src/linux-headers-$(uname -r)/include/linux/sched.h
=descriptor table:grep -R -n -A80 'struct files_struct {' \
/usr/src/linux-headers-$(uname -r)/include/linux/
=// // 2: grep -R -n -A40 'struct fdtable {' \
/usr/src/linux-headers-$(uname -r)/include/linux/

| fb_func         | ipfs_api    | Notes                                                                            |
| --------------- | ----------- | -------------------------------------------------------------------------------- |
| fb_lfs_freemem  | ?           |                                                                                  |
| fb_lfs_open     | -           | no need to open a file to obtain a fd, so return OK                              |
| fb_lfs_pread    | files/read  | read can specify offset                                                          |
| fb_lfs_read     | files/read  |                                                                                  |
| fb_lfs_pwrite   | files/write | write can specify offset                                                         |
| fb_lfs_write    | files/write |                                                                                  |
| fb_lfs_lseek    | ?           |                                                                                  |
| fb_lfs_truncate | ?           |                                                                                  |
| fb_lfs_rename   | files/mv    |                                                                                  |
| fb_lfs_close    | -           | no fd to close in ipfs, so return OK                                             |
| fb_lfs_link     | ?           |                                                                                  |
| fb_lfs_symlink  | ?           |                                                                                  |
| fb_lfs_unlink   | ?           |                                                                                  |
| fb_lfs_readlink | ?           |                                                                                  |
| fb_lfs_mkdir    | files/mkdir |                                                                                  |
| fb_lfs_rmdir    | files/rm    | specify force remove for directories                                             |
| fb_lfs_opendir  | ?           |                                                                                  |
| fb_lfs_readdir  | ?           |                                                                                  |
| fb_lfs_closedir | -           | no directory to close, so return OK                                              |
| fb_lfs_fsync    | ?           |                                                                                  |
| fb_lfs_stat     | ?           |                                                                                  |
| fb_lfs_fstat    | ?           |                                                                                  |
| fb_lfs_access   | ?           |                                                                                  |
| fb_lfs_recur_rm | files/rm    | specify force remove for directories, force implies recursive rm for directories |
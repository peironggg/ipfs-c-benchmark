| fb_func         | ipfs_api    | Notes                                                     |
| --------------- | ----------- | --------------------------------------------------------- |
| fb_lfs_freemem  | ?           |                                                           |
| fb_lfs_open     | files/write | write requires some data in the request, use empty string |
| fb_lfs_pread    | files/read  | read can specify offset                                   |
| fb_lfs_read     | files/read  |                                                           |
| fb_lfs_pwrite   | files/write | write can specify offset                                  |
| fb_lfs_write    | files/write |                                                           |
| fb_lfs_lseek    | ?           |                                                           |
| fb_lfs_truncate | ?           |                                                           |
| fb_lfs_rename   | files/mv    |                                                           |
| fb_lfs_close    | no need     | no fd to close in ipfs                                    |
| fb_lfs_link     | ?           |                                                           |
| fb_lfs_symlink  | ?           |                                                           |
| fb_lfs_unlink   | ?           |                                                           |
| fb_lfs_readlink | ?           |                                                           |
| fb_lfs_mkdir    | files/mkdir |                                                           |
| fb_lfs_rmdir    | files/rm    | specify force remove for directories                      |
| fb_lfs_opendir  | ?           |                                                           |
| fb_lfs_readdir  | ?           |                                                           |
| fb_lfs_closedir | ?           |                                                           |
| fb_lfs_fsync    | ?           |                                                           |
| fb_lfs_stat     | ?           |                                                           |
| fb_lfs_fstat    | ?           |                                                           |
| fb_lfs_access   | ?           |                                                           |
| fb_lfs_recur_rm | ?           |                                                           |
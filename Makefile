all:
	gcc -o ipfs_write_file.out ipfs_write_file.c -lcurl
	gcc -o ipfs_read_file.out ipfs_read_file.c -lcurl
	gcc -o ipfs_mkdir.out ipfs_mkdir.c -lcurl
	gcc -o ipfs_rename.out ipfs_rename.c -lcurl

clean:
	rm ipfs*.out
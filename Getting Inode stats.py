#Find inode data of a file
#For displaying full path from root to files
import os
f = open("filename", 'w')
#fstat to pass file pointer
#stats = os.fstat(f)
#stat for passing filename
stats = os.stat('filename')
print(stats)
print("inode number is ", stats.st_ino)
print("size of file is ", stats.st_size)


#For displaying filename, inode number and file_size of all the files within a root directory
import os
for root, subdir, files in os.walk("."):
    for each in files:
        stats = os.stat(each)
        #printing filename, inode_number and file size of each file within given root directory
        print(each, stats.st_ino, stats.st_size)


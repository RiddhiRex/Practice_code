#For iteratively traversing from a root directory and printing its structure
import os
rootDir = '.'
for dirName, subdirList, fileList in os.walk(rootDir):
    print('top directory:', dirName)
    print("Subdirectory list: ", subdirList)
    print("files list within this current sub-directory:")
    for fname in fileList:
        print('\t', fname)
        
        
#For displaying complete path from root to files
import os
path = "."

fname = []
for root,d_names,f_names in os.walk(path):
	for f in f_names:
		fname.append(os.path.join(root, f))

print("complete path of files", fname)

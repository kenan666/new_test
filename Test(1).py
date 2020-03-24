import os
def readFile(filename,str,label=''):
    # print('filename==>'+filename+'\nstr==>'+str)
    newstr=str
    if os.path.exists(newstr):
        if os.path.isfile(newstr):
            newstr=os.path.join(newstr,filename)
            # print("-------"+newstr)
        else:
            get_dir = os.listdir(newstr)
            for i in get_dir:
                sub_dir = os.path.join(newstr, i)
                if os.path.isdir(sub_dir):
                    if(i=="not_obstruct"):
                        readFile(i,sub_dir,0)
                    elif(i=="obstruct"):
                        readFile(i, sub_dir, 1)
                else:
                    # print('i==>'+i+'\nnewstr==>'+newstr)
                    # os.path.join(newstr, i)
                    outstr = i
                    savefile(label,outstr)

def savefile(labels,filename):
    filename=filename.split('.')
    if(labels==0):
        filename[0]+=" 0\n"
        outfile = "test/not_obstruct/not_obstruct.txt"
        fp = open(outfile, "a", encoding="utf-8")
        fp.write(filename[0])
        fp.close()
    elif(labels==1):
        filename [0]+= " 1\n"
        outfile = "test/obstruct/obstruct.txt"
        fp = open(outfile, "a", encoding="utf-8")
        fp.write(filename[0])
        fp.close()


if __name__ == "__main__":
    readFile('',r'test')
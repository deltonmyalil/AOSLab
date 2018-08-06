import subprocess as sp

myFile = open("output.txt", "a")
sp.Popen("ls", stdout = myFile)
sp.Popen(["ls","-l"], stdout = myFile)
sp.call(["mkdir" , "delton"])
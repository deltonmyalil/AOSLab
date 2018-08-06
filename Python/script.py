import subprocess as sp

myFile = open("output.txt", "w")
sp.Popen("ls", stdout = myFile)
sp.Popen(["ls","-l"], stdout = myFile)
sp.call(["mkdir" , "delton"])
sp.Popen("ls", stdout = myFile)
## added another folder and called ls
sp.Popen(["ls","-a"], stdout = myFile)
sp.Popen(["ls","-s"], stdout = myFile)
sp.Popen(["ls","-R"], stdout = myFile)
sp.Popen(["ls","-S"], stdout = myFile)

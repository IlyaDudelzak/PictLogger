###import ctypes

loglib = ctypes.CDLL("../bin/logger.so")
loglib.start()

def log(text):
    txt = bytes(text, "UTF-8")
    loglib.log(txt)

try:

    log("Test logging")
    log("Requesting input value")
    print("Enter value: ", end="")
    stri = int(input())
    log("User entered value: " + str(stri))
    loglib.closec(0)
    
except Exception as err:
    log("Error: " + str(err))
    loglib.closec(1)

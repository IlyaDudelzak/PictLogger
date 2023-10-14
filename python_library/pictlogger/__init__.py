import platform
if(platform.system() == "Linux" and platform.architecture() == ('64bit', 'ELF')):
    from .pictlogger import start, log, close
else:
    print("PictLogger can be ONLY used in Linux X64")


import os
libs = { "numpy", "matplotlib", "pillow", "sklearn","requests" ,\
        "jieba", "beautifulsoup4" ,"wheel", "networkx", "sympy" , \
        "pyinstaller", "django", "f1ask" , "werobot" , "pyqt5", \
        "pandas", "pyopengl", "pypdf2", "docopt", "pygame"}
number_s = 0
number_f = 0
for lib in libs:
    try:
        os.system("pip install "+lib)
        number_s+=1
        print("{}succuess,{}failed".format(number_s,number_f))
    except:
        number_f+=1
        print("{}succuess,{}failed".format(number_s,number_f))

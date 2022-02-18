# -*-coding=UTF-8 -*-
import numpy as np
from PIL import Image
import jieba
import wordcloud
mask = np.array(Image.open("C:/Users/Future/Desktop/map.jpg"))
exclude=["和","的","在","了","是","都","中","一个"]
my_stop_words = set(wordcloud.STOPWORDS)
for i in exclude:
    my_stop_words.add(i)
txt = open("c:\\Users\\Future\\Desktop\\Python\\Notes\\Code\\txt_wordcloud.txt","r",encoding="utf-8").read()
jieba_list = jieba.lcut(txt)
jieba_cut = " ".join(jieba_list)
w = wordcloud.WordCloud(width=2500,height=1500,font_path="msyh.ttc",\
    background_color="white",stopwords=my_stop_words,mask=mask)
w.generate(jieba_cut)
w.to_file("c:\\Users\\Future\\Desktop\\Python\\Notes\\Code\\Government.png")

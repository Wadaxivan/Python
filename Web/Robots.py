import urllib.robotparser

url = 'https://ai.baidu.com'
rp = urllib.robotparser.RobotFileParser()
rp.set_url(url + '/robots.txt')
rp.read()
info = rp.can_fetch("*", 'https://ai.baidu.com/tech/speech/asr')
print(info)
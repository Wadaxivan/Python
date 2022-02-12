from urllib.parse import urlparse
from requests_html import HTMLSession
session = HTMLSession()
origin = 'https://ai.baidu.com'
r = session.get(origin)
print(r.html.links)

domain = 'ai.baidu.com'

def is_inner_link(link):
    netloc = urlparse(link).netloc
    return (not netloc) or (netloc == domain)
	
for link in r.html.links:
    print(is_inner_link(link), link)

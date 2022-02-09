from requests_html import HTMLSession
session = HTMLSession()

links = ['http://stock.finance.sina.com.cn/usstock/quotes/BIDU.html', 'http://stock.finance.sina.com.cn/usstock/quotes/AAPL.html', 'http://stock.finance.sina.com.cn/usstock/quotes/msft.html']
for link in links:
    r = session.get(link)
    r.html.render()
    title = r.html.find('#hqPrice', first=True)
    print(title.text)
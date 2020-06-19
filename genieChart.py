import requests
from bs4 import BeautifulSoup

headers = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/83.0.4103.106 Safari/537.36'}
url = "https://www.genie.co.kr/chart/top200"

html = requests.get(url, headers=headers).text
soup = BeautifulSoup(html, "html.parser")
rank = soup.find_all('td', class_='info')

num = 1
for i in rank:
    title = i.find(class_="title ellipsis").text.strip()
    artist = i.find(class_="artist ellipsis").text
    print()
    print(str(num) + "위: " + title + " - " + artist)
    num += 1

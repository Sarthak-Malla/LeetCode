import requests
import bs4
import time

import os.path

# from google.auth.transport.requests import Request
# from google.oauth2.credentials import Credentials
# from google_auth_oauthlib.flow import InstalledAppFlow
# from googleapiclient.discovery import build
# from googleapiclient.errors import HttpError

class LeetCodeDescriptionScraper:
    def __init__(self) -> None:
        pass

    def scrape(self, url):
        url = url.strip()
        response = requests.get(url)
        soup = bs4.BeautifulSoup(response.text, 'lxml')

        print(soup.text)

        description = ""

        if soup:
            title = soup.find('div', {'class': 'css-v3d350'})
            title = title.text if title else " "

            print(title)
        else:
            print("error")


if __name__ == "__main__":

    input_file = "url.txt"
    with open(input_file, 'r', encoding="utf-8") as f:
        urls = [x.strip() for x in f.readlines()]
    
    scraper = LeetCodeDescriptionScraper()
    for url in urls:
        scraper.scrape(url)

    # scraper.make_file()

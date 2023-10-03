import requests
from bs4 import BeautifulSoup
import sqlite3


def scrape_and_store_listings():
    conn = sqlite3.connect('realtor_listings.db')
    cursor = conn.cursor()

    cursor.execute('''
        CREATE TABLE IF NOT EXISTS listings (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            title TEXT,
            price TEXT,
            location TEXT,
            for_sale INTEGER,
            area TEXT
        )
    ''')

    url = "https://www.realtor.com/realestateandhomes-search/Maui_HI/pnd-hide"

    payload = ""
    headers = {
        'Cookie': '__bot=false; __ssn=b0b811e3-5f43-4d6f-bd0b-3adc6fbadb5b; __ssnstarttime=1696359420; __vst=9c9a88f0-9c0d-4c64-87d6-0f2569df39b6; split=n; split_tcv=152',
        'User-Agent': 'PostmanRuntime/7.33.0'
    }

    response = requests.request("GET", url, headers=headers, data=payload)

    # Check if the request was successful
    if response.status_code == 200:
        # Parse the HTML content of the page
        soup = BeautifulSoup(response.text, 'html.parser')

        # Find property listings on the page
        listings = soup.find_all(
            'div', class_='BasePropertyCard_propertyCardWrap__J0xUj')

        for listing in listings:
            # Extract relevant information from the listing
            title = listing.find(
                'span', class_='BrokerTitle_titleText__20u1P').text.strip()
            price = listing.find(
                'div', class_='Pricestyles__StyledPrice-rui__btk3ge-0 bvgLFe card-price').text.strip()
            location = listing.find(
                'div', class_='card-address truncate-line').text.strip()
            for_sale = listing.find(
                'div', class_='base__StyledType-rui__sc-108xfm0-0 kpUjhd message').text.strip() == 'For Sale'
            area_wrapper = listing.find(
                'li', class_='PropertySqftMetastyles__StyledPropertySqftMeta-rui__sc-1gdau7i-0')
            area = "unknown"
            if area_wrapper:
                area = area_wrapper.find(
                    'span', class_='meta-value').text.strip()

            cursor.execute('''
                INSERT INTO listings (title, price, location, for_sale, area)
                VALUES (?, ?, ?, ?, ?)
            ''', (title, price, location, for_sale, area))

        conn.commit()
        conn.close()
        print('Scraping and storing completed successfully.')
    else:
        print(response)
        print('Failed to retrieve the web page.')


if __name__ == '__main__':
    scrape_and_store_listings()

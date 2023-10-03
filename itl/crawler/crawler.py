import requests
from lxml import html
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

    headers = {
        'Cookie': '__bot=false; __ssn=b0b811e3-5f43-4d6f-bd0b-3adc6fbadb5b; __ssnstarttime=1696359420; __vst=9c9a88f0-9c0d-4c64-87d6-0f2569df39b6; split=n; split_tcv=152',
        'User-Agent': 'PostmanRuntime/7.33.0'
    }

    response = requests.get(url, headers=headers)

    # Check if the request was successful
    if response.status_code == 200:
        # Parse the HTML content of the page using lxml
        page_content = html.fromstring(response.text)

        # Find property listings on the page using XPath
        listings = page_content.xpath('//div[contains(@class, "BasePropertyCard_propertyCardWrap__J0xUj")]')

        for listing in listings:
            # Extract relevant information from the listing using XPath
            title = listing.xpath('.//span[contains(@class, "BrokerTitle_titleText__20u1P")]/text()')[0].strip()
            price = listing.xpath('.//div[contains(@class, "Pricestyles__StyledPrice-rui__btk3ge-0")]/text()')[0].strip()
            
            # Check if the location element exists before accessing it
            location_elements = listing.xpath('.//div[contains(@class, "card-address truncate-line")]/text()')
            location = location_elements[0].strip() if location_elements else "Location not found"

            for_sale = 'For Sale' in listing.xpath('.//div[contains(@class, "base__StyledType-rui__sc-108xfm0-0 kpUjhd message")]/text()')[0].strip()
            area_wrapper = listing.xpath('.//li[contains(@class, "PropertySqftMetastyles__StyledPropertySqftMeta-rui__sc-1gdau7i-0")]')
            area = "unknown"
            if area_wrapper:
                area_elements = area_wrapper[0].xpath('.//span[contains(@class, "meta-value")]/text()')
                area = area_elements[0].strip() if area_elements else "Area not found"

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

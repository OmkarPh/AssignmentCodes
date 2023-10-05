import requests
from lxml import html
import sqlite3
import time


def scrape_and_store_listings():
    conn = sqlite3.connect('realtor_listings.db')
    cursor = conn.cursor()

    cursor.execute('DROP TABLE IF EXISTS listings')

    cursor.execute('''
        CREATE TABLE IF NOT EXISTS listings (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            brokered_by TEXT,
            price TEXT,
            location TEXT,
            for_sale INTEGER,
            area TEXT
        )
    ''')

    base_url = "https://www.realtor.com/realestateandhomes-search/Maui_HI"

    headers = {
        # 'Cookie': '__bot=false; __ssn=b0b811e3-5f43-4d6f-bd0b-3adc6fbadb5b; __ssnstarttime=1696359420; __vst=9c9a88f0-9c0d-4c64-87d6-0f2569df39b6; split=n; split_tcv=152',
        # 'User-Agent': 'PostmanRuntime/7.33.0'
        'User-Agent': 'Mozilla/5.0 (Linux; Android 11; SAMSUNG SM-G973U) AppleWebKit/537.36 (KHTML, like Gecko) SamsungBrowser/14.2 Chrome/87.0.4280.141 Mobile Safari/537.36',
        'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8',
        'Accept-Encoding': 'gzip, deflate, br',
        'Accept-Language': 'en-US,en;q=0.6'
    }

    for page in range(1, 11):
        pageUrl = f"{base_url}/pg-`{page}`"
        response = requests.get(pageUrl, headers=headers)

        if response.status_code == 200:
            page_content = html.fromstring(response.text)

            listings = page_content.xpath(
                '//div[contains(@class, "BasePropertyCard_propertyCardWrap__J0xUj")]')

            for listing in listings:
                brokered_container = listing.xpath(
                    './/span[contains(@class, "BrokerTitle_titleText__20u1P")]/text()')
                brokered_by = brokered_container[0].strip() if len(
                    brokered_container) > 0 else "Broker not available"

                price_container = listing.xpath(
                    './/div[contains(@class, "Pricestyles__StyledPrice-rui__btk3ge-0")]/text()')
                price = price_container[0].strip() if len(
                    price_container) > 0 else "Price not available"

                # Check if the location element exists before accessing it
                location_elements = listing.xpath(
                    './/div[contains(@class, "card-address truncate-line")]')
                location = location_elements[0].text_content().strip(
                ) if location_elements else "Location not found"

                for_sale = 'For Sale' in listing.xpath(
                    './/div[contains(@class, "base__StyledType-rui__sc-108xfm0-0 kpUjhd message")]/text()')[0].strip()
                area_wrapper = listing.xpath(
                    './/li[contains(@class, "PropertySqftMetastyles__StyledPropertySqftMeta-rui__sc-1gdau7i-0")]')
                area = "Area not available"

                if area_wrapper:
                    area_elements = area_wrapper[0].xpath(
                        './/span[contains(@class, "meta-value")]/text()')
                    area = area_elements[0].strip(
                    ) if area_elements else "Area not available"

                cursor.execute('''
                    INSERT INTO listings (brokered_by, price, location, for_sale, area)
                    VALUES (?, ?, ?, ?, ?)
                ''', (brokered_by, price, location, for_sale, area))

            print(f'Scraped and stored listing page {page}')
            time.sleep(2)
        else:
            print('Listing completed !')
            break
    conn.commit()
    conn.close()
    print('Entire property Listing scraped & data saved to DB')


if __name__ == '__main__':
    scrape_and_store_listings()

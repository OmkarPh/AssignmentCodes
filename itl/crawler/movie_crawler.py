import requests
from bs4 import BeautifulSoup
import sqlite3
import pandas as pd

# Create a connection to the SQLite database
conn = sqlite3.connect('movies_info.db')

# Create a cursor object
cursor = conn.cursor()

# Create a table to store movie information
cursor.execute('''
    CREATE TABLE IF NOT EXISTS movies (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        title TEXT,
        year INTEGER,
        ratings INTEGER,
        director TEXT,
        cast TEXT,
        genre TEXT
    )
''')

headers = {
    # 'Cookie': '__bot=false; __ssn=b0b811e3-5f43-4d6f-bd0b-3adc6fbadb5b; __ssnstarttime=1696359420; __vst=9c9a88f0-9c0d-4c64-87d6-0f2569df39b6; split=n; split_tcv=152',
    # 'User-Agent': 'PostmanRuntime/7.33.0'
    'User-Agent': 'Mozilla/5.0 (Linux; Android 11; SAMSUNG SM-G973U) AppleWebKit/537.36 (KHTML, like Gecko) SamsungBrowser/14.2 Chrome/87.0.4280.141 Mobile Safari/537.36',
    'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8',
    'Accept-Encoding': 'gzip, deflate, br',
    'Accept-Language': 'en-US,en;q=0.6'
}

url = 'https://editorial.rottentomatoes.com/guide/best-horror-movies-of-all-time/'
response = requests.get(url, headers=headers)

print(response.status_code)

soup = BeautifulSoup(response.content, 'lxml')  # html.parser
divs = soup.find_all('div', {'class': 'col-sm-18 col-full-xs countdown-item-content'})

# Getting Title, Year, and rating of the movie
headings = [div.find('h2') for div in divs]

movie_names = [heading.find('a').string for heading in headings]
# years = [int(heading.find('span', class_='subtle start-year').string[1:-1]) for heading in headings]
ratings = [int(heading.find('span', class_='tMeterScore').string.strip('%')) for heading in headings]

# Director
directors = [div.find('div', class_='info director') for div in divs]
directors = [director.find('a').string if director else None for director in directors]

# Casting info
casting = [div.find('div', class_='info cast') for div in divs]
cast = []

for c in casting:
    cast_links = c.find_all('a')
    cast_names = [link.string for link in cast_links]
    cast.append(', '.join(cast_names))

print("Scraped")

# Create a DataFrame
movies_info = pd.DataFrame()
movies_info['Title'] = movie_names
movies_info['Year'] = []
movies_info['Ratings'] = ratings
movies_info['Director'] = directors
movies_info['Cast'] = cast
movies_info['Genre'] = 'Horror'

print("Created DF")

# Insert movie data into the database
for title, year, rating, director, cast, genre in zip(movie_names, years, ratings, directors, cast, ['Horror'] * len(movie_names)):
    cursor.execute('''
        INSERT INTO movies (title, year, ratings, director, cast, genre)
        VALUES (?, ?, ?, ?, ?, ?)
    ''', (title, year, rating, director, cast, genre))

print("Added to DB")

# Commit the changes and close the connection
conn.commit()
conn.close()

print("Done !")
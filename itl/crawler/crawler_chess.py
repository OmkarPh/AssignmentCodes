import requests
from bs4 import BeautifulSoup
import sqlite3

# Define the URL of the website to scrape
url = "https://2700chess.com/"

headers = {
    # 'Cookie': '__bot=false; __ssn=b0b811e3-5f43-4d6f-bd0b-3adc6fbadb5b; __ssnstarttime=1696359420; __vst=9c9a88f0-9c0d-4c64-87d6-0f2569df39b6; split=n; split_tcv=152',
    # 'User-Agent': 'PostmanRuntime/7.33.0'
    'User-Agent': 'Mozilla/5.0 (Linux; Android 11; SAMSUNG SM-G973U) AppleWebKit/537.36 (KHTML, like Gecko) SamsungBrowser/14.2 Chrome/87.0.4280.141 Mobile Safari/537.36',
    'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8',
    'Accept-Encoding': 'gzip, deflate, br',
    'Accept-Language': 'en-US,en;q=0.6'
}

# Send an HTTP GET request to the URL
response = requests.get(url, headers=headers)

# Parse the HTML content of the page using BeautifulSoup
soup = BeautifulSoup(response.content, "html.parser")

# Initialize a SQLite database and cursor
conn = sqlite3.connect("chess_players.db")
cursor = conn.cursor()

# Create a table to store player data
cursor.execute('''
    CREATE TABLE IF NOT EXISTS chess_players (
        id INTEGER PRIMARY KEY,
        name TEXT,
        rating INTEGER,
        category_ratings TEXT
    )
''')

# Find the element containing player information
player_list = soup.find("ul", class_="rating-list")
if player_list:
    players = player_list.find_all("li")

    # Iterate through each player and extract information
    for player in players:
        name = player.find("a").text.strip()
        rating = player.find("span", class_="rating").text.strip()
        categories = player.find("span", class_="categories").text.strip()

        # Insert player data into the SQLite database
        cursor.execute('''
            INSERT INTO chess_players (name, rating, category_ratings)
            VALUES (?, ?, ?)
        ''', (name, rating, categories))

    # Commit changes and close the database connection
    conn.commit()
    conn.close()

    print("Data scraped and stored successfully in chess_players.db.")
else:
    print("Player list not found on the website.")


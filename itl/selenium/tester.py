from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.alert import Alert
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.options import Options  # Import ChromeOptions
import time

# Define the WEBSITE variable
WEBSITE = "http://localhost:5500/"

driver = webdriver.Chrome()

def clear_local_storage():
    driver.get(WEBSITE + "index.html")
    driver.find_element(By.ID, "clearLocalStorageButton").click()
    print("Cleared localstorage successfully!\n")

def test_screenshot():
    driver.save_screenshot("screenshot.png")
    print("Screenshot saved to `screenshot.png` successfully!\n")

def test_responsiveness():
    driver.get(WEBSITE + "index.html")

    ogwidth = driver.get_window_size()["width"]
    ogheight = driver.get_window_size()["height"]

    desktop_only_div = driver.find_element(By.CLASS_NAME, "desktop-only")
    assert desktop_only_div.is_displayed(), "Desktop-only div is not visible on desktop."
    print("Desktop mode verified")

    mobile_only_div = driver.find_element(By.CLASS_NAME, "mobile-only")
    assert not mobile_only_div.is_displayed(), "Mobile-only div is visible on desktop."

    driver.set_window_size(375, 667)

    assert not desktop_only_div.is_displayed(), "Desktop-only div is visible on mobile."
    assert mobile_only_div.is_displayed(), "Mobile-only div is not visible on mobile."
    print("Mobile mode verified")

    print("Website responsiveness test passed Successfully!\n")
    driver.set_window_size(ogwidth, ogheight)


def test_add_preset():
    driver.get(WEBSITE + "index.html")

    # Click the "Add Preset" button three times
    add_preset_button = driver.find_element("id", "addPresetButton")
    add_preset_button.click()
    
    
    time.sleep(1)

    # Check if there are 3 entries in the list
    items = driver.find_elements(By.TAG_NAME, 'li')
    assert len(items) == 3
    print("Number of items: ", len(items))
    print("Add Preset Test Passed Successfully!\n")

def test_add_password():
    driver.get(WEBSITE + "index.html")

    # Enter values in the username and password fields
    username_input = driver.find_element("id", "username")
    password_input = driver.find_element("id", "password")

    username_input.send_keys("test_user")
    password_input.send_keys("test_password")

    # Click the "Add Item" button
    add_button = driver.find_element("id", "addItemButton")
    add_button.click()

    # Wait for a moment to let the item be added
    time.sleep(2)

    # Check if the item is displayed in the list
    item_list = driver.find_element("id", "itemList")
    assert "test_user" in item_list.text

    print("Add Password Test Passed Successfully!\n")


def test_copy_password():
    driver.get(WEBSITE + "index.html")

    # Click the "Copy Password" button for the first item
    copy_password_button = driver.find_element(
        "css selector", "#itemList li:first-child button[data-action='copyPassword']")
    expected_password = copy_password_button.get_attribute("data-pass")
    copy_password_button.click()

    # Use JavaScript to get the content of the clipboard
    clipboard_content = driver.execute_script(
        "return navigator.clipboard.readText();")

    # Check if the clipboard content matches the expected password
    print({"clipboard_content": clipboard_content, "expected": expected_password})
    assert clipboard_content == expected_password

    print("Copy Password Test Passed Successfully!\n")

def test_delete_password():
    driver.get(WEBSITE + "index.html")

    # Click the "Delete" button for the first item
    delete_button = driver.find_element(
        "css selector", "#itemList li:first-child button[data-action='deleteItem']")
    deleted_username = delete_button.get_attribute("data-username")
    delete_button.click()

    # Wait for a moment to let the item be deleted
    time.sleep(2)

    # Check if the item is not displayed in the list
    item_list = driver.find_element("id", "itemList")
    assert deleted_username not in item_list.text
    print("Delete Password Test Passed Successfully!\n")

def test_alert():
    driver.get(WEBSITE + "index.html")

    # Click the "Alert" button
    alert_button = driver.find_element("id", "alertButton")
    alert_button.click()

    # Wait for a moment to let the alert be displayed
    time.sleep(2)

    # Switch to the alert and accept it
    alert = Alert(driver)
    alertedText = alert.text;
    alert.accept()

    print("Alert Text: ", alertedText)
    print("Alert Test Passed Successfully!\n")

# NavigateToProfileTest - Clicking on Profile link must take the user to the profile page


def test_navigate_to_profile():
    driver.get(WEBSITE + "index.html")
    print("Current URL", driver.current_url)

    # Click the "Profile" link
    profile_link = driver.find_element(By.ID, "profileLink")
    profile_link.click()

    print("Current URL", driver.current_url)

    # Check if the page navigates to the profile page
    assert "profile.html" in driver.current_url

    print("Navigate to Profile Test Passed Successfully!\n")

clear_local_storage()

# Run the tests
test_add_preset()
test_screenshot()
test_responsiveness()
test_add_password()
# test_copy_password()
test_delete_password()
test_alert()
test_navigate_to_profile()

# Close the browser
driver.quit()

# Test 12
# Search An Element

from selenium import webdriver
from selenium.webdriver.common.keys import Keys
import time

driver = webdriver.Chrome(executable_path="F:\\3-2 Projects\\PycharmProjects\\ProjectSeleniumTest\\drivers\\chromedriver.exe")

driver.get("http://127.0.0.1:8000/")
assert "irt-eXpress" in driver.title
driver.maximize_window()

elem = driver.find_element_by_name("search")
elem.clear()
elem.send_keys("Java")
elem.send_keys(Keys.RETURN)
time.sleep(5)

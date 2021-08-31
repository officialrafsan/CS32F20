#Test 4
#Hit our project url & maximize window

from selenium import webdriver
from selenium.webdriver.common.by import By
import time
driver= webdriver.Chrome(executable_path="F:\\3-2 Projects\\PycharmProjects\\ProjectSeleniumTest\\drivers\\chromedriver.exe")

driver.get("http://127.0.0.1:8000")
driver.maximize_window()
print("URL: "+driver.current_url)
print(driver.title)
time.sleep(5)
print("Test Successful")
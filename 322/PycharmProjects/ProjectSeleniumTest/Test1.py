#Test 1
#Hit our project url

from selenium import webdriver
from selenium.webdriver.common.by import By
import time

driver= webdriver.Chrome(executable_path="F:\\3-2 Projects\\PycharmProjects\\ProjectSeleniumTest\\drivers\\chromedriver.exe")

driver.get("http://127.0.0.1:8000")
print("URL: " +driver.current_url)
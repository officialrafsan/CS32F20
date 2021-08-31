#Test 3
# Hit our project url & uap url & back uap url & forward project url

from selenium import webdriver
from selenium.webdriver.common.by import By
import time
driver= webdriver.Chrome(executable_path="F:\\3-2 Projects\\PycharmProjects\\ProjectSeleniumTest\\drivers\\chromedriver.exe")

driver.get("http://127.0.0.1:8000")
print("URL: " +driver.current_url)

print(driver.title)
time.sleep(5)
driver.get("http://www.uap-bd.edu/")
print("URL: " +driver.current_url)
print(driver.title)
time.sleep(5)

driver.back()
print("\nBack to ->")
print(driver.title)
time.sleep(5)

driver.forward()
print("\nForward to ->")
print(driver.title)
time.sleep(5)

#Test 5
#Hit our project login page & register button

from selenium import webdriver
from selenium.webdriver.common.by import By
import time
driver= webdriver.Chrome(executable_path="F:\\3-2 Projects\\PycharmProjects\\ProjectSeleniumTest\\drivers\\chromedriver.exe")
driver.get("http://127.0.0.1:8000/")

driver.find_element(By.ID, "Login").click()
print("click login button\n")

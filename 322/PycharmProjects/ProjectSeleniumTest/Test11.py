# Test11
# Hit the view details

from selenium import webdriver
from selenium.webdriver.common.by import By
import time
driver = webdriver.Chrome(executable_path="F:\\3-2 Projects\\PycharmProjects\\irt-hit\\drivers\\chromedriver.exe")

driver.get("http://127.0.0.1:8000/")
print(driver.current_url)

driver.find_element_by_class_name("btn btn-outline-success").click()
print("Success\n")


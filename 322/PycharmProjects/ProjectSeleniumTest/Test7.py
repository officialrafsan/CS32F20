# Test7
# Hit register part and field email password and confirm wrong password

from selenium import webdriver
from selenium.webdriver.common.keys import Keys
import time

driver = webdriver.Chrome(executable_path="F:\\3-2 Projects\\PycharmProjects\\ProjectSeleniumTest\\drivers\\chromedriver.exe")
driver.get("http://127.0.0.1:8000/register/")

elem = driver.find_element_by_name("username")
elem.clear()
elem.send_keys("rafsan")
elem.send_keys(Keys.RETURN)
time.sleep(5)

elem1 = driver.find_element_by_name("first_name")
elem1.clear()
elem1.send_keys("Hasan")
elem1.send_keys(Keys.RETURN)
time.sleep(5)

elem2 = driver.find_element_by_name("last_name")
elem2.clear()
elem2.send_keys("Rafsan")
elem2.send_keys(Keys.RETURN)
time.sleep(5)

elem3 = driver.find_element_by_name("email")
elem3.clear()
elem3.send_keys("rafsan64@gmail.com")
elem3.send_keys(Keys.RETURN)
time.sleep(5)


elem4 = driver.find_element_by_name("password")
elem4.clear()
elem4.send_keys("tahsincse")
elem4.send_keys(Keys.RETURN)
time.sleep(5)

elem5 = driver.find_element_by_name("confirm_password")
elem5.clear()
elem5.send_keys("tahsin.cse")
elem5.send_keys(Keys.RETURN)
time.sleep(5)

assert "No results found." not in driver.page_source
driver.close()
print("sample test case successfully completed")

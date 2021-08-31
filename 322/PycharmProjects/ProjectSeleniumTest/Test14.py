# Test 14
# View Description of an Item
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
import time

driver = webdriver.Chrome(executable_path="F:\\3-2 Projects\\PycharmProjects\\ProjectSeleniumTest\\drivers\\chromedriver.exe")

driver.get("http://127.0.0.1:8000/login/")
assert "irt-eXpress" in driver.title
driver.maximize_window()

elem = driver.find_element_by_name("username")
elem.clear()
elem.send_keys("admin")
elem.send_keys(Keys.RETURN)
time.sleep(5)

elem2 = driver.find_element_by_name("password")
elem2.clear()
elem2.send_keys("123")
elem2.send_keys(Keys.RETURN)
time.sleep(5)

driver.get("http://127.0.0.1:8000/show_items/1")

driver.find_element(Keys.LINK_TEXT,"btn btn-outline-success").click()
driver.find_element(Keys.LINK_TEXT,"btn btn-success").click()
driver.get("http://127.0.0.1:8000/item_detail/10")

assert "No results found." not in driver.page_source
driver.close()
print("sample test case successfully completed")

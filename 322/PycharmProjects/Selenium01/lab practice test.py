from selenium import webdriver
from selenium.webdriver.common.by import By
import time
from PIL import Image

driver = webdriver.Chrome(executable_path="F:\\3-2 Projects\\PycharmProjects\\Selenium01\\drivers\\chromedriver.exe")

driver.get("https://opensource-demo.orangehrmlive.com/")


element = driver.find_element_by_id("divLogo");
location = element.location;
size = element.size;
driver.save_screenshot("logoImage.png");

# crop image
x = location['x'];
y = location['y'];
width = location['x']+size['width'];
height = location['y']+size['height'];
im = Image.open('logoImage.png')
im = im.crop((int(x), int(y), int(width), int(height)))
im.save('logo-section-Image.png')

driver.quit()







# driver.get("https://opensource-demo.orangehrmlive.com/")
#
# time.sleep(2)
# driver.save_screenshot("image.png")
#
# # Loading the image
# image = Image.open("image.png")
#
# # Showing the iamge
# image.show()
# driver.close()
#



# driver.find_element(By.XPATH, "//input[@id='txtUsername']").send_keys("Admin")
# print("find username field\n")
# driver.find_element(By.CSS_SELECTOR,"input[type='password']").send_keys("admin123")
# print("find password field\n")
# time.sleep(2)
# driver.find_element(By.XPATH, "//input[@value='LOGIN']").click()
# print("find username field\n")
#
# driver.find_element(By.XPATH,"//a[contains(text(),'Welcome')]").click()
# print("find welcome text \n")
# time.sleep(2)
# driver.find_element(By.XPATH,"//a[contains(text(),'About')]").click()
# print("After About ", driver.current_url)
#
#
# assert "login" in driver.current_url
#
# driver.close()

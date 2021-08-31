from selenium import webdriver
from selenium.webdriver.common.by import By
import HtmlTestRunner
import unittest

class TestReport(unittest.TestCase):

    @classmethod
    def setUpClass(cls):
        cls.driver = webdriver.Chrome(executable_path="F:\\3-2 Projects\\PycharmProjects\\Selenium01\\drivers\\chromedriver.exe")
        cls.driver.implicitly_wait(2)

    def Test_Case_1(self):
        self.driver.get("https://opensource-demo.orangehrmlive.com/")
        self.driver.find_element(By.LINK_TEXT,"Forget your password?").click()

    @classmethod
    def tearDownClass(cls):
        cls.driver.close()
        cls.driver.quit()
        print("Test Completed")

if __name__ == '__main__':
    unittest.main(testRunner=HtmlTestRunner.HTMLTestRunner(output="F:/3-2 Projects/PycharmProjects/Selenium01/Reports"))
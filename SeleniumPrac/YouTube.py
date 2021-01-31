import time
from selenium import webdriver
from selenium.webdriver.chrome.options import Options

# Example on POM.
# Essentially, the concept revolves around the notion that
# an object represents a page.
class YouTube(object):

    def __init__(self, driver):
        self.driver = driver
        self.driver.get('https://www.youtube.com/')
        time.sleep(5)

    def interact_with_hamburger(self):
        self.driver.find_element_by_id('guide-button').click()
        time.sleep(5)
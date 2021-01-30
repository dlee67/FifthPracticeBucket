import time
from selenium import webdriver
from selenium.webdriver.chrome.options import Options

chrome_options = Options()
driver = webdriver.Chrome(executable_path='./chromedriver', options=chrome_options)

driver.get('https://www.youtube.com/')
time.sleep(10)  

driver.find_element_by_id('search').send_keys('Lol')

time.sleep(10)
driver.quit()
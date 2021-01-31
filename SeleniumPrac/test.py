from YouTube import YouTube
from selenium import webdriver
from selenium.webdriver.chrome.options import Options

chrome_options = Options()
driver = webdriver.Chrome(executable_path='./chromedriver', options=chrome_options)

youtubePage = YouTube(driver)
youtubePage.interact_with_hamburger()

driver.quit()
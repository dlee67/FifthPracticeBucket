import { browser, by, element } from 'protractor';

describe('your first protractor test', () => {
  it('should load a page and verify the url', () => {
    browser.get('/');
    expect(browser.getCurrentUrl())
        .toEqual(browser.baseUrl);    
  });

  it('should lol', () => {
    element(by.className('some-text')).sendKeys('Some texts.');
    element(by.className('to-project')).click();
    expect(browser.getCurrentUrl()).toEqual('http://localhost:4200/projects');
    // Essentially, whatever Espresso can do (in Android), protractor can also do.
    // Like, "is this UI still there?" or, "after click this UI, expect that UI."
  });
});
import { browser, by, element } from 'protractor';

describe('your first protractor test', () => {
  it('should load a page and verify the url', () => {
    browser.get('/');
    expect(browser.getCurrentUrl())
        .toEqual(browser.baseUrl);    
  });

  it('should lol', () => {
    element(by.className('to-project')).click();
    expect(browser.getCurrentUrl()).toEqual('http://localhost:4200/projects');
  });
});
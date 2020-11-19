import { Component } from '@angular/core';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css']
})
export class AppComponent {
  title = 'scroll-prac';

  ngOnInit(): void {
    document.getElementById('bar').style.setProperty('--gradient', 'linear-gradient(to left, rgba(255, 255, 255, 1) 0%, rgba(255, 255, 255, 0) 100%)');
  }

  onScroll(event): void {
    
    const tab = document.getElementById('bar')
    const offset =  tab.scrollLeft + tab.clientWidth;
    
    if (offset === tab.scrollWidth) {
      tab.style.setProperty('--gradient', 'none');
    } else {
      tab.style.setProperty('--gradient', 'linear-gradient(to left, rgba(255, 255, 255, 1) 0%, rgba(255, 255, 255, 0) 100%)');
    } 
  }
}

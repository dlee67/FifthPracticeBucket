import { TestBed, async, fakeAsync, tick } from '@angular/core/testing';
import { RouterTestingModule } from '@angular/router/testing';
import { FooterComponent } from './footer/footer.component';
import { HeaderComponent } from './header/header.component';
import { HomeComponent } from './home/home.component';
import { ProjectsComponent } from './projects/projects.component';
import { AppComponent } from './app.component';

describe('AppComponent', () => {
  beforeEach(async(() => {
    TestBed.configureTestingModule({
      imports: [
        RouterTestingModule
      ],
      declarations: [
        AppComponent,
        FooterComponent,
        HeaderComponent,
        HomeComponent,
        ProjectsComponent
      ],
    }).compileComponents();
  }));

  it('should tick', fakeAsync(() => { // fakeAsynch ensures that all asynchronous processes are finished, before the next test begins, I think ...
    tick(50);
    console.log("tick");
    tick(50);
    console.log("tock");
    tick(50);
    console.log("tick");
    tick(50);
    console.log("tock");
  }));

  it('should create the app', fakeAsync(() => {
    const fixture = TestBed.createComponent(AppComponent);
    const app = fixture.debugElement.componentInstance;
    expect(app).toBeTruthy();
  }));
});

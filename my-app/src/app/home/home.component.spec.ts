import { async, ComponentFixture, TestBed, fakeAsync, flush, tick } from '@angular/core/testing';

import { Component, DebugElement, Injectable, OnInit } from '@angular/core';
import { By } from '@angular/platform-browser';
import { Location } from '@angular/common';
import { RouterTestingModule } from "@angular/router/testing";
import { Router } from "@angular/router";
import { ProjectsComponent } from '../projects/projects.component';
import { HomeComponent } from './home.component';
import { AppComponent } from '../app.component';
import { HeaderComponent } from '../header/header.component';
import { FooterComponent } from '../footer/footer.component';

describe('HomeComponent', () => {
  let component: HomeComponent;
  let fixture: ComponentFixture<HomeComponent>;
  let router: Router;
  let location: Location;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      imports: [RouterTestingModule.withRoutes([
        { path: '', component: HomeComponent },
        { path: 'projects', component: ProjectsComponent }
      ])],
      declarations: [ HomeComponent, ProjectsComponent]
    })
    .compileComponents();

    router = TestBed.get(Router);
    location = TestBed.get(Location);
    router.navigateByUrl('/');
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(HomeComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  function advance(): void {
    flush(); // flush is used to manually resolve outstanding asynchronous calls after fakeAsync().
    fixture.detectChanges();
  }

  it('should create', () => {
    expect(component).toBeTruthy();
  });

  // According to some Stack Oveflow posts, this is how you test routes.
  it('should goto project', fakeAsync(() => {
    router.navigate(['']);
    advance();
    component.toProjects();
    advance();
    expect(location.path()).toEqual("/projects");
  }));
});

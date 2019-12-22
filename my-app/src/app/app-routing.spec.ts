import { Component, DebugElement, Injectable, OnInit } from '@angular/core';
import { By } from '@angular/platform-browser';
import { Location } from '@angular/common';
import { TestBed, fakeAsync, flush, tick } from '@angular/core/testing';
import { RouterTestingModule } from "@angular/router/testing";
import { Router } from "@angular/router";
import { ProjectsComponent } from './projects/projects.component';
import { HomeComponent } from './home/home.component';
import { AppComponent } from './app.component';
import { HeaderComponent } from './header/header.component';
import { FooterComponent } from './footer/footer.component';

describe('Testing routes', () => {
    let fixture;
    let router: Router;
    let location: Location;

    beforeEach(() => {
        TestBed.configureTestingModule({
            imports: [RouterTestingModule.withRoutes([
                { path: '', component: HomeComponent },
                { path: 'projects', component: ProjectsComponent }
            ])],
            // providers: [{ // They are not needed because I am not using any modules and other aucillary stuff.
            // }],
            declarations: [AppComponent, HomeComponent, ProjectsComponent, HeaderComponent, FooterComponent]
        }).compileComponents();

        router = TestBed.get(Router);
        location = TestBed.get(Location);
        fixture = TestBed.createComponent(AppComponent);
        router.navigateByUrl('/');    
    });

    function advance(): void {
        flush(); // flush is used to manually resolve outstanding asynchronous calls after fakeAsync().
        fixture.detectChanges();
    }
    
    // it('Route to other page', fakeAsync(() => {
    //     router.navigate(['']);
    //     advance(); // Since, changing route is an asynchronous operation, I need to invoke tick() time to time.
    //     const toProject = fixture.debugElement.nativeElement.querySelector("a");
    //     toProject.click();
    //     advance();
    //     expect(location.path()).toEqual("/projects"); // Keeps telling me that location.path() is returning '/'
    // }));
});
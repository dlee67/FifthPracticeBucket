import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';
import { StoreModule } from '@ngrx/store';

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';

import { counterReducer } from './counter.reducer';
import { MyCounterComponent } from './my-counter/my-counter.component';
import { nameReducer } from './name.reducer';

@NgModule({
  declarations: [
    AppComponent,
    MyCounterComponent
  ],
  imports: [
    BrowserModule,
    StoreModule.forRoot(
      { count: counterReducer,name: nameReducer}
    ),
    AppRoutingModule
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }

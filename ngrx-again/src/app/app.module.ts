import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';

import { AppComponent } from './app.component';

import { StoreModule } from '@ngrx/store';
import { counterReducer } from './counter.reducer';
import { nameReducer } from './name.reducer'
import { MyCounterComponent } from './my-counter/my-counter.component';

@NgModule({
  declarations: [AppComponent, MyCounterComponent],
  // The StoreModule.forRoot is what actually registers 
  imports: [BrowserModule, StoreModule.forRoot({ count: counterReducer, name: nameReducer })],
  providers: [],
  bootstrap: [AppComponent],
})
export class AppModule {}
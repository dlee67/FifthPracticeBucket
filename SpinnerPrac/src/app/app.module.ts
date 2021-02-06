import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';
import {MatProgressSpinnerModule} from '@angular/material/progress-spinner';
import {Overlay} from '@angular/cdk/overlay';

import { AppComponent } from './app.component';
import { HeaderComponent } from './components/header/header.component';
import { FooterComponent } from './components/footer/footer.component';
import { NgbModule } from '@ng-bootstrap/ng-bootstrap';
import { SpinnerOverlayComponent } from './components/spinner-overlay/spinner-overlay.component';
import { SpinnerOverlayService } from './services/service-overlay.service'

@NgModule({
  declarations: [
    AppComponent,
    HeaderComponent,
    FooterComponent,
    SpinnerOverlayComponent
  ],
  imports: [
    BrowserModule,
    NgbModule,
    MatProgressSpinnerModule
  ],
  providers: [
    Overlay,
    SpinnerOverlayService
  ],
  entryComponents: [SpinnerOverlayComponent],
  bootstrap: [AppComponent]
})
export class AppModule { }

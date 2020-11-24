import { HttpInterceptor, HttpRequest, HttpHandler, HttpEvent, HttpErrorResponse } from '@angular/common/http';
import { Injectable } from '@angular/core';
import { Observable } from 'rxjs';
import { OAuthService } from '../oauth.service';

@Injectable({
  providedIn: 'root'
})
export class TokenInterceptorService implements HttpInterceptor {

  constructor(public authService: OAuthService) { }

  //https://ultimatecourses.com/blog/intro-to-angular-http-interceptors#:~:text=Interceptors%20are%20a%20unique%20type,the%20value%20of%20the%20request.
  //intercept() always be invoked whenever HTTP request happens.
  intercept(request: HttpRequest<any>, next: HttpHandler): Observable<HttpEvent<any>> {
    console.log('Token being intercepted.');
    request = request.clone({
      setHeaders: {
        Authorization: 'Bearer ' + this.authService.getSavedToken()
      }
    });
    console.log('saved token at: ' + this.authService.getSavedToken());

    return next.handle(request);
  }
}
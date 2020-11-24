import { Injectable } from '@angular/core';
import { HttpClient, HttpHeaders } from '@angular/common/http';
import { throwError, Observable} from 'rxjs';
import {catchError} from 'rxjs/operators';
import { environment } from 'src/environments/environment';


@Injectable({
  providedIn: 'root'
})
export class OAuthService {

constructor(private http:HttpClient) { }


GetAuthPage():Observable<string>
{

return this.http.get<string>(environment.baseUrl+'/AuthPage');
}

getAcessToken(auth_code:string)
{
  this.saveToken(auth_code);
  return this.http.post(environment.baseUrl+'/getAccessToken',{code:auth_code});
}

getSavedToken() {
  return sessionStorage.getItem('token');
}

saveToken(token: string) {
  sessionStorage.setItem('token', token);
} 

getUserDetails()
{
return this.http.get(environment.baseUrl+'/getUserDetails');

}

logout()
{
  return this.http.get(environment.baseUrl+'/logout');
 
}

}

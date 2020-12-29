import { Component } from '@angular/core';

declare var Module: any;

@Component({
    selector: 'app-root',
    templateUrl: './app.component.html',
    styleUrls: ['./app.component.css']
})
export class AppComponent {
    multiplyResult: number;
    getLengthResult: number;

    multiply(a: number, b: number): void {
        // this.multiplyResult = Module.multiply(a, b);
    }

    getLength(s: string): void {
        // this.getLengthResult = Module.get_length(s);
    }
}
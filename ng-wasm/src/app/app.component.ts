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
        this.multiplyResult = Module.multiply(a, b);
    }

    getLength(s: string): void {
        console.log('WASM gave me string: ' + Module.getHello());
        console.log('WASM bool: ' + Module.flipBool(false));
        this.getLengthResult = Module.get_length(s);
    }

    sumOneMillJS(): void {
        console.time()
        let res = 0;
        for (let i = 0; i < 10000000; i++) {
            res += 1
        }
        console.timeEnd();
    }

    sumOneMillWASM(): void {
        console.time()
        Module.sumonemill();
        console.timeEnd()
    }
}
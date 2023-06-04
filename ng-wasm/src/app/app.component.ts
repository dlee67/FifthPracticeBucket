import { Component } from '@angular/core';

declare var Module: any;

@Component({
    selector: 'app-root',
    templateUrl: './app.component.html',
    styleUrls: ['./app.component.css']
})
export class AppComponent {

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

    findMaxWASM(): void {
        console.time()
        const vec = new Module.VectorFloat();
        vec.push_back(1.0);
        vec.push_back(1.0);
        vec.push_back(1.0);
        vec.push_back(1.0);
        vec.push_back(2.0);
        const largestFloat = Module.findLargestFloat(vec);
        console.timeEnd()
        console.log('Largest float at: ' + largestFloat);
    }
    
    findMaxJS(): void {
        console.time()
        let floatArray = [
            1.0, 1.0, 1.0, 1.0, 
            2.0];
        let largest = floatArray[0];
        for (var i = 1; i < floatArray.length; ++i) {
            if (floatArray[i] > largest) {
                largest = floatArray[i];
            }
        }
        console.timeEnd()
        console.log('Largest float at: ' + largest);
    }

}
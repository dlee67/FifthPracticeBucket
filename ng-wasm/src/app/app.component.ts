import { Component } from '@angular/core';

declare var Module: any;

declare namespace ExampleModule {
    function processStringNNumberArray(array: StringNNumber[], len: number): void;
}

interface StringNNumber {
    label: string;
    num: number;
}

@Component({
    selector: 'app-root',
    templateUrl: './app.component.html',
    styleUrls: ['./app.component.css']
})
export class AppComponent {

    public floatArray = [
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
        1.0, 1.0, 1.0, 1.0, 2.0,
    ];

    public someArray: StringNNumber[] = [
        { label: "Item 1", num: 10 },
        { label: "Item 2", num: 20 },
    ];

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
        const largestFloat = Module.findLargestFloat();
        console.timeEnd()
        console.log('Largest float at: ' + largestFloat);
    }
    
    findMaxJSWrapper(): void {
        console.time()
        this.findMaxJS()
        console.timeEnd()
    }

    findMaxJS(): number {
        
        let largest = this.floatArray[0];
        for (var i = 1; i < this.floatArray.length; ++i) {
            if (this.floatArray[i] > largest) {
                largest = this.floatArray[i];
            }
        }
        return largest;
    }
    
    // passJSONObject(): void {
    //     console.log("some array length at: ", this.someArray.length);
    //     console.log("some array label at: ", this.someArray[0].label);
    //     console.log("some array number at: ", this.someArray[0].num);
    //     // This doesn't work.
    //     // https://stackoverflow.com/questions/71681491/passing-arrays-and-objects-from-javascript-to-c-in-web-assembly
    //     // Apparently, there is a way to pass an array of JSON objects to a WASM function, but it's not human friendly.
    //     var someNum = Module._processStringNNumberArray(this.someArray, this.someArray.length);
    //     console.log("lol", someNum);
    // }

    populate(): void {
        Module.populate();
    }
}
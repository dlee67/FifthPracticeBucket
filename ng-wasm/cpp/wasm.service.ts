import { Injectable } from "@angular/core";
import { Observable, BehaviorSubject } from "rxjs";
import { filter, map } from "rxjs/operators";

import * as Module from "./webassembly.js";
import "!!file-loader?name=cpp/webassembly.wasm!../cpp/webassembly.wasm";

@Injectable()
export class WasmService {
  module: any;

  wasmReady = new BehaviorSubject<boolean>(false);

  constructor() {
    this.instantiateWasm();
  }

  private async instantiateWasm() {
    const wasmFile = await fetch("cpp/webassembly.wasm");
    const buffer = await wasmFile.arrayBuffer();
    const binary = new Uint8Array(buffer);

    const moduleArgs = {
        wasmBinary: binary,
        onRuntimeInitialized: () => {
          this.wasmReady.next(true);
        }
    };
    
    this.module = Module(moduleArgs);
}

  public sum_up(): Observable<number> {
    let result = this.wasmReady.pipe(filter(value => value === true)).pipe(
      map(() => {
        
        return this.module.__zone_symbol__value._sum_up([1,2,3]);
      })
    );
    return result;
  }
}

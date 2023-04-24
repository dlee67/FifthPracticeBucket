Huge thanks to: https://componenthouse.com/2018/02/15/how-to-make-angular-and-webassembly-work-together/ <br/>

and the comment section that made everything work. <br/><br/>

Currently uses: ```em++ --bind ./main.cc -s WASM=1 -s "EXPORTED_FUNCTIONS=['_sum_up']" -s "EXPORTED_RUNTIME_METHODS=['ccall','cwrap']" -o .\webassembly.js``` <br/>
to generate the WASM file.

Haven't used: ```em++ -O3 --bind ./main.cc -s WASM=1 -s "EXPORTED_FUNCTIONS=['_sum_up']" -s "EXPORTED_RUNTIME_METHODS=['ccall','cwrap']" -o ./webassembly.js``` yet.
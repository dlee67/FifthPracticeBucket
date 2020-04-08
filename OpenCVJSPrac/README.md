Was able to finally get to somewhere via setting the --emscripten_dir with the below:
/emsdk/fastcomp/emscripten

and execute the below with the above:
python ./platforms/js/build_js.py build_js --build_test

However, without sudo, I noticed that the I can't transpile anything.

Something like ...:
python ./opencv/platforms/js/build_js.py build_js --build_test --emscripten_dir /lol/lol/emsdk/fastcomp/emscripten

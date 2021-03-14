emcc \
  -O3 \
  -s WASM=1 \
  -s "EXTRA_EXPORTED_RUNTIME_METHODS=['ccall']" \
  -o /home/saud/Programming/Code/NEPSE/nepse-web-client/src/assets/prod/prod.js \
  /home/saud/Programming/Code/NEPSE/nepse-web-client/src/assets/prod/main.c

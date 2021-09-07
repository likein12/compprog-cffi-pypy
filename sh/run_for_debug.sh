cp ./src_builders/temp_compile.py ./src_builders/_compile.py
sh ./sh/debug_compile.sh
python3 ./src_builders/source_builder.py COMPILE
echo "testing..."
echo "===input=================="
cat ./input/input.txt
echo "===output================="
pypy3 ./built_files/main.py LOCAL_TEST < ./input/input.txt
rm ./_compprog_cffi.*
srcPath=$1
dstPath=$2

llvm_o=$(find "$srcPath" -name llvm.o)
graalSample_o=$(find "$srcPath" -name GraalSample.o)

echo "Copying to $dstPath:"
[ -f "$llvm_o" ] && cp $llvm_o $dstPath
[ -f "$graalSample_o" ] && cp $graalSample_o $dstPath
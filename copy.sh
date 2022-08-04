srcPath=$1
dstPath=$2

graalSample_o=$(find $srcPath -name GraalSample.o)

echo "Copying to $dstPath:"
[ -f "$graalSample_o" ] && cp $graalSample_o $dstPath
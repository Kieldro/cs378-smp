# file variables
source="RunSMP.c++"
unitFile="TestSMP.c++"
inFile="RunSMP.in"
outFile="RunSMP.out"
compile=true
unit=false

if $unit; then
	echo UNIT TESTS...
	g++ -ansi -pedantic -lcppunit -ldl -Wall $unitFile -o $unitFile.app
	valgrind $unitFile.app >& $unitFile.out
fi

echo COMPILING...
g++ -ansi -pedantic -Wall $source -o $source.app

echo RUNNING PROGRAM...
$source.app < $inFile #>& $outFile
#valgrind $source.app < $inFile >& $outFile

echo CHECKING OUTPUT...; diff -lc RunSMP.out RunSMP.in

echo GENERATING COMMIT LOG...
git log > SMP.log

#echo RUNNING DOXYGEN...; doxygen Doxyfile

<<MULTICOMMENT
free comments!source

#echo UPDATING SPHERECOLLATZ FILE...; cp $source Sphere$source

zip SMP README.txt html/* RunSMP.c++ RunSMP.h RunSMP.in RunSMP.out SMP.h SMP.log SphereSMP.c++ TestSMP.c++ TestSMP.out

turnin --submit inbleric cs378pj2 SMP.zip

MULTICOMMENT
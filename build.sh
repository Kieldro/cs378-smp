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
git log > Collatz.log

#echo RUNNING DOXYGEN...; doxygen Doxyfile

<<MULTICOMMENT
free comments!source

MULTICOMMENT

#echo UPDATING SPHERECOLLATZ FILE...; cp $source Sphere$
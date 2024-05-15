#!/bin/bash

#untar your crap
echo "Untaring  directory with analyzer code"
tar -xf cmsswTar.tar.gz
cd CMSSW_10_6_30/src/llp_analyzer

#Arguments taken
#1 - the eos directory to drop the output
#2 - the sample text file
#3 - the output file name

#Running the selection maker
echo "Beginning analysis"
./RazorRun $2 HSCPAnalyzer_METStudies -f=$3 -d=no

for FILE in *.root
do
    echo ${FILE}
    echo "copying ${FILE} to eos $1"
    xrdcp ${FILE} $1/${FILE}
    XRDEXIT=$?
    if [[ $XRDEXIT -ne 0 ]]; then
	rm ${FILE}
	echo "failure in xrdcp, exit code $XRDEXIT"
	exit $XRDEXIT
    fi
    rm ${FILE}
done


#cleanup
cd ${_CONDOR_SCRATCH_DIR_}
rm -rf CMSSW_10_6_30
rm cmsswTar.tar.gz


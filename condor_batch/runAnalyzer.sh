#!/bin/bash

export X509_CERT_DIR=/cvmfs/grid.cern.ch/etc/grid-security/certificates/

#Print stuff about the job
echo "Starting job on " `date` #Date/time of start of job
echo "Running on: `uname -a`" #Condor job is running on this node
echo "System software: `cat /etc/redhat-release`" #Operating System on that node

#untar your crap
source /cvmfs/cms.cern.ch/cmsset_default.sh
echo "Untaring  directory with analyzer code"
tar -xf cmsswTar.tar.gz
cd CMSSW_10_6_30/src/llp_analyzer
scram b ProjectRename
cmsenv

#Arguments taken
#1 - the eos directory to drop the output
#2 - the sample text file
#3 - the output file name

#Running the selection maker
echo "Beginning analysis"
echo "Saving in directory:"
echo $1
echo "Using as list executable:"
echo $2
echo "(Desired) output file:"
echo $3
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


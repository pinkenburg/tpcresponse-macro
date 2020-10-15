# Welcome Dmitri

this is just a scratch repo with the macro to run the tpc response simulator on the sPHENIX TPC hits

First source the sphenix setup macro (works with any account, PHENIX or STAR, sPHENIX account needs to source the sh script), -n wipes out the previous sphenix/phenix environment (good for refreshing):

source /opt/sphenix/core/bin/sphenix_setup.csh -n

By default the Fun4All_G4_TpcResponse.C uses a min bias hijing file which contains tons of hits. The checked in G4sPHENIX.root is created with single particles. The file is the second argument, so

.x Fun4All_G4_TpcResponse.C(1,"G4sPHENIX.root") will read this file instead

the module code is in coresoftware/simulation/g4simulation/tpcresponse
the tpcrs lib and includes are installed centrally and copied from there to $OFFLINE_MAIN, a private installation in your install area should work
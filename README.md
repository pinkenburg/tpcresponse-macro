# Welcome Dmitri

this is just a scratch repo with the macro to run the tpc response simulator on the sPHENIX TPC hits


By default the Fun4All_G4_TpcResponse.C uses a min bias hijing file which contains tons of hits. The checked in G4sPHENIX.root is created with single particles. The file is the second argument, so

.x Fun4All_G4_TpcResponse.C(1,"G4sPHENIX.root") will read this file instead
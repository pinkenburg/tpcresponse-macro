#ifndef FUN4ALL_G4_TPCRESPONSE_C
#define FUN4ALL_G4_TPCRESPONSE_C

#include <tpcresponse/TpcRS.h>

#include <fun4all/Fun4AllDstInputManager.h>
#include <fun4all/Fun4AllInputManager.h>
#include <fun4all/Fun4AllServer.h>

R__LOAD_LIBRARY(libfun4all.so)
R__LOAD_LIBRARY(libtpcresponse.so)
R__LOAD_LIBRARY(libtpcrs.so)

void Fun4All_G4_TpcResponse(const int nevnt, const std::string &infile = "/sphenix/sim/sim01/sphnxpro/Micromegas/3/G4Hits_sHijing_0-12fm_000000_001000.root")
{
gSystem->Load("libg4dst.so");
Fun4AllServer *se = Fun4AllServer::instance();

TpcRS *rs = new TpcRS();
rs->SetupConfigurator("starY14_AuAu200b.yaml");
se->registerSubsystem(rs);
Fun4AllInputManager *hitsin = new Fun4AllDstInputManager("DSTin");
hitsin->fileopen(infile);  
se->registerInputManager(hitsin);
if (nevnt < 0)
{
return;
}
se->run(nevnt);
se->End();
delete se;
gSystem->Exit(0);

}

#endif

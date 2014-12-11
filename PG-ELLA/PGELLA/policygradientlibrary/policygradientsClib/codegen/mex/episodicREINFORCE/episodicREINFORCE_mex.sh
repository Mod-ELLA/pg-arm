MATLAB="/Applications/MATLAB_R2013b.app"
Arch=maci64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/Users/haithambouammar/.matlab/R2013b"
OPTSFILE_NAME="./mexopts.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for episodicREINFORCE" > episodicREINFORCE_mex.mki
echo "CC=$CC" >> episodicREINFORCE_mex.mki
echo "CFLAGS=$CFLAGS" >> episodicREINFORCE_mex.mki
echo "CLIBS=$CLIBS" >> episodicREINFORCE_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> episodicREINFORCE_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> episodicREINFORCE_mex.mki
echo "CXX=$CXX" >> episodicREINFORCE_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> episodicREINFORCE_mex.mki
echo "CXXLIBS=$CXXLIBS" >> episodicREINFORCE_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> episodicREINFORCE_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> episodicREINFORCE_mex.mki
echo "LD=$LD" >> episodicREINFORCE_mex.mki
echo "LDFLAGS=$LDFLAGS" >> episodicREINFORCE_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> episodicREINFORCE_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> episodicREINFORCE_mex.mki
echo "Arch=$Arch" >> episodicREINFORCE_mex.mki
echo OMPFLAGS= >> episodicREINFORCE_mex.mki
echo OMPLINKFLAGS= >> episodicREINFORCE_mex.mki
echo "EMC_COMPILER=" >> episodicREINFORCE_mex.mki
echo "EMC_CONFIG=optim" >> episodicREINFORCE_mex.mki
"/Applications/MATLAB_R2013b.app/bin/maci64/gmake" -B -f episodicREINFORCE_mex.mk

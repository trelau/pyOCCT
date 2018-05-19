# Manually provide the SMESH modules since the library names may not match up
# exactly with the module names based on the header file names. The
# SMESH_LIBRARIES should be found by find_package(SMESH).
set(SMESH_MODULES
    BaseTraceCollector
    BasicsGenericDestructor
    BLSURFPlugin
    Driver
    DriverDAT
    DriverGMF
    DriverSTL
    DriverUNV
    LocalTraceBufferPool
    NETGENPlugin
    SMDS
    SMDSAbs
    SMESH
    SMESHDS
    StdMeshers
    Utils
)

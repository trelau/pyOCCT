# This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
# geometry kernel.
#
# Copyright (C) 2016-2018  Laughlin Research, LLC (info@laughlinresearch.com)
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA
import unittest


class TestModuleImport(unittest.TestCase):
    """
    Test import of each module.
    """

    def test_Adaptor2d(self):
        try:
            import OCCT.Adaptor2d
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_Adaptor3d(self):
        try:
            import OCCT.Adaptor3d
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_AdvApp2Var(self):
        try:
            import OCCT.AdvApp2Var
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_AdvApprox(self):
        try:
            import OCCT.AdvApprox
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_AIS(self):
        try:
            import OCCT.AIS
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_APIHeaderSection(self):
        try:
            import OCCT.APIHeaderSection
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_AppBlend(self):
        try:
            import OCCT.AppBlend
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_AppCont(self):
        try:
            import OCCT.AppCont
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_AppDef(self):
        try:
            import OCCT.AppDef
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_AppParCurves(self):
        try:
            import OCCT.AppParCurves
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_Approx(self):
        try:
            import OCCT.Approx
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_ApproxInt(self):
        try:
            import OCCT.ApproxInt
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_AppStd(self):
        try:
            import OCCT.AppStd
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_AppStdL(self):
        try:
            import OCCT.AppStdL
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_Aspect(self):
        try:
            import OCCT.Aspect
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_BaseTraceCollector(self):
        try:
            import OCCT.BaseTraceCollector
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_BasicsGenericDestructor(self):
        try:
            import OCCT.BasicsGenericDestructor
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_BinDrivers(self):
        try:
            import OCCT.BinDrivers
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_BinLDrivers(self):
        try:
            import OCCT.BinLDrivers
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_BinMDataStd(self):
        try:
            import OCCT.BinMDataStd
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_BinMDataXtd(self):
        try:
            import OCCT.BinMDataXtd
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_BinMDF(self):
        try:
            import OCCT.BinMDF
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_BinMDocStd(self):
        try:
            import OCCT.BinMDocStd
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_BinMFunction(self):
        try:
            import OCCT.BinMFunction
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_BinMNaming(self):
        try:
            import OCCT.BinMNaming
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_BinMXCAFDoc(self):
        try:
            import OCCT.BinMXCAFDoc
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_BinObjMgt(self):
        try:
            import OCCT.BinObjMgt
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_BinTObjDrivers(self):
        try:
            import OCCT.BinTObjDrivers
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_BinTools(self):
        try:
            import OCCT.BinTools
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_BinXCAFDrivers(self):
        try:
            import OCCT.BinXCAFDrivers
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_Bisector(self):
        try:
            import OCCT.Bisector
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_BiTgte(self):
        try:
            import OCCT.BiTgte
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_Blend(self):
        try:
            import OCCT.Blend
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_BlendFunc(self):
        try:
            import OCCT.BlendFunc
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_Bnd(self):
        try:
            import OCCT.Bnd
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_BndLib(self):
        try:
            import OCCT.BndLib
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_BOPAlgo(self):
        try:
            import OCCT.BOPAlgo
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_BOPCol(self):
        try:
            import OCCT.BOPCol
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_BOPDS(self):
        try:
            import OCCT.BOPDS
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_BOPTools(self):
        try:
            import OCCT.BOPTools
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_BRep(self):
        try:
            import OCCT.BRep
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_BRepAdaptor(self):
        try:
            import OCCT.BRepAdaptor
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_BRepAlgo(self):
        try:
            import OCCT.BRepAlgo
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_BRepAlgoAPI(self):
        try:
            import OCCT.BRepAlgoAPI
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_BRepApprox(self):
        try:
            import OCCT.BRepApprox
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_BRepBlend(self):
        try:
            import OCCT.BRepBlend
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_BRepBndLib(self):
        try:
            import OCCT.BRepBndLib
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_BRepBuilderAPI(self):
        try:
            import OCCT.BRepBuilderAPI
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_BRepCheck(self):
        try:
            import OCCT.BRepCheck
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_BRepClass(self):
        try:
            import OCCT.BRepClass
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_BRepClass3d(self):
        try:
            import OCCT.BRepClass3d
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_BRepExtrema(self):
        try:
            import OCCT.BRepExtrema
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_BRepFeat(self):
        try:
            import OCCT.BRepFeat
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_BRepFill(self):
        try:
            import OCCT.BRepFill
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_BRepFilletAPI(self):
        try:
            import OCCT.BRepFilletAPI
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_BRepGProp(self):
        try:
            import OCCT.BRepGProp
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_BRepIntCurveSurface(self):
        try:
            import OCCT.BRepIntCurveSurface
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_BRepLib(self):
        try:
            import OCCT.BRepLib
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_BRepLProp(self):
        try:
            import OCCT.BRepLProp
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_BRepMAT2d(self):
        try:
            import OCCT.BRepMAT2d
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_BRepMesh(self):
        try:
            import OCCT.BRepMesh
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_BRepOffset(self):
        try:
            import OCCT.BRepOffset
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_BRepOffsetAPI(self):
        try:
            import OCCT.BRepOffsetAPI
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_BRepPrim(self):
        try:
            import OCCT.BRepPrim
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_BRepPrimAPI(self):
        try:
            import OCCT.BRepPrimAPI
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_BRepProj(self):
        try:
            import OCCT.BRepProj
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_BRepSweep(self):
        try:
            import OCCT.BRepSweep
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_BRepToIGES(self):
        try:
            import OCCT.BRepToIGES
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_BRepToIGESBRep(self):
        try:
            import OCCT.BRepToIGESBRep
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_BRepTools(self):
        try:
            import OCCT.BRepTools
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_BRepTopAdaptor(self):
        try:
            import OCCT.BRepTopAdaptor
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_BSplCLib(self):
        try:
            import OCCT.BSplCLib
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_BSplSLib(self):
        try:
            import OCCT.BSplSLib
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_BVH(self):
        try:
            import OCCT.BVH
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_CDF(self):
        try:
            import OCCT.CDF
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_CDM(self):
        try:
            import OCCT.CDM
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_ChFi2d(self):
        try:
            import OCCT.ChFi2d
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_ChFi3d(self):
        try:
            import OCCT.ChFi3d
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_ChFiDS(self):
        try:
            import OCCT.ChFiDS
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_ChFiKPart(self):
        try:
            import OCCT.ChFiKPart
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_Cocoa(self):
        try:
            import OCCT.Cocoa
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_Contap(self):
        try:
            import OCCT.Contap
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_Convert(self):
        try:
            import OCCT.Convert
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_CPnts(self):
        try:
            import OCCT.CPnts
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_CSLib(self):
        try:
            import OCCT.CSLib
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_Draft(self):
        try:
            import OCCT.Draft
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_Driver(self):
        try:
            import OCCT.Driver
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_DriverDAT(self):
        try:
            import OCCT.DriverDAT
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_DriverGMF(self):
        try:
            import OCCT.DriverGMF
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_DriverSTL(self):
        try:
            import OCCT.DriverSTL
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_DriverUNV(self):
        try:
            import OCCT.DriverUNV
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_DsgPrs(self):
        try:
            import OCCT.DsgPrs
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_ElCLib(self):
        try:
            import OCCT.ElCLib
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_ElSLib(self):
        try:
            import OCCT.ElSLib
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_Expr(self):
        try:
            import OCCT.Expr
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_ExprIntrp(self):
        try:
            import OCCT.ExprIntrp
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_Extrema(self):
        try:
            import OCCT.Extrema
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_FairCurve(self):
        try:
            import OCCT.FairCurve
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_FEmTool(self):
        try:
            import OCCT.FEmTool
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_FilletSurf(self):
        try:
            import OCCT.FilletSurf
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_Font(self):
        try:
            import OCCT.Font
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_FSD(self):
        try:
            import OCCT.FSD
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_GC(self):
        try:
            import OCCT.GC
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_GccAna(self):
        try:
            import OCCT.GccAna
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_GccEnt(self):
        try:
            import OCCT.GccEnt
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_GccInt(self):
        try:
            import OCCT.GccInt
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_gce(self):
        try:
            import OCCT.gce
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_GCE2d(self):
        try:
            import OCCT.GCE2d
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_GCPnts(self):
        try:
            import OCCT.GCPnts
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_Geom(self):
        try:
            import OCCT.Geom
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_Geom2d(self):
        try:
            import OCCT.Geom2d
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_Geom2dAdaptor(self):
        try:
            import OCCT.Geom2dAdaptor
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_Geom2dAPI(self):
        try:
            import OCCT.Geom2dAPI
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_Geom2dConvert(self):
        try:
            import OCCT.Geom2dConvert
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_Geom2dEvaluator(self):
        try:
            import OCCT.Geom2dEvaluator
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_Geom2dGcc(self):
        try:
            import OCCT.Geom2dGcc
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_Geom2dHatch(self):
        try:
            import OCCT.Geom2dHatch
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_Geom2dInt(self):
        try:
            import OCCT.Geom2dInt
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_Geom2dLProp(self):
        try:
            import OCCT.Geom2dLProp
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_Geom2dToIGES(self):
        try:
            import OCCT.Geom2dToIGES
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_GeomAbs(self):
        try:
            import OCCT.GeomAbs
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_GeomAdaptor(self):
        try:
            import OCCT.GeomAdaptor
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_GeomAPI(self):
        try:
            import OCCT.GeomAPI
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_GeomConvert(self):
        try:
            import OCCT.GeomConvert
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_GeomEvaluator(self):
        try:
            import OCCT.GeomEvaluator
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_GeomFill(self):
        try:
            import OCCT.GeomFill
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_GeomInt(self):
        try:
            import OCCT.GeomInt
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_GeomLib(self):
        try:
            import OCCT.GeomLib
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_GeomLProp(self):
        try:
            import OCCT.GeomLProp
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_GeomPlate(self):
        try:
            import OCCT.GeomPlate
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_GeomProjLib(self):
        try:
            import OCCT.GeomProjLib
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_GeomToIGES(self):
        try:
            import OCCT.GeomToIGES
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_GeomTools(self):
        try:
            import OCCT.GeomTools
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_GeomToStep(self):
        try:
            import OCCT.GeomToStep
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_gp(self):
        try:
            import OCCT.gp
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_GProp(self):
        try:
            import OCCT.GProp
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_Graphic3d(self):
        try:
            import OCCT.Graphic3d
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_Hatch(self):
        try:
            import OCCT.Hatch
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_HatchGen(self):
        try:
            import OCCT.HatchGen
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_HeaderSection(self):
        try:
            import OCCT.HeaderSection
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_Hermit(self):
        try:
            import OCCT.Hermit
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_HLRAlgo(self):
        try:
            import OCCT.HLRAlgo
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_HLRAppli(self):
        try:
            import OCCT.HLRAppli
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_HLRBRep(self):
        try:
            import OCCT.HLRBRep
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_HLRTopoBRep(self):
        try:
            import OCCT.HLRTopoBRep
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_IFGraph(self):
        try:
            import OCCT.IFGraph
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_IFSelect(self):
        try:
            import OCCT.IFSelect
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_IGESAppli(self):
        try:
            import OCCT.IGESAppli
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_IGESBasic(self):
        try:
            import OCCT.IGESBasic
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_IGESCAFControl(self):
        try:
            import OCCT.IGESCAFControl
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_IGESControl(self):
        try:
            import OCCT.IGESControl
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_IGESConvGeom(self):
        try:
            import OCCT.IGESConvGeom
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_IGESData(self):
        try:
            import OCCT.IGESData
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_IGESDefs(self):
        try:
            import OCCT.IGESDefs
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_IGESDimen(self):
        try:
            import OCCT.IGESDimen
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_IGESDraw(self):
        try:
            import OCCT.IGESDraw
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_IGESFile(self):
        try:
            import OCCT.IGESFile
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_IGESGeom(self):
        try:
            import OCCT.IGESGeom
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_IGESGraph(self):
        try:
            import OCCT.IGESGraph
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_IGESSelect(self):
        try:
            import OCCT.IGESSelect
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_IGESSolid(self):
        try:
            import OCCT.IGESSolid
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_IGESToBRep(self):
        try:
            import OCCT.IGESToBRep
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_Image(self):
        try:
            import OCCT.Image
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_IntAna(self):
        try:
            import OCCT.IntAna
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_IntAna2d(self):
        try:
            import OCCT.IntAna2d
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_IntCurve(self):
        try:
            import OCCT.IntCurve
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_IntCurvesFace(self):
        try:
            import OCCT.IntCurvesFace
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_IntCurveSurface(self):
        try:
            import OCCT.IntCurveSurface
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_Interface(self):
        try:
            import OCCT.Interface
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_Intf(self):
        try:
            import OCCT.Intf
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_IntImp(self):
        try:
            import OCCT.IntImp
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_IntImpParGen(self):
        try:
            import OCCT.IntImpParGen
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_IntPatch(self):
        try:
            import OCCT.IntPatch
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_IntPolyh(self):
        try:
            import OCCT.IntPolyh
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_IntRes2d(self):
        try:
            import OCCT.IntRes2d
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_Intrv(self):
        try:
            import OCCT.Intrv
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_IntStart(self):
        try:
            import OCCT.IntStart
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_IntSurf(self):
        try:
            import OCCT.IntSurf
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_IntTools(self):
        try:
            import OCCT.IntTools
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_IntWalk(self):
        try:
            import OCCT.IntWalk
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_Law(self):
        try:
            import OCCT.Law
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_LDOM(self):
        try:
            import OCCT.LDOM
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_LDOMBasicString(self):
        try:
            import OCCT.LDOMBasicString
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_LDOMParser(self):
        try:
            import OCCT.LDOMParser
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_LDOMString(self):
        try:
            import OCCT.LDOMString
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_LocalAnalysis(self):
        try:
            import OCCT.LocalAnalysis
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_LocalTraceBufferPool(self):
        try:
            import OCCT.LocalTraceBufferPool
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_LocOpe(self):
        try:
            import OCCT.LocOpe
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_LProp(self):
        try:
            import OCCT.LProp
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_LProp3d(self):
        try:
            import OCCT.LProp3d
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_MAT(self):
        try:
            import OCCT.MAT
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_MAT2d(self):
        try:
            import OCCT.MAT2d
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_math(self):
        try:
            import OCCT.math
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_MeshVS(self):
        try:
            import OCCT.MeshVS
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_Message(self):
        try:
            import OCCT.Message
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_MMgt(self):
        try:
            import OCCT.MMgt
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_MoniTool(self):
        try:
            import OCCT.MoniTool
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_NCollection(self):
        try:
            import OCCT.NCollection
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_NETGENPlugin(self):
        try:
            import OCCT.NETGENPlugin
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_NLPlate(self):
        try:
            import OCCT.NLPlate
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_ObjectPool(self):
        try:
            import OCCT.ObjectPool
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_OpenGl(self):
        try:
            import OCCT.OpenGl
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_OSD(self):
        try:
            import OCCT.OSD
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_PCDM(self):
        try:
            import OCCT.PCDM
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_Plate(self):
        try:
            import OCCT.Plate
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_PLib(self):
        try:
            import OCCT.PLib
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_Plugin(self):
        try:
            import OCCT.Plugin
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_Poly(self):
        try:
            import OCCT.Poly
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_Precision(self):
        try:
            import OCCT.Precision
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_ProjLib(self):
        try:
            import OCCT.ProjLib
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_Prs3d(self):
        try:
            import OCCT.Prs3d
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_PrsMgr(self):
        try:
            import OCCT.PrsMgr
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_Quantity(self):
        try:
            import OCCT.Quantity
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_Resource(self):
        try:
            import OCCT.Resource
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_RWHeaderSection(self):
        try:
            import OCCT.RWHeaderSection
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_RWStepAP203(self):
        try:
            import OCCT.RWStepAP203
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_RWStepAP214(self):
        try:
            import OCCT.RWStepAP214
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_RWStepAP242(self):
        try:
            import OCCT.RWStepAP242
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_RWStepBasic(self):
        try:
            import OCCT.RWStepBasic
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_RWStepDimTol(self):
        try:
            import OCCT.RWStepDimTol
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_RWStepElement(self):
        try:
            import OCCT.RWStepElement
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_RWStepFEA(self):
        try:
            import OCCT.RWStepFEA
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_RWStepGeom(self):
        try:
            import OCCT.RWStepGeom
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_RWStepRepr(self):
        try:
            import OCCT.RWStepRepr
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_RWStepShape(self):
        try:
            import OCCT.RWStepShape
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_RWStepVisual(self):
        try:
            import OCCT.RWStepVisual
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_RWStl(self):
        try:
            import OCCT.RWStl
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_Select3D(self):
        try:
            import OCCT.Select3D
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_SelectBasics(self):
        try:
            import OCCT.SelectBasics
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_SelectMgr(self):
        try:
            import OCCT.SelectMgr
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_ShapeAlgo(self):
        try:
            import OCCT.ShapeAlgo
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_ShapeAnalysis(self):
        try:
            import OCCT.ShapeAnalysis
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_ShapeBuild(self):
        try:
            import OCCT.ShapeBuild
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_ShapeConstruct(self):
        try:
            import OCCT.ShapeConstruct
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_ShapeCustom(self):
        try:
            import OCCT.ShapeCustom
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_ShapeExtend(self):
        try:
            import OCCT.ShapeExtend
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_ShapeFix(self):
        try:
            import OCCT.ShapeFix
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_ShapeProcess(self):
        try:
            import OCCT.ShapeProcess
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_ShapeProcessAPI(self):
        try:
            import OCCT.ShapeProcessAPI
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_ShapeUpgrade(self):
        try:
            import OCCT.ShapeUpgrade
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_SMDS(self):
        try:
            import OCCT.SMDS
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_SMDSAbs(self):
        try:
            import OCCT.SMDSAbs
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_SMESH(self):
        try:
            import OCCT.SMESH
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_SMESHDS(self):
        try:
            import OCCT.SMESHDS
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_Standard(self):
        try:
            import OCCT.Standard
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_StdDrivers(self):
        try:
            import OCCT.StdDrivers
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_StdFail(self):
        try:
            import OCCT.StdFail
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_StdLDrivers(self):
        try:
            import OCCT.StdLDrivers
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_StdLPersistent(self):
        try:
            import OCCT.StdLPersistent
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_StdMeshers(self):
        try:
            import OCCT.StdMeshers
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_StdObject(self):
        try:
            import OCCT.StdObject
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_StdObjMgt(self):
        try:
            import OCCT.StdObjMgt
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_StdPersistent(self):
        try:
            import OCCT.StdPersistent
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_StdPrs(self):
        try:
            import OCCT.StdPrs
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_StdSelect(self):
        try:
            import OCCT.StdSelect
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_StdStorage(self):
        try:
            import OCCT.StdStorage
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_StepAP203(self):
        try:
            import OCCT.StepAP203
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_StepAP209(self):
        try:
            import OCCT.StepAP209
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_StepAP214(self):
        try:
            import OCCT.StepAP214
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_StepAP242(self):
        try:
            import OCCT.StepAP242
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_StepBasic(self):
        try:
            import OCCT.StepBasic
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_STEPCAFControl(self):
        try:
            import OCCT.STEPCAFControl
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_STEPConstruct(self):
        try:
            import OCCT.STEPConstruct
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_STEPControl(self):
        try:
            import OCCT.STEPControl
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_StepData(self):
        try:
            import OCCT.StepData
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_StepDimTol(self):
        try:
            import OCCT.StepDimTol
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_STEPEdit(self):
        try:
            import OCCT.STEPEdit
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_StepElement(self):
        try:
            import OCCT.StepElement
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_StepFEA(self):
        try:
            import OCCT.StepFEA
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_StepFile(self):
        try:
            import OCCT.StepFile
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_StepGeom(self):
        try:
            import OCCT.StepGeom
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_StepRepr(self):
        try:
            import OCCT.StepRepr
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_StepSelect(self):
        try:
            import OCCT.StepSelect
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_STEPSelections(self):
        try:
            import OCCT.STEPSelections
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_StepShape(self):
        try:
            import OCCT.StepShape
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_StepToGeom(self):
        try:
            import OCCT.StepToGeom
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_StepToTopoDS(self):
        try:
            import OCCT.StepToTopoDS
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_StepVisual(self):
        try:
            import OCCT.StepVisual
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_StlAPI(self):
        try:
            import OCCT.StlAPI
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_Storage(self):
        try:
            import OCCT.Storage
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_Sweep(self):
        try:
            import OCCT.Sweep
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_TColGeom(self):
        try:
            import OCCT.TColGeom
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_TColGeom2d(self):
        try:
            import OCCT.TColGeom2d
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_TColgp(self):
        try:
            import OCCT.TColgp
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_TCollection(self):
        try:
            import OCCT.TCollection
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_TColQuantity(self):
        try:
            import OCCT.TColQuantity
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_TColStd(self):
        try:
            import OCCT.TColStd
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_TDataStd(self):
        try:
            import OCCT.TDataStd
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_TDataXtd(self):
        try:
            import OCCT.TDataXtd
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_TDF(self):
        try:
            import OCCT.TDF
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_TDocStd(self):
        try:
            import OCCT.TDocStd
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_TFunction(self):
        try:
            import OCCT.TFunction
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_TNaming(self):
        try:
            import OCCT.TNaming
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_TObj(self):
        try:
            import OCCT.TObj
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_TopAbs(self):
        try:
            import OCCT.TopAbs
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_TopBas(self):
        try:
            import OCCT.TopBas
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_TopClass(self):
        try:
            import OCCT.TopClass
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_TopCnx(self):
        try:
            import OCCT.TopCnx
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_TopExp(self):
        try:
            import OCCT.TopExp
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_TopLoc(self):
        try:
            import OCCT.TopLoc
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_TopoDS(self):
        try:
            import OCCT.TopoDS
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_TopoDSToStep(self):
        try:
            import OCCT.TopoDSToStep
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_TopOpeBRep(self):
        try:
            import OCCT.TopOpeBRep
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_TopOpeBRepBuild(self):
        try:
            import OCCT.TopOpeBRepBuild
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_TopOpeBRepDS(self):
        try:
            import OCCT.TopOpeBRepDS
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_TopOpeBRepTool(self):
        try:
            import OCCT.TopOpeBRepTool
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_TopTools(self):
        try:
            import OCCT.TopTools
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_TopTrans(self):
        try:
            import OCCT.TopTrans
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_TPrsStd(self):
        try:
            import OCCT.TPrsStd
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_Transfer(self):
        try:
            import OCCT.Transfer
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_TransferBRep(self):
        try:
            import OCCT.TransferBRep
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_TShort(self):
        try:
            import OCCT.TShort
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_Units(self):
        try:
            import OCCT.Units
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_UnitsAPI(self):
        try:
            import OCCT.UnitsAPI
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_UnitsMethods(self):
        try:
            import OCCT.UnitsMethods
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    @unittest.expectedFailure
    def test_Utils(self):
        try:
            import OCCT.Utils
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_UTL(self):
        try:
            import OCCT.UTL
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_V3d(self):
        try:
            import OCCT.V3d
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_Vrml(self):
        try:
            import OCCT.Vrml
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_VrmlAPI(self):
        try:
            import OCCT.VrmlAPI
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_VrmlConverter(self):
        try:
            import OCCT.VrmlConverter
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_VrmlData(self):
        try:
            import OCCT.VrmlData
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_WNT(self):
        try:
            import OCCT.WNT
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_XBRepMesh(self):
        try:
            import OCCT.XBRepMesh
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_XCAFApp(self):
        try:
            import OCCT.XCAFApp
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_XCAFDimTolObjects(self):
        try:
            import OCCT.XCAFDimTolObjects
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_XCAFDoc(self):
        try:
            import OCCT.XCAFDoc
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_XCAFPrs(self):
        try:
            import OCCT.XCAFPrs
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_XCAFView(self):
        try:
            import OCCT.XCAFView
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_XmlDrivers(self):
        try:
            import OCCT.XmlDrivers
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_XmlLDrivers(self):
        try:
            import OCCT.XmlLDrivers
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_XmlMDataStd(self):
        try:
            import OCCT.XmlMDataStd
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_XmlMDataXtd(self):
        try:
            import OCCT.XmlMDataXtd
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_XmlMDF(self):
        try:
            import OCCT.XmlMDF
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_XmlMDocStd(self):
        try:
            import OCCT.XmlMDocStd
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_XmlMFunction(self):
        try:
            import OCCT.XmlMFunction
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_XmlMNaming(self):
        try:
            import OCCT.XmlMNaming
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_XmlMXCAFDoc(self):
        try:
            import OCCT.XmlMXCAFDoc
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_XmlObjMgt(self):
        try:
            import OCCT.XmlObjMgt
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_XmlTObjDrivers(self):
        try:
            import OCCT.XmlTObjDrivers
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_XmlXCAFDrivers(self):
        try:
            import OCCT.XmlXCAFDrivers
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_XSAlgo(self):
        try:
            import OCCT.XSAlgo
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)

    def test_XSControl(self):
        try:
            import OCCT.XSControl
            mod_ok = True
        except ImportError:
            mod_ok = False
        self.assertTrue(mod_ok)


if __name__ == '__main__':
    unittest.main()

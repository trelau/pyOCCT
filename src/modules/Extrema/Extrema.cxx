/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC
Copyright (C) 2019 Trevor Laughlin and the pyOCCT contributors

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include <pyOCCT_Common.hxx>

void bind_Extrema_ExtFlag(py::module &);
void bind_Extrema_ExtAlgo(py::module &);
void bind_Extrema_ElementType(py::module &);
void bind_Extrema_ECC(py::module &);
void bind_Extrema_POnCurv(py::module &);
void bind_Extrema_SequenceOfPOnCurv(py::module &);
void bind_Extrema_ExtCC(py::module &);
void bind_Extrema_Array1OfPOnCurv(py::module &);
void bind_Extrema_HArray1OfPOnCurv(py::module &);
void bind_Extrema_POnSurf(py::module &);
void bind_Extrema_Array1OfPOnSurf(py::module &);
void bind_Extrema_HArray1OfPOnSurf(py::module &);
void bind_Extrema_ExtElCS(py::module &);
void bind_Extrema_SequenceOfPOnSurf(py::module &);
void bind_Extrema_ExtCS(py::module &);
void bind_Extrema_ExtElSS(py::module &);
void bind_Extrema_ExtSS(py::module &);
void bind_Extrema_ExtPElC(py::module &);
void bind_Extrema_PCFOfEPCOfExtPC(py::module &);
void bind_Extrema_EPCOfExtPC(py::module &);
void bind_Extrema_ExtPC(py::module &);
void bind_Extrema_ExtPElS(py::module &);
void bind_Extrema_POnSurfParams(py::module &);
void bind_Extrema_Array2OfPOnSurfParams(py::module &);
void bind_Extrema_HArray2OfPOnSurfParams(py::module &);
void bind_Extrema_UBTreeOfSphere(py::module &);
void bind_Extrema_UBTreeFillerOfSphere(py::module &);
void bind_Extrema_HUBTreeOfSphere(py::module &);
void bind_Extrema_FuncPSNorm(py::module &);
void bind_Extrema_GenExtPS(py::module &);
void bind_Extrema_ExtPS(py::module &);
void bind_Extrema_PCLocFOfLocEPCOfLocateExtPC(py::module &);
void bind_Extrema_LocEPCOfLocateExtPC(py::module &);
void bind_Extrema_PCFOfEPCOfELPCOfLocateExtPC(py::module &);
void bind_Extrema_EPCOfELPCOfLocateExtPC(py::module &);
void bind_Extrema_ELPCOfLocateExtPC(py::module &);
void bind_Extrema_LocateExtPC(py::module &);
void bind_Extrema_LocateExtCC(py::module &);
void bind_Extrema_POnCurv2d(py::module &);
void bind_Extrema_Array1OfPOnCurv2d(py::module &);
void bind_Extrema_Array2OfPOnCurv(py::module &);
void bind_Extrema_Array2OfPOnCurv2d(py::module &);
void bind_Extrema_Array2OfPOnSurf(py::module &);
void bind_Extrema_CCLocFOfLocECC(py::module &);
void bind_Extrema_SequenceOfPOnCurv2d(py::module &);
void bind_Extrema_CCLocFOfLocECC2d(py::module &);
void bind_Extrema_Curve2dTool(py::module &);
void bind_Extrema_CurveTool(py::module &);
void bind_Extrema_ECC2d(py::module &);
void bind_Extrema_ExtPElC2d(py::module &);
void bind_Extrema_PCFOfEPCOfELPCOfLocateExtPC2d(py::module &);
void bind_Extrema_EPCOfELPCOfLocateExtPC2d(py::module &);
void bind_Extrema_ELPCOfLocateExtPC2d(py::module &);
void bind_Extrema_PCFOfEPCOfExtPC2d(py::module &);
void bind_Extrema_EPCOfExtPC2d(py::module &);
void bind_Extrema_ExtCC2d(py::module &);
void bind_Extrema_ExtElC(py::module &);
void bind_Extrema_ExtElC2d(py::module &);
void bind_Extrema_ExtPC2d(py::module &);
void bind_Extrema_ExtPExtS(py::module &);
void bind_Extrema_ExtPRevS(py::module &);
void bind_Extrema_FuncExtCS(py::module &);
void bind_Extrema_FuncExtSS(py::module &);
void bind_Extrema_FuncPSDist(py::module &);
void bind_Extrema_GenExtCS(py::module &);
void bind_Extrema_GenExtSS(py::module &);
void bind_Extrema_GenLocateExtCS(py::module &);
void bind_Extrema_GenLocateExtPS(py::module &);
void bind_Extrema_GenLocateExtSS(py::module &);
void bind_Extrema_GlobOptFuncCCC0(py::module &);
void bind_Extrema_GlobOptFuncCCC1(py::module &);
void bind_Extrema_GlobOptFuncCCC2(py::module &);
void bind_Extrema_GlobOptFuncCS(py::module &);
void bind_Extrema_HArray1OfPOnCurv2d(py::module &);
void bind_Extrema_HArray2OfPOnCurv(py::module &);
void bind_Extrema_HArray2OfPOnCurv2d(py::module &);
void bind_Extrema_HArray2OfPOnSurf(py::module &);
void bind_Extrema_LocateExtCC2d(py::module &);
void bind_Extrema_PCLocFOfLocEPCOfLocateExtPC2d(py::module &);
void bind_Extrema_LocEPCOfLocateExtPC2d(py::module &);
void bind_Extrema_LocateExtPC2d(py::module &);
void bind_Extrema_LocECC(py::module &);
void bind_Extrema_LocECC2d(py::module &);

PYBIND11_MODULE(Extrema, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.Adaptor3d");
py::module::import("OCCT.math");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.gp");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.Bnd");
py::module::import("OCCT.Adaptor2d");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.Geom");
py::module::import("OCCT.GeomAdaptor");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.Precision");

bind_Extrema_ExtFlag(mod);
bind_Extrema_ExtAlgo(mod);
bind_Extrema_ElementType(mod);
bind_Extrema_ECC(mod);
bind_Extrema_POnCurv(mod);
bind_Extrema_SequenceOfPOnCurv(mod);
bind_Extrema_ExtCC(mod);
bind_Extrema_Array1OfPOnCurv(mod);
bind_Extrema_HArray1OfPOnCurv(mod);
bind_Extrema_POnSurf(mod);
bind_Extrema_Array1OfPOnSurf(mod);
bind_Extrema_HArray1OfPOnSurf(mod);
bind_Extrema_ExtElCS(mod);
bind_Extrema_SequenceOfPOnSurf(mod);
bind_Extrema_ExtCS(mod);
bind_Extrema_ExtElSS(mod);
bind_Extrema_ExtSS(mod);
bind_Extrema_ExtPElC(mod);
bind_Extrema_PCFOfEPCOfExtPC(mod);
bind_Extrema_EPCOfExtPC(mod);
bind_Extrema_ExtPC(mod);
bind_Extrema_ExtPElS(mod);
bind_Extrema_POnSurfParams(mod);
bind_Extrema_Array2OfPOnSurfParams(mod);
bind_Extrema_HArray2OfPOnSurfParams(mod);
bind_Extrema_UBTreeOfSphere(mod);
bind_Extrema_UBTreeFillerOfSphere(mod);
bind_Extrema_HUBTreeOfSphere(mod);
bind_Extrema_FuncPSNorm(mod);
bind_Extrema_GenExtPS(mod);
bind_Extrema_ExtPS(mod);
bind_Extrema_PCLocFOfLocEPCOfLocateExtPC(mod);
bind_Extrema_LocEPCOfLocateExtPC(mod);
bind_Extrema_PCFOfEPCOfELPCOfLocateExtPC(mod);
bind_Extrema_EPCOfELPCOfLocateExtPC(mod);
bind_Extrema_ELPCOfLocateExtPC(mod);
bind_Extrema_LocateExtPC(mod);
bind_Extrema_LocateExtCC(mod);
bind_Extrema_POnCurv2d(mod);
bind_Extrema_Array1OfPOnCurv2d(mod);
bind_Extrema_Array2OfPOnCurv(mod);
bind_Extrema_Array2OfPOnCurv2d(mod);
bind_Extrema_Array2OfPOnSurf(mod);
bind_Extrema_CCLocFOfLocECC(mod);
bind_Extrema_SequenceOfPOnCurv2d(mod);
bind_Extrema_CCLocFOfLocECC2d(mod);
bind_Extrema_Curve2dTool(mod);
bind_Extrema_CurveTool(mod);
bind_Extrema_ECC2d(mod);
bind_Extrema_ExtPElC2d(mod);
bind_Extrema_PCFOfEPCOfELPCOfLocateExtPC2d(mod);
bind_Extrema_EPCOfELPCOfLocateExtPC2d(mod);
bind_Extrema_ELPCOfLocateExtPC2d(mod);
bind_Extrema_PCFOfEPCOfExtPC2d(mod);
bind_Extrema_EPCOfExtPC2d(mod);
bind_Extrema_ExtCC2d(mod);
bind_Extrema_ExtElC(mod);
bind_Extrema_ExtElC2d(mod);
bind_Extrema_ExtPC2d(mod);
bind_Extrema_ExtPExtS(mod);
bind_Extrema_ExtPRevS(mod);
bind_Extrema_FuncExtCS(mod);
bind_Extrema_FuncExtSS(mod);
bind_Extrema_FuncPSDist(mod);
bind_Extrema_GenExtCS(mod);
bind_Extrema_GenExtSS(mod);
bind_Extrema_GenLocateExtCS(mod);
bind_Extrema_GenLocateExtPS(mod);
bind_Extrema_GenLocateExtSS(mod);
bind_Extrema_GlobOptFuncCCC0(mod);
bind_Extrema_GlobOptFuncCCC1(mod);
bind_Extrema_GlobOptFuncCCC2(mod);
bind_Extrema_GlobOptFuncCS(mod);
bind_Extrema_HArray1OfPOnCurv2d(mod);
bind_Extrema_HArray2OfPOnCurv(mod);
bind_Extrema_HArray2OfPOnCurv2d(mod);
bind_Extrema_HArray2OfPOnSurf(mod);
bind_Extrema_LocateExtCC2d(mod);
bind_Extrema_PCLocFOfLocEPCOfLocateExtPC2d(mod);
bind_Extrema_LocEPCOfLocateExtPC2d(mod);
bind_Extrema_LocateExtPC2d(mod);
bind_Extrema_LocECC(mod);
bind_Extrema_LocECC2d(mod);

}

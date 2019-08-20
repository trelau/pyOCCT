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
#include <Standard.hxx>
#include <TopoDS_Edge.hxx>
#include <HLRBRep_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <HLRBRep_CurveTool.hxx>
#include <HLRBRep_BCurveTool.hxx>
#include <HLRBRep_SurfaceTool.hxx>
#include <HLRBRep_BSurfaceTool.hxx>
#include <HLRBRep_Surface.hxx>
#include <HLRBRep_CLPropsATool.hxx>
#include <HLRBRep_CLProps.hxx>
#include <HLRBRep_SLPropsATool.hxx>
#include <HLRBRep_SLProps.hxx>
#include <HLRBRep_CInter.hxx>
#include <HLRBRep_LineTool.hxx>
#include <HLRBRep_InterCSurf.hxx>
#include <HLRBRep_EdgeFaceTool.hxx>
#include <HLRBRep_Intersector.hxx>
#include <HLRBRep_EdgeData.hxx>
#include <HLRBRep_FaceData.hxx>
#include <HLRBRep_FaceIterator.hxx>
#include <HLRBRep_Data.hxx>
#include <HLRBRep_ShapeToHLR.hxx>
#include <HLRBRep_HLRToShape.hxx>
#include <HLRBRep_ShapeBounds.hxx>
#include <HLRBRep_EdgeInterferenceTool.hxx>
#include <HLRBRep_VertexList.hxx>
#include <HLRBRep_EdgeIList.hxx>
#include <HLRBRep_AreaLimit.hxx>
#include <HLRBRep_EdgeBuilder.hxx>
#include <HLRBRep_Hider.hxx>
#include <HLRBRep_InternalAlgo.hxx>
#include <HLRBRep_Algo.hxx>
#include <HLRBRep_PolyAlgo.hxx>
#include <HLRBRep_BiPoint.hxx>
#include <HLRBRep_BiPnt2D.hxx>
#include <HLRBRep_PolyHLRToShape.hxx>
#include <HLRBRep_TheCurveLocatorOfTheProjPCurOfCInter.hxx>
#include <HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter.hxx>
#include <HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter.hxx>
#include <HLRBRep_TheProjPCurOfCInter.hxx>
#include <HLRBRep_MyImpParToolOfTheIntersectorOfTheIntConicCurveOfCInter.hxx>
#include <HLRBRep_TheIntersectorOfTheIntConicCurveOfCInter.hxx>
#include <HLRBRep_TheIntConicCurveOfCInter.hxx>
#include <HLRBRep_IntConicCurveOfCInter.hxx>
#include <HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter.hxx>
#include <HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter.hxx>
#include <HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter.hxx>
#include <HLRBRep_TheIntPCurvePCurveOfCInter.hxx>
#include <HLRBRep_ThePolygonOfInterCSurf.hxx>
#include <HLRBRep_ThePolygonToolOfInterCSurf.hxx>
#include <HLRBRep_ThePolyhedronOfInterCSurf.hxx>
#include <HLRBRep_ThePolyhedronToolOfInterCSurf.hxx>
#include <HLRBRep_TheInterferenceOfInterCSurf.hxx>
#include <HLRBRep_TheCSFunctionOfInterCSurf.hxx>
#include <HLRBRep_TheExactInterCSurf.hxx>
#include <HLRBRep_TheQuadCurvFuncOfTheQuadCurvExactInterCSurf.hxx>
#include <HLRBRep_TheQuadCurvExactInterCSurf.hxx>
#include <HLRBRep.hxx>

void bind_HLRBRep(py::module &mod){

py::class_<HLRBRep, std::unique_ptr<HLRBRep>> cls_HLRBRep(mod, "HLRBRep", "Hidden Lines Removal algorithms on the BRep DataStructure.");

// Constructors

// Fields

// Methods
// cls_HLRBRep.def_static("operator new_", (void * (*)(size_t)) &HLRBRep::operator new, "None", py::arg("theSize"));
// cls_HLRBRep.def_static("operator delete_", (void (*)(void *)) &HLRBRep::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep.def_static("MakeEdge_", (TopoDS_Edge (*)(const HLRBRep_Curve &, const Standard_Real, const Standard_Real)) &HLRBRep::MakeEdge, "None", py::arg("ec"), py::arg("U1"), py::arg("U2"));
cls_HLRBRep.def_static("MakeEdge3d_", (TopoDS_Edge (*)(const HLRBRep_Curve &, const Standard_Real, const Standard_Real)) &HLRBRep::MakeEdge3d, "None", py::arg("ec"), py::arg("U1"), py::arg("U2"));
cls_HLRBRep.def_static("PolyHLRAngleAndDeflection_", [](const Standard_Real InAngl, Standard_Real & OutAngl, Standard_Real & OutDefl){ HLRBRep::PolyHLRAngleAndDeflection(InAngl, OutAngl, OutDefl); return std::tuple<Standard_Real &, Standard_Real &>(OutAngl, OutDefl); }, "None", py::arg("InAngl"), py::arg("OutAngl"), py::arg("OutDefl"));

// Enums

}
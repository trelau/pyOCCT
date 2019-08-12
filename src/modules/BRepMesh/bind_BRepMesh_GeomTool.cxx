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
#include <BRepAdaptor_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <Precision.hxx>
#include <Standard_Handle.hxx>
#include <BRepAdaptor_HSurface.hxx>
#include <GeomAbs_IsoType.hxx>
#include <gp_Pnt.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Dir.hxx>
#include <BRepMesh_GeomTool.hxx>
#include <gp_XY.hxx>
#include <TopoDS_Edge.hxx>
#include <GCPnts_TangentialDeflection.hxx>

void bind_BRepMesh_GeomTool(py::module &mod){

py::class_<BRepMesh_GeomTool, std::unique_ptr<BRepMesh_GeomTool, Deleter<BRepMesh_GeomTool>>> cls_BRepMesh_GeomTool(mod, "BRepMesh_GeomTool", "Tool class accumulating common geometrical functions as well as functionality using shape geometry to produce data necessary for tessellation. General aim is to calculate discretization points for the given curve or iso curve of surface according to the specified parameters.");

// Constructors
cls_BRepMesh_GeomTool.def(py::init<const BRepAdaptor_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("theCurve"), py::arg("theFirstParam"), py::arg("theLastParam"), py::arg("theLinDeflection"), py::arg("theAngDeflection"));
cls_BRepMesh_GeomTool.def(py::init<const BRepAdaptor_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("theCurve"), py::arg("theFirstParam"), py::arg("theLastParam"), py::arg("theLinDeflection"), py::arg("theAngDeflection"), py::arg("theMinPointsNb"));
cls_BRepMesh_GeomTool.def(py::init<const BRepAdaptor_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real>(), py::arg("theCurve"), py::arg("theFirstParam"), py::arg("theLastParam"), py::arg("theLinDeflection"), py::arg("theAngDeflection"), py::arg("theMinPointsNb"), py::arg("theMinSize"));
cls_BRepMesh_GeomTool.def(py::init<const opencascade::handle<BRepAdaptor_HSurface> &, const GeomAbs_IsoType, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("theSurface"), py::arg("theIsoType"), py::arg("theParamIso"), py::arg("theFirstParam"), py::arg("theLastParam"), py::arg("theLinDeflection"), py::arg("theAngDeflection"));
cls_BRepMesh_GeomTool.def(py::init<const opencascade::handle<BRepAdaptor_HSurface> &, const GeomAbs_IsoType, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("theSurface"), py::arg("theIsoType"), py::arg("theParamIso"), py::arg("theFirstParam"), py::arg("theLastParam"), py::arg("theLinDeflection"), py::arg("theAngDeflection"), py::arg("theMinPointsNb"));
cls_BRepMesh_GeomTool.def(py::init<const opencascade::handle<BRepAdaptor_HSurface> &, const GeomAbs_IsoType, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real>(), py::arg("theSurface"), py::arg("theIsoType"), py::arg("theParamIso"), py::arg("theFirstParam"), py::arg("theLastParam"), py::arg("theLinDeflection"), py::arg("theAngDeflection"), py::arg("theMinPointsNb"), py::arg("theMinSize"));

// Fields

// Methods
// cls_BRepMesh_GeomTool.def_static("operator new_", (void * (*)(size_t)) &BRepMesh_GeomTool::operator new, "None", py::arg("theSize"));
// cls_BRepMesh_GeomTool.def_static("operator delete_", (void (*)(void *)) &BRepMesh_GeomTool::operator delete, "None", py::arg("theAddress"));
// cls_BRepMesh_GeomTool.def_static("operator new[]_", (void * (*)(size_t)) &BRepMesh_GeomTool::operator new[], "None", py::arg("theSize"));
// cls_BRepMesh_GeomTool.def_static("operator delete[]_", (void (*)(void *)) &BRepMesh_GeomTool::operator delete[], "None", py::arg("theAddress"));
// cls_BRepMesh_GeomTool.def_static("operator new_", (void * (*)(size_t, void *)) &BRepMesh_GeomTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepMesh_GeomTool.def_static("operator delete_", (void (*)(void *, void *)) &BRepMesh_GeomTool::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepMesh_GeomTool.def("AddPoint", [](BRepMesh_GeomTool &self, const gp_Pnt & a0, const Standard_Real a1) -> Standard_Integer { return self.AddPoint(a0, a1); });
cls_BRepMesh_GeomTool.def("AddPoint", (Standard_Integer (BRepMesh_GeomTool::*)(const gp_Pnt &, const Standard_Real, const Standard_Boolean)) &BRepMesh_GeomTool::AddPoint, "Adds point to already calculated points (or replaces existing).", py::arg("thePoint"), py::arg("theParam"), py::arg("theIsReplace"));
cls_BRepMesh_GeomTool.def("NbPoints", (Standard_Integer (BRepMesh_GeomTool::*)() const) &BRepMesh_GeomTool::NbPoints, "Returns number of discretization points.");
cls_BRepMesh_GeomTool.def("Value", [](BRepMesh_GeomTool &self, const Standard_Integer theIndex, const Standard_Real theIsoParam, Standard_Real & theParam, gp_Pnt & thePoint, gp_Pnt2d & theUV){ Standard_Boolean rv = self.Value(theIndex, theIsoParam, theParam, thePoint, theUV); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theParam); }, "Gets parameters of discretization point with the given index.", py::arg("theIndex"), py::arg("theIsoParam"), py::arg("theParam"), py::arg("thePoint"), py::arg("theUV"));
cls_BRepMesh_GeomTool.def("Value", [](BRepMesh_GeomTool &self, const Standard_Integer theIndex, Standard_Real & theParam, gp_Pnt & thePoint){ Standard_Boolean rv = self.Value(theIndex, theParam, thePoint); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theParam); }, "Gets parameters of discretization point with the given index.", py::arg("theIndex"), py::arg("theParam"), py::arg("thePoint"));
cls_BRepMesh_GeomTool.def_static("Normal_", (Standard_Boolean (*)(const opencascade::handle<BRepAdaptor_HSurface> &, const Standard_Real, const Standard_Real, gp_Pnt &, gp_Dir &)) &BRepMesh_GeomTool::Normal, "Computes normal to the given surface at the specified position in parametric space.", py::arg("theSurface"), py::arg("theParamU"), py::arg("theParamV"), py::arg("thePoint"), py::arg("theNormal"));
// cls_BRepMesh_GeomTool.def_static("IntLinLin_", (BRepMesh_GeomTool::IntFlag (*)(const gp_XY &, const gp_XY &, const gp_XY &, const gp_XY &, gp_XY &, Standard_Real (&)[2])) &BRepMesh_GeomTool::IntLinLin, "Checks intersection between two lines defined by two points.", py::arg("theStartPnt1"), py::arg("theEndPnt1"), py::arg("theStartPnt2"), py::arg("theEndPnt2"), py::arg("theIntPnt"), py::arg("theParamOnSegment"));
cls_BRepMesh_GeomTool.def_static("IntSegSeg_", (BRepMesh_GeomTool::IntFlag (*)(const gp_XY &, const gp_XY &, const gp_XY &, const gp_XY &, const Standard_Boolean, const Standard_Boolean, gp_Pnt2d &)) &BRepMesh_GeomTool::IntSegSeg, "Checks intersection between the two segments. Checks that intersection point lies within ranges of both segments.", py::arg("theStartPnt1"), py::arg("theEndPnt1"), py::arg("theStartPnt2"), py::arg("theEndPnt2"), py::arg("isConsiderEndPointTouch"), py::arg("isConsiderPointOnSegment"), py::arg("theIntPnt"));

// Enums
py::enum_<BRepMesh_GeomTool::IntFlag>(cls_BRepMesh_GeomTool, "IntFlag", "Enumerates states of segments intersection check.")
	.value("NoIntersection", BRepMesh_GeomTool::IntFlag::NoIntersection)
	.value("Cross", BRepMesh_GeomTool::IntFlag::Cross)
	.value("EndPointTouch", BRepMesh_GeomTool::IntFlag::EndPointTouch)
	.value("PointOnSegment", BRepMesh_GeomTool::IntFlag::PointOnSegment)
	.value("Glued", BRepMesh_GeomTool::IntFlag::Glued)
	.value("Same", BRepMesh_GeomTool::IntFlag::Same)
	.export_values();

}
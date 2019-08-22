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
#include <AppCont_Function.hxx>
#include <Standard.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Edge.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Geom2d_Curve.hxx>
#include <GeomAbs_Shape.hxx>
#include <Geom_Curve.hxx>
#include <gp_Pnt.hxx>
#include <gp_Pnt2d.hxx>
#include <NCollection_Array1.hxx>
#include <gp_Vec2d.hxx>
#include <gp_Vec.hxx>
#include <Geom2dAdaptor_Curve.hxx>
#include <BRepFill_MultiLine.hxx>

void bind_BRepFill_MultiLine(py::module &mod){

py::class_<BRepFill_MultiLine, AppCont_Function> cls_BRepFill_MultiLine(mod, "BRepFill_MultiLine", "Class used to compute the 3d curve and the two 2d curves resulting from the intersection of a surface of linear extrusion( Bissec, Dz) and the 2 faces. This 3 curves will have the same parametrization as the Bissectrice. This class is to be send to an approximation routine.");

// Constructors
cls_BRepFill_MultiLine.def(py::init<>());
cls_BRepFill_MultiLine.def(py::init<const TopoDS_Face &, const TopoDS_Face &, const TopoDS_Edge &, const TopoDS_Edge &, const Standard_Boolean, const Standard_Boolean, const opencascade::handle<Geom2d_Curve> &>(), py::arg("Face1"), py::arg("Face2"), py::arg("Edge1"), py::arg("Edge2"), py::arg("Inv1"), py::arg("Inv2"), py::arg("Bissec"));

// Fields

// Methods
// cls_BRepFill_MultiLine.def_static("operator new_", (void * (*)(size_t)) &BRepFill_MultiLine::operator new, "None", py::arg("theSize"));
// cls_BRepFill_MultiLine.def_static("operator delete_", (void (*)(void *)) &BRepFill_MultiLine::operator delete, "None", py::arg("theAddress"));
// cls_BRepFill_MultiLine.def_static("operator new[]_", (void * (*)(size_t)) &BRepFill_MultiLine::operator new[], "None", py::arg("theSize"));
// cls_BRepFill_MultiLine.def_static("operator delete[]_", (void (*)(void *)) &BRepFill_MultiLine::operator delete[], "None", py::arg("theAddress"));
// cls_BRepFill_MultiLine.def_static("operator new_", (void * (*)(size_t, void *)) &BRepFill_MultiLine::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepFill_MultiLine.def_static("operator delete_", (void (*)(void *, void *)) &BRepFill_MultiLine::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepFill_MultiLine.def("IsParticularCase", (Standard_Boolean (BRepFill_MultiLine::*)() const) &BRepFill_MultiLine::IsParticularCase, "Search if the Projection of the Bissectrice on the faces needs an approximation or not. Returns true if the approximation is not needed.");
cls_BRepFill_MultiLine.def("Continuity", (GeomAbs_Shape (BRepFill_MultiLine::*)() const) &BRepFill_MultiLine::Continuity, "Returns the continuity betwwen the two faces seShape from GeomAbsparated by myBis.");
cls_BRepFill_MultiLine.def("Curves", (void (BRepFill_MultiLine::*)(opencascade::handle<Geom_Curve> &, opencascade::handle<Geom2d_Curve> &, opencascade::handle<Geom2d_Curve> &) const) &BRepFill_MultiLine::Curves, "raises if IsParticularCase is <False>.", py::arg("Curve"), py::arg("PCurve1"), py::arg("PCurve2"));
cls_BRepFill_MultiLine.def("FirstParameter", (Standard_Real (BRepFill_MultiLine::*)() const) &BRepFill_MultiLine::FirstParameter, "returns the first parameter of the Bissectrice.");
cls_BRepFill_MultiLine.def("LastParameter", (Standard_Real (BRepFill_MultiLine::*)() const) &BRepFill_MultiLine::LastParameter, "returns the last parameter of the Bissectrice.");
cls_BRepFill_MultiLine.def("Value", (gp_Pnt (BRepFill_MultiLine::*)(const Standard_Real) const) &BRepFill_MultiLine::Value, "Returns the current point on the 3d curve", py::arg("U"));
cls_BRepFill_MultiLine.def("ValueOnF1", (gp_Pnt2d (BRepFill_MultiLine::*)(const Standard_Real) const) &BRepFill_MultiLine::ValueOnF1, "returns the current point on the PCurve of the first face", py::arg("U"));
cls_BRepFill_MultiLine.def("ValueOnF2", (gp_Pnt2d (BRepFill_MultiLine::*)(const Standard_Real) const) &BRepFill_MultiLine::ValueOnF2, "returns the current point on the PCurve of the first face", py::arg("U"));
cls_BRepFill_MultiLine.def("Value3dOnF1OnF2", (void (BRepFill_MultiLine::*)(const Standard_Real, gp_Pnt &, gp_Pnt2d &, gp_Pnt2d &) const) &BRepFill_MultiLine::Value3dOnF1OnF2, "None", py::arg("U"), py::arg("P3d"), py::arg("PF1"), py::arg("PF2"));
cls_BRepFill_MultiLine.def("Value", (Standard_Boolean (BRepFill_MultiLine::*)(const Standard_Real, NCollection_Array1<gp_Pnt2d> &, NCollection_Array1<gp_Pnt> &) const) &BRepFill_MultiLine::Value, "Returns the point at parameter <theU>.", py::arg("theU"), py::arg("thePnt2d"), py::arg("thePnt"));
cls_BRepFill_MultiLine.def("D1", (Standard_Boolean (BRepFill_MultiLine::*)(const Standard_Real, NCollection_Array1<gp_Vec2d> &, NCollection_Array1<gp_Vec> &) const) &BRepFill_MultiLine::D1, "Returns the derivative at parameter <theU>.", py::arg("theU"), py::arg("theVec2d"), py::arg("theVec"));

// Enums

}
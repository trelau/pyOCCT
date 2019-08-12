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
#include <TopoDS_Vertex.hxx>
#include <TopoDS_Edge.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <Extrema_ExtPC.hxx>
#include <Standard_Handle.hxx>
#include <BRepAdaptor_HCurve.hxx>
#include <BRepExtrema_ExtPC.hxx>

void bind_BRepExtrema_ExtPC(py::module &mod){

py::class_<BRepExtrema_ExtPC, std::unique_ptr<BRepExtrema_ExtPC, Deleter<BRepExtrema_ExtPC>>> cls_BRepExtrema_ExtPC(mod, "BRepExtrema_ExtPC", "None");

// Constructors
cls_BRepExtrema_ExtPC.def(py::init<>());
cls_BRepExtrema_ExtPC.def(py::init<const TopoDS_Vertex &, const TopoDS_Edge &>(), py::arg("V"), py::arg("E"));

// Fields

// Methods
// cls_BRepExtrema_ExtPC.def_static("operator new_", (void * (*)(size_t)) &BRepExtrema_ExtPC::operator new, "None", py::arg("theSize"));
// cls_BRepExtrema_ExtPC.def_static("operator delete_", (void (*)(void *)) &BRepExtrema_ExtPC::operator delete, "None", py::arg("theAddress"));
// cls_BRepExtrema_ExtPC.def_static("operator new[]_", (void * (*)(size_t)) &BRepExtrema_ExtPC::operator new[], "None", py::arg("theSize"));
// cls_BRepExtrema_ExtPC.def_static("operator delete[]_", (void (*)(void *)) &BRepExtrema_ExtPC::operator delete[], "None", py::arg("theAddress"));
// cls_BRepExtrema_ExtPC.def_static("operator new_", (void * (*)(size_t, void *)) &BRepExtrema_ExtPC::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepExtrema_ExtPC.def_static("operator delete_", (void (*)(void *, void *)) &BRepExtrema_ExtPC::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepExtrema_ExtPC.def("Initialize", (void (BRepExtrema_ExtPC::*)(const TopoDS_Edge &)) &BRepExtrema_ExtPC::Initialize, "None", py::arg("E"));
cls_BRepExtrema_ExtPC.def("Perform", (void (BRepExtrema_ExtPC::*)(const TopoDS_Vertex &)) &BRepExtrema_ExtPC::Perform, "An exception is raised if the fields have not been initialized.", py::arg("V"));
cls_BRepExtrema_ExtPC.def("IsDone", (Standard_Boolean (BRepExtrema_ExtPC::*)() const) &BRepExtrema_ExtPC::IsDone, "True if the distances are found.");
cls_BRepExtrema_ExtPC.def("NbExt", (Standard_Integer (BRepExtrema_ExtPC::*)() const) &BRepExtrema_ExtPC::NbExt, "Returns the number of extremum distances.");
cls_BRepExtrema_ExtPC.def("IsMin", (Standard_Boolean (BRepExtrema_ExtPC::*)(const Standard_Integer) const) &BRepExtrema_ExtPC::IsMin, "Returns True if the <N>th extremum distance is a minimum.", py::arg("N"));
cls_BRepExtrema_ExtPC.def("SquareDistance", (Standard_Real (BRepExtrema_ExtPC::*)(const Standard_Integer) const) &BRepExtrema_ExtPC::SquareDistance, "Returns the value of the <N>th extremum square distance.", py::arg("N"));
cls_BRepExtrema_ExtPC.def("Parameter", (Standard_Real (BRepExtrema_ExtPC::*)(const Standard_Integer) const) &BRepExtrema_ExtPC::Parameter, "Returns the parameter on the edge of the <N>th extremum distance.", py::arg("N"));
cls_BRepExtrema_ExtPC.def("Point", (gp_Pnt (BRepExtrema_ExtPC::*)(const Standard_Integer) const) &BRepExtrema_ExtPC::Point, "Returns the Point of the <N>th extremum distance.", py::arg("N"));
cls_BRepExtrema_ExtPC.def("TrimmedSquareDistances", [](BRepExtrema_ExtPC &self, Standard_Real & dist1, Standard_Real & dist2, gp_Pnt & pnt1, gp_Pnt & pnt2){ self.TrimmedSquareDistances(dist1, dist2, pnt1, pnt2); return std::tuple<Standard_Real &, Standard_Real &>(dist1, dist2); }, "if the curve is a trimmed curve, dist1 is a square distance between <P> and the point of parameter FirstParameter <pnt1> and dist2 is a square distance between <P> and the point of parameter LastParameter <pnt2>.", py::arg("dist1"), py::arg("dist2"), py::arg("pnt1"), py::arg("pnt2"));

// Enums

}
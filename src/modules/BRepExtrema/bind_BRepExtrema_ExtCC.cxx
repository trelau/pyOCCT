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
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <Extrema_ExtCC.hxx>
#include <Standard_Handle.hxx>
#include <BRepAdaptor_HCurve.hxx>
#include <BRepExtrema_ExtCC.hxx>

void bind_BRepExtrema_ExtCC(py::module &mod){

py::class_<BRepExtrema_ExtCC> cls_BRepExtrema_ExtCC(mod, "BRepExtrema_ExtCC", "None");

// Constructors
cls_BRepExtrema_ExtCC.def(py::init<>());
cls_BRepExtrema_ExtCC.def(py::init<const TopoDS_Edge &, const TopoDS_Edge &>(), py::arg("E1"), py::arg("E2"));

// Fields

// Methods
// cls_BRepExtrema_ExtCC.def_static("operator new_", (void * (*)(size_t)) &BRepExtrema_ExtCC::operator new, "None", py::arg("theSize"));
// cls_BRepExtrema_ExtCC.def_static("operator delete_", (void (*)(void *)) &BRepExtrema_ExtCC::operator delete, "None", py::arg("theAddress"));
// cls_BRepExtrema_ExtCC.def_static("operator new[]_", (void * (*)(size_t)) &BRepExtrema_ExtCC::operator new[], "None", py::arg("theSize"));
// cls_BRepExtrema_ExtCC.def_static("operator delete[]_", (void (*)(void *)) &BRepExtrema_ExtCC::operator delete[], "None", py::arg("theAddress"));
// cls_BRepExtrema_ExtCC.def_static("operator new_", (void * (*)(size_t, void *)) &BRepExtrema_ExtCC::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepExtrema_ExtCC.def_static("operator delete_", (void (*)(void *, void *)) &BRepExtrema_ExtCC::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepExtrema_ExtCC.def("Initialize", (void (BRepExtrema_ExtCC::*)(const TopoDS_Edge &)) &BRepExtrema_ExtCC::Initialize, "None", py::arg("E2"));
cls_BRepExtrema_ExtCC.def("Perform", (void (BRepExtrema_ExtCC::*)(const TopoDS_Edge &)) &BRepExtrema_ExtCC::Perform, "An exception is raised if the fields have not been initialized.", py::arg("E1"));
cls_BRepExtrema_ExtCC.def("IsDone", (Standard_Boolean (BRepExtrema_ExtCC::*)() const) &BRepExtrema_ExtCC::IsDone, "True if the distances are found.");
cls_BRepExtrema_ExtCC.def("NbExt", (Standard_Integer (BRepExtrema_ExtCC::*)() const) &BRepExtrema_ExtCC::NbExt, "Returns the number of extremum distances.");
cls_BRepExtrema_ExtCC.def("IsParallel", (Standard_Boolean (BRepExtrema_ExtCC::*)() const) &BRepExtrema_ExtCC::IsParallel, "Returns True if E1 and E2 are parallel.");
cls_BRepExtrema_ExtCC.def("SquareDistance", (Standard_Real (BRepExtrema_ExtCC::*)(const Standard_Integer) const) &BRepExtrema_ExtCC::SquareDistance, "Returns the value of the <N>th extremum square distance.", py::arg("N"));
cls_BRepExtrema_ExtCC.def("ParameterOnE1", (Standard_Real (BRepExtrema_ExtCC::*)(const Standard_Integer) const) &BRepExtrema_ExtCC::ParameterOnE1, "Returns the parameter on the first edge of the <N>th extremum distance.", py::arg("N"));
cls_BRepExtrema_ExtCC.def("PointOnE1", (gp_Pnt (BRepExtrema_ExtCC::*)(const Standard_Integer) const) &BRepExtrema_ExtCC::PointOnE1, "Returns the Point of the <N>th extremum distance on the edge E1.", py::arg("N"));
cls_BRepExtrema_ExtCC.def("ParameterOnE2", (Standard_Real (BRepExtrema_ExtCC::*)(const Standard_Integer) const) &BRepExtrema_ExtCC::ParameterOnE2, "Returns the parameter on the second edge of the <N>th extremum distance.", py::arg("N"));
cls_BRepExtrema_ExtCC.def("PointOnE2", (gp_Pnt (BRepExtrema_ExtCC::*)(const Standard_Integer) const) &BRepExtrema_ExtCC::PointOnE2, "Returns the Point of the <N>th extremum distance on the edge E2.", py::arg("N"));
cls_BRepExtrema_ExtCC.def("TrimmedSquareDistances", [](BRepExtrema_ExtCC &self, Standard_Real & dist11, Standard_Real & distP12, Standard_Real & distP21, Standard_Real & distP22, gp_Pnt & P11, gp_Pnt & P12, gp_Pnt & P21, gp_Pnt & P22){ self.TrimmedSquareDistances(dist11, distP12, distP21, distP22, P11, P12, P21, P22); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(dist11, distP12, distP21, distP22); }, "if the edges is a trimmed curve, dist11 is a square distance between the point on E1 of parameter FirstParameter and the point of parameter FirstParameter on E2.", py::arg("dist11"), py::arg("distP12"), py::arg("distP21"), py::arg("distP22"), py::arg("P11"), py::arg("P12"), py::arg("P21"), py::arg("P22"));

// Enums

}
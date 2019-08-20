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
#include <TopoDS_Face.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <Extrema_ExtSS.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <Extrema_SequenceOfPOnSurf.hxx>
#include <Standard_Handle.hxx>
#include <BRepAdaptor_HSurface.hxx>
#include <BRepExtrema_ExtFF.hxx>

void bind_BRepExtrema_ExtFF(py::module &mod){

py::class_<BRepExtrema_ExtFF, std::unique_ptr<BRepExtrema_ExtFF>> cls_BRepExtrema_ExtFF(mod, "BRepExtrema_ExtFF", "None");

// Constructors
cls_BRepExtrema_ExtFF.def(py::init<>());
cls_BRepExtrema_ExtFF.def(py::init<const TopoDS_Face &, const TopoDS_Face &>(), py::arg("F1"), py::arg("F2"));

// Fields

// Methods
// cls_BRepExtrema_ExtFF.def_static("operator new_", (void * (*)(size_t)) &BRepExtrema_ExtFF::operator new, "None", py::arg("theSize"));
// cls_BRepExtrema_ExtFF.def_static("operator delete_", (void (*)(void *)) &BRepExtrema_ExtFF::operator delete, "None", py::arg("theAddress"));
// cls_BRepExtrema_ExtFF.def_static("operator new[]_", (void * (*)(size_t)) &BRepExtrema_ExtFF::operator new[], "None", py::arg("theSize"));
// cls_BRepExtrema_ExtFF.def_static("operator delete[]_", (void (*)(void *)) &BRepExtrema_ExtFF::operator delete[], "None", py::arg("theAddress"));
// cls_BRepExtrema_ExtFF.def_static("operator new_", (void * (*)(size_t, void *)) &BRepExtrema_ExtFF::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepExtrema_ExtFF.def_static("operator delete_", (void (*)(void *, void *)) &BRepExtrema_ExtFF::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepExtrema_ExtFF.def("Initialize", (void (BRepExtrema_ExtFF::*)(const TopoDS_Face &)) &BRepExtrema_ExtFF::Initialize, "None", py::arg("F2"));
cls_BRepExtrema_ExtFF.def("Perform", (void (BRepExtrema_ExtFF::*)(const TopoDS_Face &, const TopoDS_Face &)) &BRepExtrema_ExtFF::Perform, "An exception is raised if the fields have not been initialized. Be careful: this method uses the Face F2 only for classify, not for the fields.", py::arg("F1"), py::arg("F2"));
cls_BRepExtrema_ExtFF.def("IsDone", (Standard_Boolean (BRepExtrema_ExtFF::*)() const) &BRepExtrema_ExtFF::IsDone, "True if the distances are found.");
cls_BRepExtrema_ExtFF.def("IsParallel", (Standard_Boolean (BRepExtrema_ExtFF::*)() const) &BRepExtrema_ExtFF::IsParallel, "Returns True if the surfaces are parallel.");
cls_BRepExtrema_ExtFF.def("NbExt", (Standard_Integer (BRepExtrema_ExtFF::*)() const) &BRepExtrema_ExtFF::NbExt, "Returns the number of extremum distances.");
cls_BRepExtrema_ExtFF.def("SquareDistance", (Standard_Real (BRepExtrema_ExtFF::*)(const Standard_Integer) const) &BRepExtrema_ExtFF::SquareDistance, "Returns the value of the <N>th extremum square distance.", py::arg("N"));
cls_BRepExtrema_ExtFF.def("ParameterOnFace1", [](BRepExtrema_ExtFF &self, const Standard_Integer N, Standard_Real & U, Standard_Real & V){ self.ParameterOnFace1(N, U, V); return std::tuple<Standard_Real &, Standard_Real &>(U, V); }, "Returns the parameters on the Face F1 of the <N>th extremum distance.", py::arg("N"), py::arg("U"), py::arg("V"));
cls_BRepExtrema_ExtFF.def("ParameterOnFace2", [](BRepExtrema_ExtFF &self, const Standard_Integer N, Standard_Real & U, Standard_Real & V){ self.ParameterOnFace2(N, U, V); return std::tuple<Standard_Real &, Standard_Real &>(U, V); }, "Returns the parameters on the Face F2 of the <N>th extremum distance.", py::arg("N"), py::arg("U"), py::arg("V"));
cls_BRepExtrema_ExtFF.def("PointOnFace1", (gp_Pnt (BRepExtrema_ExtFF::*)(const Standard_Integer) const) &BRepExtrema_ExtFF::PointOnFace1, "Returns the Point of the <N>th extremum distance.", py::arg("N"));
cls_BRepExtrema_ExtFF.def("PointOnFace2", (gp_Pnt (BRepExtrema_ExtFF::*)(const Standard_Integer) const) &BRepExtrema_ExtFF::PointOnFace2, "Returns the Point of the <N>th extremum distance.", py::arg("N"));

// Enums

}
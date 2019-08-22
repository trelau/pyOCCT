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
#include <TopoDS_Face.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <Extrema_ExtCS.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <Extrema_SequenceOfPOnSurf.hxx>
#include <Extrema_SequenceOfPOnCurv.hxx>
#include <Standard_Handle.hxx>
#include <BRepAdaptor_HSurface.hxx>
#include <BRepExtrema_ExtCF.hxx>

void bind_BRepExtrema_ExtCF(py::module &mod){

py::class_<BRepExtrema_ExtCF> cls_BRepExtrema_ExtCF(mod, "BRepExtrema_ExtCF", "None");

// Constructors
cls_BRepExtrema_ExtCF.def(py::init<>());
cls_BRepExtrema_ExtCF.def(py::init<const TopoDS_Edge &, const TopoDS_Face &>(), py::arg("E"), py::arg("F"));

// Fields

// Methods
// cls_BRepExtrema_ExtCF.def_static("operator new_", (void * (*)(size_t)) &BRepExtrema_ExtCF::operator new, "None", py::arg("theSize"));
// cls_BRepExtrema_ExtCF.def_static("operator delete_", (void (*)(void *)) &BRepExtrema_ExtCF::operator delete, "None", py::arg("theAddress"));
// cls_BRepExtrema_ExtCF.def_static("operator new[]_", (void * (*)(size_t)) &BRepExtrema_ExtCF::operator new[], "None", py::arg("theSize"));
// cls_BRepExtrema_ExtCF.def_static("operator delete[]_", (void (*)(void *)) &BRepExtrema_ExtCF::operator delete[], "None", py::arg("theAddress"));
// cls_BRepExtrema_ExtCF.def_static("operator new_", (void * (*)(size_t, void *)) &BRepExtrema_ExtCF::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepExtrema_ExtCF.def_static("operator delete_", (void (*)(void *, void *)) &BRepExtrema_ExtCF::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepExtrema_ExtCF.def("Initialize", (void (BRepExtrema_ExtCF::*)(const TopoDS_Edge &, const TopoDS_Face &)) &BRepExtrema_ExtCF::Initialize, "None", py::arg("E"), py::arg("F"));
cls_BRepExtrema_ExtCF.def("Perform", (void (BRepExtrema_ExtCF::*)(const TopoDS_Edge &, const TopoDS_Face &)) &BRepExtrema_ExtCF::Perform, "An exception is raised if the fields have not been initialized. Be careful: this method uses the Face only for classify not for the fields.", py::arg("E"), py::arg("F"));
cls_BRepExtrema_ExtCF.def("IsDone", (Standard_Boolean (BRepExtrema_ExtCF::*)() const) &BRepExtrema_ExtCF::IsDone, "True if the distances are found.");
cls_BRepExtrema_ExtCF.def("NbExt", (Standard_Integer (BRepExtrema_ExtCF::*)() const) &BRepExtrema_ExtCF::NbExt, "Returns the number of extremum distances.");
cls_BRepExtrema_ExtCF.def("SquareDistance", (Standard_Real (BRepExtrema_ExtCF::*)(const Standard_Integer) const) &BRepExtrema_ExtCF::SquareDistance, "Returns the value of the <N>th extremum square distance.", py::arg("N"));
cls_BRepExtrema_ExtCF.def("IsParallel", (Standard_Boolean (BRepExtrema_ExtCF::*)() const) &BRepExtrema_ExtCF::IsParallel, "Returns True if the curve is on a parallel surface.");
cls_BRepExtrema_ExtCF.def("ParameterOnEdge", (Standard_Real (BRepExtrema_ExtCF::*)(const Standard_Integer) const) &BRepExtrema_ExtCF::ParameterOnEdge, "Returns the parameters on the Edge of the <N>th extremum distance.", py::arg("N"));
cls_BRepExtrema_ExtCF.def("ParameterOnFace", [](BRepExtrema_ExtCF &self, const Standard_Integer N, Standard_Real & U, Standard_Real & V){ self.ParameterOnFace(N, U, V); return std::tuple<Standard_Real &, Standard_Real &>(U, V); }, "Returns the parameters on the Face of the <N>th extremum distance.", py::arg("N"), py::arg("U"), py::arg("V"));
cls_BRepExtrema_ExtCF.def("PointOnEdge", (gp_Pnt (BRepExtrema_ExtCF::*)(const Standard_Integer) const) &BRepExtrema_ExtCF::PointOnEdge, "Returns the Point of the <N>th extremum distance.", py::arg("N"));
cls_BRepExtrema_ExtCF.def("PointOnFace", (gp_Pnt (BRepExtrema_ExtCF::*)(const Standard_Integer) const) &BRepExtrema_ExtCF::PointOnFace, "Returns the Point of the <N>th extremum distance.", py::arg("N"));

// Enums

}
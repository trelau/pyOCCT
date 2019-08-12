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
#include <TopoDS_Face.hxx>
#include <Extrema_ExtFlag.hxx>
#include <Extrema_ExtAlgo.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <Extrema_ExtPS.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <Extrema_SequenceOfPOnSurf.hxx>
#include <BRepAdaptor_Surface.hxx>
#include <BRepExtrema_ExtPF.hxx>

void bind_BRepExtrema_ExtPF(py::module &mod){

py::class_<BRepExtrema_ExtPF, std::unique_ptr<BRepExtrema_ExtPF, Deleter<BRepExtrema_ExtPF>>> cls_BRepExtrema_ExtPF(mod, "BRepExtrema_ExtPF", "None");

// Constructors
cls_BRepExtrema_ExtPF.def(py::init<>());
cls_BRepExtrema_ExtPF.def(py::init<const TopoDS_Vertex &, const TopoDS_Face &>(), py::arg("TheVertex"), py::arg("TheFace"));
cls_BRepExtrema_ExtPF.def(py::init<const TopoDS_Vertex &, const TopoDS_Face &, const Extrema_ExtFlag>(), py::arg("TheVertex"), py::arg("TheFace"), py::arg("TheFlag"));
cls_BRepExtrema_ExtPF.def(py::init<const TopoDS_Vertex &, const TopoDS_Face &, const Extrema_ExtFlag, const Extrema_ExtAlgo>(), py::arg("TheVertex"), py::arg("TheFace"), py::arg("TheFlag"), py::arg("TheAlgo"));

// Fields

// Methods
// cls_BRepExtrema_ExtPF.def_static("operator new_", (void * (*)(size_t)) &BRepExtrema_ExtPF::operator new, "None", py::arg("theSize"));
// cls_BRepExtrema_ExtPF.def_static("operator delete_", (void (*)(void *)) &BRepExtrema_ExtPF::operator delete, "None", py::arg("theAddress"));
// cls_BRepExtrema_ExtPF.def_static("operator new[]_", (void * (*)(size_t)) &BRepExtrema_ExtPF::operator new[], "None", py::arg("theSize"));
// cls_BRepExtrema_ExtPF.def_static("operator delete[]_", (void (*)(void *)) &BRepExtrema_ExtPF::operator delete[], "None", py::arg("theAddress"));
// cls_BRepExtrema_ExtPF.def_static("operator new_", (void * (*)(size_t, void *)) &BRepExtrema_ExtPF::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepExtrema_ExtPF.def_static("operator delete_", (void (*)(void *, void *)) &BRepExtrema_ExtPF::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepExtrema_ExtPF.def("Initialize", [](BRepExtrema_ExtPF &self, const TopoDS_Face & a0) -> void { return self.Initialize(a0); });
cls_BRepExtrema_ExtPF.def("Initialize", [](BRepExtrema_ExtPF &self, const TopoDS_Face & a0, const Extrema_ExtFlag a1) -> void { return self.Initialize(a0, a1); });
cls_BRepExtrema_ExtPF.def("Initialize", (void (BRepExtrema_ExtPF::*)(const TopoDS_Face &, const Extrema_ExtFlag, const Extrema_ExtAlgo)) &BRepExtrema_ExtPF::Initialize, "None", py::arg("TheFace"), py::arg("TheFlag"), py::arg("TheAlgo"));
cls_BRepExtrema_ExtPF.def("Perform", (void (BRepExtrema_ExtPF::*)(const TopoDS_Vertex &, const TopoDS_Face &)) &BRepExtrema_ExtPF::Perform, "An exception is raised if the fields have not been initialized. Be careful: this method uses the Face only for classify not for the fields.", py::arg("TheVertex"), py::arg("TheFace"));
cls_BRepExtrema_ExtPF.def("IsDone", (Standard_Boolean (BRepExtrema_ExtPF::*)() const) &BRepExtrema_ExtPF::IsDone, "True if the distances are found.");
cls_BRepExtrema_ExtPF.def("NbExt", (Standard_Integer (BRepExtrema_ExtPF::*)() const) &BRepExtrema_ExtPF::NbExt, "Returns the number of extremum distances.");
cls_BRepExtrema_ExtPF.def("SquareDistance", (Standard_Real (BRepExtrema_ExtPF::*)(const Standard_Integer) const) &BRepExtrema_ExtPF::SquareDistance, "Returns the value of the <N>th extremum square distance.", py::arg("N"));
cls_BRepExtrema_ExtPF.def("Parameter", [](BRepExtrema_ExtPF &self, const Standard_Integer N, Standard_Real & U, Standard_Real & V){ self.Parameter(N, U, V); return std::tuple<Standard_Real &, Standard_Real &>(U, V); }, "Returns the parameters on the Face of the <N>th extremum distance.", py::arg("N"), py::arg("U"), py::arg("V"));
cls_BRepExtrema_ExtPF.def("Point", (gp_Pnt (BRepExtrema_ExtPF::*)(const Standard_Integer) const) &BRepExtrema_ExtPF::Point, "Returns the Point of the <N>th extremum distance.", py::arg("N"));
cls_BRepExtrema_ExtPF.def("SetFlag", (void (BRepExtrema_ExtPF::*)(const Extrema_ExtFlag)) &BRepExtrema_ExtPF::SetFlag, "None", py::arg("F"));
cls_BRepExtrema_ExtPF.def("SetAlgo", (void (BRepExtrema_ExtPF::*)(const Extrema_ExtAlgo)) &BRepExtrema_ExtPF::SetAlgo, "None", py::arg("A"));

// Enums

}